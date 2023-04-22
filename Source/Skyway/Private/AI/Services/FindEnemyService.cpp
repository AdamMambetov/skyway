


#include "AI/Services/FindEnemyService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Components/BaseAIPerceptionComponent.h"
#include "CUtils.h"

UFindEnemyService::UFindEnemyService()
{
    NodeName = "Find Enemy";
}

void UFindEnemyService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{   
    const auto Blackboard = OwnerComp.GetBlackboardComponent();
   
    GEngine->AddOnScreenDebugMessage(-1, DeltaSeconds, FColor::Green, FString::Printf(TEXT("NAME:   %s"), *OwnerComp.GetFullName()));
    if(Blackboard)
    {
        const auto Controller = OwnerComp.GetAIOwner();
        const auto PerceptionComponent = CUtils::GetPlayerComponent<UBaseAIPerceptionComponent>(Controller);
        if(PerceptionComponent)
        {
            Blackboard->SetValueAsObject(EnemyActorKey.SelectedKeyName, PerceptionComponent->GetClosestEnemy());
        }
    }
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}