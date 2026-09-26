
int _ipc_port_copyout_receiver(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (param_1 == (int *)0xffffffff)) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    if (param_1[2] == param_2) {
      iVar2 = param_1[3];
    }
    iVar1 = *param_1;
    *param_1 = iVar1 + -1;
    if (iVar1 == 1) {
      _zfree((&_ipc_object_zones)[*(word *)(param_1 + 1) & 0x7fff],param_1);
    }
  }
  return iVar2;
}
