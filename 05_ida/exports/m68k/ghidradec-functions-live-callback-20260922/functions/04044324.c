
int _mach_port_kernel_object
              (undefined4 param_1,undefined4 param_2,undefined2 *param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  uint *puStack_8;
  
  iVar2 = _ipc_right_lookup_write(param_1,param_2,&puStack_8);
  if (iVar2 == 0) {
    if ((*puStack_8 & 0x30000) != 0) {
      uVar1 = puStack_8[1];
      iVar2 = *(int *)(uVar1 + 4);
      if (iVar2 < 0) {
        *param_3 = 0;
        param_3[1] = (sword)iVar2;
        *param_4 = *(undefined4 *)(uVar1 + 0x10);
        return 0;
      }
    }
    iVar2 = 0x11;
  }
  return iVar2;
}

