/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ccc70 */

int * _class_getInstanceMethod(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_2;
  if (param_1 != 0) {
    while (iVar2 != 0) {
      for (puVar1 = *(undefined4 **)(param_1 + 0x1c); puVar1 != (undefined4 *)0x0;
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
      param_1 = *(int *)(param_1 + 4);
      iVar2 = param_1;
    }
  }
  return (int *)0x0;
}

