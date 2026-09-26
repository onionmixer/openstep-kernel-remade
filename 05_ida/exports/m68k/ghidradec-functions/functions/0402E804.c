
undefined4 _xdr_pmap(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_u_long(param_1,param_2);
  if (((iVar1 != 0) && (iVar1 = _xdr_u_long(param_1,param_2 + 4), iVar1 != 0)) &&
     (iVar1 = _xdr_u_long(param_1,param_2 + 8), iVar1 != 0)) {
    uVar2 = _xdr_u_long(param_1,param_2 + 0xc);
    return uVar2;
  }
  return 0;
}
