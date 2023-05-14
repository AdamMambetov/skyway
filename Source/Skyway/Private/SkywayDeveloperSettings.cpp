// Copyright UC Games, Inc. All Rights Reserved.

#include "SkywayDeveloperSettings.h"

void USkywayDeveloperSettings::SetBotMainColor(FLinearColor NewColor)
{
    BotMainColor = NewColor;
    SaveConfig();
}

void USkywayDeveloperSettings::SetBotSecondColor(FLinearColor NewColor)
{
    BotSecondColor = NewColor;
    SaveConfig();
}
