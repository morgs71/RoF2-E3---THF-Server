|----------------------------------------------------------------------------|
| Beastlord Functions
|----------------------------------------------------------------------------|
Sub BST_Setup
	/call IniToVar "${Character_Ini},Beastlord,Band of the Gargoyle-Wild Cat IV (On/Off)" BeastGargoyle bool outer
/return
|----------------------------------------------------------------------------|
SUB BST_MacroSettings
/if (${Debug}) /echo |- BST_MacroSettings ==>
	/call WriteToIni "${advSettings_Ini},BST Functions,BST Function#1" "check_Burns" 1
	/call WriteToIni "${advSettings_Ini},BST Functions,BST Function#2" "check_Debuffs" 1
  /call WriteToIni "${advSettings_Ini},BST Functions,BST Function#3" "check_Heals" 1
  /call WriteToIni "${advSettings_Ini},BST Functions,BST Function#4" "check_Cures" 1
	/call WriteToIni "${advSettings_Ini},BST Functions,BST Function#5" "check_Buffs" 1
	/call WriteToIni "${advSettings_Ini},BST Functions,BST Function#6" "check_Nukes" 1
	/call WriteToIni "${advSettings_Ini},BST Functions,BST Function#7" "check_Pets" 1
  /call WriteToIni "${advSettings_Ini},BST Functions,BST Function#8" "check_DoTs" 1
/if (${Debug}) /echo <== BST_MacroSettings -|
/RETURN
|----------------------------------------------------------------------------|
#event AE_POS "#*# tells you, 'AEPOS'"
sub Event_AE_POS(string line)
  /if (${Me.Class.ShortName.Equal[BST]}) {
   /if (${Me.AltAbilityReady[Mass Group Buff]} && ${Me.AltAbilityReady[Paragon of Spirit]}) {
     /bc MGB Paragon of Spirit inc...
     /casting "Mass Group Buff|alt" -maxtries|3
     /delay 5 !${Me.AltAbilityReady[Mass Group Buff]}
     /delay 5
     /casting "Paragon of Spirit|alt" -maxtries|3
     /delay 5 !${Me.AltAbilityReady[Paragon of Spirit]}
     /casting "Paragon of Spirit|alt" -maxtries|3
     /rs MGB Paragon of Spirit inc...
   } else /if (!${Me.AltAbilityReady[Mass Group Buff]}) {
      /bc Mass Group Buff is not available...
   } else /bc Paragon of Spirit is not available...
  }
/return
|----------------------------------------------------------------------------|
Sub BST_Background_Events
  /doevents AE_POS
  /if (${BeastGargoyle} && !${BeastGargoyleTimer} && ${Me.Combat} && ${FindItemCount[=Band of the Gargoyle]})  {

	/call e3_Cast ${Me.ID} "Band of the Gargoyle"
	/call CreateTimer BeastGargoyleTimer 21
	}


/return
|----------------------------------------------------------------------------|
SUB BST_CharacterSettings
	/call WriteToIni "${Character_Ini},${Me.Class},Band of the Gargoyle-Wild Cat IV (On/Off)" Off
/RETURN
|----------------------------------------------------------------------------|
Sub BST_Aliases
/return