/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ac0a4 */

undefined4
FUN_001ac0a4(undefined4 param_1,undefined4 param_2,int param_3,char *param_4,int *param_5)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  int local_1c;
  undefined4 local_18;
  undefined *local_14;
  undefined4 local_10 [3];
  
  local_1c = *param_5;
  if (local_1c == 0) {
    local_1c = 0x200;
  }
  iVar2 = 0x1b;
  bVar5 = true;
  pcVar3 = param_4;
  pcVar4 = "IOSCSIControllerStatistics";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    local_10[0] = _objc_msgSend(param_1,PTR_s_maxQueueLength_001f9ae8);
    local_10[1] = _objc_msgSend(param_1,PTR_s_numQueueSamples_001f9ae4);
    local_10[2] = _objc_msgSend(param_1,PTR_s_sumQueueLengths_001f9ae0);
    *param_5 = 0;
    iVar2 = 0;
    do {
      if (*param_5 == local_1c) break;
      *(undefined4 *)(param_3 + iVar2 * 4) = local_10[iVar2];
      *param_5 = *param_5 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    uVar1 = 0;
  }
  else {
    iVar2 = 0x14;
    bVar5 = true;
    pcVar3 = param_4;
    pcVar4 = "IOIsASCSIController";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      *param_5 = 0;
      uVar1 = 0;
    }
    else {
      local_18 = param_1;
      local_14 = PTR_s_IODirectDevice_001fa360;
      uVar1 = _objc_msgSendSuper(&local_18,PTR_s_getIntValues_forParameter_count__001f9528,param_3,
                                 param_4,param_5);
    }
  }
  return uVar1;
}

