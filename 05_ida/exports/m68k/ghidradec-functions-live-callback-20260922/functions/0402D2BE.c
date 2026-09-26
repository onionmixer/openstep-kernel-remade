
undefined4 _xdr_rddirargs(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_fhandle(param_1,param_2);
  if (((iVar1 != 0) && (iVar1 = _xdr_u_long(param_1,param_2 + 0x20), iVar1 != 0)) &&
     (iVar1 = _xdr_u_long(param_1,param_2 + 0x24), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

