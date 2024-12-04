#pragma once

#include "CoreMinimal.h"
#include "SequenceEventData.h"
#include "Engine/DeveloperSettings.h"
#include "EventSettings.generated.h"

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName = "Sequence Settings"))
class PROJETVR_TEAM8_API UEventSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Sequence")
	TObjectPtr<USequenceEventData> SequenceData;
};