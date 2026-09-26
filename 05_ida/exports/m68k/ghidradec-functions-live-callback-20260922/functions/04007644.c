
void _setreuid(void)

{
  int *piVar1;
  sword sVar4;
  int iVar2;
  sword sVar5;
  undefined4 uVar3;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar2 = *piVar1;
  if (iVar2 == -1) {
    sVar4 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 6);
  }
  else {
    sVar4 = (sword)iVar2;
  }
  if (((sVar4 != *(sword *)(*(int *)((int)_active_u + 0x1a) + 6)) &&
      (sVar4 != *(sword *)(*(int *)((int)_active_u + 0x1a) + 2))) && (iVar2 = _suser(), iVar2 == 0))
  {
    return;
  }
  iVar2 = piVar1[1];
  if (iVar2 == -1) {
    sVar5 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
  }
  else {
    sVar5 = (sword)iVar2;
  }
  if (((sVar5 != *(sword *)(*(int *)((int)_active_u + 0x1a) + 6)) &&
      (sVar5 != *(sword *)(*(int *)((int)_active_u + 0x1a) + 2))) && (iVar2 = _suser(), iVar2 == 0))
  {
    return;
  }
  _lock_write((int)_active_u + 0x1e);
  uVar3 = _crcopy(*(undefined4 *)((int)_active_u + 0x1a));
  *(undefined4 *)((int)_active_u + 0x1a) = uVar3;
  *(sword *)(*_active_u + 0x2c) = sVar5;
  *(sword *)(*(int *)((int)_active_u + 0x1a) + 6) = sVar4;
  *(sword *)(*(int *)((int)_active_u + 0x1a) + 2) = sVar5;
  _lock_done((int)_active_u + 0x1e);
  return;
}

