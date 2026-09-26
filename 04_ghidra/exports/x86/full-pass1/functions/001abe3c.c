/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001abe3c */

void FUN_001abe3c(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x22c),PTR_s_lock_001f9220);
  iVar2 = _objc_msgSend(param_1,PTR_s_numberOfTargets_001f9410);
  if (param_3 < iVar2) {
    iVar2 = _objc_msgSend(param_1,PTR_s_searchReserveQ_lun__001f9aec,param_3,param_4,param_5,param_6
                         );
    if (iVar2 == 0) {
      pcVar5 = "IOSCSIController releaseTarget: NOT RESERVED\n";
    }
    else {
      if (*(int *)(iVar2 + 0x10) == param_7) {
        iVar1 = *(int *)(iVar2 + 0x14);
        piVar4 = *(int **)(iVar2 + 0x18);
        iVar3 = iVar1;
        if (param_1 + 0x128 != iVar1) {
          iVar3 = iVar1 + 0x14;
        }
        *(int **)(iVar3 + 4) = piVar4;
        if ((int *)(param_1 + 0x128) != piVar4) {
          piVar4 = piVar4 + 5;
        }
        *piVar4 = iVar1;
        _IOFree(iVar2,0x1c);
        *(int *)(param_1 + 0x228) = *(int *)(param_1 + 0x228) + -1;
        goto LAB_001abefa;
      }
      pcVar5 = "IOSCSIController releaseTarget: INVALID OWNER\n";
    }
  }
  else {
    pcVar5 = "IOSCSIController releaseTarget: INVALID TARGET\n";
  }
  _IOLog(pcVar5);
LAB_001abefa:
  _objc_msgSend(*(undefined4 *)(param_1 + 0x22c),PTR_s_unlock_001f9474);
  return;
}

