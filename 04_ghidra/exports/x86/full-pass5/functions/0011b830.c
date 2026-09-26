/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b830 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0011b830(int *param_1)

{
  int iVar1;
  
  *(int *)(param_1[3] + 8) = param_1[2];
  *(int *)(param_1[2] + 0xc) = param_1[3];
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _vn_rele(param_1[5]);
  param_1[5] = 0;
  _vn_rele(param_1[4]);
  param_1[4] = 0;
  if (param_1[0xf] != 0) {
    _crfree(param_1[0xf]);
    param_1[0xf] = 0;
  }
  if ((char)param_1[0x11] != '\0') {
    _kfree(param_1[0x10],(int)*(short *)((int)param_1 + 0x46));
    *(undefined1 *)(param_1 + 0x11) = 0;
    *(undefined2 *)((int)param_1 + 0x46) = 0;
  }
  iVar1 = (int)DAT_001e9be8;
  DAT_001e9be8 = param_1;
  param_1[2] = iVar1;
  *(int **)(iVar1 + 0xc) = param_1;
  param_1[3] = (int)&_nc_lru;
  param_1[1] = (int)param_1;
  *param_1 = (int)param_1;
  _DAT_001e9c20 = _DAT_001e9c20 + -1;
  return;
}

