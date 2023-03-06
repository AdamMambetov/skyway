// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

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
			"NavigationSystem"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[]
		{
			"Skyway/Public/AI",
			"Skyway/Private/AI/Tasks",
			"Skyway/Public/Building",
			"Skyway/Public/Core",
		});
		
	}
}
