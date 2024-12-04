#pragma once

#include "CoreMinimal.h"
#include "ProjetVR_Team8/EventSettings.h"
#include "Subsystems/WorldSubsystem.h"
#include "EventManagerSubSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventManager_UnlockDoors);

UCLASS()
class PROJETVR_TEAM8_API UEventManagerSubSystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FEventManager_UnlockDoors OnUnlockDoorEvent;
	
	TObjectPtr<const UEventSettings> EventSettings;
	TArray<FEventInfo> CurrentTimeline;

	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void Tick(float DeltaTime) override;

private:
	float TimeElapsed;
};
