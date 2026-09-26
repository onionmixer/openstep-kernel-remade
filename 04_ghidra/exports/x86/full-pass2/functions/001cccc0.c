/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cccc0 */

int * _class_getClassMethod(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    if ((*(byte *)(param_1 + 4) & 2) == 0) {
      param_1 = (undefined4 *)*param_1;
    }
    do {
      for (puVar1 = (undefined4 *)param_1[7]; puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        piVar3 = puVar1 + 2;
        iVar2 = puVar1[1];
        while (iVar2 = iVar2 + -1, -1 < iVar2) {
          if (*piVar3 == param_2) {
            return piVar3;
          }
          piVar3 = piVar3 + 3;
        }
      }
      param_1 = (undefined4 *)param_1[1];
    } while (param_1 != (undefined4 *)0x0);
  }
  return (int *)0x0;
}

