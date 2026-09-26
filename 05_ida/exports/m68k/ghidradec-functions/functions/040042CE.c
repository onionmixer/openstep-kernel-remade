
void _close(void)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  
  uVar1 = **(uint **)(dword_40B57D4 + 0x24);
  if (((uVar1 < *(uint *)((int)_active_u + 0x152)) &&
      (iVar2 = *(int *)(*(int *)((int)_active_u + 0x146) + uVar1 * 4), iVar2 != 0)) &&
     (iVar2 != -0x10000)) {
    _vno_lockrelease(iVar2);
    pbVar3 = (byte *)(uVar1 + *(int *)((int)_active_u + 0x14a));
    if ((*pbVar3 & 2) != 0) {
      _munmapfd(uVar1);
    }
    *(undefined4 *)(*(int *)((int)_active_u + 0x146) + uVar1 * 4) = 0;
    while( true ) {
      if ((*(int *)((int)_active_u + 0x14e) < 0) ||
         (*(int *)(*(int *)((int)_active_u + 0x146) + *(int *)((int)_active_u + 0x14e) * 4) != 0))
      break;
      *(int *)((int)_active_u + 0x14e) = *(int *)((int)_active_u + 0x14e) + -1;
    }
    *pbVar3 = 0;
    _closef(iVar2);
    if ((((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && (*(char *)(dword_40B57D4 + 100) == '\x1c'))
       && ((*(byte *)(iVar2 + 10) & 0x10) != 0)) {
      *(undefined *)(dword_40B57D4 + 100) = 0;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 9;
  }
  return;
}
