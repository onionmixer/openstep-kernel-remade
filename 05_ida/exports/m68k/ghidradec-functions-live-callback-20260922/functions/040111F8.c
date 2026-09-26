
/* WARNING: Removing unreachable block (ram,0x04011238) */

uint _getc(int *param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  if (*param_1 < 1) {
    uVar4 = 0xffffffff;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[1] = 0;
  }
  else {
    pbVar1 = (byte *)param_1[1];
    uVar4 = (uint)*pbVar1;
    iVar3 = (int)((uint)pbVar1 & 0x3f) >> 3;
    if (((int)*(char *)(iVar3 + 4 + ((uint)pbVar1 & 0xffffffc0)) &
        1 << (((uint)pbVar1 & 0x3f) + iVar3 * -8 & 0x1f)) != 0) {
      uVar4 = *pbVar1 | 0x100;
    }
    param_1[1] = (int)(pbVar1 + 1);
    iVar3 = *param_1;
    *param_1 = iVar3 + -1;
    if (iVar3 == 1 || iVar3 + -1 < 0) {
      piVar2 = (int *)(param_1[1] - 1U & 0xffffffc0);
      param_1[1] = 0;
      param_1[2] = 0;
      *piVar2 = (int)_cfreelist;
      _cfreelist = piVar2;
    }
    else {
      if ((param_1[1] & 0x3fU) != 0) {
        return uVar4;
      }
      piVar2 = (int *)(param_1[1] - 0x40);
      param_1[1] = *piVar2 + 0xc;
      *piVar2 = (int)_cfreelist;
      _cfreelist = piVar2;
    }
    _cfreecount = _cfreecount + 0x34;
    if (_cwaiting != '\0') {
      _wakeup(&_cwaiting);
      _cwaiting = '\0';
    }
  }
  return uVar4;
}

