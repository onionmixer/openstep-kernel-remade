
int _in_bootp_setaddress(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  
  *(word *)(param_2 + 0x10) = *(word *)(param_1 + 0xc) & 0xfffe;
  iVar1 = _ifioctl(param_3,0x80206910,param_2);
  if (iVar1 == 0) {
    *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xbfff;
    _bzero((undefined2 *)(param_2 + 0x10),0x10);
    *(undefined2 *)(param_2 + 0x10) = 2;
    iVar1 = _ifioctl(param_3,0x80206916,param_2);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x14) = *param_4;
      iVar1 = _ifioctl(param_3,0x8020690c,param_2);
      if (iVar1 == 0) {
        *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x8000;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}
