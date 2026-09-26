
undefined4 sub_402D1B4(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_u_long(param_1,param_2);
  if ((((iVar1 != 0) && (iVar1 = _xdr_u_long(param_1,param_2 + 4), iVar1 != 0)) &&
      (iVar1 = _xdr_u_long(param_1,param_2 + 8), iVar1 != 0)) &&
     (((iVar1 = _xdr_u_long(param_1,param_2 + 0xc), iVar1 != 0 &&
       (iVar1 = sub_402D624(param_1,param_2 + 0x10), iVar1 != 0)) &&
      (iVar1 = sub_402D624(param_1,param_2 + 0x18), iVar1 != 0)))) {
    return 1;
  }
  return 0;
}

