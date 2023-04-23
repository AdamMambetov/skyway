// Copyright UC Games, Inc. All Rights Reserved.

#include "Core/FileManager.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"

void UFileManager::SetWorldNames(TArray<FString> WorldNames)
{
    FString FilePath = FPaths::ProjectContentDir();
    FilePath.Append(FString("../Saved/WorldNames.txt"));
    FFileHelper::SaveStringArrayToFile(WorldNames, *FilePath);
}

TArray<FString> UFileManager::GetWorldNames()
{
    FString FilePath = FPaths::ProjectContentDir();
    FilePath.Append(FString("../Saved/WorldNames.txt"));

    TArray<FString> ReturnArray;
    if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath)) return ReturnArray;

    FFileHelper::LoadFileToStringArray(ReturnArray, *FilePath);

    return ReturnArray;
}

void UFileManager::SetPlayerName(FString PlayerName)
{
    FString FilePath = FPaths::ProjectContentDir();
    FilePath.Append(FString("../Saved/PlayerName.txt"));
    FFileHelper::SaveStringToFile(PlayerName, *FilePath);
}

FString UFileManager::GetPlayerName()
{
    FString FilePath = FPaths::ProjectContentDir();
    FString ReturnValue;
    FilePath.Append(FString("../Saved/PlayerName.txt"));

    if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath)) return ReturnValue;

    FFileHelper::LoadFileToString(ReturnValue, *FilePath);
    return ReturnValue;
}
