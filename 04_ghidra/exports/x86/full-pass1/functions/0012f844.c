/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f844 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rfree(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1[0xc] + 0x128) + 0x18);
  *piVar1 = *piVar1 + -1;
  if (param_1[0x1c] != 0) {
    _crfree(param_1[0x1c]);
    param_1[0x1c] = 0;
  }
  if (*param_1 == 0) {
    if (_rpfreelist == (int *)0x0) {
      *param_1 = (int)param_1;
      param_1[1] = (int)param_1;
    }
    else {
      *param_1 = (int)_rpfreelist;
      param_1[1] = _rpfreelist[1];
      *(int **)_rpfreelist[1] = param_1;
      _rpfreelist[1] = (int)param_1;
    }
    _rpfreelist = param_1;
    __rnfree = __rnfree + 1;
  }
  return;
}

