
undefined4 _soo_ioctl(int param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x16);
  if (param_2 == 0x200073ff) {
    *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) | 0x80;
  }
  else if ((int)param_2 < 0x20007400) {
    if (param_2 == 0x8004667e) {
      if (*param_3 == 0) {
        *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) & 0xfeff;
      }
      else {
        *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) | 0x100;
      }
    }
    else if ((int)param_2 < -0x7ffb9981) {
      if (param_2 != 0x8004667d) {
loc_400CA24:
        uVar2 = (param_2 & 0xffff) >> 8;
        if (uVar2 == 0x69) {
          uVar3 = _ifioctl(iVar1,param_2,param_3);
          return uVar3;
        }
        if (uVar2 != 0x72) {
          uVar3 = (**(code **)(*(int *)(iVar1 + 0xc) + 0x1a))(iVar1,0xb,param_2,param_3,0);
          return uVar3;
        }
        uVar3 = _rtioctl(param_2,param_3);
        return uVar3;
      }
      if (*param_3 == 0) {
        *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) & 0xfdff;
      }
      else {
        *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) | 0x200;
      }
    }
    else {
      if (param_2 != 0x80047308) goto loc_400CA24;
      *(sword *)(iVar1 + 0x54) = (sword)*param_3;
    }
  }
  else if (param_2 == 0x40047307) {
    *param_3 = (*(uint *)(iVar1 + 7) & 0x7fffffff) >> 0x1e;
  }
  else if ((int)param_2 < 0x40047308) {
    if (param_2 != 0x4004667f) goto loc_400CA24;
    *param_3 = (uint)*(word *)(iVar1 + 0x22);
  }
  else {
    if (param_2 != 0x40047309) goto loc_400CA24;
    *param_3 = (int)*(sword *)(iVar1 + 0x54);
  }
  return 0;
}
