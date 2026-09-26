
int _in_bootp(void *param_1,void *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int local_30;
  int local_2c;
  int local_28;
  ifreq_result_bytes local_24;
  
  local_30 = 0;
  iVar2 = 0;
  local_2c = 0;
  FUN_00124cb8(&local_24,param_1,param_2);
  iVar1 = FUN_00124338(param_1,&local_24,&local_28);
  if (iVar1 == 0) {
    local_30 = FUN_001244a0(param_1,param_2,param_3);
    iVar2 = _kalloc(300);
    while (iVar1 = FUN_0012470c(param_1,local_28,local_30,iVar2,param_3,&local_2c), iVar1 == 0) {
      if (*(char *)(iVar2 + 0xf2) == '\0') {
        if (local_2c != 0) {
          FUN_00124ad0(local_2c);
          local_2c = 0;
        }
        iVar1 = FUN_00124c2c(param_1,&local_24,local_28,iVar2 + 0x10);
        if (iVar1 == 0) {
          _bcopy(local_24.sockaddr_bytes,param_2,0x10);
          goto LAB_001242ab;
        }
        break;
      }
      if (((local_2c == 0) && (iVar1 = FUN_00124a60(&local_2c), iVar1 != 0)) ||
         (iVar1 = FUN_00124ae8(local_2c,local_30,iVar2), iVar1 != 0)) break;
    }
  }
  else {
    if (iVar1 == -1) {
      iVar2 = _ifioctl(local_28,0x8020690c,&local_24);
      if (iVar2 == 0) {
        _bcopy(local_24.sockaddr_bytes,param_2,0x10);
      }
      _soclose(local_28);
      return iVar2;
    }
LAB_001242ab:
    if (iVar1 == 0) goto LAB_001242d5;
  }
  if (local_28 != 0) {
    local_24.sockaddr_bytes._0_2_ = *(ushort *)((int)param_1 + 0xc) & 0xfffe;
    _ifioctl(local_28,0x80206910,&local_24);
  }
LAB_001242d5:
  *(ushort *)((int)param_1 + 0xc) = *(ushort *)((int)param_1 + 0xc) & 0xbfff;
  if (local_28 != 0) {
    _soclose(local_28);
  }
  if (local_30 != 0) {
    _kfree(local_30,0x148);
  }
  if (iVar2 != 0) {
    _kfree(iVar2,300);
  }
  if (iVar1 == 0) {
    FUN_00124ad0(local_2c);
  }
  return iVar1;
}

