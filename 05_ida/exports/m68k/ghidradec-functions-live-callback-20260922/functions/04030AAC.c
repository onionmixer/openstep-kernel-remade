
undefined4 _xdr_bp_whoami_res(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_bp_machine_name_t(param_1,param_2);
  if ((iVar1 != 0) && (iVar1 = _xdr_bp_machine_name_t(param_1,param_2 + 4), iVar1 != 0)) {
    iVar1 = _xdr_bp_address(param_1,param_2 + 8);
    if (iVar1 == 0) {
      return 0;
    }
    return 1;
  }
  return 0;
}

