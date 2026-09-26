
/* WARNING: Removing unreachable block (ram,0xf004e0c8) */
/* WARNING: Removing unreachable block (ram,0xf004e058) */
/* WARNING: Removing unreachable block (ram,0xf004dfe0) */
/* WARNING: Removing unreachable block (ram,0xf004dfb0) */
/* WARNING: Removing unreachable block (ram,0xf004df7c) */
/* WARNING: Removing unreachable block (ram,0xf004df10) */
/* WARNING: Removing unreachable block (ram,0xf004de8c) */
/* WARNING: Removing unreachable block (ram,0xf004de38) */
/* WARNING: Removing unreachable block (ram,0xf004dde4) */
/* WARNING: Removing unreachable block (ram,0xf004dd00) */
/* WARNING: Removing unreachable block (ram,0xf004dd1c) */
/* WARNING: Removing unreachable block (ram,0xf004dea8) */
/* WARNING: Removing unreachable block (ram,0xf004de54) */
/* WARNING: Removing unreachable block (ram,0xf004dee4) */
/* WARNING: Removing unreachable block (ram,0xf004df6c) */
/* WARNING: Removing unreachable block (ram,0xf004df94) */
/* WARNING: Removing unreachable block (ram,0xf004dfb8) */
/* WARNING: Removing unreachable block (ram,0xf004dffc) */
/* WARNING: Removing unreachable block (ram,0xf004e0b0) */
/* WARNING: Removing unreachable block (ram,0xf004e174) */
/* WARNING: Removing unreachable block (ram,0xf004dce8) */

undefined8 _iget(sword param_1,int param_2,int *param_3)

{
  word wVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_l0;
  int *piVar9;
  uint uVar10;
  undefined4 unaff_l1;
  int *piVar11;
  undefined4 uVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar13;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
loc_F004DCE4:
  do {
    piVar9 = (int *)(int)param_1;
    piVar3 = piVar9;
    _getmp();
    if (piVar3 == (int *)0x0) {
      _panic(aIgetBadDev);
      iVar5 = iRam0000000c;
    }
    else {
      iVar5 = piVar3[3];
    }
    if (*(int *)(iVar5 + 0x20) != param_2) {
      _panic(aIgetBadFs);
    }
    iVar5 = ((uint)((int)piVar9 + (int)param_3) & 0x1ff) * 8;
    puVar4 = _ihead;
    piVar13 = *(int **)(_ihead + iVar5);
    piVar11 = (int *)(_ihead + iVar5);
    if (piVar13 != piVar11) {
      puVar4 = (undefined *)piVar13[0x12];
      while( true ) {
        if (param_3 == (int *)puVar4) {
          puVar4 = (undefined *)(int)*(sword *)((int)piVar13 + 0x46);
          if (piVar9 == (int *)puVar4) {
            wVar1 = *(word *)(piVar13 + 0x11);
            if ((wVar1 & 1) == 0) {
              if ((wVar1 & 0x100) == 0) {
                iVar5 = piVar13[0x17];
                piVar3 = (int *)piVar13[0x18];
                if (iVar5 != 0) {
                  *(int **)(iVar5 + 0x60) = (int *)piVar13[0x18];
                  piVar3 = _ifreet;
                }
                _ifreet = piVar3;
                *(int *)piVar13[0x18] = iVar5;
                piVar13[0x17] = 0;
                piVar13[0x18] = 0;
                *(undefined4 *)piVar13[3] = 0;
                wVar1 = *(word *)(piVar13 + 0x11);
              }
              *(word *)(piVar13 + 0x11) = wVar1 | 0x100;
              while ((wVar1 & 1) != 0) {
                *(word *)(piVar13 + 0x11) = *(word *)(piVar13 + 0x11) | 0x10;
                _sleep(piVar13,10);
                wVar1 = *(word *)(piVar13 + 0x11);
              }
              *(word *)(piVar13 + 0x11) = *(word *)(piVar13 + 0x11) | 1;
              *(sword *)((int)piVar13 + 0x12) = *(sword *)((int)piVar13 + 0x12) + 1;
              goto locret_F004E190;
            }
            *(word *)(piVar13 + 0x11) = wVar1 | 0x10;
            _sleep(piVar13,10);
            goto loc_F004DCE4;
          }
          piVar13 = (int *)*piVar13;
        }
        else {
          piVar13 = (int *)*piVar13;
        }
        if (piVar13 == piVar11) break;
        puVar4 = (undefined *)piVar13[0x12];
      }
    }
    if (_ifreeh != (int *)0x0) {
      piVar9 = (int *)_ifreeh[0x17];
      piVar13 = _ifreeh;
      goto loc_F004DEC0;
    }
    _new_inode();
    if ((int *)puVar4 != (int *)0x0) {
      *(int **)((int)puVar4 + 0x5c) = _ifreeh;
      piVar9 = *(int **)((int)puVar4 + 0x5c);
      piVar13 = (int *)puVar4;
      goto loc_F004DEC0;
    }
    do {
      if (_ifreeh != (int *)0x0) break;
      piVar9 = _ifreeh;
      _dnlc_purge1();
    } while (piVar9 == (int *)0x1);
    piVar13 = _ifreeh;
  } while (_ifreeh != (int *)0x0);
  _panic(aIgetOutOfInode);
  piVar9 = piRam0000005c;
loc_F004DEC0:
  if (piVar9 != (int *)0x0) {
    piVar9[0x18] = (int)&_ifreeh;
  }
  _ifreeh = piVar9;
  piVar13[0x17] = 0;
  piVar13[0x18] = 0;
  _mfs_uncache(piVar13 + 3);
  *(undefined2 *)(piVar13 + 0x11) = 0x100;
  *(word *)(piVar13 + 0x11) = *(word *)(piVar13 + 0x11) | 1;
  if (*(sword *)((int)piVar13 + 0x12) != 0) {
    _panic(aFreeInodeIsnT_0);
  }
  *(int *)(*piVar13 + 4) = piVar13[1];
  *(int *)piVar13[1] = *piVar13;
  *piVar13 = *piVar11;
  piVar13[1] = (int)piVar11;
  *(int **)(*piVar11 + 4) = piVar13;
  *piVar11 = (int)piVar13;
  *(sword *)((int)piVar13 + 0x46) = param_1;
  piVar13[0x10] = piVar3[2];
  piVar13[0x12] = (int)param_3;
  piVar13[0x13] = 0;
  piVar13[0x14] = param_2;
  piVar13[0x16] = 0;
  uVar12 = *(undefined4 *)(param_2 + 0xb8);
  piVar9 = param_3;
  .udiv(param_3,uVar12);
  iVar5 = *(int *)(param_2 + 0xbc);
  .umul(iVar5,piVar9);
  iVar7 = *(int *)(param_2 + 0x18);
  .umul(iVar7,(uint)piVar9 & ~*(uint *)(param_2 + 0x1c));
  iVar8 = *(int *)(param_2 + 0x10);
  piVar9 = param_3;
  .urem(param_3,uVar12);
  .udiv();
  puVar6 = (uint *)piVar13[0x10];
  _bread(puVar6,iVar5 + iVar7 + iVar8 +
                ((int)piVar9 << ((byte)*(undefined4 *)(param_2 + 0x60) & 0x1f)) <<
                ((byte)*(undefined4 *)(param_2 + 100) & 0x1f),*(undefined4 *)(param_2 + 0x30));
  if ((*puVar6 & 4) == 0) {
    uVar10 = puVar6[8];
    piVar9 = param_3;
    .urem(param_3,*(undefined4 *)(param_2 + 0x78));
    _memcpy(piVar13 + 0x19,uVar10 + (int)piVar9 * 0x80,0x80);
    *(undefined2 *)(piVar13 + 4) = 0;
    *(undefined2 *)((int)piVar13 + 0x12) = 1;
    *(undefined2 *)((int)piVar13 + 0x16) = 0;
    *(undefined2 *)(piVar13 + 5) = 0;
    piVar13[0xc] = *piVar3;
    piVar13[0xd] = *(int *)(_iftovt_tab + (uint)(*(word *)(piVar13 + 0x19) >> 0xd) * 4);
    piVar13[0xb] = 0;
    piVar13[9] = 0;
    piVar13[8] = 0;
    *(sword *)(piVar13 + 0xe) = (sword)piVar13[0x23];
    if (param_3 == (int *)0x2) {
      *(word *)(piVar13 + 4) = *(word *)(piVar13 + 4) | 1;
    }
    if (*(sword *)(piVar13[0xc] + 0x124) != 0) {
      *(undefined2 *)(piVar13 + 0x39) = *(undefined2 *)(piVar13 + 0x1a);
      *(undefined2 *)((int)piVar13 + 0xe6) = *(undefined2 *)((int)piVar13 + 0x6a);
      uVar2 = _nogroup;
      *(undefined2 *)(piVar13 + 0x1a) = *(undefined2 *)(piVar13[0xc] + 0x124);
      *(undefined2 *)((int)piVar13 + 0x6a) = uVar2;
    }
    _brelse(puVar6);
    *(undefined4 *)piVar13[3] = 0;
    *(int *)(piVar13[3] + 0x14) = piVar13[0x1c];
  }
  else {
    _brelse(puVar6);
    *(int *)(*piVar13 + 4) = piVar13[1];
    *(int *)piVar13[1] = *piVar13;
    *piVar13 = (int)piVar13;
    piVar13[1] = (int)piVar13;
    piVar13[0x12] = 0;
    *(undefined2 *)((int)piVar13 + 0x12) = 0;
    wVar1 = *(word *)(piVar13 + 0x11);
    *(word *)(piVar13 + 0x11) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(piVar13 + 0x11) = wVar1 & 0xffee;
      _wakeup(piVar13);
    }
    piVar3 = _ifreeh;
    *(undefined2 *)(piVar13 + 0x11) = 0;
    piVar9 = (int *)&_ifreeh;
    piVar11 = piVar13;
    if (piVar3 != (int *)0x0) {
      *_ifreet = (int)piVar13;
      piVar9 = _ifreet;
      piVar11 = _ifreeh;
    }
    _ifreeh = piVar11;
    piVar13[0x18] = (int)piVar9;
    piVar13[0x17] = 0;
    _ifreet = piVar13 + 0x17;
    piVar13 = (int *)0x0;
  }
locret_F004E190:
  return CONCAT44(param_2,piVar13);
}
