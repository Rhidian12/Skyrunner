// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 *
 */
UCLASS()
class SKYRUNNER_API AEnemyController : public AAIController
{
	GENERATED_BODY()
public:
	AEnemyController();

	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void Init();
};
