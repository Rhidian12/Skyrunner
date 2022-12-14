// Copyright Epic Games, Inc. All Rights Reserved.


#include "SkyrunnerGameModeBase.h"

ASkyrunnerGameModeBase::ASkyrunnerGameModeBase()
{
	pInitSystemInstance = NewObject<UInitialisationSystem>(this, "InitSystem");
}

void ASkyrunnerGameModeBase::StartMatch()
{
	Super::StartMatch();

	pInitSystemInstance->OnGameStart.Broadcast();

	pInitSystemInstance->OnLateGameStart.Broadcast();
}