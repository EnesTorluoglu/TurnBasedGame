// Temp

using UnrealBuildTool;
using System.Collections.Generic;

public class TurnBasedTarget : TargetRules
{
	public TurnBasedTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "TurnBased" } );
	}
}
