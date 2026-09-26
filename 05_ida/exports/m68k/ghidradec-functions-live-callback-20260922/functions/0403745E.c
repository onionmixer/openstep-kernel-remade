
void _inode_cache_clear(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  while( true ) {
    piVar5 = _ifreeh;
    if (_ifreeh == (int *)0x0) {
      _ifreeh = (int *)0x0;
      iVar3 = _inode_list;
      iVar6 = _inode_list;
      while (iVar4 = iVar3, iVar4 != 0) {
        if (*(sword *)(iVar4 + 0x42) < 0) {
          if (iVar4 == iVar6) {
            iVar6 = *(int *)(iVar4 + 8);
            _inode_list = iVar6;
          }
          else {
            *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar4 + 8);
          }
          iVar3 = *(int *)(iVar4 + 8);
          _zfree(_vm_info_zone,*(undefined4 *)(iVar4 + 0xc));
          _zfree(_inode_zone,iVar4);
        }
        else {
          iVar3 = *(int *)(iVar4 + 8);
          iVar6 = iVar4;
        }
      }
      return;
    }
    piVar2 = *(int **)((int)_ifreeh + 0x5a);
    if (piVar2 != (int *)0x0) {
      *(int ***)((int)piVar2 + 0x5e) = &_ifreeh;
    }
    puVar1 = (undefined4 *)((int)_ifreeh + 0x5a);
    _ifreeh = piVar2;
    *puVar1 = 0;
    *(undefined4 *)((int)piVar5 + 0x5e) = 0;
    _mfs_uncache(piVar5 + 3);
    *(undefined2 *)((int)piVar5 + 0x42) = 0x8000;
    *(word *)((int)piVar5 + 0x42) = *(word *)((int)piVar5 + 0x42) | 1;
    if (*(sword *)((int)piVar5 + 0x12) != 0) break;
    *(int *)(*piVar5 + 4) = piVar5[1];
    *(int *)piVar5[1] = *piVar5;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aFreeInodeIsnT);
}

