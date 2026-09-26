
undefined4 _xdr_bp_getfile_arg(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_bp_machine_name_t(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = _xdr_bp_fileid_t(param_1,param_2 + 4);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}
