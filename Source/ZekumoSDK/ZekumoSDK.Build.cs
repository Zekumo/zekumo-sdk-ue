using UnrealBuildTool;
public class ZekumoSDK:ModuleRules { public ZekumoSDK(ReadOnlyTargetRules Target):base(Target){PCHUsage=PCHUsageMode.UseExplicitOrSharedPCHs;PublicDependencyModuleNames.AddRange(new[]{"Core","HTTP","Json","JsonUtilities","WebSockets"});}}
