
int _vno_ioctl(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined auStack_3e [20];
  int iStack_2a;
  
  iVar2 = *(int *)(param_1 + 0x16);
  switch(*(undefined4 *)(iVar2 + 0x28)) {
  case :
    break;
  case :
  case :
    goto loc_4018DFC;
  :
    return 0x19;
  case :
  case :
    *(undefined4 *)(dword_40B57D4 + 0x5c) = 0;
    iVar1 = _setjmp(dword_40B57D4 + 0x28);
    if (iVar1 == 0) {
      iVar2 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0xc))
                        (iVar2,param_2,param_3,*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(param_1 + 0x1e));
      return iVar2;
    }
    if (*(int *)((int)_active_u + 0x136) << 0x20 - *(char *)(*_active_u + 0x17) < 0) {
      return 4;
    }
    *(undefined *)(dword_40B57D4 + 0x65) = 2;
    return 0;
  }
  if (param_2 == -0x3ffb9996) {
    iVar2 = *param_3;
    if (iVar2 == 1) {
      *(word *)(param_1 + 10) = *(word *)(param_1 + 10) | 0x1000;
    }
    else if (iVar2 < 2) {
      if (iVar2 != 0) {
        return 0x16;
      }
    }
    else {
      if (iVar2 != 2) {
        return 0x16;
      }
      *(word *)(param_1 + 10) = *(word *)(param_1 + 10) & 0xefff;
    }
    if ((*(uint *)(param_1 + 8) & 0x1000) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
    *param_3 = iVar2;
    return 0;
  }
loc_4018DFC:
  if (param_2 < -0x7ffb9983) {
    return 0x19;
  }
  if (-0x7ffb9982 < param_2) {
    if (param_2 != 0x4004667f) {
      return 0x19;
    }
    iVar2 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x14))
                      (iVar2,auStack_3e,*(undefined4 *)((int)_active_u + 0x1a));
    if (iVar2 != 0) {
      return iVar2;
    }
    *param_3 = iStack_2a - *(int *)(param_1 + 0x1a);
    return 0;
  }
  return 0;
}

