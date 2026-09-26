
void _vfs_remove(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = _rootvfs;
  if (param_1 == _rootvfs) {
                    /* WARNING: Subroutine does not return */
    _panic(aVfsRemoveUnmou);
  }
  do {
    piVar3 = piVar4;
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(aVfsRemoveVfsNo);
    }
    piVar4 = (int *)*piVar3;
  } while (param_1 != piVar4);
  *piVar3 = *piVar4;
  iVar2 = piVar4[2];
  if (*(int *)(iVar2 + 0xc) == 0) {
    piVar4 = (int *)(iVar2 + 0x10);
    iVar1 = *piVar4;
    while (iVar1 != 0) {
      if (param_1 == (int *)*piVar4) goto loc_401733C;
      piVar4 = (int *)*piVar4 + 0x48;
      iVar1 = *piVar4;
    }
    if (param_1 != (int *)*piVar4) {
                    /* WARNING: Subroutine does not return */
      _panic(aVfsRemoveCanTF);
    }
loc_401733C:
    *piVar4 = param_1[0x48];
    _microtime(iVar2 + 0x14);
  }
  else {
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  _vfs_unlock(param_1);
  return;
}
