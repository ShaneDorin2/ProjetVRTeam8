// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FEventInfo.h"
#include "GameFramework/Actor.h"
#include "EventManager.generated.h"

class USequenceEventData;

UCLASS()
class PROJETVR_TEAM8_API AEventManager : public AActor
{
	GENERATED_BODY()

public:
	AEventManager();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<USequenceEventData> TimelineA;
	
	TArray<TObjectPtr<UEventInfoClass>> Events;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	float TimeElapsed;
	float CurrentTimelineElapsed;
	void ChangeTimeline (USequenceEventData* NewTimeline);
	
	TObjectPtr<USequenceEventData> CurrentTimeline;
	bool ValidateNextTimeline;

	UFUNCTION()
	void OnReboot();
};

