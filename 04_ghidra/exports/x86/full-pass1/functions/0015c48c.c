/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c48c */

int * _firstsegfromheader(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x1c);
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    do {
      if (*piVar2 == 1) {
        return piVar2;
      }
      piVar2 = (int *)((int)piVar2 + piVar2[1]);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x10));
  }
  return (int *)0x0;
}

