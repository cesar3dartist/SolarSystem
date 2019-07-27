// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class cplusplus_makeActorTarget : TargetRules
{
	public cplusplus_makeActorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "cplusplus_makeActor" } );
	}
}
