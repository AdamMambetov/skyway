#include "Core/FileManager.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"

void UFileManager::SaveWorld(FString WorldName)
{
    FString FilePath = FPaths::ProjectContentDir();
    FilePath.Append(FString("../Saved/WorldNames.txt"));

    TArray<FString> WorldNames = GetWorldNames();
    WorldNames.AddUnique(WorldName);

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
