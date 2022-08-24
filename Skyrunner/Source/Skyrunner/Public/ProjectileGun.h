// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseGun.h"
#include "BaseProjectile.h"
#include "ProjectileGun.generated.h"

/**
 * 
 */
UCLASS()
class SKYRUNNER_API AProjectileGun : public ABaseGun
{
	GENERATED_BODY()
public:

	virtual void Fire(const FVector& dir) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ABaseProjectile> ProjectileToFire;
};
