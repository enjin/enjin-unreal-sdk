// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

using UnrealBuildTool;

public class EnjinSdkCore : ModuleRules
{
	public EnjinSdkCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"HTTP",
			"Json",
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Engine",
			"Projects",
			"WebSockets",
		});
	}
}