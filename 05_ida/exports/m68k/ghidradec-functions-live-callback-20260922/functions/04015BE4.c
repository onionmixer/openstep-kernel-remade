
int _sockargs(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 < 0x71) {
    iVar2 = _m_get(1,param_4);
    if (iVar2 == 0) {
      iVar1 = 0x37;
    }
    else {
      *(sword *)(iVar2 + 8) = (sword)param_3;
      iVar1 = _copyinmsg(param_2,*(int *)(iVar2 + 4) + iVar2,param_3);
      if (iVar1 == 0) {
        *param_1 = iVar2;
      }
      else {
        _m_free(iVar2);
      }
    }
  }
  else {
    iVar1 = 0x16;
  }
  return iVar1;
}

