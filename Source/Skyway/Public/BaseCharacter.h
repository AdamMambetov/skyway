
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AISightTargetInterface.h"
#include "GenericTeamAgentInterface.h"
#include "BaseCharacter.generated.h"

// class UBehaviorTree;

UCLASS()
class SKYWAY_API ABaseCharacter : public ACharacter, public IAISightTargetInterface, public IGenericTeamAgentInterface
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "AI")
    int32 ID = 0;

    virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }

protected:
    FGenericTeamId TeamId;
};