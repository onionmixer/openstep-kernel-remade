
int _vm_map_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _zalloc(_vm_map_zone);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmMapCreate);
  }
  iVar1 = iVar2 + 8;
  *(int *)(iVar2 + 0xc) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  *(undefined4 *)(iVar2 + 0x1c) = param_4;
  *(undefined4 *)(iVar2 + 0x24) = 0;
  *(undefined4 *)(iVar2 + 0x2c) = 1;
  *(undefined4 *)(iVar2 + 0x20) = param_1;
  *(undefined4 *)(iVar2 + 0x28) = 1;
  *(undefined4 *)(iVar2 + 0x10) = param_2;
  *(undefined4 *)(iVar2 + 0x14) = param_3;
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  *(undefined4 *)(iVar2 + 0x38) = 0;
  *(int *)(iVar2 + 0x34) = iVar1;
  *(int *)(iVar2 + 0x30) = iVar1;
  *(undefined4 *)(iVar2 + 0x40) = 0;
  _lock_init(iVar2,1);
  *(undefined4 *)(iVar2 + 0x40) = 0;
  return iVar2;
}

