
undefined4
_xdrmbuf_putbuf(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  sword *psVar1;
  int iVar2;
  uint uStack_8;
  
  uStack_8 = param_3;
  if (((param_3 & 3) == 0) && (iVar2 = _xdrmbuf_putlong(param_1,&uStack_8), iVar2 != 0)) {
    psVar1 = (sword *)(*(int *)(param_1 + 0x10) + 8);
    *psVar1 = *psVar1 - *(sword *)(param_1 + 0x16);
    iVar2 = _mclgetx(param_4,param_5,param_2,param_3,1);
    if (iVar2 != 0) {
      **(int **)(param_1 + 0x10) = iVar2;
      *(undefined4 *)(param_1 + 0x14) = 0;
      return 1;
    }
    _printf(aXdrmbufPutbufM);
  }
  return 0;
}

