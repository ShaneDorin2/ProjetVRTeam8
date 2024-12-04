#include "EventManagerSubSystem.h"

void UEventManagerSubSystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	EventSettings = GetDefault<UEventSettings>();
	CurrentTimeline = EventSettings->SequenceData->Events;
}

void UEventManagerSubSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeElapsed += DeltaTime;

	for (int i = CurrentTimeline.Num() - 1; i < 0; --i)
	{
		if (CurrentTimeline[i].EventTime >= TimeElapsed)
		{
			switch (CurrentTimeline[i].EventType.GetValue())
			{
				case UnlockDoors:
					GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("Unlock Doors")));
					OnUnlockDoorEvent.Broadcast();
					break;
			}

			CurrentTimeline.RemoveAt(i);
		}
	}
}
