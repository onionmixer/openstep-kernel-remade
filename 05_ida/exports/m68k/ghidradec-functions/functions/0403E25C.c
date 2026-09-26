
undefined4 _ipc_kmsg_copyout_object(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int *piStack_8;
  
  if ((param_2 == (int *)0x0) || (param_2 == (int *)0xffffffff)) {
    *param_4 = param_2;
  }
  else if ((((param_3 == 0x11) && (*(int *)(param_1 + 4) != 0)) && (param_2[1] < 0)) &&
          (iVar1 = _ipc_hash_local_lookup(param_1,param_2,param_4,&piStack_8), iVar1 != 0)) {
    param_2[6] = param_2[6] + -1;
    *param_2 = *param_2 + -1;
    if ((sword)(*piStack_8 + 1) != -1) {
      *piStack_8 = *piStack_8 + 1;
    }
  }
  else {
    iVar1 = _ipc_object_copyout(param_1,param_2,param_3,1,param_4);
    if (iVar1 != 0) {
      _ipc_object_destroy(param_2,param_3);
      if (iVar1 != 0x14) {
        *param_4 = 0;
        if (iVar1 != 6) {
          return 0x2000;
        }
        return 0x800;
      }
      *param_4 = 0xffffffff;
    }
  }
  return 0;
}
