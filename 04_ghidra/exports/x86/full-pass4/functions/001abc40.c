/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001abc40 */

void FUN_001abc40(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int local_c;
  undefined *local_8;
  
  piVar1 = *(int **)(param_1 + 0x128);
  if (piVar1 != (int *)0x0) {
    piVar3 = (int *)(param_1 + 0x128);
    while (piVar3 != piVar1) {
      iVar5 = *(int *)(param_1 + 0x128);
      piVar1 = *(int **)(iVar5 + 0x14);
      piVar2 = *(int **)(iVar5 + 0x18);
      piVar4 = piVar3;
      if (piVar3 != piVar1) {
        piVar4 = piVar1 + 5;
      }
      piVar4[1] = (int)piVar2;
      piVar4 = piVar3;
      if (piVar3 != piVar2) {
        piVar4 = piVar2 + 5;
      }
      *piVar4 = (int)piVar1;
      _IOFree(iVar5,0x1c);
      piVar1 = *(int **)(param_1 + 0x128);
    }
  }
  iVar5 = _objc_msgSend(param_1,PTR_s_unit_001f9c28);
  if (iVar5 == DAT_001e516c + -1) {
    DAT_001e516c = iVar5;
  }
  local_c = param_1;
  local_8 = PTR_s_IODirectDevice_001fa360;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

