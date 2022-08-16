// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGun.h"
#include "../SkyrunnerGameModeBase.h"

// Sets default values
ABaseGun::ABaseGun()
	: RateOfFireTimer{}
	, ReloadTimer{}
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseGun::BeginPlay()
{
	Super::BeginPlay();

	FScriptDelegate initializeDelegate{};
	initializeDelegate.BindUFunction(this, "Init");
	Cast<ASkyrunnerGameModeBase>(GetWorld()->GetAuthGameMode())->GetInitSystem()->OnGameStart.Add(initializeDelegate);
}

void ABaseGun::Init()
{
	CurrentMagazine = MagazineSize;
	CurrentAmmo = MaxAmmo;
}

// Called every frame
void ABaseGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (RateOfFireTimer > 0.f)
	{
		RateOfFireTimer -= DeltaTime;
	}

	if (ReloadTimer > 0.f)
	{
		ReloadTimer -= DeltaTime;
	}
}

void ABaseGun::AddAmmo(const int nrOfMagazines)
{
	CurrentAmmo += nrOfMagazines * MagazineSize;

	if (CurrentAmmo > MaxAmmo)
	{
		CurrentAmmo = MaxAmmo;
	}
}

void ABaseGun::Reload()
{
	if (CurrentMagazine >= MagazineSize || CurrentAmmo <= 0)
	{
		return;
	}

	int ammoToReload = (MagazineSize - CurrentMagazine);
	if (ammoToReload > CurrentAmmo)
	{
		ammoToReload = CurrentAmmo;
	}
	CurrentAmmo -= ammoToReload;

	CurrentMagazine += ammoToReload;
}
