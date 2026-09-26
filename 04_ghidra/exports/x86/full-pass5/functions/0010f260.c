/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010f260 */

void _ttypend(undefined4 *param_1)

{
  int iVar1;
  uchar *local_10;
  int local_c;
  int local_8;
  
  param_1[0xf] = param_1[0xf] & 0xdfffffff;
  param_1[0x10] = param_1[0x10] | 0x100000;
  local_10 = (uchar *)*param_1;
  local_c = param_1[1];
  local_8 = param_1[2];
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  while( true ) {
    iVar1 = _getc((FILE *)&local_10);
    if (iVar1 < 0) break;
    _ttyinput(iVar1,param_1);
  }
  param_1[0x10] = param_1[0x10] & 0xffefffff;
  return;
}

