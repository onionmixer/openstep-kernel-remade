/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012a6d4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _tcp_drop(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x1c);
  if (*(short *)(param_1 + 8) < 3) {
    _DAT_001eed80 = _DAT_001eed80 + 1;
  }
  else {
    *(undefined2 *)(param_1 + 8) = 0;
    _tcp_output(param_1);
    _DAT_001eed7c = _DAT_001eed7c + 1;
  }
  if ((param_2 == 0x3c) && (*(short *)(param_1 + 0x6a) != 0)) {
    param_2 = (int)*(short *)(param_1 + 0x6a);
  }
  *(short *)(iVar1 + 0x56) = (short)param_2;
  _tcp_close(param_1);
  return;
}

