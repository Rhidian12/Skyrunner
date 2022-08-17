// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SKYRUNNER_API APlayerCharacter : public ACharacter
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
	UFUNCTION(BlueprintPure)
	bool CanDash() const;
	UFUNCTION(BlueprintPure)
	bool IsInvulnerable() const;

	UPROPERTY(EditAnywhere)
	float DashForce;
	UPROPERTY(EditAnywhere)
	float DashCooldownTime;
	UPROPERTY(EditAnywhere)
	float DashInvulnerabilityTime;

	float DashCooldownTimer;
	float DashInvulnerabilityTimer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
