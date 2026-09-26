
int _mach_port_extract_right
              (int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if (param_3 - 0x10U < 6) {
    iVar1 = _ipc_object_copyin(param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      uVar2 = _ipc_object_copyin_type(param_3);
      *param_5 = uVar2;
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}
