﻿// Fill out your copyright notice in the Description page of Project Settings.


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

void ARoadTileGridSlot::ChangeCurrentRoadTile(RoadTile* newRoadTile)
{
	CurrentRoadTile = newRoadTile;
}

