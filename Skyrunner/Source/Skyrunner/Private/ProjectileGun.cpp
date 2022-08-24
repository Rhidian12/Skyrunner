// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileGun.h"
#include "Components/ArrowComponent.h"

void AProjectileGun::Fire(const FVector& dir)
{
	if (!CanFire())
	{
		return;
	}

	FRotator rotation{ 0.f };
	FVector location{ pStartLocationActor->GetComponentLocation() };
	ABaseProjectile* pProj{ Cast<ABaseProjectile>(GetWorld()->SpawnActor(*ProjectileToFire, &location, &rotation)) };

	pProj->Direction = dir;
}