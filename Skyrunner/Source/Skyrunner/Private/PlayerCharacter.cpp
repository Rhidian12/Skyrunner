// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::Dash()
{
	if (CanDash())
	{
		FVector playerForward{ GetActorForwardVector() };
		
		if (GetMovementComponent()->IsMovingOnGround() && playerForward.Z < 0.0f)
		{
			playerForward.Z = 0;
			playerForward.Normalize();
		}
		
		LaunchCharacter(playerForward * DashForce, true, true);
		DashCooldownTimer = DashCooldownTime;
		DashInvulnerabilityTimer = DashInvulnerabilityTime;
	}
}

bool APlayerCharacter::CanDash() const
{
	return DashCooldownTimer <= 0.0f;
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

