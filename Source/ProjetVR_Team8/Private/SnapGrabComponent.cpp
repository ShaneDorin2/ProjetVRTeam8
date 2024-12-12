

#include "SnapGrabComponent.h"
#include "HandGrabState.h"


USnapGrabComponent::USnapGrabComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USnapGrabComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USnapGrabComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateObject(DeltaTime);
}

void USnapGrabComponent::Grab(USceneComponent* Controller, USceneComponent* Hand)
{	
	if(MotionControllerComponents.Num() == 0 || !MotionControllerComponents.Contains(Controller))
		MotionControllerComponents.Add(Controller);

	if(HandsComponents.Num() == 0 || !HandsComponents.Contains(Hand))
		HandsComponents.Add(Hand);
  
	Hand->AttachToComponent(TargetObject, FAttachmentTransformRules::KeepWorldTransform);
}

void USnapGrabComponent::Ungrab(USceneComponent* Controller, USceneComponent* Hand)
{
	if(MotionControllerComponents.Contains(Controller))
		MotionControllerComponents.Remove(Controller);

	if(HandsComponents.Contains(Hand))
		HandsComponents.Remove(Hand);
		
	Hand->AttachToComponent(Controller, FAttachmentTransformRules::KeepRelativeTransform);
}

void USnapGrabComponent::UpdateObject(float DeltaTime)
{
	//FVector LeadControllerPosition =  MotionControllerComponents[0]->GetComponentLocation();
}


