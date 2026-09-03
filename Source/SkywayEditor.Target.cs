// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SkywayEditorTarget : TargetRules
{
	public SkywayEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
		CppStandard = CppStandardVersion.Cpp20;
		ExtraModuleNames.AddRange(new string[] { "Skyway" });
	}
}
