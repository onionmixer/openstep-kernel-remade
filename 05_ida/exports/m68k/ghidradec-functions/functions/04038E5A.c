
void _update(word param_1,word param_2)

{
  int iVar1;
  int iVar2;
  word wVar3;
  int iVar4;
  undefined4 auStack_c [2];
  
  if (_syncprt != 0) {
    _bufstats();
  }
  if (_updlock == 0) {
    _updlock = 1;
    for (iVar2 = _mounttab; iVar1 = _inode_list, iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
      if ((((param_1 == 0xffff) || ((param_2 & *(word *)(iVar2 + 4)) == param_1)) &&
          (*(int *)(iVar2 + 10) != 0)) &&
         ((*(sword *)(iVar2 + 4) != -1 &&
          (iVar1 = *(int *)(*(int *)(iVar2 + 10) + 0x20), *(char *)(iVar1 + 0xd0) != '\0')))) {
        if (*(char *)(iVar1 + 0xd2) != '\0') {
          _printf(aFsS,iVar1 + 0xd4);
                    /* WARNING: Subroutine does not return */
          _panic(aUpdateRoFsMod);
        }
        *(undefined *)(iVar1 + 0xd0) = 0;
        _getthetime(auStack_c);
        *(undefined4 *)(iVar1 + 0x20) = auStack_c[0];
        _sbupdate(iVar2);
      }
    }
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if (param_1 == 0xffff) {
loc_4038F50:
        wVar3 = *(word *)(iVar1 + 0x42);
        if ((((wVar3 & 1) == 0) && ((wVar3 & 0x100) != 0)) && ((wVar3 & 0x4e) != 0)) {
          *(word *)(iVar1 + 0x42) = *(word *)(iVar1 + 0x42) | 1;
          *(sword *)(iVar1 + 0x12) = *(sword *)(iVar1 + 0x12) + 1;
          _iupdat(iVar1,0);
          _iput(iVar1);
        }
      }
      else if ((param_2 & *(word *)(iVar1 + 0x44)) == param_1) {
        iVar2 = *(int *)(iVar1 + 0xc) + 0x18;
        iVar4 = _lock_try_write(iVar2);
        if (iVar4 == 1) {
          _lock_done(iVar2);
          _mfs_fsync(iVar1 + 0xc);
        }
        goto loc_4038F50;
      }
    }
    _updlock = 0;
    _bflush(0,(int)(sword)param_1,(int)(sword)param_2);
  }
  return;
}
