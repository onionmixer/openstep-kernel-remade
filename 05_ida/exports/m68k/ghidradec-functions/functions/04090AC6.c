
int _in_bootp(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_2c;
  int iStack_28;
  undefined auStack_24 [16];
  word awStack_14 [8];
  
  iVar2 = 0;
  iVar3 = 0;
  iStack_2c = 0;
  sub_4090A50(param_1,param_2);
  iVar1 = _in_bootp_initnet(param_1,auStack_24,&iStack_28);
  if (iVar1 == 0) {
    iVar2 = _in_bootp_buildpacket(param_1,param_2,param_3);
    iVar3 = _kalloc(300);
    while (iVar1 = _in_bootp_sendrequest(param_1,iStack_28,iVar2,iVar3,param_3,&iStack_2c),
          iVar1 == 0) {
      if (*(char *)(iVar3 + 0xf2) == '\0') {
        if (iStack_2c != 0) {
          _in_bootp_closeconsole(iStack_2c);
          iStack_2c = 0;
        }
        iVar1 = _in_bootp_setaddress(param_1,auStack_24,iStack_28,iVar3 + 0x10);
        if (iVar1 == 0) {
          _bcopy(awStack_14,param_2,0x10);
          goto loc_4090C04;
        }
        break;
      }
      if (((iStack_2c == 0) && (iVar1 = _in_bootp_openconsole(&iStack_2c), iVar1 != 0)) ||
         (iVar1 = _in_bootp_processreply(iStack_2c,iVar2,iVar3), iVar1 != 0)) break;
    }
  }
  else {
    if (iVar1 == -1) {
      iVar2 = _ifioctl(iStack_28,0x8020690c,auStack_24);
      if (iVar2 == 0) {
        _bcopy(awStack_14,param_2,0x10);
      }
      _soclose(iStack_28);
      return iVar2;
    }
loc_4090C04:
    if (iVar1 == 0) goto loc_4090C30;
  }
  if (iStack_28 != 0) {
    awStack_14[0] = *(word *)(param_1 + 0xc) & 0xfffe;
    _ifioctl(iStack_28,0x80206910,auStack_24);
  }
loc_4090C30:
  *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xbfff;
  if (iStack_28 != 0) {
    _soclose(iStack_28);
  }
  if (iVar2 != 0) {
    _kfree(iVar2,0x148);
  }
  if (iVar3 != 0) {
    _kfree(iVar3,300);
  }
  if (iStack_2c != 0) {
    _in_bootp_closeconsole(iStack_2c);
  }
  return iVar1;
}
