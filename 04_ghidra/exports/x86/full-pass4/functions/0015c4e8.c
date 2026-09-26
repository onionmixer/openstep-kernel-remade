/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c4e8 */

int * _nextsegfromheader(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  iVar1 = param_1 + 0x1c;
  uVar3 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    do {
      if (iVar1 == param_2) break;
      iVar1 = iVar1 + *(int *)(iVar1 + 4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x10));
  }
  if (uVar3 != *(uint *)(param_1 + 0x10)) {
    piVar2 = (int *)(iVar1 + *(int *)(iVar1 + 4));
    for (; uVar3 < *(uint *)(param_1 + 0x10); uVar3 = uVar3 + 1) {
      if (*piVar2 == 1) {
        return piVar2;
      }
      piVar2 = (int *)((int)piVar2 + piVar2[1]);
    }
  }
  return (int *)0x0;
}

