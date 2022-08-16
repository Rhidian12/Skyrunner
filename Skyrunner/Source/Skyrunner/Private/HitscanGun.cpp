// Fill out your copyright notice in the Description page of Project Settings.


#include "HitscanGun.h"

void AHitscanGun::Fire(const FVector3d& dir)
{
	FHitResult hit{};

	if (GetWorld()->LineTraceSingleByChannel(
		hit,
		StartLocation,
		StartLocation + dir * 5000.f,
		ECC_GameTraceChannel1))
	{
		DrawDebugLine(GetWorld(), StartLocation, hit.GetActor()->GetActorLocation(), FColor::Cyan, false, 5.f, 0u, 3.f);
	}
	else
	{
		DrawDebugLine(GetWorld(), StartLocation, StartLocation + dir * 5000.f, FColor::Cyan, false, 5.f, 0u, 3.f);
	}
}