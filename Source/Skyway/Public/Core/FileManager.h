// Copyright UC Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileManager.generated.h"

UCLASS()
class SKYWAY_API UFileManager : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    static void SetWorldNames(TArray<FString> WorldNames);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FString> GetWorldNames();

    UFUNCTION(BlueprintCallable)
    static void SetPlayerName(FString PlayerName);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetPlayerName();
};
