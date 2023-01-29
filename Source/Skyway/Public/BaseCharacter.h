
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AISightTargetInterface.h"
#include "GenericTeamAgentInterface.h"
#include "BaseCharacter.generated.h"

UCLASS()
class SKYWAY_API ABaseCharacter : public ACharacter, public IAISightTargetInterface, public IGenericTeamAgentInterface
{
    GENERATED_BODY()

public:
    ABaseCharacter();

    UFUNCTION(BlueprintGetter, Category = "AI")
    const int32 GetId() { return ID; }

    UFUNCTION(BlueprintSetter, Category = "AI")
    const void SetId(int32 NewId);

private:
    UPROPERTY(EditAnywhere, BlueprintGetter = GetId, BlueprintSetter = SetId, Category = "AI")
    int32 ID;
};