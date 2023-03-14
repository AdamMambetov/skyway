

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileManager.generated.h"

UCLASS()
class SKYWAY_API UFileManager : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable)
    static void SaveWorld(FString WorldName);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FString> GetWorldNames();
};