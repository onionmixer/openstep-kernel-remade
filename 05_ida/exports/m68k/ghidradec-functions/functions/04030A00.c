
undefined4 _xdr_ip_addr_t(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_char(param_1,param_2);
  if (((iVar1 != 0) && (iVar1 = _xdr_char(param_1,param_2 + 1), iVar1 != 0)) &&
     (iVar1 = _xdr_char(param_1,param_2 + 2), iVar1 != 0)) {
    iVar1 = _xdr_char(param_1,param_2 + 3);
    if (iVar1 == 0) {
      return 0;
    }
    return 1;
  }
  return 0;
}
