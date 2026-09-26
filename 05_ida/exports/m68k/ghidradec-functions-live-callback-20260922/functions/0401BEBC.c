
int _ifioctl(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == -0x7fdb96e0) {
loc_401BF04:
    iVar1 = _suser();
    if (iVar1 != 0) {
loc_401BF10:
      iVar1 = _arpioctl(param_2,param_3);
      return iVar1;
    }
    goto loc_401C02E;
  }
  if (param_2 < -0x7fdb96df) {
    if (param_2 == -0x7fdb96e2) goto loc_401BF04;
  }
  else {
    if (param_2 == -0x3ff796ec) {
      iVar1 = _ifconf(0xc0086914,param_3);
      return iVar1;
    }
    if (param_2 == -0x3fdb96e1) goto loc_401BF10;
  }
  iVar1 = _ifunit(param_3);
  if (iVar1 == 0) {
    return 6;
  }
  if (param_2 == -0x7fdf9683) goto loc_401C03C;
  if (-0x7fdf9683 < param_2) {
    if (param_2 == -0x3fdf96e9) {
      *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar1 + 0xe);
      return 0;
    }
    if (param_2 < -0x3fdf96e8) {
      if (param_2 != -0x7fdf9681) {
        if (param_2 == -0x3fdf96ef) {
          *(undefined2 *)(param_3 + 0x10) = *(undefined2 *)(iVar1 + 0xc);
          return 0;
        }
        goto loc_401C050;
      }
    }
    else if ((param_2 != -0x3fdf9684) && (param_2 != -0x3fdf9682)) goto loc_401C050;
loc_401C03C:
    if (*(int *)(iVar1 + 0x36) == 0) {
      return 0x2d;
    }
    iVar1 = _if_ioctl(iVar1,param_2,param_3);
    return iVar1;
  }
  if (param_2 == -0x7fdf96e8) {
    iVar2 = _suser();
    if (iVar2 != 0) {
      *(undefined4 *)(iVar1 + 0xe) = *(undefined4 *)(param_3 + 0x10);
      return 0;
    }
loc_401C02E:
    return (int)*(char *)(dword_40B57D4 + 100);
  }
  if (param_2 < -0x7fdf96e7) {
    if (param_2 == -0x7fdf96f0) {
      iVar2 = _suser();
      if (iVar2 != 0) {
        if (((*(byte *)(iVar1 + 0xd) & 1) != 0) && ((*(byte *)(param_3 + 0x11) & 1) == 0)) {
          _if_down(iVar1);
        }
        *(word *)(iVar1 + 0xc) =
             *(word *)(param_3 + 0x10) & 0x37ad | *(word *)(iVar1 + 0xc) & 0xc852;
        _if_ioctl(iVar1,0x80206910,param_3);
        return 0;
      }
      goto loc_401C02E;
    }
  }
  else if ((param_2 < -0x7fdf96cd) && (-0x7fdf96d0 < param_2)) {
    iVar2 = _suser();
    if (iVar2 != 0) goto loc_401C03C;
    goto loc_401C02E;
  }
loc_401C050:
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0x2d;
  }
  iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,0xb,param_2,param_3,iVar1);
  return iVar1;
}

