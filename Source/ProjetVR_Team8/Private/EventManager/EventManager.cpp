#include "EventManager.h"
#include "EventManager/EventManager.h"
#include "EventManager/EventManagerSubSystem.h"
#include "EventManager/GameManager.h"
#include "EventManager/SequenceEventData.h"


AEventManager::AEventManager()
{
	PrimaryActorTick.bCanEverTick = true;
	TimeElapsed = 0.0f;
	CurrentTimelineElapsed = 0.0f;
}

void AEventManager::BeginPlay()
{
	Super::BeginPlay();
	ChangeTimeline(TimelineA);
	GetWorld()->GetSubsystem<UEventManagerSubSystem>()->OnRebootEvent.AddDynamic(this, &AEventManager::OnReboot);
	GetWorld()->GetSubsystem<UEventManagerSubSystem>()->ActivationManager.AddDynamic(this, &AEventManager::SetActivation);
}

void AEventManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsActivated)
	{
		return;
	}
	
	TimeElapsed += DeltaTime;
	CurrentTimelineElapsed += DeltaTime;

	//end of timeline
	if (TimeElapsed >= CurrentTimeline->TimelineDuration)
	{
		TimeElapsed = 0.0f;
		if (CurrentTimeline->IsClimaxTimeline)
		{
			if (ValidateNextTimeline)
			{
				ChangeTimeline(CurrentTimeline->NextTimeline);
			}
			else
			{
				GetWorld()->GetSubsystem<UGameManager>()->OnDie.Broadcast();

				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("DIED")));
			}

			ValidateNextTimeline = false;
		}
		else
		{
			ChangeTimeline(CurrentTimeline->NextTimeline);
		}
	}
	
	for (int i = Events.Num() - 1; i >= 0; i--)
	{
		if (CurrentTimelineElapsed >= Events[i]->EventTime)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, *StaticEnum<EEventType>()->GetValueAsString(Events[i]->EventType));
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("%f "), Events[i]->EventTime) + StaticEnum<EEventType>()->GetValueAsString(Events[i]->EventType));
			
			switch (Events[i]->EventType.GetValue())
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
				
				case RoadTurn:
					GetWorld()->GetSubsystem<UEventManagerSubSystem>()->OnRoadTurnEvent.Broadcast();
					break;
				
				case CarTalk:
					//UEventInfoCarTalk* CarTalkEvent = Cast<UEventInfoCarTalk>(Events[i]);
					GetWorld()->GetSubsystem<UEventManagerSubSystem>()->OnCarTalkEvent.Broadcast(Cast<UEventInfoCarTalk>(Events[i])->CarTalkSound);
					break;

				case RoadAppearance:
					//UEventRoadAppearance* RoadAppearance = Cast<UEventRoadAppearance>(Events[i]);
					GetWorld()->GetSubsystem<UEventManagerSubSystem>()->OnRoadAppearanceEvent.Broadcast(Cast<UEventRoadAppearance>(Events[i])->RoadAppearanceType);
					break;
			}

			Events.RemoveAt(i);
		}
	}
}

void AEventManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetSubsystem<UEventManagerSubSystem>()->OnRebootEvent.RemoveDynamic(this, &AEventManager::OnReboot); 
}

void AEventManager::ChangeTimeline(USequenceEventData* NewTimeline)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, NewTimeline->GetName());
	
	if (NewTimeline != nullptr)
	{
		Events.Empty();
		for (UEventInfoClass* Event : NewTimeline->Events)
		{
			Events.Add(Event);
		}
	}
	
	CurrentTimelineElapsed = 0;
	CurrentTimeline = NewTimeline;
}

void AEventManager::SetActivation(bool Activation)
{
	IsActivated = Activation;
}

void AEventManager::OnReboot()
{
	if (CurrentTimeline->IsClimaxTimeline)
	{
		ValidateNextTimeline = true;
	}
	else
	{
		ChangeTimeline(CurrentTimeline->TimelineB);
	}
}

