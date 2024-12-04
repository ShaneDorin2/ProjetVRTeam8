// Fill out your copyright notice in the Description page of Project Settings.


#include "Road/RoadTileGrid.h"


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
	
}

// Called every frame
void ARoadTileGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

