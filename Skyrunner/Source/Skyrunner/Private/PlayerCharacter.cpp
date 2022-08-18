// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "../SkyrunnerGameModeBase.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TeamID = FGenericTeamId{ 0 };
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	FScriptDelegate initializeDelegate{};
	initializeDelegate.BindUFunction(this, "Init");
	Cast<ASkyrunnerGameModeBase>(GetWorld()->GetAuthGameMode())->GetInitSystem()->OnGameStart.Add(initializeDelegate);
}

void APlayerCharacter::Init()
{
	pCharacterMovementComponent = Cast<UCharacterMovementComponent>(GetMovementComponent());
}

FGenericTeamId APlayerCharacter::GetGenericTeamId() const
{
	return TeamID;
}

void APlayerCharacter::Dash()
{
	if (CanDash())
	{
		FVector playerForward{ GetActorForwardVector() };

		playerForward.Z = 0;
		bool successfulNormalise = playerForward.Normalize();
		
		if (successfulNormalise)
		{
			OldGroundFriction = pCharacterMovementComponent->GroundFriction;
			pCharacterMovementComponent->GroundFriction = pCharacterMovementComponent->FallingLateralFriction;
			MovementSpeedPreDashSquared = pCharacterMovementComponent->Velocity.SquaredLength();

			LaunchCharacter(playerForward * DashForce, true, true);
			DashCooldownTimer = DashCooldownTime;
			DashDurationTimer = DashDuration;
			DashInvulnerabilityTimer = DashInvulnerabilityTime;
		}
	}
}

void APlayerCharacter::OnDashEnd()
{
	if (!IsDashing()) // if we ended our dash at the end of it's duration (if we end early then it's because a sudden velocity change we don't wanna mess with)
	{
		// reset speed to speed before we dashed
		// (pCharacterMovementComponent->Velocity.Normalize() * sqrt(MovementSpeedPreDashSquared))
		pCharacterMovementComponent->Velocity.Normalize();
		pCharacterMovementComponent->Velocity *= pCharacterMovementComponent->GetMaxSpeed();
	}
	pCharacterMovementComponent->GroundFriction = OldGroundFriction;

	DashDurationTimer = 0; // reset timer in case we ended our dash by losing speed (Slamming into a wall)
	DashInvulnerabilityTimer = 0; // reset timer in case we ended our dash by losing speed (Slamming into a wall)
}

bool APlayerCharacter::CanDash() const
{
	return DashCooldownTimer <= 0.0f;
}

bool APlayerCharacter::IsDashing() const
{
	return DashDurationTimer > 0.0f;
}

bool APlayerCharacter::IsInvulnerable() const
{
	return DashInvulnerabilityTimer > 0.0f;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (!CanDash())
	{
		DashCooldownTimer -= DeltaTime;
	}
	if (IsDashing())
	{
		DashDurationTimer -= DeltaTime;
		if (!IsDashing() || pCharacterMovementComponent->Velocity.SquaredLength() <= MovementSpeedPreDashSquared)
		{
			OnDashEnd();
		}
	}
	if (IsInvulnerable())
	{
		DashInvulnerabilityTimer -= DeltaTime;
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

