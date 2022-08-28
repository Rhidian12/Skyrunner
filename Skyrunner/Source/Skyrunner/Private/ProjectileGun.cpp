// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileGun.h"
#include "Components/ArrowComponent.h"

void AProjectileGun::Fire(const FVector& dir)
{
	if (!CanFire())
	{
		return;
	}

	FTransform transform{ pStartLocationActor->GetComponentTransform() };
	ABaseProjectile* pProj{ Cast<ABaseProjectile>(GetWorld()->SpawnActor(*ProjectileToFire, &transform)) };

	RateOfFireTimer = RateOfFire;
}