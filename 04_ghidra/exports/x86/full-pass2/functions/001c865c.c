/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c865c */

undefined4
FUN_001c865c(int param_1,undefined4 param_2,undefined4 *param_3,char *param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  int local_c;
  undefined *local_8;
  
  iVar2 = 0x10;
  bVar5 = true;
  pcVar3 = param_4;
  pcVar4 = "VPSetVPCodeSize";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    if (param_5 != 1) {
      return 0xfffffd3e;
    }
    if (*(int *)(param_1 + 0x23c) != 0) {
      _IOFree(*(int *)(param_1 + 0x23c),*(int *)(param_1 + 0x240) * 4);
    }
    *(undefined4 *)(param_1 + 0x240) = *param_3;
    *(undefined4 *)(param_1 + 0x244) = 0;
    iVar2 = _IOMalloc(*(int *)(param_1 + 0x240) * 4);
    *(int *)(param_1 + 0x23c) = iVar2;
    if (iVar2 != 0) {
      _IOLog("About to receive %d bytes of VPCode!\n",*(undefined4 *)(param_1 + 0x240));
      return 0;
    }
  }
  else {
    iVar2 = 0xc;
    bVar5 = true;
    pcVar3 = param_4;
    pcVar4 = "VPSetVPCode";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar2 = 0xc;
      bVar5 = true;
      pcVar3 = param_4;
      pcVar4 = "VPEndVPCode";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (!bVar5) {
        local_c = param_1;
        local_8 = PTR_s_IOFrameBufferDisplay_001fa658;
        uVar1 = _objc_msgSendSuper(&local_c,PTR_s_setIntValues_forParameter_count__001f94bc,param_3,
                                   param_4,param_5);
        return uVar1;
      }
      iVar2 = _objc_msgSend(param_1,PTR_s_getDisplayInfo_001f9570);
      if (iVar2 != 0) {
        return 0;
      }
      return 0xfffffd39;
    }
    if (*(int *)(param_1 + 0x23c) != 0) {
      if (*(uint *)(param_1 + 0x240) < (uint)(param_5 + *(int *)(param_1 + 0x244))) {
        return 0xfffffd3e;
      }
      _memcpy((void *)(*(int *)(param_1 + 0x23c) + *(int *)(param_1 + 0x244) * 4),param_3,
              param_5 * 4);
      *(int *)(param_1 + 0x244) = *(int *)(param_1 + 0x244) + param_5;
      _IOLog("Received %d bytes of VPCode!\n",param_5);
      return 0;
    }
  }
  return 0xfffffd43;
}

