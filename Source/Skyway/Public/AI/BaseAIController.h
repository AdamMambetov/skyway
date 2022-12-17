
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
	class UAISenseConfig_Sight* Sight;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UBaseAIPerceptionComponent* BaseAIPerceptionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FName FocusOnKeyName = "EnemyActor";
	virtual void BeginPlay();

	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;

	FGenericTeamId TeamId;
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;


private:
	AActor* GetFocusOnActor() const;
};