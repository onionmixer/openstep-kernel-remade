
undefined4 _xdr_writeargs(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if ((((iVar1 != 0) && (iVar1 = _xdr_long(param_1,param_2 + 0x20), iVar1 != 0)) &&
      (iVar1 = _xdr_long(param_1,param_2 + 0x24), iVar1 != 0)) &&
     (iVar1 = _xdr_long(param_1,param_2 + 0x28), iVar1 != 0)) {
    if (((undefined *)param_1[1] == _xdrmbuf_ops) && (*param_1 == 1)) {
      iVar1 = _xdrmbuf_getmbuf(param_1,param_2 + 0x34,param_2 + 0x2c);
    }
    else {
      iVar1 = _xdr_bytes(param_1,param_2 + 0x30,param_2 + 0x2c,0x2000);
    }
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}
