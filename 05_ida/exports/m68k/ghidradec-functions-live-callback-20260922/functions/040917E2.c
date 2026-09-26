
undefined4 _nvram_check(int param_1)

{
  word wVar1;
  word wVar3;
  undefined4 uVar2;
  
  _bzero(param_1,0x20);
  _rtc_blkread(0,param_1,0x20);
  wVar1 = *(word *)(param_1 + 0x1e);
  *(undefined2 *)(param_1 + 0x1e) = 0;
  wVar3 = _checksum_16(param_1,0x10);
  wVar3 = ~wVar3;
  if ((wVar3 == 0) || (wVar1 != wVar3)) {
    _printf(aNonVolatileMem);
    uVar2 = 0xffffffff;
  }
  else {
    *(word *)(param_1 + 0x1e) = wVar3;
    uVar2 = 0;
  }
  return uVar2;
}

