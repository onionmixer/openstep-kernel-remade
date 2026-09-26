/* GHIDRADEC_FUNCTION index=480 start=0x4017200 */

int _vfs_add(int param_1,undefined4 *param_2,word param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = _vfs_lock(param_2);
  if (iVar2 == 0) {
    if (param_1 == 0) {
      _rootvfs = param_2;
      *param_2 = 0;
    }
    else {
      if (*(int *)(param_1 + 0xc) != 0) {
        _vfs_unlock(param_2);
        return 0x10;
      }
      if ((sword)param_3 < 0) {
        param_2[0x48] = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 **)(param_1 + 0x10) = param_2;
        _microtime(param_1 + 0x14);
      }
      else {
        *(undefined4 **)(param_1 + 0xc) = param_2;
      }
      puVar1 = _rootvfs;
      *param_2 = *_rootvfs;
      *puVar1 = param_2;
    }
    param_2[2] = param_1;
    if ((param_3 & 1) == 0) {
      param_2[3] = param_2[3] & 0xfffffffe;
    }
    else {
      param_2[3] = param_2[3] | 1;
    }
    if ((param_3 & 2) == 0) {
      param_2[3] = param_2[3] & 0xfffffff7;
    }
    else {
      param_2[3] = param_2[3] | 8;
    }
    if ((param_3 & 8) == 0) {
      param_2[3] = param_2[3] & 0xffffffef;
    }
    else {
      param_2[3] = param_2[3] | 0x10;
    }
    if ((param_3 & 0x20) == 0) {
      param_2[3] = param_2[3] & 0xffffffdf;
    }
    else {
      param_2[3] = param_2[3] | 0x20;
    }
    *(word *)((int)param_2 + 0xe) = *(word *)((int)param_2 + 0xe) & 0xff7f;
    iVar2 = 0;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=481 start=0x40172d4 */

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
/* GHIDRADEC_FUNCTION index=482 start=0x4017378 */

undefined4 _vfs_lock(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0xc) & 2) == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 2;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=483 start=0x401739c */

void _vfs_unlock(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 0xf) & 2) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVfsUnlock);
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffffd;
  if ((uVar1 & 4) != 0) {
    *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffff9;
    _wakeup(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=484 start=0x40173e6 */

int * _getvfs(int *param_1)

{
  int *piVar1;
  
  if (_rootvfs != (int *)0x0) {
    piVar1 = _rootvfs;
    do {
      if ((*param_1 == piVar1[5]) && (piVar1[6] == param_1[1])) {
        return piVar1;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  return (int *)0x0;
}

