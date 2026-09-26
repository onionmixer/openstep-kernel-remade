/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a588 */

void _logswap(undefined1 param_1,undefined4 param_2,undefined4 param_3,byte param_4,char param_5)

{
  int iVar1;
  int iVar2;
  
  if (1999 < _logswapindex) {
    _logswapindex = 0;
  }
  iVar1 = _logswapindex;
  iVar2 = _logswapindex * 0xc;
  (&_logswp)[_logswapindex * 3] = param_2;
  (&DAT_001ef304)[iVar1 * 3] = param_3;
  (&DAT_001ef308)[iVar2] = (&DAT_001ef308)[iVar2] & 0xf0 | param_4 & 0xf;
  (&DAT_001ef308)[_logswapindex * 0xc] = (&DAT_001ef308)[_logswapindex * 0xc] & 0xf | param_5 << 4;
  (&DAT_001ef309)[_logswapindex * 0xc] = param_1;
  _logswapindex = _logswapindex + 1;
  return;
}

