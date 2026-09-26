
int sub_4073B56(sword param_1,int param_2,sword *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    while (iVar1 = _np_ioctl_common((int)param_1,param_2,param_3,param_4,param_5), iVar1 == 0) {
      if ((((param_2 != -0x3fed8fff) || (*param_3 != 3)) ||
          ((*(byte *)((int)param_3 + 5) & 0x40) == 0)) || (iVar2 = iVar2 + 1, 2 < iVar2)) {
        return 0;
      }
    }
    if (iVar1 != 5) {
      return iVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  _printf(aNp0IoctlErrorF);
  return 5;
}
