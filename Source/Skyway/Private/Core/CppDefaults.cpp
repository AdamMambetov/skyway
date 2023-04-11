// Copyright UC Games, Inc. All Rights Reserved.

#include "Core/CppDefaults.h"
#include "GameplayTagContainer.h"

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
