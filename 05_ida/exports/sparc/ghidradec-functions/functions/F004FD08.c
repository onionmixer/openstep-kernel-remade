
/* WARNING: Removing unreachable block (ram,0xf004fecc) */
/* WARNING: Removing unreachable block (ram,0xf004fe78) */
/* WARNING: Removing unreachable block (ram,0xf004fe5c) */
/* WARNING: Removing unreachable block (ram,0xf004fde0) */
/* WARNING: Removing unreachable block (ram,0xf004fdcc) */
/* WARNING: Removing unreachable block (ram,0xf004fdd4) */
/* WARNING: Removing unreachable block (ram,0xf004fdf0) */
/* WARNING: Removing unreachable block (ram,0xf004fe70) */
/* WARNING: Removing unreachable block (ram,0xf004fec4) */
/* WARNING: Removing unreachable block (ram,0xf004fefc) */
/* WARNING: Removing unreachable block (ram,0xf004fd20) */

undefined8 _update(undefined4 param_1,undefined4 param_2)

{
  word wVar1;
  word wVar2;
  int iVar3;
  word wVar4;
  undefined4 unaff_l0;
  int iVar5;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  if (_syncprt != 0) {
    _bufstats();
  }
  if (_updlock == 0) {
    _updlock = 1;
    wVar1 = (word)param_1;
    wVar4 = (word)param_2;
    iVar5 = _mounttab;
    while (iVar3 = _inode_list, iVar5 != 0) {
      if (wVar1 == 0xffff) {
        iVar3 = *(int *)(iVar5 + 0xc);
loc_F004FD8C:
        if (iVar3 == 0) {
          iVar5 = *(int *)(iVar5 + 0x20);
        }
        else if (*(sword *)(iVar5 + 4) == -1) {
          iVar5 = *(int *)(iVar5 + 0x20);
        }
        else {
          iVar3 = *(int *)(iVar3 + 0x20);
          if (*(char *)(iVar3 + 0xd0) == '\0') {
            iVar5 = *(int *)(iVar5 + 0x20);
          }
          else {
            if (*(char *)(iVar3 + 0xd2) != '\0') {
              _printf(aFsS_0,iVar3 + 0xd4);
              _panic(aUpdateRoFsMod);
            }
            *(undefined *)(iVar3 + 0xd0) = 0;
            _getthetime((undefined *)((int)register0x00000038 + -0x10));
            *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0x10);
            _sbupdate(iVar5);
            iVar5 = *(int *)(iVar5 + 0x20);
          }
        }
      }
      else {
        if (wVar1 == (*(word *)(iVar5 + 4) & wVar4)) {
          iVar3 = *(int *)(iVar5 + 0xc);
          goto loc_F004FD8C;
        }
        iVar5 = *(int *)(iVar5 + 0x20);
      }
    }
    while (iVar3 != 0) {
      if (wVar1 == 0xffff) {
        wVar2 = *(word *)(iVar3 + 0x44);
loc_F004FE84:
        if ((wVar2 & 1) == 0) {
          if ((wVar2 & 0x100) == 0) {
            iVar3 = *(int *)(iVar3 + 8);
          }
          else if ((wVar2 & 0x4e) == 0) {
            iVar3 = *(int *)(iVar3 + 8);
          }
          else {
            *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 1;
            *(sword *)(iVar3 + 0x12) = *(sword *)(iVar3 + 0x12) + 1;
            _iupdat(iVar3,0);
            _iput(iVar3);
            iVar3 = *(int *)(iVar3 + 8);
          }
        }
        else {
          iVar3 = *(int *)(iVar3 + 8);
        }
      }
      else {
        if (wVar1 == (*(word *)(iVar3 + 0x46) & wVar4)) {
          if (wVar1 == 0xffff) {
            wVar2 = *(word *)(iVar3 + 0x44);
          }
          else {
            iVar6 = *(int *)(iVar3 + 0xc) + 0x18;
            iVar5 = iVar6;
            _lock_try_write();
            if (iVar5 == 1) {
              _lock_done(iVar6);
              _mfs_fsync(iVar3 + 0xc);
              wVar2 = *(word *)(iVar3 + 0x44);
            }
            else {
              wVar2 = *(word *)(iVar3 + 0x44);
            }
          }
          goto loc_F004FE84;
        }
        iVar3 = *(int *)(iVar3 + 8);
      }
    }
    param_1 = 0;
    _updlock = 0;
    _bflush(0,(int)(sword)wVar1,(int)(sword)wVar4);
  }
  return CONCAT44(param_2,param_1);
}
