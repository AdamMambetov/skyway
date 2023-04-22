
#pragma once

#include "CoreMinimal.h"
#include "AIController.h" 
#include "BaseAIController.generated.h"



class UBaseAIPerceptionComponent;


UCLASS()
class SKYWAY_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

public:
	ABaseAIController(const FObjectInitializer& ObjectInitializer);
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }
	class ABaseNPC* Agent;

protected:
	virtual void BeginPlay();

	virtual void OnPossess(APawn* InPawn) override;

	FGenericTeamId TeamId;
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;


private:
};