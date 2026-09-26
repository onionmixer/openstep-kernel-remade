
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

