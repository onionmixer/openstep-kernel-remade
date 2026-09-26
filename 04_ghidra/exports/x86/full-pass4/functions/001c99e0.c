/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c99e0 */

undefined4 FUN_001c99e0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 4);
  piVar1 = piVar3 + *(int *)(param_1 + 8);
  while( true ) {
    if (piVar1 <= piVar3) {
      return 0;
    }
    if (*piVar3 == param_3) break;
    piVar3 = piVar3 + 1;
  }
  uVar2 = _objc_msgSend(param_1,PTR_s_removeObjectAt__001f9d28,
                        (int)piVar3 - *(int *)(param_1 + 4) >> 2);
  return uVar2;
}

