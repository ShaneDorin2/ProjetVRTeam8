// Fill out your copyright notice in the Description page of Project Settings.


#include "Road/RoadTileGrid.h"

#include "MaterialHLSLTree.h"
#include "Road/RoadTile.h"
#include "Road/RoadTileGridSlot.h"


// Sets default values
ARoadTileGrid::ARoadTileGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARoadTileGrid::BeginPlay()
{
	Super::BeginPlay();
	InitRoadTileGridSlots();
	
}

// Called every frame
void ARoadTileGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateSlotPositions(DeltaTime);
	if (PrimeSlotIsNotInPrimeSlotPosition())
	{
		AssignNewPrimeSlot();
		DespawnOldTileAndSpawnNewTile();
	}
}

void ARoadTileGrid::InitRoadTileGridSlots()
{
	for (int i=0; i<3; i++)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = this;
		SpawnParameters.Instigator = GetInstigator();

		ARoadTileGridSlot* RoadTileGridSlot = GetWorld()->SpawnActor<ARoadTileGridSlot>(RoadTileGridSlotBP, SpawnParameters);
		RoadTileGridSlot->AttachToActor(this,FAttachmentTransformRules::KeepRelativeTransform);
		RoadTileGridSlots.Add(RoadTileGridSlot);
		SlotIndexQueue->Enqueue(i);
	}
	PrimeSlotIndex = 1;
	TileWidth = RoadTileGridSlots[0]->GetTileWidth();

	RoadTileGridSlots[0]->SetActorLocation(FVector(TileWidth, 0, 0));
	RoadTileGridSlots[1]->SetActorLocation(FVector(0, 0, 0));
	RoadTileGridSlots[2]->SetActorLocation(FVector(-TileWidth, 0, 0));
}

void ARoadTileGrid::UpdateSlotPositions(float DeltaTime)
{
	for (ARoadTileGridSlot* Slot : RoadTileGridSlots)
	{
		Slot->SetActorLocation(FVector(Slot->GetActorLocation() + MovementDirection * MovementSpeed * DeltaTime));
	}
}

bool ARoadTileGrid::PrimeSlotIsNotInPrimeSlotPosition()
{
	return !IsSlotInPrimeSlotPosition(RoadTileGridSlots[PrimeSlotIndex]->GetActorLocation());
}

void ARoadTileGrid::AssignNewPrimeSlot()
{
	for (int i=0; i<3; i++)
	{
		if (IsSlotInPrimeSlotPosition(RoadTileGridSlots[i]->GetActorLocation()))
		{
			PrimeSlotIndex = i;
		}
	}
}

bool ARoadTileGrid::IsSlotInPrimeSlotPosition(const FVector& SlotPosition)
{
	return SlotPosition.X < TileWidth/2 && SlotPosition.X > TileWidth/2 *-1 &&
		SlotPosition.Y < TileWidth/2 && SlotPosition.Y > TileWidth/2 *-1;
}

void ARoadTileGrid::DespawnOldTileAndSpawnNewTile()
{
	int OldestSlotIndex;
	SlotIndexQueue->Dequeue(OldestSlotIndex);
	ARoadTileGridSlot* OldestSlot = RoadTileGridSlots[OldestSlotIndex];
	OldestSlot->SetActorLocation(GetNewSlotLocation());
	SlotIndexQueue->Enqueue(OldestSlotIndex);
}

FVector ARoadTileGrid::GetNewSlotLocation()
{
	return RoadTileGridSlots[PrimeSlotIndex]->GetActorLocation() - MovementDirection * TileWidth;
}



