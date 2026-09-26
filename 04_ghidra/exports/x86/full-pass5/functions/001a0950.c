/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0950 */

int FUN_001a0950(int param_1,undefined4 param_2,int *param_3,char *param_4,uint param_5)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  int local_10;
  int local_c;
  undefined *local_8;
  
  local_10 = -0x2c2;
  iVar1 = 0x14;
  bVar4 = true;
  pcVar2 = param_4;
  pcVar3 = s_Evs_SetMouseScaling_001e4a98;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    if ((param_5 < 0x2a) && (*param_3 * 2 + 1U <= param_5)) {
      _objc_msgSend(param_1,PTR_s_setPointerScaling_data__001f9544,*param_3,param_3 + 1);
      local_10 = 0;
    }
  }
  else {
    iVar1 = 0x17;
    bVar4 = true;
    pcVar2 = param_4;
    pcVar3 = s_Evs_SetMouseHandedness_001e4aac;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      if (param_5 == 1) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
        *(int *)(param_1 + 0x144) = *param_3;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_unlock_001f9474);
        local_10 = 0;
      }
    }
    else {
      iVar1 = 0xf;
      bVar4 = true;
      pcVar2 = param_4;
      pcVar3 = s_Evs_ResetMouse_001e4ac3;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        local_10 = 0;
      }
      else {
        local_c = param_1;
        local_8 = PTR_s_IOEventSource_001fa068;
        local_10 = _objc_msgSendSuper(&local_c,PTR_s_setIntValues_forParameter_count__001f94bc,
                                      param_3,param_4,param_5);
        if (local_10 == -0x2c7) {
          local_10 = -0x2c2;
        }
      }
    }
  }
  return local_10;
}

