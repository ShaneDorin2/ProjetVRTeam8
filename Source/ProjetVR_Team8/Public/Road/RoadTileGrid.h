// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoadTile.h"
#include "EventManager/EventEnums.h"
#include "GameFramework/Actor.h"
#include "RoadTileGrid.generated.h"

class ARoadTileGridSlot;
class UGameManager;

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


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ARoadTileGridSlot> RoadTileGridSlotBP;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 10;

	
private:

	void InitRoadTileGridSlots();

	void UpdateSlotPositions(float DeltaTime);

	bool PrimeSlotIsNotInPrimeSlotPosition();
	
	void AssignNewPrimeSlot();

	bool IsSlotInPrimeSlotPosition(const FVector& SlotPosition);
	
	void DespawnOldTileAndSpawnNewTile();

	FVector GetNewSlotLocation();

	TArray<ARoadTileGridSlot*> RoadTileGridSlots;
	TQueue<int> SlotIndexQueue[3];
	int PrimeSlotIndex;

	float TileWidth;
	
	FVector MovementDirection = FVector(1, 0, 0);

	UGameManager* GameManager;

#pragma region Spawn Object on RoadTile

public:
	
	UFUNCTION(BlueprintCallable)
	void QueueNewRoadsideObject(ERoadAppearanceType ObjectType);

private:
	//bool RoadsideSignHasBeenQueued = false;

	TQueue<ERoadAppearanceType> RoadsideObjectQueue;

	void AddRoadsideObjects(ARoadTileGridSlot* TileSlot);

#pragma endregion 
};
