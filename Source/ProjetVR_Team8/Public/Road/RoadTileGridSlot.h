// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoadTileGridSlot.generated.h"

UCLASS()
class PROJETVR_TEAM8_API ARoadTileGridSlot : public AActor
{
	GENERATED_BODY()

	
public:
	// Sets default values for this actor's properties
	ARoadTileGridSlot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
