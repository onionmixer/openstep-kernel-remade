
undefined4 _xdr_rmtcall_args(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = _xdr_u_long(param_1,param_2);
  if (((iVar2 != 0) && (iVar2 = _xdr_u_long(param_1,param_2 + 4), iVar2 != 0)) &&
     (iVar2 = _xdr_u_long(param_1,param_2 + 8), iVar2 != 0)) {
    uVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
    piVar1 = (int *)(param_2 + 0xc);
    iVar2 = _xdr_u_long(param_1,piVar1);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
      iVar4 = (**(code **)(param_2 + 0x14))(param_1,*(undefined4 *)(param_2 + 0x10));
      if (iVar4 != 0) {
        iVar4 = (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
        *piVar1 = iVar4 - iVar2;
        (**(code **)(*(int *)(param_1 + 4) + 0x14))(param_1,uVar3);
        iVar2 = _xdr_u_long(param_1,piVar1);
        if (iVar2 != 0) {
          (**(code **)(*(int *)(param_1 + 4) + 0x14))(param_1,iVar4);
          return 1;
        }
      }
    }
  }
  return 0;
}
