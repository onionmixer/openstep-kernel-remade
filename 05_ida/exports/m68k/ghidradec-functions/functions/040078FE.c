
void _setregid(void)

{
  int *piVar1;
  sword sVar2;
  sword sVar5;
  int iVar3;
  sword sVar6;
  undefined4 uVar4;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = *piVar1;
  if (iVar3 == -1) {
    sVar5 = *(sword *)(*(int *)(_active_u + 0x1a) + 8);
  }
  else {
    sVar5 = (sword)iVar3;
  }
  if (((sVar5 != *(sword *)(*(int *)(_active_u + 0x1a) + 8)) &&
      (sVar5 != *(sword *)(*(int *)(_active_u + 0x1a) + 4))) && (iVar3 = _suser(), iVar3 == 0)) {
    return;
  }
  iVar3 = piVar1[1];
  if (iVar3 == -1) {
    sVar6 = *(sword *)(*(int *)(_active_u + 0x1a) + 4);
  }
  else {
    sVar6 = (sword)iVar3;
  }
  if (((sVar6 != *(sword *)(*(int *)(_active_u + 0x1a) + 8)) &&
      (sVar6 != *(sword *)(*(int *)(_active_u + 0x1a) + 4))) && (iVar3 = _suser(), iVar3 == 0)) {
    return;
  }
  _lock_write(_active_u + 0x1e);
  uVar4 = _crcopy(*(undefined4 *)(_active_u + 0x1a));
  *(undefined4 *)(_active_u + 0x1a) = uVar4;
  sVar2 = *(sword *)(*(int *)(_active_u + 0x1a) + 8);
  if (sVar5 != sVar2) {
    _leavegroup((int)sVar2);
    _entergroup((int)sVar5);
    *(sword *)(*(int *)(_active_u + 0x1a) + 8) = sVar5;
  }
  *(sword *)(*(int *)(_active_u + 0x1a) + 4) = sVar6;
  _lock_done(_active_u + 0x1e);
  return;
}
