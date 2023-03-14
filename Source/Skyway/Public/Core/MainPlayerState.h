

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MainPlayerState.generated.h"

/**
 *
 */
UCLASS()
class SKYWAY_API AMainPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void SetNewPlayerName(FString NewName);
};
