// Fill out your copyright notice in the Description page of Project Settings.


#include "HitscanGun.h"
#include "Components/ArrowComponent.h"

void AHitscanGun::Fire(const FVector& dir)
{
	FHitResult hit{};

	const FVector& start{ pStartLocationActor->GetComponentLocation() };

	if (GetWorld()->LineTraceSingleByChannel(
		hit,
		start,
		start + dir * 5000.f,
		ECC_GameTraceChannel1))
	{
		DrawDebugLine(GetWorld(), start, hit.ImpactPoint, FColor::Cyan, false, 5.f, 0u, 3.f);
	}
	else
	{
		DrawDebugLine(GetWorld(), start, start + dir * 5000.f, FColor::Cyan, false, 5.f, 0u, 3.f);
	}
}