
undefined4 _syioctl(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_2 == 0x20007471) {
    iVar1 = *_active_u;
    iVar3 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
    iVar2 = *(int *)(*(int *)(iVar3 + 0xe) + 8);
    if (iVar1 == *(int *)(iVar2 + 4)) {
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined2 *)(*(int *)(*(int *)(iVar3 + 0xe) + 8) + 0xc) = 0;
    }
    *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) & 0xbf;
    *(undefined4 *)((int)_active_u + 0x15e) = 0;
    *(undefined2 *)((int)_active_u + 0x162) = 0;
    uVar4 = 0;
  }
  else if (*(int *)((int)_active_u + 0x15e) == 0) {
    uVar4 = 6;
  }
  else {
    uVar4 = (**(code **)(DAT_40b0ad0 + (uint)(*(word *)((int)_active_u + 0x162) >> 8) * 0x2c))
                      ((int)(sword)*(word *)((int)_active_u + 0x162),param_2,param_3,param_4);
  }
  return uVar4;
}
