
int _mach_port_set_mscount(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&iStack_8);
    if (iVar1 == 0) {
      *(undefined4 *)(iStack_8 + 0x14) = param_3;
      iVar1 = 0;
    }
  }
  return iVar1;
}
