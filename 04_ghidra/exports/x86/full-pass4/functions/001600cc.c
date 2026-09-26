/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001600cc */

undefined4 FUN_001600cc(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined **ppuVar7;
  bool bVar8;
  undefined **local_8;
  
  local_8 = (undefined **)0x0;
  ppuVar7 = &_miniMonCommands;
  puVar3 = _miniMonCommands;
  while (puVar3 != (undefined *)0x0) {
    pcVar5 = *ppuVar7;
    cVar1 = *pcVar5;
    pcVar6 = param_1;
    while ((((cVar1 != '\0' && (cVar1 = *pcVar6, cVar1 != ' ')) && (1 < (byte)(cVar1 - 9U))) &&
           (cVar1 != '\0'))) {
      cVar2 = *pcVar5;
      pcVar6 = pcVar6 + 1;
      pcVar5 = pcVar5 + 1;
      if (cVar2 != cVar1) goto LAB_00160121;
      cVar1 = *pcVar5;
    }
    bVar8 = local_8 != (undefined **)0x0;
    local_8 = ppuVar7;
    if (bVar8) {
      pcVar5 = s_Ambiguous_command___type_____for_001df0b7;
      goto LAB_001601a1;
    }
LAB_00160121:
    ppuVar7 = ppuVar7 + 3;
    puVar3 = *ppuVar7;
  }
  ppuVar7 = &_miniMonMDCommands;
  puVar3 = _miniMonMDCommands;
  do {
    if (puVar3 == (undefined *)0x0) {
      if (local_8 == (undefined **)0x0) {
        pcVar5 = s_Invalid_command___type_____for_h_001df105;
LAB_001601a1:
        _safe_prf(pcVar5);
        uVar4 = 1;
      }
      else {
        uVar4 = (*(code *)local_8[1])(param_1);
      }
      return uVar4;
    }
    pcVar5 = *ppuVar7;
    cVar1 = *pcVar5;
    pcVar6 = param_1;
    while (((cVar1 != '\0' && (cVar1 = *pcVar6, cVar1 != ' ')) &&
           ((1 < (byte)(cVar1 - 9U) && (cVar1 != '\0'))))) {
      cVar2 = *pcVar5;
      pcVar6 = pcVar6 + 1;
      pcVar5 = pcVar5 + 1;
      if (cVar2 != cVar1) goto LAB_0016016d;
      cVar1 = *pcVar5;
    }
    bVar8 = local_8 != (undefined **)0x0;
    local_8 = ppuVar7;
    if (bVar8) {
      pcVar5 = s_Ambiguous_command___type_____for_001df0de;
      goto LAB_001601a1;
    }
LAB_0016016d:
    ppuVar7 = ppuVar7 + 3;
    puVar3 = *ppuVar7;
  } while( true );
}

