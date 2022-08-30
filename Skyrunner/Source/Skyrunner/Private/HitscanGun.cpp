// Fill out your copyright notice in the Description page of Project Settings.


#include "HitscanGun.h"
#include "Components/ArrowComponent.h"

void AHitscanGun::Fire(const FVector& dir)
{
	if (!CanFire())
	{
		return;
	}

	FHitResult hit{};

	const FVector& forward{ GetActorForwardVector() };
	const FVector& cameraStart{ Cast<APlayerController>(
		Cast<APawn>(
			GetOwner())->GetController())
		->PlayerCameraManager->GetCameraLocation() };
	const FVector& muzzleStart{ pStartLocationActor->GetComponentLocation() };

	const FVector& end{ cameraStart + forward * 5000.f };

	if (GetWorld()->LineTraceSingleByChannel(hit, muzzleStart, end, ECC_GameTraceChannel1))
	{
		DrawDebugLine(GetWorld(), muzzleStart, hit.ImpactPoint, FColor::Cyan, false, 5.f, 0u, 3.f);
	
		OnHit(hit.GetActor());
	}
	else
	{
		DrawDebugLine(GetWorld(), muzzleStart, end, FColor::Cyan, false, 5.f, 0u, 3.f);
	}

	RateOfFireTimer = RateOfFire;
}

void AHitscanGun::BeginPlay()
{
	Super::BeginPlay();
}
