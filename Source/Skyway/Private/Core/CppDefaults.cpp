// Copyright UC Games, Inc. All Rights Reserved.

#include "Core/CppDefaults.h"
#include "GameplayTagContainer.h"
#include "SkywayDeveloperSettings.h"

TArray<FGameplayTag> UCppDefaults::GetChildrensByTag(FGameplayTag Id, UDataTable* DataTable)
{
    TArray<FGameplayTag> ReturnValue;
    if (!Id.IsValid() || !DataTable) return ReturnValue;

    auto RowNames = DataTable->GetRowNames();
    for (const auto& RowName : RowNames)
    {
        FGameplayTag Tag = FGameplayTag::RequestGameplayTag(RowName);

            if (!Tag.MatchesTag(Id)) continue;

        ReturnValue.Add(Tag);
    }
    return ReturnValue;
}

FLinearColor UCppDefaults::GetBotMainColor()
{
    return GetMutableDefault<USkywayDeveloperSettings>()->GetBotMainColor();
}

void UCppDefaults::SetBotMainColor(FLinearColor NewColor)
{
    GetMutableDefault<USkywayDeveloperSettings>()->SetBotMainColor(NewColor);
}

FLinearColor UCppDefaults::GetBotSecondColor()
{
    return GetMutableDefault<USkywayDeveloperSettings>()->GetBotSecondColor();
}

void UCppDefaults::SetBotSecondColor(FLinearColor NewColor)
{
    GetMutableDefault<USkywayDeveloperSettings>()->SetBotSecondColor(NewColor);
}

int32 UCppDefaults::GetGraphicIndex()
{
    return GetMutableDefault<USkywayDeveloperSettings>()->GetGraphicIndex();
}

void UCppDefaults::SetGraphicIndex(int32 NewGraphicIndex)
{
    GetMutableDefault<USkywayDeveloperSettings>()->SetGraphicIndex(NewGraphicIndex);
}