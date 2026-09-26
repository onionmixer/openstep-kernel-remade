/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c4fc4 */

undefined4 FUN_001c4fc4(int param_1,undefined4 param_2,int param_3,char *param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  int local_c;
  undefined *local_8;
  
  iVar2 = 0x14;
  bVar6 = true;
  pcVar4 = param_4;
  pcVar5 = "IO_4BPS_to_5BPS_map";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    if (param_5 == 0x10) {
      if (*(int *)(param_1 + 0x200) == 0) {
        uVar1 = _IOMalloc(0x10);
        *(undefined4 *)(param_1 + 0x200) = uVar1;
      }
      uVar3 = 0;
      do {
        *(undefined1 *)(uVar3 + *(int *)(param_1 + 0x200)) = *(undefined1 *)(uVar3 + param_3);
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x10);
      return 0;
    }
  }
  else {
    iVar2 = 0x14;
    bVar6 = true;
    pcVar4 = param_4;
    pcVar5 = "IO_5BPS_to_4BPS_map";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) {
      iVar2 = 0x1d;
      bVar6 = true;
      pcVar4 = param_4;
      pcVar5 = "IOCommitToPendingDisplayMode";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (!bVar6) {
        local_c = param_1;
        local_8 = PTR_s_IODisplay_001fa608;
        uVar1 = _objc_msgSendSuper(&local_c,PTR_s_setCharValues_forParameter_count_001f9538,param_3,
                                   param_4,param_5);
        return uVar1;
      }
      if (-1 < *(int *)(param_1 + 0x214)) {
        _objc_msgSend(param_1,PTR_s__commitToPendingMode_001f95e4);
        *(undefined4 *)(param_1 + 0x214) = 0xffffffff;
        return 0;
      }
      return 0xfffffd39;
    }
    if (param_5 == 0x20) {
      if (*(int *)(param_1 + 0x204) == 0) {
        uVar1 = _IOMalloc(0x20);
        *(undefined4 *)(param_1 + 0x204) = uVar1;
      }
      uVar3 = 0;
      do {
        *(undefined1 *)(uVar3 + *(int *)(param_1 + 0x204)) = *(undefined1 *)(uVar3 + param_3);
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x20);
      return 0;
    }
  }
  return 0xfffffd3e;
}

