
byte _ndflush(int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  bool bVar6;
  bool bVar7;
  
  cVar5 = '\0';
  bVar6 = *param_1 < 0;
  bVar7 = *param_1 == 0;
  if (0 < *param_1) {
    while (0 < (int)param_2) {
      if (*param_1 == 0) goto loc_4011544;
      piVar2 = (int *)(param_1[1] & 0xffffffc0);
      piVar4 = (int *)param_1[2];
      if ((int *)((int)piVar4 - 1U & 0xffffffc0) != piVar2) {
        piVar4 = piVar2 + 0x10;
      }
      iVar3 = (int)piVar4 - param_1[1];
      if ((int)param_2 < iVar3) {
        *param_1 = *param_1 - param_2;
        uVar1 = param_1[1];
        cVar5 = CARRY4(param_2,uVar1);
        param_1[1] = param_2 + uVar1;
        bVar6 = *param_1 < 0;
        bVar7 = *param_1 == 0;
        if (0 < *param_1) goto loc_401154E;
        *piVar2 = (int)_cfreelist;
        cVar5 = 0xffffffcb < _cfreecount;
        _cfreecount = _cfreecount + 0x34;
        _cfreelist = piVar2;
        if (_cwaiting != '\0') {
          _wakeup(&_cwaiting);
          _cwaiting = '\0';
        }
        break;
      }
      param_2 = param_2 - iVar3;
      *param_1 = *param_1 - iVar3;
      param_1[1] = *piVar2 + 0xc;
      *piVar2 = (int)_cfreelist;
      cVar5 = 0xffffffcb < _cfreecount;
      _cfreecount = _cfreecount + 0x34;
      _cfreelist = piVar2;
      if (_cwaiting != '\0') {
        _wakeup(&_cwaiting);
        _cwaiting = '\0';
      }
    }
    bVar6 = *param_1 < 0;
    bVar7 = *param_1 == 0;
    if (*param_1 < 1) {
loc_4011544:
      param_1[2] = 0;
      param_1[1] = 0;
      *param_1 = 0;
      bVar6 = false;
      bVar7 = true;
    }
  }
loc_401154E:
  return cVar5 << 4 | bVar6 << 3 | bVar7 << 2;
}
