#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SequenceEventData.generated.h"

class UEventInfoClass;
// struct FEventInfoCarTalk;
// struct FEventInfo;

UCLASS()
class PROJETVR_TEAM8_API USequenceEventData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(Instanced, EditAnywhere)
	TArray<UEventInfoClass*> Events;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<USequenceEventData> NextTimeline;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<USequenceEventData> TimelineB;

	UPROPERTY(EditAnywhere)
	bool IsClimaxTimeline;

	UPROPERTY(EditAnywhere)
	float TimelineDuration;
};

