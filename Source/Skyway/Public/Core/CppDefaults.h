// Copyright UC Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagsManager.h"
#include "CppDefaults.generated.h"

class UDataTable;

UCLASS()
class SKYWAY_API UCppDefaults : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintPure)
    static TArray<FGameplayTag> GetChildrensByTag(FGameplayTag Id, UDataTable* DataTable);

    UFUNCTION(BlueprintPure)
    static FLinearColor GetBotMainColor();

    UFUNCTION(BlueprintCallable)
    static void SetBotMainColor(FLinearColor NewColor);

    UFUNCTION(BlueprintPure)
    static FLinearColor GetBotSecondColor();

    UFUNCTION(BlueprintCallable)
    static void SetBotSecondColor(FLinearColor NewColor);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetGraphicIndex();

    UFUNCTION(BlueprintCallable)
    static void SetGraphicIndex(int32 NewGraphicIndex);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<UDataTable*> GetDataTableList();
};
