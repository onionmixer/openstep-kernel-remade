
undefined4 _xdr_authunix_parms(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_u_long(param_1,param_2);
  if ((((iVar1 != 0) && (iVar1 = _xdr_string(param_1,param_2 + 4,0xff), iVar1 != 0)) &&
      (iVar1 = _xdr_int(param_1,param_2 + 8), iVar1 != 0)) &&
     ((iVar1 = _xdr_int(param_1,param_2 + 0xc), iVar1 != 0 &&
      (iVar1 = _xdr_array(param_1,param_2 + 0x14,param_2 + 0x10,0x10,4,_xdr_int), iVar1 != 0)))) {
    return 1;
  }
  return 0;
}
