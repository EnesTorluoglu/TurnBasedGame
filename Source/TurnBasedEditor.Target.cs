// Temp

using UnrealBuildTool;
using System.Collections.Generic;

public class TurnBasedEditorTarget : TargetRules
{
	public TurnBasedEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "TurnBased" } );
	}
}
