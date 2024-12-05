#include "EventManager.h"

#include "EventManagerSubSystem.h"
#include "SequenceEventData.h"


AEventManager::AEventManager()
{
	PrimaryActorTick.bCanEverTick = true;
	TimeElapsed = 0.0f;
}

void AEventManager::BeginPlay()
{
	Super::BeginPlay();
	ChangeTimeline(TimelineA);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("START EVENTS")));
}

void AEventManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeElapsed += DeltaTime;

	for (int i = Events.Num() - 1; i >= 0; i--)
	{
		if (TimeElapsed >= Events[i].EventTime)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, *StaticEnum<EEventType>()->GetValueAsString(Events[i]->EventType));
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("%f "), Events[i].EventTime) + StaticEnum<EEventType>()->GetValueAsString(Events[i].EventType));
			
			switch (Events[i].EventType.GetValue())
			{
				case UnlockDoors:
					GetWorld()->GetSubsystem<UEventManagerSubSystem>()->OnUnlockDoorEvent.Broadcast();
					break;
				
				case LightFlicker:
					GetWorld()->GetSubsystem<UEventManagerSubSystem>()->OnLightFlickerEvent.Broadcast();
					break;
				
				case RadioBug:
					GetWorld()->GetSubsystem<UEventManagerSubSystem>()->OnRadioBugEvent.Broadcast();
					break;
				
				case RoadAppearance:
					GetWorld()->GetSubsystem<UEventManagerSubSystem>()->OnRoadAppearanceEvent.Broadcast();
					break;
				
				case RoadTurn:
					GetWorld()->GetSubsystem<UEventManagerSubSystem>()->OnRoadTurnEvent.Broadcast();
					break;
			}

			Events.RemoveAt(i);
		}
	}
}

void AEventManager::ChangeTimeline(USequenceEventData* EventData)
{
	if (EventData != nullptr)
	{
		Events.Empty();
		for (FEventInfo Event : EventData->Events)
		{
			Events.Add(Event);
		}
	}
}

