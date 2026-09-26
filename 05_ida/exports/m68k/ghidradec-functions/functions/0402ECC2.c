
undefined4 _xdr_accepted_reply(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_opaque_auth(param_1,param_2);
  if (iVar1 != 0) {
    iVar1 = _xdr_enum(param_1,(int *)(param_2 + 0xc));
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_2 + 0xc);
      if (iVar1 == 0) {
        uVar2 = (**(code **)(param_2 + 0x14))(param_1,*(undefined4 *)(param_2 + 0x10));
        return uVar2;
      }
      if (iVar1 != 2) {
        return 1;
      }
      iVar1 = _xdr_u_long(param_1,param_2 + 0x10);
      if (iVar1 != 0) {
        uVar2 = _xdr_u_long(param_1,param_2 + 0x14);
        return uVar2;
      }
    }
  }
  return 0;
}
