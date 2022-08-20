// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseGun.h"
#include "HitscanGun.generated.h"

/**
 * 
 */
UCLASS()
class SKYRUNNER_API AHitscanGun : public ABaseGun
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	virtual void Fire(const FVector& dir) override;

	UFUNCTION(BlueprintImplementableEvent)
		void OnHit(AActor* pHitActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int DamagePerBullet;
};
