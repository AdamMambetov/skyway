

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "BaseAIPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS()
class SKYWAY_API UBaseAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()

public:
	AActor* GetClosestEnemy() const;
};
