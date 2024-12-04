// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoadTileGrid.generated.h"

class ARoadTileGridSlot;

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
	
	

	
	
	/*
	 * init:
	 *		create 3 slots (each slot creates their own tile)
	 *		Add the 3 slots into the array [this gives them their index/id]
	 *		Set the 3 slot positions based on tile size/x  (0, 0), (0, x), (0, -x)
	 *		set up queue of idexes (0, 1, 2)
	 *		set up primeSlot index (1)
	 *
	 * Tick:
	 *		Move all slots in the direction / speed.
	 *		if primeSlot.pos = +- tile width/2:
	 *			POP oldest slot from queue.
	 *			Change position of slop (based on pos of LATEST slot) (0, LATEST + x)
	 *			ADD poped slot onto queue. 
	 *
	 */
};
