
int _q_to_b(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_2;
    if (*param_1 < 1) {
      *param_1 = 0;
      param_1[2] = 0;
      param_1[1] = 0;
      iVar3 = 0;
    }
    else {
      do {
        iVar4 = 0x40 - (param_1[1] & 0x3fU);
        if (param_3 < iVar4) {
          iVar4 = param_3;
        }
        if (*param_1 < iVar4) {
          iVar4 = *param_1;
        }
        _bcopy(param_1[1],iVar3,iVar4);
        param_1[1] = iVar4 + param_1[1];
        iVar1 = *param_1;
        *param_1 = iVar1 - iVar4;
        param_3 = param_3 - iVar4;
        iVar3 = iVar4 + iVar3;
        if (iVar1 - iVar4 < 1) {
          piVar2 = (int *)(param_1[1] - 1U & 0xffffffc0);
          param_1[2] = 0;
          param_1[1] = 0;
          *piVar2 = (int)_cfreelist;
          _cfreecount = _cfreecount + 0x34;
          _cfreelist = piVar2;
          if (_cwaiting != '\0') {
            _wakeup(&_cwaiting);
            _cwaiting = '\0';
          }
          break;
        }
        if ((param_1[1] & 0x3fU) == 0) {
          piVar2 = (int *)(param_1[1] - 0x40);
          param_1[1] = *piVar2 + 0xc;
          *piVar2 = (int)_cfreelist;
          _cfreecount = _cfreecount + 0x34;
          _cfreelist = piVar2;
          if (_cwaiting != '\0') {
            _wakeup(&_cwaiting);
            _cwaiting = '\0';
          }
        }
      } while (param_3 != 0);
      iVar3 = iVar3 - param_2;
    }
  }
  return iVar3;
}
