
undefined4 _xdr_fhstatus(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_int(param_1,param_2);
  if (iVar1 == 0) {
loc_4030BD2:
    uVar2 = 0;
  }
  else {
    if (*param_2 == 0) {
      iVar1 = _xdr_fhandle(param_1,param_2 + 1);
      if (iVar1 == 0) goto loc_4030BD2;
    }
    uVar2 = 1;
  }
  return uVar2;
}

