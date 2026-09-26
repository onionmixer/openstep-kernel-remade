
void _profil(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = _active_u;
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  piVar3 = (int *)(_active_u + 0x23c);
  *(undefined4 *)(_active_u + 0x244) = *puVar1;
  *(undefined4 *)(iVar4 + 0x248) = puVar1[1];
  *(undefined4 *)(iVar4 + 0x24c) = puVar1[2];
  *(undefined4 *)(iVar4 + 0x250) = puVar1[3];
  if (*piVar3 == 0) {
    iVar5 = _simple_lock_alloc();
    *piVar3 = iVar5;
  }
  iVar5 = *(int *)(iVar4 + 0x240);
  while (iVar5 != 0) {
    iVar2 = *(int *)(iVar5 + 4);
    _kfree(iVar5,0x18);
    iVar5 = iVar2;
  }
  *(undefined4 *)(iVar4 + 0x240) = 0;
  return;
}
