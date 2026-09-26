/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010dd68 */

void _ttychars(int param_1)

{
  int iVar1;
  
  iVar1 = _ttynty(param_1);
  *(undefined4 *)(param_1 + 0x4d) = _ttydefaults;
  *(undefined4 *)(param_1 + 0x51) = DAT_001daf30;
  *(undefined4 *)(param_1 + 0x55) = DAT_001daf34;
  *(undefined2 *)(param_1 + 0x59) = DAT_001daf38;
  *(undefined1 *)(iVar1 + 0x14) = 0x5c;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined1 *)(iVar1 + 0x16) = 0;
  _ttysetspec(iVar1);
  return;
}

