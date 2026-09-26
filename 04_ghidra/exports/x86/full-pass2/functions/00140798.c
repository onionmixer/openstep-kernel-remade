/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140798 */

int * _iget(short param_1,int param_2,uint param_3)

{
  int *piVar1;
  ushort uVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  int *piVar8;
  
LAB_001407a9:
  do {
    piVar3 = (int *)_getmp((int)param_1);
    piVar8 = _ifreeh;
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_iget__bad_dev_001ddfd2);
    }
    if (*(int *)(piVar3[3] + 0x20) != param_2) {
                    /* WARNING: Subroutine does not return */
      _panic(s_iget__bad_fs_001ddfe0);
    }
    uVar4 = param_3 + (int)param_1 & 0x1ff;
    piVar1 = &_ihead + uVar4 * 2;
    for (piVar5 = (int *)(&_ihead)[uVar4 * 2]; piVar5 != piVar1; piVar5 = (int *)*piVar5) {
      if ((piVar5[0x12] == param_3) && (*(short *)((int)piVar5 + 0x46) == param_1)) {
        uVar2 = *(ushort *)(piVar5 + 0x11);
        if ((uVar2 & 1) == 0) {
          if ((uVar2 & 0x100) == 0) {
            iVar6 = piVar5[0x17];
            if (iVar6 == 0) {
              _ifreet = (int *)piVar5[0x18];
            }
            else {
              *(int *)(iVar6 + 0x60) = piVar5[0x18];
            }
            *(int *)piVar5[0x18] = iVar6;
            piVar5[0x17] = 0;
            piVar5[0x18] = 0;
            *(undefined4 *)piVar5[3] = 0;
          }
          uVar2 = *(ushort *)(piVar5 + 0x11);
          *(ushort *)(piVar5 + 0x11) = uVar2 | 0x100;
          if ((uVar2 & 1) != 0) {
            do {
              *(byte *)(piVar5 + 0x11) = *(byte *)(piVar5 + 0x11) | 0x10;
              _sleep((uint)piVar5);
            } while ((*(byte *)(piVar5 + 0x11) & 1) != 0);
          }
          *(byte *)(piVar5 + 0x11) = *(byte *)(piVar5 + 0x11) | 1;
          *(short *)((int)piVar5 + 0x12) = *(short *)((int)piVar5 + 0x12) + 1;
          return piVar5;
        }
        *(ushort *)(piVar5 + 0x11) = uVar2 | 0x10;
        _sleep((uint)piVar5);
        goto LAB_001407a9;
      }
    }
    if (_ifreeh != (int *)0x0) {
LAB_00140979:
      _ifreeh = (int *)piVar8[0x17];
      if (_ifreeh != (int *)0x0) {
        _ifreeh[0x18] = (int)&_ifreeh;
      }
      piVar8[0x17] = 0;
      piVar8[0x18] = 0;
      _mfs_uncache(piVar8 + 3);
      *(undefined2 *)(piVar8 + 0x11) = 0x100;
      *(byte *)(piVar8 + 0x11) = *(byte *)(piVar8 + 0x11) | 1;
      if (*(short *)((int)piVar8 + 0x12) == 0) {
        *(int *)(*piVar8 + 4) = piVar8[1];
        *(int *)piVar8[1] = *piVar8;
        *piVar8 = *piVar1;
        piVar8[1] = (int)piVar1;
        *(int **)(*piVar1 + 4) = piVar8;
        *piVar1 = (int)piVar8;
        *(short *)((int)piVar8 + 0x46) = param_1;
        piVar8[0x10] = piVar3[2];
        piVar8[0x12] = param_3;
        piVar8[0x13] = 0;
        piVar8[0x14] = param_2;
        piVar8[0x16] = 0;
        uVar4 = param_3 / *(uint *)(param_2 + 0xb8);
        pbVar7 = (byte *)_bread(piVar8[0x10],
                                *(int *)(param_2 + 0xbc) * uVar4 +
                                (uVar4 & ~*(uint *)(param_2 + 0x1c)) * *(int *)(param_2 + 0x18) +
                                *(int *)(param_2 + 0x10) +
                                ((int)(((ulonglong)param_3 % (ulonglong)*(uint *)(param_2 + 0xb8)) /
                                      (ulonglong)*(uint *)(param_2 + 0x78)) <<
                                ((byte)*(undefined4 *)(param_2 + 0x60) & 0x1f)) <<
                                ((byte)*(undefined4 *)(param_2 + 100) & 0x1f),
                                *(undefined4 *)(param_2 + 0x30));
        if ((*pbVar7 & 4) == 0) {
          _byte_swap_inode_in((param_3 % *(uint *)(param_2 + 0x78)) * 0x80 + *(int *)(pbVar7 + 0x20)
                              ,piVar8);
          *(undefined2 *)(piVar8 + 4) = 0;
          *(undefined2 *)((int)piVar8 + 0x12) = 1;
          *(undefined2 *)((int)piVar8 + 0x16) = 0;
          *(undefined2 *)(piVar8 + 5) = 0;
          piVar8[0xc] = *piVar3;
          piVar8[0xd] = *(int *)(&_iftovt_tab + (uint)(*(ushort *)(piVar8 + 0x19) >> 0xd) * 4);
          *(short *)(piVar8 + 0xe) = (short)piVar8[0x23];
          piVar8[0xb] = 0;
          piVar8[9] = 0;
          piVar8[8] = 0;
          if (param_3 == 2) {
            *(byte *)(piVar8 + 4) = *(byte *)(piVar8 + 4) | 1;
          }
          if (*(short *)(piVar8[0xc] + 0x124) != 0) {
            *(short *)(piVar8 + 0x39) = (short)piVar8[0x1a];
            *(undefined2 *)((int)piVar8 + 0xe6) = *(undefined2 *)((int)piVar8 + 0x6a);
            *(undefined2 *)(piVar8 + 0x1a) = *(undefined2 *)(piVar8[0xc] + 0x124);
            *(undefined2 *)((int)piVar8 + 0x6a) = _nogroup;
          }
          _brelse(pbVar7);
          *(undefined4 *)piVar8[3] = 0;
          *(int *)(piVar8[3] + 0x14) = piVar8[0x1b];
        }
        else {
          _brelse(pbVar7);
          *(int *)(*piVar8 + 4) = piVar8[1];
          *(int *)piVar8[1] = *piVar8;
          *piVar8 = (int)piVar8;
          piVar8[1] = (int)piVar8;
          piVar8[0x12] = 0;
          *(undefined2 *)((int)piVar8 + 0x12) = 0;
          uVar2 = *(ushort *)(piVar8 + 0x11);
          *(ushort *)(piVar8 + 0x11) = uVar2 & 0xfffe;
          if ((uVar2 & 0x10) != 0) {
            *(ushort *)(piVar8 + 0x11) = uVar2 & 0xffee;
            _wakeup(piVar8);
          }
          *(undefined2 *)(piVar8 + 0x11) = 0;
          if (_ifreeh == (int *)0x0) {
            _ifreeh = piVar8;
            piVar8[0x18] = (int)&_ifreeh;
          }
          else {
            *_ifreet = (int)piVar8;
            piVar8[0x18] = (int)_ifreet;
          }
          piVar8[0x17] = 0;
          _ifreet = piVar8 + 0x17;
          piVar8 = (int *)0x0;
        }
        return piVar8;
      }
                    /* WARNING: Subroutine does not return */
      _panic(s_free_inode_isn_t_001de007);
    }
    piVar5 = (int *)_zalloc(_inode_zone);
    if (piVar5 != (int *)0x0) {
      _bzero(piVar5,0xe8);
      *piVar5 = (int)piVar5;
      piVar5[1] = (int)piVar5;
      piVar5[0x17] = 0;
      piVar5[0x18] = 0;
      piVar5[0xf] = (int)piVar5;
      piVar5[10] = (int)&_ufs_vnodeops;
      piVar5[3] = 0;
      _vm_info_init(piVar5 + 3);
      *(byte *)(piVar5[3] + 0x38) = *(byte *)(piVar5[3] + 0x38) & 0xfb;
      piVar5[2] = (int)_inode_list;
      piVar8 = piVar5;
      _inode_list = piVar5;
    }
    if (piVar8 != (int *)0x0) {
      piVar8[0x17] = (int)_ifreeh;
      goto LAB_00140979;
    }
    do {
      if (_ifreeh != (int *)0x0) break;
      iVar6 = _dnlc_purge1();
    } while (iVar6 == 1);
    if (_ifreeh == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_iget__out_of_inode_space_001ddfed);
    }
  } while( true );
}

