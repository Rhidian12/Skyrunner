// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GenericTeamAgentInterface.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SKYRUNNER_API APlayerCharacter : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Dash();
	UFUNCTION(BlueprintCallable)
	void OnDashEnd();
	UFUNCTION(BlueprintPure)
	bool CanDash() const;
	UFUNCTION(BlueprintPure)
	bool IsDashing() const;
	UFUNCTION(BlueprintPure)
	bool IsInvulnerable() const;

	UPROPERTY(EditAnywhere)
	float DashForce;
	UPROPERTY(EditAnywhere)
	float DashCooldownTime;
	UPROPERTY(EditAnywhere)
	float DashDuration;
	UPROPERTY(EditAnywhere)
	float DashInvulnerabilityTime;

	float DashCooldownTimer;
	float DashDurationTimer;
	float DashInvulnerabilityTimer;

	UCharacterMovementComponent* pCharacterMovementComponent;
	float OldGroundFriction;
	float MovementSpeedPreDashSquared;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION()
	void Init();

	FGenericTeamId TeamID;

	virtual FGenericTeamId GetGenericTeamId() const override;
};
