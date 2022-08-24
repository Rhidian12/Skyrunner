// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	KillSelfComponent = CreateDefaultSubobject<UKillSelfComponent>("Kill Self Component");

}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Direction != FVector::ZeroVector)
	{
		FVector currentPos{ GetActorLocation() };

		currentPos += Direction * DeltaTime * Speed;

		SetActorLocation(currentPos);
	}
}

