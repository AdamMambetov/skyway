


#include "AI/BaseAIController.h"
#include "AI/BaseNPC.h"
#include "AI/Components/BaseAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/CrowdFollowingComponent.h"

ABaseAIController::ABaseAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>
    (TEXT("PathFollowingComponent")))
{
}

void ABaseAIController::BeginPlay()
{
    Super::BeginPlay();
    
}


void ABaseAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    const auto BaseNPC = Cast<ABaseNPC>(InPawn);
    if(BaseNPC) RunBehaviorTree(BaseNPC->BehaviorTreeAsset);
    ABaseNPC* Chr = Cast<ABaseNPC>(GetPawn());
    if(Chr)
    {
        Agent = Chr;
        TeamId = FGenericTeamId(Agent->GetId());
    }
}



 ETeamAttitude::Type ABaseAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
    const APawn* OtherPawn = Cast<APawn>(&Other);
    if (OtherPawn == nullptr)
        return ETeamAttitude::Neutral;

    auto PlayerTI = Cast<IGenericTeamAgentInterface>(&Other);
    IGenericTeamAgentInterface* BotTI = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController());
    if (BotTI == nullptr && PlayerTI == nullptr)
        return ETeamAttitude::Neutral;

    FGenericTeamId OtherActorTeamId = NULL;
    if (BotTI != nullptr)
        OtherActorTeamId = BotTI->GetGenericTeamId();
    else if (PlayerTI != nullptr)
        OtherActorTeamId = PlayerTI->GetGenericTeamId();
    
    FGenericTeamId ThisId = GetGenericTeamId();

    if (OtherActorTeamId == 8)
    {
        return ETeamAttitude::Neutral;
    }
    else if (OtherActorTeamId == ThisId)
    {
        return ETeamAttitude::Friendly;
    }
    else
    {
        return ETeamAttitude::Hostile;
    }
        
}

