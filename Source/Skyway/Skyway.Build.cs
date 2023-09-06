// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class Skyway : ModuleRules
{
	public Skyway(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"GameplayTasks",
			"NavigationSystem",
			"GameplayTags",
			"DeveloperSettings",
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[]
		{
			"Skyway/Public/AI",
			"Skyway/Private/AI/Tasks",
			"Skyway/Public/Building",
			"Skyway/Public/Core",
		});

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			var manifestFile = Path.Combine(this.ModuleDirectory, "RemoveAndroidPermissions_UPL.xml");
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", manifestFile);
		}

	}
}
