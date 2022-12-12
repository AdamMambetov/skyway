


#include "AI/BaseAIController.h"
#include "AI/BaseNPC.h"
#include "AI/Components/BaseAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/CrowdFollowingComponent.h"


ABaseAIController::ABaseAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>
    (TEXT("PathFollowingComponent")))
{
    BaseAIPerceptionComponent = CreateDefaultSubobject<UBaseAIPerceptionComponent>("BasePerceptionComponent");
    SetPerceptionComponent(*BaseAIPerceptionComponent);
}



void ABaseAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    const auto BaseNPC = Cast<ABaseNPC>(InPawn);
    if(BaseNPC) RunBehaviorTree(BaseNPC->BehaviorTreeAsset);
}

AActor* ABaseAIController::GetFocusOnActor() const
{
    if(!GetBlackboardComponent()) return nullptr;
    return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}

void ABaseAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    const auto AimActor = GetFocusOnActor();
    SetFocus(AimActor);
}

