
bool _xdr_bp_whoami_arg(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _xdr_bp_address(param_1,param_2);
  return iVar1 != 0;
}

