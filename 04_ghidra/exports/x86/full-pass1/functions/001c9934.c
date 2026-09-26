/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9934 */

int FUN_001c9934(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    piVar3 = *(int **)(param_1 + 4);
    piVar2 = piVar3 + *(int *)(param_1 + 8);
    for (; piVar3 < piVar2; piVar3 = piVar3 + 1) {
      if (*piVar3 == param_3) {
        return param_1;
      }
    }
    iVar1 = _objc_msgSend(param_1,PTR_s_insertObject_at__001f9d2c,param_3,
                          *(undefined4 *)(param_1 + 8));
  }
  return iVar1;
}

