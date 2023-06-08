// Copyright UC Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/DataTable.h"
#include "Misc/Paths.h"
#include "GameplayTagsManager.h"
#include "SkywayDeveloperSettings.generated.h"

UCLASS(Config = "Game", DefaultConfig, meta = (DisplayName = "Skyway"))
class SKYWAY_API USkywayDeveloperSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    FLinearColor GetBotMainColor() { return BotMainColor; };

    FLinearColor GetBotSecondColor() { return BotSecondColor; };

    void SetBotMainColor(FLinearColor NewColor);

    void SetBotSecondColor(FLinearColor NewColor);

    void SetGraphicIndex(int32 NewGraphicIndex);

    int32 GetGraphicIndex() { return GraphicIndex; };

protected:
    UPROPERTY(EditAnywhere, Config, Category = "Bot", meta = (DisplayName = "Bot Main Color"))
    FLinearColor BotMainColor;

    UPROPERTY(EditAnywhere, Config, Category = "Bot", meta = (DisplayName = "Bot Second Color"))
    FLinearColor BotSecondColor;

    UPROPERTY(EditAnywhere, Config, Category = "Bot", meta = (DisplayName = "Graphic Index"))
    int32 GraphicIndex;
};
