
int _sgioctl(byte param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = (sword)(word)param_1 * 0x42;
  puVar3 = (undefined4 *)(_sg_sgd + iVar1);
  iVar2 = 0;
  if (_sg_sgd[iVar1 + 0x16] == '\0') {
    param_3[7] = 0xb;
    iVar2 = 0xd;
  }
  else if (param_2 == 0x20007302) {
    _sg_sgd[iVar1 + 0x17] = 1;
  }
  else {
    if (param_2 < 0x20007303) {
      if (param_2 == -0x7ffd8d00) {
        iVar1 = sub_407FC78(puVar3,param_3);
        return iVar1;
      }
      if (param_2 == -0x3fad8cff) {
        iVar1 = sub_407FD2C(puVar3,param_3);
        return iVar1;
      }
    }
    else {
      if (param_2 == 0x20007304) {
        iVar1 = _suser();
        if (iVar1 == 0) {
          return (int)*(char *)(dword_40B57D4 + 100);
        }
        iVar1 = _scsi_ioctl(*puVar3,0x20006409,0,0);
        return iVar1;
      }
      if (param_2 < 0x20007304) {
        _sg_sgd[iVar1 + 0x17] = 0;
        return 0;
      }
      if (param_2 == 0x40047307) {
        *param_3 = (int)(char)_sg_sgd[iVar1 + 0x17];
        return 0;
      }
    }
    iVar2 = 0x16;
  }
  return iVar2;
}
