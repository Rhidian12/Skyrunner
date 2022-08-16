// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Public/InitialisationSystem.h"
#include "SkyrunnerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SKYRUNNER_API ASkyrunnerGameModeBase : public AGameMode
{
	GENERATED_BODY()
	
public:
	ASkyrunnerGameModeBase();

	virtual void StartMatch() override;

	UInitialisationSystem* const GetInitSystem() const { return pInitSystemInstance; }

private:
	UInitialisationSystem* pInitSystemInstance{};
};
