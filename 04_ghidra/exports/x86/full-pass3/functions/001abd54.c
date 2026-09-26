/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001abd54 */

undefined4
FUN_001abd54(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x22c),PTR_s_lock_001f9220);
  iVar2 = _objc_msgSend(param_1,PTR_s_numberOfTargets_001f9410);
  if (param_3 < iVar2) {
    iVar2 = _objc_msgSend(param_1,PTR_s_searchReserveQ_lun__001f9aec,param_3,param_4,param_5,param_6
                         );
    if (iVar2 == 0) {
      piVar3 = (int *)_IOMalloc(0x1c);
      *piVar3 = param_3;
      piVar3[1] = param_4;
      piVar3[2] = param_5;
      piVar3[3] = param_6;
      piVar3[4] = param_7;
      iVar2 = param_1 + 0x128;
      if (*(int *)(param_1 + 0x128) == iVar2) {
        *(int **)(param_1 + 0x128) = piVar3;
        *(int **)(param_1 + 300) = piVar3;
        piVar3[5] = iVar2;
        piVar3[6] = iVar2;
      }
      else {
        iVar1 = *(int *)(param_1 + 300);
        piVar3[6] = iVar1;
        piVar3[5] = iVar2;
        *(int **)(param_1 + 300) = piVar3;
        *(int **)(iVar1 + 0x14) = piVar3;
      }
      *(int *)(param_1 + 0x228) = *(int *)(param_1 + 0x228) + 1;
      goto LAB_001abe1c;
    }
  }
  uVar4 = 1;
LAB_001abe1c:
  _objc_msgSend(*(undefined4 *)(param_1 + 0x22c),PTR_s_unlock_001f9474);
  return uVar4;
}

