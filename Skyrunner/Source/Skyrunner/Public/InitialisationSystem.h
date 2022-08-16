// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InitialisationSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLateOnGameStart);

/**
 * 
 */
UCLASS()
class SKYRUNNER_API UInitialisationSystem final : public UObject
{
	GENERATED_BODY()
public:
	UInitialisationSystem();

	UPROPERTY(BlueprintAssignable)
	FOnGameStart OnGameStart;

	UPROPERTY(BlueprintAssignable)
	FLateOnGameStart OnLateGameStart;
};
