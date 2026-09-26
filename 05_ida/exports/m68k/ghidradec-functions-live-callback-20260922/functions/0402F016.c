
undefined4 _xdr_callhdr(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = 2;
  if ((((*param_1 == 0) && (iVar1 = _xdr_u_long(param_1,param_2), iVar1 != 0)) &&
      (iVar1 = _xdr_enum(param_1,param_2 + 4), iVar1 != 0)) &&
     ((iVar1 = _xdr_u_long(param_1,param_2 + 8), iVar1 != 0 &&
      (iVar1 = _xdr_u_long(param_1,param_2 + 0xc), iVar1 != 0)))) {
    uVar2 = _xdr_u_long(param_1,param_2 + 0x10);
    return uVar2;
  }
  return 0;
}

