/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f96c */

int FUN_0019f96c(int param_1,undefined4 param_2,undefined4 *param_3,char *param_4,uint *param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  int local_14;
  undefined *local_10;
  undefined4 local_c [2];
  
  iVar2 = 0x15;
  bVar6 = true;
  pcVar4 = param_4;
  pcVar5 = s_Evs_CurrentKeyRepeat_001e4911;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    if (*param_5 < 4) {
      return -0x2c2;
    }
    *param_5 = 4;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
    local_c[0] = *(undefined4 *)(param_1 + 0x170);
    local_c[1] = *(undefined4 *)(param_1 + 0x174);
    uVar3 = 0;
    do {
      param_3[uVar3] = local_c[uVar3];
      uVar3 = uVar3 + 1;
    } while (uVar3 < 2);
    local_c[0] = *(undefined4 *)(param_1 + 0x168);
    local_c[1] = *(undefined4 *)(param_1 + 0x16c);
    uVar3 = 0;
    do {
      param_3[uVar3 + 2] = local_c[uVar3];
      uVar3 = uVar3 + 1;
    } while (uVar3 < 2);
    uVar1 = *(undefined4 *)(param_1 + 0x124);
  }
  else {
    iVar2 = 0x1c;
    bVar6 = true;
    pcVar4 = param_4;
    pcVar5 = s_Evs_CurrentKeyMappingLength_001e4926;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar2 = 0x14;
      bVar6 = true;
      pcVar4 = param_4;
      pcVar5 = s_Evs_EventDeviceInfo_001e4942;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        *param_5 = 0;
        uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_interfaceId_001f9520);
        *param_3 = uVar1;
        param_3[2] = 1;
        param_3[1] = 0;
        uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_handlerId_001f9524);
        param_3[3] = uVar1;
        *param_5 = 4;
        return 0;
      }
      local_14 = param_1;
      local_10 = PTR_s_IOEventSource_001fa040;
      iVar2 = _objc_msgSendSuper(&local_14,PTR_s_getIntValues_forParameter_count__001f9528,param_3,
                                 param_4,param_5);
      if (iVar2 != -0x2c7) {
        return iVar2;
      }
      return -0x2c2;
    }
    if (*param_5 == 0) {
      return -0x2c2;
    }
    *param_5 = 1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
    if (*(int *)(param_1 + 0x128) == 0) {
      *param_3 = 0;
    }
    else {
      uVar1 = _objc_msgSend(*(int *)(param_1 + 0x128),PTR_s_keyMappingLength_001f951c);
      *param_3 = uVar1;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x124);
  }
  _objc_msgSend(uVar1,PTR_s_unlock_001f9474);
  return 0;
}

