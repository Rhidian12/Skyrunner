// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGun.generated.h"

UCLASS()
class SKYRUNNER_API ABaseGun : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseGun();

	virtual void Tick(float DeltaTime) override;

	void AddAmmo(const int nrOfMagazines);
	void Reload();
	virtual void Fire(const FVector3d& dir) { UE_LOG(LogTemp, Warning, TEXT("Base gun should not be fired")); }
	bool CanFire() const { return (RateOfFireTimer <= 0.f && ReloadTimer <= 0.f); }

	int MagazineSize;
	float RateOfFire;
	float ReloadTime;
	int MaxAmmo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void Init();

	int CurrentMagazine;
	int CurrentAmmo;
	float RateOfFireTimer;
	float ReloadTimer;
};