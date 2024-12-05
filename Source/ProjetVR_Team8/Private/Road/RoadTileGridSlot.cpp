// Fill out your copyright notice in the Description page of Project Settings.


#include "Road/RoadTileGridSlot.h"
#include "Road/RoadTile.h"


// Sets default values
ARoadTileGridSlot::ARoadTileGridSlot()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARoadTileGridSlot::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	
	ARoadTile* RoadTile = GetWorld()->SpawnActor<ARoadTile>(RoadTileBP, SpawnParameters);
	RoadTile->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	ChangeCurrentRoadTile(RoadTile);
}

// Called every frame
void ARoadTileGridSlot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARoadTileGridSlot::SetSlotPosition(FVector NewPosition)
{
	this->SetActorLocation(NewPosition);
}

void ARoadTileGridSlot::ChangeCurrentRoadTile(ARoadTile* newRoadTile)
{
	CurrentRoadTile = newRoadTile;
}

float ARoadTileGridSlot::GetTileWidth()
{
	return CurrentRoadTile->GetComponentsBoundingBox().GetExtent().X *2;
}

