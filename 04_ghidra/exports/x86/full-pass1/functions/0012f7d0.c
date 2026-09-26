/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f7d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0012f7d0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    if (piVar1 == param_1) {
      _rpfreelist = (int *)0x0;
    }
    else {
      if (_rpfreelist == param_1) {
        _rpfreelist = piVar1;
      }
      *(int *)param_1[1] = *param_1;
      *(int *)(*param_1 + 4) = param_1[1];
    }
    param_1[1] = 0;
    *param_1 = 0;
    __rnfree = __rnfree + -1;
  }
  return;
}

