
undefined4 _if_ioctl(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  uint uStack_c;
  int iStack_8;
  
  if (*(code **)(param_1 + 0x36) == (code *)0x0) {
    return 6;
  }
  if (param_2 == 0x80206931) {
    uVar1 = _if_control(param_1,_IFCONTROL_ADDMULTICAST,param_3);
    return uVar1;
  }
  if (param_2 < 0x80206932) {
    if (param_2 == 0x8020690c) {
      puVar2 = (undefined *)&_IFCONTROL_SETADDR;
    }
    else {
      if (param_2 != 0x80206910) goto loc_401CBA2;
      param_3 = param_3 + 0x10;
      puVar2 = _IFCONTROL_SETFLAGS;
    }
  }
  else if (param_2 == 0xc020690d) {
    param_3 = param_3 + 0x10;
    puVar2 = (undefined *)&_IFCONTROL_GETADDR;
  }
  else if (param_2 < 0xc020690e) {
    if (param_2 != 0x80206932) {
loc_401CBA2:
      uStack_c = param_2;
      iStack_8 = param_3;
      uVar1 = (**(code **)(param_1 + 0x36))(param_1,_IFCONTROL_UNIXIOCTL,&uStack_c);
      return uVar1;
    }
    puVar2 = _IFCONTROL_RMVMULTICAST;
  }
  else {
    if (param_2 != 0xc0206921) goto loc_401CBA2;
    param_3 = param_3 + 0x10;
    puVar2 = _IFCONTROL_AUTOADDR;
  }
  uVar1 = (**(code **)(param_1 + 0x36))(param_1,puVar2,param_3);
  return uVar1;
}
