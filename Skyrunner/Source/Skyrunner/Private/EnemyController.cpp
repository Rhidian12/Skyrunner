// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "../SkyrunnerGameModeBase.h"

AEnemyController::AEnemyController()
{
	SetGenericTeamId(FGenericTeamId{ 1 });
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	FScriptDelegate initializeDelegate{};
	initializeDelegate.BindUFunction(this, "Init");
	Cast<ASkyrunnerGameModeBase>(GetWorld()->GetAuthGameMode())->GetInitSystem()->OnGameStart.Add(initializeDelegate);
}

void AEnemyController::Init()
{

}
