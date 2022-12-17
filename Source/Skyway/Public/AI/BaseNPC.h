
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AISightTargetInterface.h"
#include "GenericTeamAgentInterface.h"
#include "BaseNPC.generated.h"




class UBehaviorTree;



UCLASS()
class SKYWAY_API ABaseNPC : public ACharacter, public IAISightTargetInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AI")
	int32 ID = 0;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTreeAsset;
	ABaseNPC(const FObjectInitializer& ObjInit);

	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }
protected:
	FGenericTeamId TeamId;

};