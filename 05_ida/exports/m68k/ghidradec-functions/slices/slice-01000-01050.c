/* GHIDRADEC_FUNCTION index=1000 start=0x4037382 */

void _disksort_init(int param_1)

{
  int iVar1;
  
  _bzero(param_1,0x26);
  sub_4036D3E(param_1);
  iVar1 = param_1 + 0xe;
  *(int *)(param_1 + 0x12) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x16) = 0x14;
  return;
}
/* GHIDRADEC_FUNCTION index=1001 start=0x40373b8 */

void _disksort_free(int param_1)

{
  if (((char)*(byte *)(param_1 + 0xc) < '\0') &&
     (*(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0x7f, dword_40C10A0 != 0)) {
    (*dword_40C109C)(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1002 start=0x40373e4 */

int _new_inode(void)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = _zalloc(_inode_zone);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    _bzero(iVar2,0xe6);
    *(int *)iVar2 = iVar2;
    *(int *)(iVar2 + 4) = iVar2;
    *(undefined4 *)(iVar2 + 0x5a) = 0;
    *(undefined4 *)(iVar2 + 0x5e) = 0;
    *(int *)(iVar2 + 0x3a) = iVar2;
    *(undefined **)(iVar2 + 0x28) = _ufs_vnodeops;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    _vm_info_init((int *)(iVar2 + 0xc));
    pbVar1 = (byte *)(*(int *)(iVar2 + 0xc) + 0x34);
    *pbVar1 = *pbVar1 & 0xdf;
    *(int *)(iVar2 + 8) = _inode_list;
    _inode_list = iVar2;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1003 start=0x403745e */

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
/* GHIDRADEC_FUNCTION index=1004 start=0x4037530 */

void _ihinit(void)

{
  word wVar1;
  int iVar2;
  sword sVar3;
  undefined *puVar4;
  
  puVar4 = _ihead;
  iVar2 = 0x1ff;
  do {
    do {
      *(undefined **)puVar4 = puVar4;
      *(undefined **)(puVar4 + 4) = puVar4;
      puVar4 = puVar4 + 8;
      wVar1 = (word)((uint)iVar2 >> 0x10);
      sVar3 = (sword)iVar2 + -1;
      iVar2 = CONCAT22(wVar1,sVar3);
    } while (sVar3 != -1);
    iVar2 = (uint)wVar1 * 0x10000 + -1;
  } while (wVar1 != 0);
  _ifreeh = 0;
  _ifreet = 0;
  _inode_list = 0;
  _inode_zone = _zinit(0xe6,2300000,0,0,aInodeStructure);
  return;
}
/* GHIDRADEC_FUNCTION index=1005 start=0x4037588 */

int * _iget(sword param_1,int param_2,uint param_3)

{
  int *piVar1;
  word wVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
loc_403759C:
  do {
    piVar3 = (int *)_getmp((int)param_1);
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(aIgetBadDev);
    }
    if (param_2 != *(int *)(*(int *)((int)piVar3 + 10) + 0x20)) {
                    /* WARNING: Subroutine does not return */
      _panic(aIgetBadFs);
    }
    piVar1 = (int *)(_ihead + (param_3 + (int)param_1 & 0x1ff) * 8);
    for (piVar4 = (int *)*piVar1; piVar1 != piVar4; piVar4 = (int *)*piVar4) {
      if ((param_3 == *(uint *)((int)piVar4 + 0x46)) && (param_1 == *(sword *)(piVar4 + 0x11))) {
        wVar2 = *(word *)((int)piVar4 + 0x42);
        if ((wVar2 & 1) == 0) {
          if ((wVar2 & 0x100) == 0) {
            iVar5 = *(int *)((int)piVar4 + 0x5a);
            if (iVar5 == 0) {
              _ifreet = *(undefined4 **)((int)piVar4 + 0x5e);
            }
            else {
              *(undefined4 *)(iVar5 + 0x5e) = *(undefined4 *)((int)piVar4 + 0x5e);
            }
            **(int **)((int)piVar4 + 0x5e) = iVar5;
            *(undefined4 *)((int)piVar4 + 0x5a) = 0;
            *(undefined4 *)((int)piVar4 + 0x5e) = 0;
            *(undefined4 *)piVar4[3] = 0;
          }
          wVar2 = *(word *)((int)piVar4 + 0x42);
          *(word *)((int)piVar4 + 0x42) = wVar2 | 0x100;
          if ((wVar2 & 1) != 0) {
            do {
              *(word *)((int)piVar4 + 0x42) = *(word *)((int)piVar4 + 0x42) | 0x10;
              _sleep(piVar4,10);
            } while ((*(byte *)((int)piVar4 + 0x43) & 1) != 0);
          }
          *(word *)((int)piVar4 + 0x42) = *(word *)((int)piVar4 + 0x42) | 1;
          *(sword *)((int)piVar4 + 0x12) = *(sword *)((int)piVar4 + 0x12) + 1;
          return piVar4;
        }
        *(word *)((int)piVar4 + 0x42) = wVar2 | 0x10;
        _sleep(piVar4,10);
        goto loc_403759C;
      }
    }
    piVar4 = _ifreeh;
    if (_ifreeh != (int *)0x0) {
loc_40376E8:
      _ifreeh = *(int **)((int)piVar4 + 0x5a);
      if (_ifreeh != (int *)0x0) {
        *(int ***)((int)_ifreeh + 0x5e) = &_ifreeh;
      }
      *(undefined4 *)((int)piVar4 + 0x5a) = 0;
      *(undefined4 *)((int)piVar4 + 0x5e) = 0;
      _mfs_uncache(piVar4 + 3);
      *(undefined2 *)((int)piVar4 + 0x42) = 0x100;
      *(word *)((int)piVar4 + 0x42) = *(word *)((int)piVar4 + 0x42) | 1;
      if (*(sword *)((int)piVar4 + 0x12) == 0) {
        *(int *)(*piVar4 + 4) = piVar4[1];
        *(int *)piVar4[1] = *piVar4;
        *piVar4 = *piVar1;
        piVar4[1] = (int)piVar1;
        *(int **)(*piVar1 + 4) = piVar4;
        *piVar1 = (int)piVar4;
        *(sword *)(piVar4 + 0x11) = param_1;
        *(undefined4 *)((int)piVar4 + 0x3e) = *(undefined4 *)((int)piVar3 + 6);
        *(uint *)((int)piVar4 + 0x46) = param_3;
        *(undefined4 *)((int)piVar4 + 0x4a) = 0;
        *(int *)((int)piVar4 + 0x4e) = param_2;
        *(undefined4 *)((int)piVar4 + 0x56) = 0;
        uVar6 = param_3 / *(uint *)(param_2 + 0xb8);
        iVar5 = _bread(*(undefined4 *)((int)piVar4 + 0x3e),
                       ((param_3 % *(uint *)(param_2 + 0xb8)) / *(uint *)(param_2 + 0x78) <<
                       (*(uint *)(param_2 + 0x60) & 0x3f)) +
                       *(int *)(param_2 + 0x10) +
                       *(int *)(param_2 + 0x18) * (~*(uint *)(param_2 + 0x1c) & uVar6) +
                       uVar6 * *(int *)(param_2 + 0xbc) << (*(uint *)(param_2 + 100) & 0x3f),
                       *(undefined4 *)(param_2 + 0x30));
        if ((*(byte *)(iVar5 + 3) & 4) == 0) {
          _bcopy(*(int *)(iVar5 + 0x20) + (param_3 % *(uint *)(param_2 + 0x78)) * 0x80,
                 (uint *)((int)piVar4 + 0x62),0x80);
          *(undefined2 *)(piVar4 + 4) = 0;
          *(undefined2 *)((int)piVar4 + 0x12) = 1;
          *(undefined2 *)((int)piVar4 + 0x16) = 0;
          *(undefined2 *)(piVar4 + 5) = 0;
          piVar4[0xc] = *piVar3;
          piVar4[0xd] = *(int *)(_iftovt_tab + (*(uint *)((int)piVar4 + 0x62) >> 0x1d) * 4);
          *(undefined2 *)(piVar4 + 0xe) = *(undefined2 *)(piVar4 + 0x23);
          piVar4[0xb] = 0;
          piVar4[9] = 0;
          piVar4[8] = 0;
          if (param_3 == 2) {
            *(word *)(piVar4 + 4) = *(word *)(piVar4 + 4) | 1;
          }
          if (*(sword *)(piVar4[0xc] + 0x124) != 0) {
            *(undefined2 *)((int)piVar4 + 0xe2) = *(undefined2 *)((int)piVar4 + 0x66);
            *(undefined2 *)(piVar4 + 0x39) = *(undefined2 *)(piVar4 + 0x1a);
            *(undefined2 *)((int)piVar4 + 0x66) = *(undefined2 *)(piVar4[0xc] + 0x124);
            *(undefined2 *)(piVar4 + 0x1a) = _nogroup;
          }
          _brelse(iVar5);
          *(undefined4 *)piVar4[3] = 0;
          *(undefined4 *)(piVar4[3] + 0x14) = *(undefined4 *)((int)piVar4 + 0x6e);
        }
        else {
          _brelse(iVar5);
          *(int *)(*piVar4 + 4) = piVar4[1];
          *(int *)piVar4[1] = *piVar4;
          *piVar4 = (int)piVar4;
          piVar4[1] = (int)piVar4;
          *(undefined4 *)((int)piVar4 + 0x46) = 0;
          *(undefined2 *)((int)piVar4 + 0x12) = 0;
          wVar2 = *(word *)((int)piVar4 + 0x42);
          *(word *)((int)piVar4 + 0x42) = wVar2 & 0xfffe;
          if ((wVar2 & 0x10) != 0) {
            *(word *)((int)piVar4 + 0x42) = wVar2 & 0xffee;
            _wakeup(piVar4);
          }
          *(undefined2 *)((int)piVar4 + 0x42) = 0;
          if (_ifreeh == (int *)0x0) {
            _ifreeh = piVar4;
            *(int ***)((int)piVar4 + 0x5e) = &_ifreeh;
          }
          else {
            *_ifreet = piVar4;
            *(undefined4 **)((int)piVar4 + 0x5e) = _ifreet;
          }
          *(undefined4 *)((int)piVar4 + 0x5a) = 0;
          _ifreet = (undefined4 *)((int)piVar4 + 0x5a);
          piVar4 = (int *)0x0;
        }
        return piVar4;
      }
                    /* WARNING: Subroutine does not return */
      _panic(aFreeInodeIsnT);
    }
    piVar4 = (int *)_new_inode();
    if (piVar4 != (int *)0x0) {
      *(int **)((int)piVar4 + 0x5a) = _ifreeh;
      goto loc_40376E8;
    }
    do {
      if (_ifreeh != (int *)0x0) break;
      iVar5 = _dnlc_purge1();
    } while (iVar5 == 1);
    if (_ifreeh == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(aIgetOutOfInode);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1006 start=0x403790a */

void _iput(int param_1)

{
  word wVar1;
  
  if ((*(byte *)(param_1 + 0x43) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aIput);
  }
  wVar1 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
  if ((*(word *)(param_1 + 0x42) & 0x46) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(param_1 + 0x43) & 4) != 0) {
      *(undefined4 *)(param_1 + 0x72) = _iuniqtime;
    }
    if ((*(byte *)(param_1 + 0x43) & 2) != 0) {
      *(undefined4 *)(param_1 + 0x7a) = _iuniqtime;
    }
    if ((*(byte *)(param_1 + 0x43) & 0x40) != 0) {
      *(undefined4 *)(param_1 + 0x4a) = 0;
      *(undefined4 *)(param_1 + 0x82) = _iuniqtime;
    }
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) & 0xffb9;
  }
  _vn_rele(param_1 + 0xc);
  return;
}
/* GHIDRADEC_FUNCTION index=1007 start=0x40379c4 */

void _irele(int param_1)

{
  if ((*(byte *)(param_1 + 0x43) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aIrele);
  }
  if ((*(word *)(param_1 + 0x42) & 0x46) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(param_1 + 0x43) & 4) != 0) {
      *(undefined4 *)(param_1 + 0x72) = _iuniqtime;
    }
    if ((*(byte *)(param_1 + 0x43) & 2) != 0) {
      *(undefined4 *)(param_1 + 0x7a) = _iuniqtime;
    }
    if ((*(byte *)(param_1 + 0x43) & 0x40) != 0) {
      *(undefined4 *)(param_1 + 0x4a) = 0;
      *(undefined4 *)(param_1 + 0x82) = _iuniqtime;
    }
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) & 0xffb9;
  }
  _vn_rele(param_1 + 0xc);
  return;
}
/* GHIDRADEC_FUNCTION index=1008 start=0x4037a52 */

void _idrop(int param_1)

{
  word wVar1;
  sword sVar2;
  
  if ((*(byte *)(param_1 + 0x43) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aIdrop);
  }
  wVar1 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
  sVar2 = *(sword *)(param_1 + 0x12);
  *(sword *)(param_1 + 0x12) = sVar2 + -1;
  if (sVar2 == 1) {
    *(undefined2 *)(param_1 + 0x42) = 0;
    if (_ifreeh == 0) {
      _ifreeh = param_1;
      *(int **)(param_1 + 0x5e) = &_ifreeh;
    }
    else {
      *_ifreet = param_1;
      *(int **)(param_1 + 0x5e) = _ifreet;
    }
    *(undefined4 *)(param_1 + 0x5a) = 0;
    _ifreet = (int *)(param_1 + 0x5a);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1009 start=0x4037aea */

void _iinactive(int param_1)

{
  undefined2 uVar1;
  word wVar2;
  
  if ((((*(word *)(param_1 + 0x42) & 0x101) == 0x100) && (*(int *)(param_1 + 0x5e) == 0)) &&
     (*(int *)(param_1 + 0x5a) == 0)) {
    if (*(char *)(*(int *)(param_1 + 0x4e) + 0xd2) == '\0') {
      while ((*(word *)(param_1 + 0x42) & 1) != 0) {
        *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
        _sleep(param_1,10);
      }
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
      if (*(sword *)(param_1 + 100) < 1) {
        *(int *)(param_1 + 0xce) = *(int *)(param_1 + 0xce) + 1;
        *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x200;
        _itrunc(param_1,0);
        uVar1 = *(undefined2 *)(param_1 + 0x62);
        *(undefined2 *)(param_1 + 0x62) = 0;
        *(undefined4 *)(param_1 + 0x8a) = 0;
        *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
        _ifree(param_1,*(undefined4 *)(param_1 + 0x46),uVar1);
      }
      if ((*(word *)(param_1 + 0x42) & 0x4e) != 0) {
        _iupdat(param_1,0);
      }
      wVar2 = *(word *)(param_1 + 0x42);
      *(word *)(param_1 + 0x42) = wVar2 & 0xfffe;
      if ((wVar2 & 0x10) != 0) {
        *(word *)(param_1 + 0x42) = wVar2 & 0xffee;
        _wakeup(param_1);
      }
    }
    *(undefined2 *)(param_1 + 0x42) = 0;
    if (_ifreeh == 0) {
      _ifreeh = param_1;
      *(int **)(param_1 + 0x5e) = &_ifreeh;
    }
    else {
      *_ifreet = param_1;
      *(int **)(param_1 + 0x5e) = _ifreet;
    }
    *(undefined4 *)(param_1 + 0x5a) = 0;
    _ifreet = (int *)(param_1 + 0x5a);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aIinactive);
}
/* GHIDRADEC_FUNCTION index=1010 start=0x4037c0c */

word _iupdat(int param_1,int param_2)

{
  int iVar1;
  word wVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x4e);
  wVar2 = *(word *)(param_1 + 0x42) & 0x4e;
  if (((*(word *)(param_1 + 0x42) & 0x4e) != 0) && (*(char *)(iVar4 + 0xd2) == '\0')) {
    uVar3 = *(uint *)(param_1 + 0x46) / *(uint *)(iVar4 + 0xb8);
    iVar1 = _bread(*(undefined4 *)(param_1 + 0x3e),
                   ((*(uint *)(param_1 + 0x46) % *(uint *)(iVar4 + 0xb8)) / *(uint *)(iVar4 + 0x78)
                   << (*(uint *)(iVar4 + 0x60) & 0x3f)) +
                   *(int *)(iVar4 + 0x10) +
                   *(int *)(iVar4 + 0x18) * (~*(uint *)(iVar4 + 0x1c) & uVar3) +
                   uVar3 * *(int *)(iVar4 + 0xbc) << (*(uint *)(iVar4 + 100) & 0x3f),
                   *(undefined4 *)(iVar4 + 0x30));
    if ((*(byte *)(iVar1 + 3) & 4) == 0) {
      if ((*(word *)(param_1 + 0x42) & 0x46) != 0) {
        _microtime(&_iuniqtime);
        if ((*(byte *)(param_1 + 0x43) & 4) != 0) {
          *(undefined4 *)(param_1 + 0x72) = _iuniqtime;
        }
        if ((*(byte *)(param_1 + 0x43) & 2) != 0) {
          *(undefined4 *)(param_1 + 0x7a) = _iuniqtime;
        }
        if ((*(byte *)(param_1 + 0x43) & 0x40) != 0) {
          *(undefined4 *)(param_1 + 0x4a) = 0;
          *(undefined4 *)(param_1 + 0x82) = _iuniqtime;
        }
      }
      wVar2 = *(word *)(param_1 + 0x42);
      *(word *)(param_1 + 0x42) = wVar2 & 0xffb1;
      iVar4 = (*(uint *)(param_1 + 0x46) % *(uint *)(iVar4 + 0x78)) * 0x80 + *(int *)(iVar1 + 0x20);
      *(word *)(param_1 + 0x42) = wVar2 & 0xfdb1;
      _bcopy(param_1 + 0x62,iVar4,0x80);
      if (*(sword *)(*(int *)(param_1 + 0x30) + 0x124) != 0) {
        *(undefined2 *)(iVar4 + 4) = *(undefined2 *)(param_1 + 0xe2);
        *(undefined2 *)(iVar4 + 6) = *(undefined2 *)(param_1 + 0xe4);
      }
      if (param_2 == 0) {
        wVar2 = _bdwrite(iVar1);
      }
      else {
        wVar2 = _bwrite(iVar1);
      }
    }
    else {
      wVar2 = _brelse(iVar1);
    }
  }
  return wVar2;
}
/* GHIDRADEC_FUNCTION index=1011 start=0x4037d54 */

int _itrunc(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  word wVar10;
  int iVar11;
  uint uVar12;
  sword sVar14;
  uint uVar13;
  int iVar15;
  undefined *puVar16;
  undefined *puVar17;
  int iVar18;
  int iStack_fa;
  undefined auStack_f6 [8];
  undefined auStack_ee [36];
  undefined auStack_ca [66];
  uint uStack_88;
  int aiStack_6c [11];
  int aiStack_40 [12];
  int aiStack_10 [3];
  
  iStack_fa = 0;
  iVar15 = 0;
  wVar10 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar10 & 0xfffe;
  if ((wVar10 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar10 & 0xffee;
    _wakeup(param_1);
  }
  iVar4 = _mfs_trunc(param_1 + 0xc,param_2);
  while ((*(word *)(param_1 + 0x42) & 1) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
    _sleep(param_1,10);
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
  if (((*(word *)(param_1 + 0x62) & 0xf000) == 0xa000) && ((*(byte *)(param_1 + 0xc9) & 1) != 0)) {
    iVar4 = 0xe;
    iVar15 = param_1 + 0x38;
    do {
      do {
        *(undefined4 *)(iVar15 + 0x8a) = 0;
        iVar15 = iVar15 + -4;
        wVar10 = (word)((uint)iVar4 >> 0x10);
        sVar14 = (sword)iVar4 + -1;
        iVar4 = CONCAT22(wVar10,sVar14);
      } while (sVar14 != -1);
      iVar4 = (uint)wVar10 * 0x10000 + -1;
    } while (wVar10 != 0);
    *(undefined4 *)(param_1 + 0xc6) = 0;
    *(undefined4 *)(param_1 + 0x6e) = 0;
loc_4037E04:
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
    _iupdat(param_1,1);
    return 0;
  }
  if (*(uint *)(param_1 + 0x6e) == param_2) goto loc_4037E04;
  iVar18 = *(int *)(param_1 + 0x4e);
  uVar12 = param_2 & ~*(uint *)(iVar18 + 0x48);
  uVar13 = param_2 - 1 >> (*(uint *)(iVar18 + 0x50) & 0x3f);
  if (*(uint *)(param_1 + 0x6e) < param_2) {
    if (uVar12 == 0) {
      uVar12 = *(uint *)(iVar18 + 0x30);
    }
    iVar15 = _bmap(param_1,uVar13,0,uVar12,&iStack_fa);
    if ((*(char *)(dword_40B57D4 + 100) == '\0') || (-1 < iVar15)) {
      *(uint *)(param_1 + 0x6e) = param_2;
      wVar10 = *(word *)(param_1 + 0x42);
      *(word *)(param_1 + 0x42) = wVar10 | 0x40;
      *(word *)(param_1 + 0x42) = wVar10 | 0x48;
      _microtime(&_iuniqtime);
      if ((*(byte *)(param_1 + 0x43) & 4) != 0) {
        *(undefined4 *)(param_1 + 0x72) = _iuniqtime;
      }
      if ((*(byte *)(param_1 + 0x43) & 2) != 0) {
        *(undefined4 *)(param_1 + 0x7a) = _iuniqtime;
      }
      if ((*(byte *)(param_1 + 0x43) & 0x40) != 0) {
        *(undefined4 *)(param_1 + 0x4a) = 0;
        *(undefined4 *)(param_1 + 0x82) = _iuniqtime;
      }
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) & 0xffb9;
    }
    if (iStack_fa != 0) {
      _iupdat(param_1,1);
    }
  }
  else {
    uVar5 = (*(int *)(iVar18 + 0x30) + param_2) - 1 >> (*(uint *)(iVar18 + 0x50) & 0x3f);
    iVar3 = uVar5 - 1;
    aiStack_10[0] = uVar5 - 0xd;
    aiStack_10[1] = aiStack_10[0] - *(int *)(iVar18 + 0x74);
    aiStack_10[2] = aiStack_10[1] - *(int *)(iVar18 + 0x74) * *(int *)(iVar18 + 0x74);
    iVar6 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
    iVar1 = *(int *)(iVar18 + 0x30);
    uVar8 = *(uint *)(param_1 + 0x6e);
    if (uVar12 == 0) {
      *(uint *)(param_1 + 0x6e) = param_2;
    }
    else {
      iVar11 = _bmap(param_1,uVar13,0,uVar12,0);
      iVar11 = iVar11 << (*(uint *)(iVar18 + 100) & 0x3f);
      cVar9 = *(char *)(dword_40B57D4 + 100);
      if ((cVar9 != '\0') || (iVar11 < 0)) goto loc_40382B2;
      *(uint *)(param_1 + 0x6e) = param_2;
      if (((int)uVar13 < 0xc) && (param_2 < uVar13 + 1 << (*(uint *)(iVar18 + 0x50) & 0x3f))) {
        uVar13 = *(uint *)(iVar18 + 0x4c) &
                 (*(int *)(iVar18 + 0x34) + (param_2 & ~*(uint *)(iVar18 + 0x48))) - 1;
      }
      else {
        uVar13 = *(uint *)(iVar18 + 0x30);
      }
      uVar2 = *(undefined4 *)(param_1 + 0x3e);
      if (**(int **)(param_1 + 0xc) != 0) {
        _vnode_uncache(param_1 + 0xc);
      }
      if (iVar4 == 0) {
        iVar4 = _bread(uVar2,iVar11,uVar13);
        if ((*(byte *)(iVar4 + 3) & 4) != 0) {
          *(undefined *)(dword_40B57D4 + 100) = 5;
          *(uint *)(param_1 + 0x6e) = uVar8;
          _brelse(iVar4);
          return 5;
        }
        _bzero(*(int *)(iVar4 + 0x20) + uVar12,uVar13 - uVar12);
        _bdwrite(iVar4);
      }
    }
    _bcopy(param_1,auStack_f6,0xe6);
    iVar11 = 2;
    iVar4 = param_1 + 8;
    do {
      if (aiStack_10[iVar11] < 0) {
        *(undefined4 *)(iVar4 + 0xba) = 0;
        aiStack_10[iVar11] = -1;
      }
      iVar4 = iVar4 + -4;
      wVar10 = (word)((uint)iVar11 >> 0x10);
      sVar14 = (sword)iVar11 + -1;
      iVar11 = CONCAT22(wVar10,sVar14);
    } while ((sVar14 != -1) || (iVar11 = (uint)wVar10 * 0x10000 + -1, wVar10 != 0));
    iVar4 = 0xb;
    if (iVar3 < 0xb) {
      iVar11 = param_1 + 0x2c;
      do {
        *(undefined4 *)(iVar11 + 0x8a) = 0;
        iVar11 = iVar11 + -4;
        iVar4 = iVar4 + -1;
      } while (iVar3 < iVar4);
    }
    *(uint *)(param_1 + 0x6e) = param_2;
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
    uStack_88 = uVar8;
    _iupdat(param_1,1);
    puVar17 = auStack_f6;
    iVar4 = 2;
    puVar16 = auStack_ee;
    do {
      iVar11 = *(int *)(puVar16 + 0xba);
      if (iVar11 != 0) {
        iVar7 = _indirtrunc(puVar17,iVar11,aiStack_10[iVar4],iVar4);
        iVar15 = iVar7 + iVar15;
        if (aiStack_10[iVar4] < 0) {
          *(undefined4 *)(puVar16 + 0xba) = 0;
          _free_block(puVar17,iVar11,*(undefined4 *)(iVar18 + 0x30));
          iVar15 = iVar1 / iVar6 + iVar15;
        }
      }
      if (-1 < aiStack_10[iVar4]) goto loc_403823E;
      puVar16 = puVar16 + -4;
      wVar10 = (word)((uint)iVar4 >> 0x10);
      sVar14 = (sword)iVar4 + -1;
      iVar4 = CONCAT22(wVar10,sVar14);
    } while ((sVar14 != -1) || (iVar4 = (uint)wVar10 * 0x10000 + -1, wVar10 != 0));
    iVar4 = 0xb;
    if (iVar3 < 0xb) {
      puVar16 = auStack_ca;
      do {
        iVar1 = *(int *)(puVar16 + 0x8a);
        if (iVar1 != 0) {
          *(undefined4 *)(puVar16 + 0x8a) = 0;
          if ((iVar4 < 0xc) && (uStack_88 < (uint)(iVar4 + 1 << (*(uint *)(iVar18 + 0x50) & 0x3f))))
          {
            uVar12 = *(uint *)(iVar18 + 0x4c) &
                     (*(int *)(iVar18 + 0x34) + (uStack_88 & ~*(uint *)(iVar18 + 0x48))) - 1;
          }
          else {
            uVar12 = *(uint *)(iVar18 + 0x30);
          }
          _free_block(puVar17,iVar1,uVar12);
          uVar13 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
          iVar15 = uVar12 / uVar13 + iVar15;
        }
        puVar16 = puVar16 + -4;
        iVar4 = iVar4 + -1;
      } while (iVar3 < iVar4);
    }
    if ((-1 < iVar3) && (aiStack_6c[iVar3] != 0)) {
      if ((iVar3 < 0xc) && (uStack_88 < uVar5 << (*(uint *)(iVar18 + 0x50) & 0x3f))) {
        uVar12 = *(uint *)(iVar18 + 0x4c) &
                 (*(int *)(iVar18 + 0x34) + (uStack_88 & ~*(uint *)(iVar18 + 0x48))) - 1;
      }
      else {
        uVar12 = *(uint *)(iVar18 + 0x30);
      }
      uStack_88 = param_2;
      if ((iVar3 < 0xc) && (param_2 < uVar5 << (*(uint *)(iVar18 + 0x50) & 0x3f))) {
        uVar13 = *(uint *)(iVar18 + 0x4c) &
                 (*(int *)(iVar18 + 0x34) + (param_2 & ~*(uint *)(iVar18 + 0x48))) - 1;
      }
      else {
        uVar13 = *(uint *)(iVar18 + 0x30);
      }
      if (uVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aItruncNewspace);
      }
      if (uVar13 != uVar12) {
        _free_block(puVar17,aiStack_6c[iVar3] + (uVar13 >> (*(uint *)(iVar18 + 0x54) & 0x3f)),
                    uVar12 - uVar13);
        uVar8 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
        iVar15 = (uVar12 - uVar13) / uVar8 + iVar15;
      }
    }
loc_403823E:
    iVar4 = 0;
    puVar16 = puVar17;
    iVar18 = param_1;
    do {
      if (*(int *)(puVar16 + 0xba) != *(int *)(iVar18 + 0xba)) {
                    /* WARNING: Subroutine does not return */
        _panic(&aItrunc1);
      }
      iVar18 = iVar18 + 4;
      puVar16 = puVar16 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    iVar4 = 0;
    iVar18 = param_1;
    do {
      if (*(int *)(puVar17 + 0x8a) != *(int *)(iVar18 + 0x8a)) {
                    /* WARNING: Subroutine does not return */
        _panic(&aItrunc2);
      }
      iVar18 = iVar18 + 4;
      puVar17 = puVar17 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xc);
    iVar15 = *(int *)(param_1 + 0xca) - iVar15;
    *(int *)(param_1 + 0xca) = iVar15;
    if (iVar15 < 0) {
      *(undefined4 *)(param_1 + 0xca) = 0;
    }
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x40;
  }
  cVar9 = *(char *)(dword_40B57D4 + 100);
loc_40382B2:
  return (int)cVar9;
}
/* GHIDRADEC_FUNCTION index=1012 start=0x40382be */

int _indirtrunc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  
  iVar7 = *(int *)(param_1 + 0x4e);
  iVar10 = 0;
  iVar11 = 1;
  iVar8 = 0;
  if (0 < param_4) {
    do {
      iVar11 = *(int *)(iVar7 + 0x74) * iVar11;
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_4);
  }
  iVar8 = param_3;
  if (0 < param_3) {
    iVar8 = param_3 / iVar11;
  }
  iVar3 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
  iVar2 = *(int *)(iVar7 + 0x30);
  iVar4 = _geteblk(*(undefined4 *)(iVar7 + 0x30));
  iVar5 = _bread(*(undefined4 *)(param_1 + 0x3e),param_2 << (*(uint *)(iVar7 + 100) & 0x3f),
                 *(undefined4 *)(iVar7 + 0x30));
  if ((*(byte *)(iVar5 + 3) & 4) == 0) {
    iVar9 = *(int *)(iVar5 + 0x20);
    _bcopy(iVar9,*(undefined4 *)(iVar4 + 0x20),*(undefined4 *)(iVar7 + 0x30));
    _bzero(iVar9 + 4 + iVar8 * 4,((*(int *)(iVar7 + 0x74) + -1) - iVar8) * 4);
    _bwrite(iVar5);
    iVar5 = *(int *)(iVar4 + 0x20);
    iVar9 = *(int *)(iVar7 + 0x74) + -1;
    if (iVar8 < iVar9) {
      piVar12 = (int *)(iVar5 + iVar9 * 4);
      do {
        iVar1 = *piVar12;
        if (iVar1 != 0) {
          if (0 < param_4) {
            iVar6 = _indirtrunc(param_1,iVar1,0xffffffff,param_4 + -1);
            iVar10 = iVar6 + iVar10;
          }
          _free_block(param_1,iVar1,*(undefined4 *)(iVar7 + 0x30));
          iVar10 = iVar2 / iVar3 + iVar10;
        }
        piVar12 = piVar12 + -1;
        iVar9 = iVar9 + -1;
      } while (iVar8 < iVar9);
    }
    if ((0 < param_4) && (-1 < param_3)) {
      iVar7 = *(int *)(iVar5 + iVar9 * 4);
      if (iVar7 != 0) {
        iVar7 = _indirtrunc(param_1,iVar7,param_3 % iVar11,param_4 + -1);
        iVar10 = iVar7 + iVar10;
      }
    }
    _brelse(iVar4);
  }
  else {
    _brelse(iVar4);
    _brelse(iVar5);
    iVar10 = 0;
  }
  return iVar10;
}
/* GHIDRADEC_FUNCTION index=1013 start=0x403843e */

int _iflush(sword param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (_inode_list != (int *)0x0) {
    piVar2 = _inode_list;
    do {
      if (param_1 == *(sword *)(piVar2 + 0x11)) {
        if ((*(byte *)((int)piVar2 + 0x42) & 1) == 0) {
          *(int *)(*piVar2 + 4) = piVar2[1];
          *(int *)piVar2[1] = *piVar2;
          *piVar2 = (int)piVar2;
          piVar2[1] = (int)piVar2;
        }
        else {
          iVar1 = -1;
        }
      }
      else if (((((*(byte *)((int)piVar2 + 0x42) & 1) != 0) &&
                ((*(word *)((int)piVar2 + 0x62) & 0xf000) == 0x6000)) &&
               ((int)param_1 == *(int *)((int)piVar2 + 0x8a))) && (-1 < iVar1)) {
        iVar1 = iVar1 + 1;
      }
      piVar2 = (int *)piVar2[2];
    } while (piVar2 != (int *)0x0);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1014 start=0x40384b8 */

void _ilock(int param_1)

{
  while ((*(word *)(param_1 + 0x42) & 1) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
    _sleep(param_1,10);
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1015 start=0x40384f2 */

void _iunlock(int param_1)

{
  word wVar1;
  
  wVar1 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1016 start=0x4038522 */

undefined4 _iaccess(int param_1,uint param_2)

{
  int iVar1;
  word wVar2;
  undefined4 uVar3;
  uint uVar4;
  sword *psVar5;
  
  if ((char)param_2 < '\0') {
    if ((((*(char *)(*(int *)(param_1 + 0x4e) + 0xd2) != '\0') &&
         (wVar2 = *(word *)(param_1 + 0x62) & 0xf000, wVar2 != 0x2000)) && (wVar2 != 0x6000)) &&
       (wVar2 != 0x1000)) {
      return 0x1e;
    }
    if (((*(byte *)(param_1 + 0x11) & 2) != 0) &&
       (_vnode_uncache(param_1 + 0xc), (*(byte *)(param_1 + 0x11) & 2) != 0)) {
      return 0x1a;
    }
  }
  iVar1 = *(int *)(_active_u + 0x1a);
  if (*(sword *)(iVar1 + 2) == 0) {
    uVar3 = 0;
  }
  else {
    uVar4 = param_2;
    if ((*(sword *)(iVar1 + 2) != *(sword *)(param_1 + 0x66)) &&
       (uVar4 = (int)param_2 >> 3, *(sword *)(param_1 + 0x68) != *(sword *)(iVar1 + 4))) {
      for (psVar5 = (sword *)(iVar1 + 10); (psVar5 < (sword *)(iVar1 + 0x2a) && (*psVar5 != -1));
          psVar5 = psVar5 + 1) {
        if (*psVar5 == *(sword *)(param_1 + 0x68)) goto loc_40385CA;
      }
      uVar4 = (int)param_2 >> 6;
    }
loc_40385CA:
    uVar3 = 0;
    if (uVar4 != (uVar4 & *(word *)(param_1 + 0x62))) {
      uVar3 = 0xd;
    }
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1017 start=0x40385e4 */

undefined4 _lf_lockctl(undefined4 param_1,sword *param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = sub_40386C0(param_1);
  puVar2 = (undefined2 *)_kalloc(0x1c);
  puVar2[1] = *param_2;
  *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(param_2 + 2);
  if (*(int *)(param_2 + 4) == 0) {
    iVar3 = -1;
  }
  else {
    iVar3 = *(int *)(param_2 + 2) + *(int *)(param_2 + 4) + -1;
  }
  *(int *)(puVar2 + 4) = iVar3;
  uVar4 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  *(undefined4 *)(puVar2 + 6) = uVar4;
  *(int *)(puVar2 + 8) = iVar1;
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  *(undefined4 *)(puVar2 + 10) = 0;
  *(undefined4 *)(puVar2 + 0xc) = 0;
  if (param_3 == 7) {
    uVar4 = sub_4038B30(puVar2,param_2);
    sub_4038E3A(puVar2);
  }
  else {
    if (*param_2 != 3) {
      if (param_3 == 8) {
        *puVar2 = 1;
      }
      else {
        *puVar2 = 2;
      }
      uVar4 = sub_403878C(puVar2);
      return uVar4;
    }
    uVar4 = sub_4038A24(puVar2);
    sub_4038E3A(puVar2);
  }
  sub_4038728(iVar1);
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=1018 start=0x4038e5a */

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
/* GHIDRADEC_FUNCTION index=1019 start=0x4038fae */

void _syncip(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  
  iVar2 = *(int *)(param_1 + 0x4e);
  uVar5 = (*(uint *)(iVar2 + 0x30) + *(int *)(param_1 + 0x6e) + -1) / *(uint *)(iVar2 + 0x30);
  iVar6 = _nbuf;
  if (_nbuf < 0) {
    iVar6 = _nbuf + 1;
  }
  if ((int)uVar5 < iVar6 >> 1) {
    iVar6 = 0;
    if (0 < (int)uVar5) {
      do {
        iVar3 = _bmap(param_1,iVar6,1);
        if ((iVar6 < 0xc) &&
           (*(uint *)(param_1 + 0x6e) < (uint)(iVar6 + 1 << (*(uint *)(iVar2 + 0x50) & 0x3f)))) {
          uVar4 = *(uint *)(iVar2 + 0x4c) &
                  (*(int *)(iVar2 + 0x34) + (*(uint *)(param_1 + 0x6e) & ~*(uint *)(iVar2 + 0x48)))
                  - 1;
        }
        else {
          uVar4 = *(uint *)(iVar2 + 0x30);
        }
        _blkflush(*(undefined4 *)(param_1 + 0x3e),iVar3 << (*(uint *)(iVar2 + 100) & 0x3f),uVar4);
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)uVar5);
    }
  }
  else {
    puVar1 = _buf + _nbuf * 0x11;
    for (puVar7 = _buf; puVar7 < puVar1; puVar7 = puVar7 + 0x11) {
      if ((puVar7[0x10] == *(uint *)(param_1 + 0x3e)) && ((*puVar7 & 0x200) != 0)) {
        if ((*puVar7 & 8) == 0) {
          *(uint *)(puVar7[4] + 0xc) = puVar7[3];
          *(uint *)(puVar7[3] + 0x10) = puVar7[4];
          *puVar7 = *puVar7 | 8;
          _bwrite(puVar7);
        }
        else {
          *puVar7 = *puVar7 | 0x40;
          _sleep(puVar7,0x15);
          puVar7 = puVar7 + -0x11;
        }
      }
    }
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x40;
  _iupdat(param_1,1);
  return;
}
/* GHIDRADEC_FUNCTION index=1020 start=0x4039100 */

void _fragacct(int param_1,int param_2,int *param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  
  iVar6 = *(int *)(param_1 + 0x38);
  bVar1 = *(byte *)(*(int *)(_fragtbl + iVar6 * 4) + param_2);
  uVar5 = 1;
  if (1 < iVar6) {
    puVar8 = unk_40AF35E;
    puVar7 = unk_40AF33A;
    do {
      param_3 = param_3 + 1;
      if (((uint)bVar1 * 2 & 1 << (uVar5 + iVar6 % 8 & 0x1f)) != 0) {
        uVar4 = *(uint *)puVar7;
        uVar3 = *(uint *)puVar8;
        uVar2 = uVar5;
        if ((int)uVar5 <= iVar6) {
          do {
            if (uVar3 == (uVar4 & param_2 * 2)) {
              *param_3 = param_4 + *param_3;
              uVar2 = uVar5 + uVar2;
              uVar4 = uVar4 << (uVar5 & 0x3f);
              uVar3 = uVar3 << (uVar5 & 0x3f);
            }
            uVar4 = uVar4 * 2;
            uVar3 = uVar3 * 2;
            uVar2 = uVar2 + 1;
          } while ((int)uVar2 <= *(int *)(param_1 + 0x38));
        }
      }
      puVar8 = (undefined *)((int)puVar8 + 4);
      puVar7 = (undefined *)((int)puVar7 + 4);
      uVar5 = uVar5 + 1;
      iVar6 = *(int *)(param_1 + 0x38);
    } while ((int)uVar5 < iVar6);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1021 start=0x403919e */

bool _badblock(int param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = *(uint *)(param_1 + 0x24) <= param_2;
  if (bVar1) {
    _printf(aBadBlockD,param_2);
    _fserr(param_1,aBadBlock);
  }
  return bVar1;
}
/* GHIDRADEC_FUNCTION index=1022 start=0x40391dc */

int _isblock(int param_1,int param_2,uint param_3)

{
  int iVar1;
  byte bVar2;
  bool bVar3;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 == 2) {
    bVar2 = (byte)(3 << (param_3 & 3) * 2);
    iVar1 = (int)param_3 >> 2;
  }
  else if (iVar1 < 3) {
    if (iVar1 != 1) {
loc_4039256:
                    /* WARNING: Subroutine does not return */
      _panic(&aIsblock);
    }
    bVar2 = (byte)(1 << (param_3 & 7));
    iVar1 = (int)param_3 >> 3;
  }
  else {
    if (iVar1 != 4) {
      if (iVar1 != 8) goto loc_4039256;
      bVar3 = *(char *)(param_2 + param_3) == -1;
      goto loc_4039250;
    }
    bVar2 = (byte)(0xf << ((param_3 & 1) << 2));
    iVar1 = (int)param_3 >> 1;
  }
  bVar3 = bVar2 == (*(byte *)(param_2 + iVar1) & bVar2);
loc_4039250:
  return -(int)(char)-bVar3;
}
/* GHIDRADEC_FUNCTION index=1023 start=0x4039270 */

void _clrblock(int param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x38);
  if (iVar3 == 2) {
    iVar4 = (int)param_3 >> 2;
    iVar3 = (param_3 & 3) * 2;
    iVar2 = 3;
loc_40392C4:
    *(byte *)(param_2 + iVar4) = ~(byte)(iVar2 << iVar3) & *(byte *)(param_2 + iVar4);
    return;
  }
  if (iVar3 < 3) {
    if (iVar3 == 1) {
      pbVar1 = (byte *)(param_2 + ((int)param_3 >> 3));
      *pbVar1 = ~(byte)(1 << (param_3 & 7)) & *pbVar1;
      return;
    }
  }
  else {
    if (iVar3 == 4) {
      iVar4 = (int)param_3 >> 1;
      iVar3 = (param_3 & 1) << 2;
      iVar2 = 0xf;
      goto loc_40392C4;
    }
    if (iVar3 == 8) {
      *(undefined *)(param_2 + param_3) = 0;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(aClrblock);
}
/* GHIDRADEC_FUNCTION index=1024 start=0x40392fa */

void _setblock(int param_1,int param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x38);
  if (iVar3 == 2) {
    iVar4 = (int)param_3 >> 2;
    iVar3 = (param_3 & 3) * 2;
    iVar2 = 3;
loc_4039350:
    *(byte *)(param_2 + iVar4) = (byte)(iVar2 << iVar3) | *(byte *)(param_2 + iVar4);
    return;
  }
  if (iVar3 < 3) {
    if (iVar3 == 1) {
      pbVar1 = (byte *)(param_2 + ((int)param_3 >> 3));
      *pbVar1 = (byte)(1 << (param_3 & 7)) | *pbVar1;
      return;
    }
  }
  else {
    if (iVar3 == 4) {
      iVar4 = (int)param_3 >> 1;
      iVar3 = (param_3 & 1) << 2;
      iVar2 = 0xf;
      goto loc_4039350;
    }
    if (iVar3 == 8) {
      *(undefined *)(param_2 + param_3) = 0xff;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(aSetblock);
}
/* GHIDRADEC_FUNCTION index=1025 start=0x4039382 */

int _getmp(sword param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _mounttab;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if ((*(int *)(iVar2 + 10) != 0) && (param_1 == *(sword *)(iVar2 + 4))) break;
    iVar2 = *(int *)(iVar2 + 0x1c);
  }
  iVar1 = *(int *)(*(int *)(iVar2 + 10) + 0x20);
  if (*(int *)(iVar1 + 0x55c) == 0x11954) {
    return iVar2;
  }
  _printf(aDev0xXFsS,(int)param_1,iVar1 + 0xd4);
                    /* WARNING: Subroutine does not return */
  _panic(aGetmpBadMagic);
}
/* GHIDRADEC_FUNCTION index=1026 start=0x40393e8 */

void _bufstats(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int aiStack_c [2];
  
  puVar5 = &_bfreelist;
  iVar3 = 0;
  do {
    iVar4 = 0;
    for (iVar2 = 0; iVar2 <= 0x2000 / _m68k_page_size; iVar2 = iVar2 + 1) {
      aiStack_c[iVar2] = 0;
    }
    for (puVar1 = (undefined4 *)puVar5[3]; puVar5 != puVar1; puVar1 = (undefined4 *)puVar1[3]) {
      aiStack_c[(int)puVar1[6] / _m68k_page_size] = aiStack_c[(int)puVar1[6] / _m68k_page_size] + 1;
      iVar4 = iVar4 + 1;
    }
    _printf(aSTotalD,*(undefined4 *)(unk_40AF326 + iVar3 * 4),iVar4);
    for (iVar2 = 0; iVar2 <= 0x2000 / _m68k_page_size; iVar2 = iVar2 + 1) {
      if (aiStack_c[iVar2] != 0) {
        _printf(&aDD,iVar2 * _m68k_page_size,aiStack_c[iVar2]);
      }
    }
    _printf(&asc_40A6049);
    puVar5 = puVar5 + 0x11;
    iVar3 = iVar3 + 1;
  } while (puVar5 < &_buf);
  return;
}
/* GHIDRADEC_FUNCTION index=1027 start=0x40394d0 */

int _scanc(int param_1,byte *param_2,int param_3,byte param_4)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = param_2 + param_1;
  if (param_2 < pbVar2) {
    bVar1 = *(byte *)(param_3 + (uint)*param_2);
    while (((param_4 & bVar1) == 0 && (param_2 = param_2 + 1, param_2 < pbVar2))) {
      bVar1 = *(byte *)(param_3 + (uint)*param_2);
    }
  }
  return (int)pbVar2 - (int)param_2;
}
/* GHIDRADEC_FUNCTION index=1028 start=0x403951c */

int _skpc(char param_1,int param_2,char *param_3)

{
  char *pcVar1;
  
  pcVar1 = param_3 + param_2;
  for (; (param_3 < pcVar1 && (param_1 == *param_3)); param_3 = param_3 + 1) {
  }
  return (int)pcVar1 - (int)param_3;
}
/* GHIDRADEC_FUNCTION index=1029 start=0x4039542 */

int _locc(char param_1,int param_2,char *param_3)

{
  char *pcVar1;
  
  pcVar1 = param_3 + param_2;
  for (; (param_3 < pcVar1 && (param_1 != *param_3)); param_3 = param_3 + 1) {
  }
  return (int)pcVar1 - (int)param_3;
}
/* GHIDRADEC_FUNCTION index=1030 start=0x4039e24 */

void _sbupdate(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *(int *)(*(int *)(param_1 + 10) + 0x20);
  iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 6) + 0x1c) + 0x80))(*(int *)(param_1 + 6));
  if (-1 < iVar2) {
    iVar2 = _getblk(*(undefined4 *)(param_1 + 6),0x2000 / iVar2,*(undefined4 *)(iVar1 + 0x68));
    _bcopy(iVar1,*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar1 + 0x68));
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x8c) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x88) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x94) = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x90) = 0;
    *(undefined *)(*(int *)(iVar2 + 0x20) + 0xd3) = 0;
    _bwrite(iVar2);
    iVar6 = (*(int *)(iVar1 + 0x34) + *(int *)(iVar1 + 0x9c) + -1) / *(int *)(iVar1 + 0x34);
    iVar2 = *(int *)(iVar1 + 0x2d8);
    iVar5 = 0;
    if (0 < iVar6) {
      do {
        iVar4 = *(int *)(iVar1 + 0x30);
        if (iVar6 < *(int *)(iVar1 + 0x38) + iVar5) {
          iVar4 = *(int *)(iVar1 + 0x34) * (iVar6 - iVar5);
        }
        iVar3 = _getblk(*(undefined4 *)(param_1 + 6),
                        iVar5 + *(int *)(iVar1 + 0x98) << (*(uint *)(iVar1 + 100) & 0x3f),iVar4);
        _bcopy(iVar2,*(undefined4 *)(iVar3 + 0x20),iVar4);
        iVar2 = iVar4 + iVar2;
        _bwrite(iVar3);
        iVar5 = *(int *)(iVar1 + 0x38) + iVar5;
      } while (iVar5 < iVar6);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1031 start=0x403b6a2 */

undefined4
_rdwri(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
      undefined4 param_6,int *param_7)

{
  undefined4 uVar1;
  undefined4 uStack_22;
  int iStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  uStack_22 = param_3;
  iStack_1e = param_4;
  puStack_1a = &uStack_22;
  uStack_16 = 1;
  uStack_12 = param_5;
  uStack_e = param_6;
  iStack_8 = param_4;
  uVar1 = sub_403A0F2(param_2 + 0xc,&puStack_1a,param_1,0,*(undefined4 *)(_active_u + 0x1a));
  if (param_7 == (int *)0x0) {
    if (iStack_8 != 0) {
      uVar1 = 5;
    }
  }
  else {
    *param_7 = iStack_8;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1032 start=0x403bfda */

undefined4 _ufs_nlinks(int param_1,int *param_2)

{
  *param_2 = (int)*(sword *)(*(int *)(param_1 + 0x2e) + 100);
  return 0;
}
/* GHIDRADEC_FUNCTION index=1033 start=0x403bff6 */

undefined4 _ipc_entry_tree_collision(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uStack_c;
  uint uStack_8;
  
  _ipc_splay_tree_bounds(param_1 + 0x18,param_2,&uStack_8,&uStack_c);
  uVar1 = 0;
  if (((uStack_8 != 0xffffffff) && (param_2 >> 8 == uStack_8 >> 8)) ||
     ((uStack_c != 0 && (param_2 >> 8 == uStack_c >> 8)))) {
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1034 start=0x403c04a */

uint * _ipc_entry_lookup(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  
  if (param_2 >> 8 < *(uint *)(param_1 + 0x10)) {
    puVar2 = (uint *)((param_2 >> 8) * 0x10 + *(int *)(param_1 + 0xc));
    uVar1 = *puVar2;
    if (param_2 << 0x18 == (uVar1 & 0xff000000)) {
      if ((uVar1 & 0x1f0000) == 0) {
        return (uint *)0x0;
      }
      return puVar2;
    }
    uVar1 = uVar1 & 0x800000;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x30);
  }
  if (uVar1 == 0) {
    return (uint *)0x0;
  }
  puVar2 = (uint *)_ipc_splay_tree_lookup(param_1 + 0x18,param_2);
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=1035 start=0x403c0b6 */

undefined4 _ipc_entry_get(int param_1,uint *param_2,int *param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = *(int *)(param_1 + 0xc);
  iVar4 = *(int *)(iVar3 + 8);
  if (iVar4 == 0) {
    uVar5 = 3;
  }
  else {
    puVar1 = (uint *)(iVar3 + iVar4 * 0x10);
    *(uint *)(iVar3 + 8) = puVar1[2];
    uVar2 = *puVar1;
    *puVar1 = uVar2 + 0x1000000;
    puVar1[2] = 0;
    *param_2 = uVar2 + 0x1000000 >> 0x18 | iVar4 << 8;
    *param_3 = (int)puVar1;
    uVar5 = 0;
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=1036 start=0x403c10c */

int _ipc_entry_alloc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  while( true ) {
    if (*(int *)(param_1 + 4) == 0) {
      return 0x10;
    }
    iVar1 = _ipc_entry_get(param_1,param_2,param_3);
    if (iVar1 == 0) break;
    iVar1 = _ipc_entry_grow_table(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1037 start=0x403c15a */

int _ipc_entry_alloc_name(int param_1,uint param_2,int *param_3)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  uVar6 = param_2 >> 8;
  puVar7 = (undefined4 *)0x0;
  do {
    while( true ) {
      if (*(int *)(param_1 + 4) == 0) {
        if (puVar7 != (undefined4 *)0x0) {
          _zfree(_ipc_tree_entry_zone,puVar7);
        }
        return 0x10;
      }
      if ((uVar6 != 0) && (uVar6 < *(uint *)(param_1 + 0x10))) {
        iVar5 = *(int *)(param_1 + 0xc);
        puVar1 = (uint *)(iVar5 + uVar6 * 0x10);
        if ((*puVar1 & 0x1f0000) == 0) {
          uVar3 = 0;
          for (uVar4 = *(uint *)(iVar5 + 8); uVar6 != uVar4;
              uVar4 = *(uint *)(iVar5 + 8 + uVar4 * 0x10)) {
            uVar3 = uVar4;
          }
          *(undefined4 *)(iVar5 + 8 + uVar3 * 0x10) = *(undefined4 *)(iVar5 + 8 + uVar4 * 0x10);
          *puVar1 = param_2 << 0x18;
          puVar1[2] = 0;
          *param_3 = (int)puVar1;
          if (puVar7 != (undefined4 *)0x0) {
            _zfree(_ipc_tree_entry_zone,puVar7);
          }
          return 0;
        }
        if (param_2 << 0x18 == (*puVar1 & 0xff000000)) {
          *param_3 = (int)puVar1;
          if (puVar7 == (undefined4 *)0x0) {
            return 0;
          }
          _zfree(_ipc_tree_entry_zone,puVar7);
          return 0;
        }
      }
      if ((*(int *)(param_1 + 0x30) != 0) &&
         (iVar5 = _ipc_splay_tree_lookup(param_1 + 0x18,param_2), iVar5 != 0)) {
        *param_3 = iVar5;
        if (puVar7 == (undefined4 *)0x0) {
          return 0;
        }
        _zfree(_ipc_tree_entry_zone,puVar7);
        return 0;
      }
      if (((uVar6 < *(uint *)(param_1 + 0x10)) ||
          (uVar3 = **(uint **)(param_1 + 0x14), uVar3 <= uVar6)) ||
         ((uint)((*(int *)(param_1 + 0x34) + 1) * 0x20) <=
          (uVar3 - *(uint *)(param_1 + 0x10)) * 0x10)) break;
      iVar5 = _ipc_entry_grow_table(param_1);
      if (iVar5 != 0) {
        if (puVar7 != (undefined4 *)0x0) {
          _zfree(_ipc_tree_entry_zone,puVar7);
          return iVar5;
        }
        return iVar5;
      }
    }
    if (puVar7 != (undefined4 *)0x0) {
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
      if (uVar6 < *(uint *)(param_1 + 0x10)) {
        pbVar2 = (byte *)(*(int *)(param_1 + 0xc) + 1 + uVar6 * 0x10);
        *pbVar2 = *pbVar2 | 0x80;
      }
      else if ((uVar6 < **(uint **)(param_1 + 0x14)) &&
              (iVar5 = _ipc_entry_tree_collision(param_1,param_2), iVar5 == 0)) {
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
      }
      _ipc_splay_tree_insert(param_1 + 0x18,param_2,puVar7);
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7[5] = param_1;
      *param_3 = (int)puVar7;
      return 0;
    }
    puVar7 = (undefined4 *)_zalloc(_ipc_tree_entry_zone);
  } while (puVar7 != (undefined4 *)0x0);
  return 6;
}
/* GHIDRADEC_FUNCTION index=1038 start=0x403c314 */

void _ipc_entry_dealloc(int param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puStack_3c;
  int iStack_38;
  undefined auStack_34 [24];
  undefined auStack_1c [24];
  
  uVar6 = param_2 >> 8;
  iVar5 = *(int *)(param_1 + 0xc);
  uVar1 = *(uint *)(param_1 + 0x10);
  if ((uVar6 < uVar1) && ((uint *)(iVar5 + uVar6 * 0x10) == param_3)) {
    if ((*param_3 & 0x800000) == 0) {
      *param_3 = *param_3 & 0xff000000;
      param_3[2] = *(uint *)(iVar5 + 8);
      *(uint *)(iVar5 + 8) = uVar6;
    }
    else {
      iVar5 = param_1 + 0x18;
      _ipc_splay_tree_split(iVar5,uVar6 * 0x100 + 0x100,auStack_34);
      _ipc_splay_tree_split(auStack_34,uVar6 << 8,auStack_1c);
      _ipc_splay_tree_pick(auStack_34,&iStack_38,&puStack_3c);
      uVar1 = *puStack_3c;
      *param_3 = uVar1 | iStack_38 << 0x18;
      uVar2 = puStack_3c[1];
      param_3[1] = uVar2;
      param_3[2] = puStack_3c[2];
      if ((uVar1 & 0x1f0000) == 0x10000) {
        _ipc_hash_global_delete(param_1,uVar2,iStack_38,puStack_3c);
        _ipc_hash_local_insert(param_1,uVar2,uVar6,param_3);
      }
      _ipc_splay_tree_delete(auStack_34,iStack_38,puStack_3c);
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
      iVar4 = _ipc_splay_tree_pick(auStack_34,&iStack_38,&puStack_3c);
      if (iVar4 != 0) {
        *(byte *)((int)param_3 + 1) = *(byte *)((int)param_3 + 1) | 0x80;
        _ipc_splay_tree_join(iVar5,auStack_34);
      }
      _ipc_splay_tree_join(iVar5,auStack_1c);
    }
  }
  else {
    _ipc_splay_tree_delete(param_1 + 0x18,param_2,param_3);
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
    if (uVar6 < uVar1) {
      iVar4 = _ipc_entry_tree_collision(param_1,param_2);
      if (iVar4 == 0) {
        pbVar3 = (byte *)(uVar6 * 0x10 + iVar5 + 1);
        *pbVar3 = *pbVar3 & 0x7f;
      }
    }
    else if (uVar6 < **(uint **)(param_1 + 0x14)) {
      iVar5 = _ipc_entry_tree_collision(param_1,param_2);
      if (iVar5 == 0) {
        *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + -1;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1039 start=0x403c4a0 */

undefined4 _ipc_entry_grow_table(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  undefined auStack_4c [24];
  undefined auStack_34 [24];
  undefined auStack_1c [24];
  
  while( true ) {
    if (*(int *)(param_1 + 8) != 0) {
      _assert_wait(param_1,0);
      _thread_block_with_continuation(0);
      return 0;
    }
    uVar5 = *(undefined4 *)(param_1 + 0xc);
    puVar10 = *(uint **)(param_1 + 0x14);
    uVar2 = *puVar10;
    puVar7 = puVar10 + -1;
    uVar3 = *puVar7;
    puVar8 = puVar10 + 1;
    uVar4 = *puVar8;
    if (uVar2 == uVar3) {
      return 3;
    }
    *(undefined4 *)(param_1 + 8) = 1;
    if (*puVar7 << 4 < _page_size) {
      puVar9 = (uint *)_ipc_table_alloc(*puVar10 << 4);
    }
    else {
      puVar9 = (uint *)_ipc_table_realloc(*puVar7 << 4,uVar5,*puVar10 << 4);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    if (puVar9 == (uint *)0x0) {
      _thread_wakeup_prim(param_1,0,0);
      return 6;
    }
    if (*(int *)(param_1 + 4) == 0) {
      _thread_wakeup_prim(param_1,0,0);
      _ipc_table_free(*puVar10 << 4,puVar9);
      return 0;
    }
    *(uint **)(param_1 + 0xc) = puVar9;
    *(uint *)(param_1 + 0x10) = uVar2;
    *(uint **)(param_1 + 0x14) = puVar8;
    if (*puVar7 << 4 < _page_size) {
      _bcopy(uVar5,puVar9,uVar3 << 4);
    }
    uVar14 = 0;
    if (uVar3 != 0) {
      do {
        puVar9[uVar14 * 4 + 3] = 0;
        uVar14 = uVar14 + 1;
      } while (uVar14 < uVar3);
    }
    _bzero(puVar9 + uVar3 * 4,(uVar2 - uVar3) * 0x10);
    uVar14 = 0;
    puVar10 = puVar9;
    if (uVar3 != 0) {
      do {
        if ((*puVar10 & 0x1f0000) == 0x10000) {
          _ipc_hash_local_insert(param_1,puVar10[1],uVar14,puVar10);
        }
        uVar14 = uVar14 + 1;
        puVar10 = puVar10 + 4;
      } while (uVar14 < uVar3);
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      _ipc_splay_tree_split(param_1 + 0x18,uVar4 << 8,auStack_4c);
      _ipc_splay_tree_split(auStack_4c,uVar2 << 8,auStack_34);
      _ipc_splay_tree_split(auStack_34,uVar3 << 8,auStack_1c);
      puVar10 = (uint *)_ipc_splay_traverse_start(auStack_34);
      while (puVar10 != (uint *)0x0) {
        uVar14 = puVar10[4];
        puVar1 = puVar9 + (uVar14 >> 8) * 4;
        if (*puVar1 == 0) {
          uVar13 = *puVar10;
          *puVar1 = uVar14 << 0x18 | uVar13;
          uVar6 = puVar10[1];
          puVar1[1] = uVar6;
          puVar1[2] = puVar10[2];
          if ((uVar13 & 0x1f0000) == 0x10000) {
            _ipc_hash_global_delete(param_1,uVar6,uVar14,puVar10);
            _ipc_hash_local_insert(param_1,uVar6,uVar14 >> 8,puVar1);
          }
          *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
          uVar11 = 1;
        }
        else {
          *puVar1 = *puVar1 | 0x800000;
          uVar11 = 0;
        }
        puVar10 = (uint *)_ipc_splay_traverse_next(auStack_34,uVar11);
      }
      _ipc_splay_traverse_finish(auStack_34);
      iVar15 = 0;
      uVar14 = 0;
      iVar12 = _ipc_splay_traverse_start(auStack_4c);
      while (iVar12 != 0) {
        uVar13 = *(uint *)(iVar12 + 0x10) >> 8;
        if (uVar14 != uVar13) {
          iVar15 = iVar15 + 1;
          uVar14 = uVar13;
        }
        iVar12 = _ipc_splay_traverse_next(auStack_4c,0);
      }
      _ipc_splay_traverse_finish(auStack_4c);
      *(int *)(param_1 + 0x34) = iVar15;
      iVar15 = param_1 + 0x18;
      _ipc_splay_tree_join(iVar15,auStack_4c);
      _ipc_splay_tree_join(iVar15,auStack_34);
      _ipc_splay_tree_join(iVar15,auStack_1c);
    }
    uVar14 = puVar9[2];
    uVar13 = uVar2 - 1;
    if (uVar3 <= uVar13) {
      puVar10 = puVar9 + uVar13 * 4;
      do {
        if (*puVar10 == 0) {
          *puVar10 = 0xff000000;
          puVar10[2] = uVar14;
          uVar14 = uVar13;
        }
        puVar10 = puVar10 + -4;
        uVar13 = uVar13 - 1;
      } while (uVar3 <= uVar13);
    }
    puVar9[2] = uVar14;
    _thread_wakeup_prim(param_1,0,0);
    _ipc_table_free(*puVar7 << 4,uVar5);
    if (*(int *)(param_1 + 4) == 0) break;
    if (puVar8 != *(uint **)(param_1 + 0x14)) {
      return 0;
    }
    if (*(int *)(param_1 + 0x34) == 0) {
      return 0;
    }
    if ((uint)(*(int *)(param_1 + 0x34) << 5) <= (uVar4 - uVar2) * 0x10) {
      return 0;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1040 start=0x403c7e4 */

undefined4 _ipc_hash_lookup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = _ipc_hash_local_lookup(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x38) == 0) {
      return 0;
    }
    iVar1 = _ipc_hash_global_lookup(param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=1041 start=0x403c83a */

void _ipc_hash_insert(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_3 >> 8;
  if ((uVar1 < *(uint *)(param_1 + 0x10)) && (*(int *)(param_1 + 0xc) + uVar1 * 0x10 == param_4)) {
    _ipc_hash_local_insert(param_1,param_2,uVar1,param_4);
  }
  else {
    _ipc_hash_global_insert(param_1,param_2,param_3,param_4);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1042 start=0x403c892 */

void _ipc_hash_delete(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = param_3 >> 8;
  if ((uVar1 < *(uint *)(param_1 + 0x10)) && (*(int *)(param_1 + 0xc) + uVar1 * 0x10 == param_4)) {
    _ipc_hash_local_delete(param_1,param_2,uVar1,param_4);
  }
  else {
    _ipc_hash_global_delete(param_1,param_2,param_3,param_4);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1043 start=0x403c8ea */

int _ipc_hash_global_lookup(uint param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)(_ipc_hash_global_table +
                  (_ipc_hash_global_mask & (param_2 >> 6) + (param_1 >> 4)) * 4);
  iVar3 = *piVar1;
  if (iVar3 != 0) {
    if ((param_2 != *(uint *)(iVar3 + 4)) || (param_1 != *(uint *)(iVar3 + 0x14))) {
      do {
        piVar2 = (int *)(iVar3 + 0xc);
        iVar3 = *piVar2;
        if (iVar3 == 0) goto loc_403C958;
      } while ((param_2 != *(uint *)(iVar3 + 4)) || (param_1 != *(uint *)(iVar3 + 0x14)));
      *piVar2 = *(int *)(iVar3 + 0xc);
      *(int *)(iVar3 + 0xc) = *piVar1;
      *piVar1 = iVar3;
    }
    *param_3 = *(undefined4 *)(iVar3 + 0x10);
    *param_4 = iVar3;
  }
loc_403C958:
  return -(int)-(iVar3 != 0);
}
/* GHIDRADEC_FUNCTION index=1044 start=0x403c96a */

void _ipc_hash_global_insert(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  piVar1 = (int *)(_ipc_hash_global_table +
                  (_ipc_hash_global_mask & (param_2 >> 6) + (param_1 >> 4)) * 4);
  *(int *)(param_4 + 0xc) = *piVar1;
  *piVar1 = param_4;
  return;
}
/* GHIDRADEC_FUNCTION index=1045 start=0x403c9a0 */

void _ipc_hash_global_delete(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
  piVar2 = (int *)(_ipc_hash_global_table +
                  (_ipc_hash_global_mask & (param_2 >> 6) + (param_1 >> 4)) * 4);
  while( true ) {
    iVar1 = *piVar2;
    if (iVar1 == 0) {
      return;
    }
    if (param_4 == iVar1) break;
    piVar2 = (int *)(iVar1 + 0xc);
  }
  *piVar2 = *(int *)(iVar1 + 0xc);
  return;
}
/* GHIDRADEC_FUNCTION index=1046 start=0x403c9ec */

undefined4 _ipc_hash_local_lookup(int param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (param_2 >> 6) % *(uint *)(param_1 + 0x10);
  while( true ) {
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0xc + uVar3 * 0x10);
    if (iVar2 == 0) {
      return 0;
    }
    puVar1 = (undefined *)(*(int *)(param_1 + 0xc) + iVar2 * 0x10);
    if (param_2 == *(uint *)(puVar1 + 4)) break;
    uVar3 = uVar3 + 1;
    if (*(uint *)(param_1 + 0x10) == uVar3) {
      uVar3 = 0;
    }
  }
  *param_3 = CONCAT31((int3)iVar2,*puVar1);
  *param_4 = (int)puVar1;
  return 1;
}
/* GHIDRADEC_FUNCTION index=1047 start=0x403ca50 */

void _ipc_hash_local_insert(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (param_2 >> 6) % *(uint *)(param_1 + 0x10);
  while (*(int *)(*(int *)(param_1 + 0xc) + 0xc + uVar1 * 0x10) != 0) {
    uVar1 = uVar1 + 1;
    if (*(uint *)(param_1 + 0x10) == uVar1) {
      uVar1 = 0;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc + uVar1 * 0x10) = param_3;
  return;
}
/* GHIDRADEC_FUNCTION index=1048 start=0x403ca92 */

void _ipc_hash_local_delete(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0xc);
  uVar2 = *(uint *)(param_1 + 0x10);
  uVar5 = (param_2 >> 6) % uVar2;
  while (param_3 != *(int *)(iVar1 + 0xc + uVar5 * 0x10)) {
    uVar5 = uVar5 + 1;
    if (uVar2 == uVar5) {
      uVar5 = 0;
    }
  }
  do {
    uVar4 = uVar5;
    if (param_3 == 0) {
      return;
    }
    do {
      while( true ) {
        uVar4 = uVar4 + 1;
        if (uVar2 == uVar4) {
          uVar4 = 0;
        }
        param_3 = *(int *)(iVar1 + 0xc + uVar4 * 0x10);
        if (param_3 == 0) goto loc_403CB04;
        uVar3 = (*(uint *)(iVar1 + 4 + param_3 * 0x10) >> 6) % uVar2;
        if (uVar4 < uVar5) break;
        if ((uVar4 < uVar3) || (uVar3 <= uVar5)) goto loc_403CB04;
      }
    } while ((uVar3 <= uVar4) || (uVar5 < uVar3));
loc_403CB04:
    *(int *)(iVar1 + 0xc + uVar5 * 0x10) = param_3;
    uVar5 = uVar4;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1049 start=0x403cb1c */

void _ipc_hash_init(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((_ipc_hash_global_size == 0) &&
     (_ipc_hash_global_size = _ipc_tree_entry_max >> 8, _ipc_hash_global_size < 0x20)) {
    _ipc_hash_global_size = 0x20;
  }
  _ipc_hash_global_mask = _ipc_hash_global_size - 1;
  if ((_ipc_hash_global_mask & _ipc_hash_global_size) != 0) {
    uVar3 = 1;
    while( true ) {
      _ipc_hash_global_mask = uVar3 | _ipc_hash_global_mask;
      _ipc_hash_global_size = _ipc_hash_global_mask + 1;
      if ((_ipc_hash_global_mask & _ipc_hash_global_size) == 0) break;
      uVar3 = uVar3 * 2;
    }
  }
  puVar2 = (undefined4 *)_kalloc(_ipc_hash_global_size << 2);
  uVar1 = _ipc_hash_global_size;
  uVar3 = 0;
  _ipc_hash_global_table = puVar2;
  if (_ipc_hash_global_size != 0) {
    do {
      *puVar2 = 0;
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar3 < uVar1);
  }
  return;
}

