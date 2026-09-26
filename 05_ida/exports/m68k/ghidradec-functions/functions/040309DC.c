
bool _xdr_bp_fileid_t(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _xdr_string(param_1,param_2,0x20);
  return iVar1 != 0;
}
