
undefined4 _xdr_rejected_reply(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  pcVar3 = _xdr_enum;
  iVar1 = _xdr_enum(param_1,param_2);
  if (iVar1 != 0) {
    if (*param_2 == 0) {
      pcVar3 = _xdr_u_long;
      iVar1 = _xdr_u_long(param_1,param_2 + 1);
      if (iVar1 != 0) {
        param_2 = param_2 + 2;
        goto loc_402ED8A;
      }
    }
    else if (*param_2 == 1) {
      param_2 = param_2 + 1;
loc_402ED8A:
      uVar2 = (*pcVar3)(param_1,param_2);
      return uVar2;
    }
  }
  return 0;
}

