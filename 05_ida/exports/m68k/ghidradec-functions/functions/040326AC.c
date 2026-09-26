
void _logswap(undefined param_1,undefined4 param_2,undefined4 param_3,byte param_4,byte param_5)

{
  int iVar1;
  
  if (1999 < _logswapindex) {
    _logswapindex = 0;
  }
  iVar1 = _logswapindex * 10;
  *(undefined4 *)(_logswp + iVar1) = param_2;
  *(undefined4 *)(_logswp + iVar1 + 4) = param_3;
  *(uint *)(_logswp + iVar1 + 8) =
       *(uint *)(_logswp + iVar1 + 8) & 0xfffffff | (uint)param_4 << 0x1c;
  *(uint *)(_logswp + _logswapindex * 10 + 8) =
       *(uint *)(_logswp + _logswapindex * 10 + 8) & 0xf0ffffff | (param_5 & 0xf) << 0x18;
  _logswp[_logswapindex * 10 + 9] = param_1;
  _logswapindex = _logswapindex + 1;
  return;
}
