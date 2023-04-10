// Copyright UC Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "CppDefaults.generated.h"

UCLASS()
class SKYWAY_API UCppDefaults : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintPure)
    static TArray<FGameplayTag> GetChildrensByTag(FGameplayTag Id, UDataTable* DataTable);
};