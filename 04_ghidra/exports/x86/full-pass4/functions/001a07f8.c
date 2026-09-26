/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a07f8 */

int FUN_001a07f8(int param_1,undefined4 param_2,uint *param_3,char *param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  int local_c;
  undefined *local_8;
  
  iVar1 = -0x2c2;
  iVar2 = 0x18;
  bVar5 = true;
  pcVar3 = param_4;
  pcVar4 = s_Evs_CurrentMouseScaling_001e4a51;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    *param_3 = *param_5 - 1 >> 1;
    _objc_msgSend(param_1,PTR_s_pointerScaling_data__001f955c,param_3,param_3 + 1);
    *param_5 = *param_3 * 2 | 1;
    iVar1 = 0;
  }
  else {
    iVar2 = 0x1b;
    bVar5 = true;
    pcVar3 = param_4;
    pcVar4 = s_Evs_CurrentMouseHandedness_001e4a69;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      if (*param_5 != 0) {
        *param_5 = 1;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
        *param_3 = *(uint *)(param_1 + 0x144);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_unlock_001f9474);
        iVar1 = 0;
      }
    }
    else {
      iVar2 = 0x14;
      bVar5 = true;
      pcVar3 = param_4;
      pcVar4 = s_Evs_EventDeviceInfo_001e4a84;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        *param_5 = 0;
        *param_3 = 4;
        param_3[2] = 2;
        param_3[1] = 0;
        param_3[3] = 0;
        *param_5 = 4;
        iVar1 = 0;
      }
      else {
        local_c = param_1;
        local_8 = PTR_s_IOEventSource_001fa068;
        iVar1 = _objc_msgSendSuper(&local_c,PTR_s_getIntValues_forParameter_count__001f9528,param_3,
                                   param_4,param_5);
        if (iVar1 == -0x2c7) {
          iVar1 = -0x2c2;
        }
      }
    }
  }
  return iVar1;
}

