
undefined4 _cnioctl(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_2 == 0x20007471) {
    iVar1 = *_active_u;
    iVar3 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
    _cons_tp = _cons;
    iVar2 = *(int *)(*(int *)(iVar3 + 0xe) + 8);
    if (iVar1 == *(int *)(iVar2 + 4)) {
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined2 *)(*(int *)(*(int *)(iVar3 + 0xe) + 8) + 0xc) = 0;
    }
    *(byte *)(iVar1 + 0x28) = *(byte *)(iVar1 + 0x28) & 0xbf;
    uVar4 = 0;
  }
  else {
    uVar4 = (**(code **)(DAT_40b0ad0 + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))
                      ((int)(sword)*(word *)(_cons_tp + 0x38),param_2,param_3,param_4);
  }
  return uVar4;
}

