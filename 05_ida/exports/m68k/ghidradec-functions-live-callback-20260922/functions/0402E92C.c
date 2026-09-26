
undefined4 _xdr_rmtcallres(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  
  uStack_8 = *param_2;
  iVar1 = _xdr_reference(param_1,&uStack_8,4,_xdr_u_long);
  if ((iVar1 != 0) && (iVar1 = _xdr_u_long(param_1,param_2 + 1), iVar1 != 0)) {
    *param_2 = uStack_8;
    uVar2 = (*(code *)param_2[3])(param_1,param_2[2]);
    return uVar2;
  }
  return 0;
}

