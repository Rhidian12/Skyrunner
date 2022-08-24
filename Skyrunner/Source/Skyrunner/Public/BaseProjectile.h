// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KillSelfComponent.h"
#include "BaseProjectile.generated.h"

UCLASS()
class SKYRUNNER_API ABaseProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UKillSelfComponent* KillSelfComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
