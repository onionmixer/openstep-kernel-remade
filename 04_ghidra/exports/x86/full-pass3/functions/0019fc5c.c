/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019fc5c */

int FUN_0019fc5c(int param_1,undefined4 param_2,int param_3,char *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  undefined *puVar6;
  int local_14;
  undefined *local_10;
  undefined4 local_c [2];
  
  iVar1 = 0x11;
  bVar5 = true;
  pcVar3 = param_4;
  pcVar4 = s_Evs_SetKeyRepeat_001e496c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    if (param_5 != 2) {
      return -0x2c2;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
    uVar2 = 0;
    do {
      local_c[uVar2] = *(undefined4 *)(param_3 + uVar2 * 4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 2);
    *(undefined4 *)(param_1 + 0x168) = local_c[0];
    *(undefined4 *)(param_1 + 0x16c) = local_c[1];
    if ((*(int *)(param_1 + 0x16c) == 0) && (*(uint *)(param_1 + 0x168) < 16700000)) {
      *(undefined4 *)(param_1 + 0x168) = 16700000;
      *(undefined4 *)(param_1 + 0x16c) = 0;
    }
    param_1 = *(int *)(param_1 + 0x124);
    puVar6 = PTR_s_unlock_001f9474;
  }
  else {
    iVar1 = 0x18;
    bVar5 = true;
    pcVar3 = param_4;
    pcVar4 = s_Evs_SetInitialKeyRepeat_001e497d;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      if (param_5 != 2) {
        return -0x2c2;
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
      uVar2 = 0;
      do {
        local_c[uVar2] = *(undefined4 *)(param_3 + uVar2 * 4);
        uVar2 = uVar2 + 1;
      } while (uVar2 < 2);
      *(undefined4 *)(param_1 + 0x170) = local_c[0];
      *(undefined4 *)(param_1 + 0x174) = local_c[1];
      if ((*(int *)(param_1 + 0x174) == 0) && (*(uint *)(param_1 + 0x170) < 16700000)) {
        *(undefined4 *)(param_1 + 0x170) = 16700000;
        *(undefined4 *)(param_1 + 0x174) = 0;
      }
      param_1 = *(int *)(param_1 + 0x124);
      puVar6 = PTR_s_unlock_001f9474;
    }
    else {
      iVar1 = 0x12;
      bVar5 = true;
      pcVar3 = param_4;
      pcVar4 = s_Evs_ResetKeyboard_001e4995;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      puVar6 = PTR_s_resetKeyboard_001f9534;
      if (!bVar5) {
        local_14 = param_1;
        local_10 = PTR_s_IOEventSource_001fa040;
        iVar1 = _objc_msgSendSuper(&local_14,PTR_s_setIntValues_forParameter_count__001f94bc,param_3
                                   ,param_4,param_5);
        if (iVar1 != -0x2c7) {
          return iVar1;
        }
        return -0x2c2;
      }
    }
  }
  _objc_msgSend(param_1,puVar6);
  return 0;
}

