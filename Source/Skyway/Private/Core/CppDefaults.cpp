// Copyright UC Games, Inc. All Rights Reserved.

#include "Core/CppDefaults.h"
#include "GameplayTagContainer.h"
#include "SkywayDeveloperSettings.h"
#include "Engine/DataTable.h"
#include "GameplayTagsSettings.h"

TArray<FGameplayTag> UCppDefaults::GetChildrensByTag(FGameplayTag Id, UDataTable* DataTable)
{
    TArray<FGameplayTag> ReturnArray;
    if (!Id.IsValid() || !DataTable) return ReturnArray;

    auto RowNames = DataTable->GetRowNames();
    for (const auto& RowName : RowNames)
    {
        FGameplayTag Tag = FGameplayTag::RequestGameplayTag(RowName);

        if (!Tag.MatchesTag(Id)) continue;

        ReturnArray.Add(Tag);
    }
    return ReturnArray;
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

TArray<UDataTable*> UCppDefaults::GetDataTableList()
{
    TArray<UDataTable*> ReturnArray;
    auto TagSettings = GetMutableDefault<UGameplayTagsSettings>();

    for (const auto& Table : TagSettings->GameplayTagTableList)
    {
        ReturnArray.Add(Cast<UDataTable>(Table.ResolveObject()));
    }

    return ReturnArray;
}
