
void _nvram_set(int param_1)

{
  word wVar2;
  int iVar1;
  undefined auStack_24 [32];
  
  *(undefined2 *)(param_1 + 0x1e) = 0;
  wVar2 = _checksum_16(param_1,0x10);
  *(word *)(param_1 + 0x1e) = ~wVar2;
  _rtc_blkwrite(0,param_1,0x20);
  _bcopy(param_1,auStack_24,0x20);
  _nvram_check(param_1);
  iVar1 = _bcmp(auStack_24,param_1,0x20);
  if (iVar1 != 0) {
    _printf(aNonVolatileMem_0);
  }
  return;
}

