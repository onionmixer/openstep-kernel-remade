/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b92e0 */

int FUN_001b92e0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = (int *)(param_1 + 0x2c);
  piVar1 = *(int **)(param_1 + 0x2c);
  while (piVar1 != piVar4) {
    iVar2 = *(int *)(param_1 + 0x2c);
    piVar1 = *(int **)(iVar2 + 0x3c);
    piVar3 = *(int **)(iVar2 + 0x40);
    piVar5 = piVar4;
    if (piVar4 != piVar1) {
      piVar5 = piVar1 + 0xf;
    }
    piVar5[1] = (int)piVar3;
    piVar5 = piVar4;
    if (piVar4 != piVar3) {
      piVar5 = piVar3 + 0xf;
    }
    *piVar5 = (int)piVar1;
    _objc_msgSend(param_1,PTR_s_freeRegion__001f9738,iVar2);
    piVar1 = *(int **)(param_1 + 0x2c);
  }
  return param_1;
}

