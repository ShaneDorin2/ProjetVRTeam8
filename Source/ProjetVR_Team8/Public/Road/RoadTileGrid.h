// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoadTileGrid.generated.h"

UCLASS()
class PROJETVR_TEAM8_API ARoadTileGrid : public AActor
{
	GENERATED_BODY()

#pragma region Unreal Defaults 
public:
	// Sets default values for this actor's properties
	ARoadTileGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

#pragma endregion

private:
	TArray<ARoadTile*> Tiles;
	
};
