
/* WARNING: Removing unreachable block (ram,0xf004dc2c) */
/* WARNING: Removing unreachable block (ram,0xf004dba8) */
/* WARNING: Removing unreachable block (ram,0xf004dc38) */
/* WARNING: Removing unreachable block (ram,0xf004db80) */

undefined8 _inode_cache_clear(undefined4 param_1,undefined4 param_2)

{
  word wVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
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
  
  piVar2 = _ifreeh;
  iVar7 = _inode_list;
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
  while (_inode_list = iVar7, piVar2 != (int *)0x0) {
    _ifreeh = (int *)piVar2[0x17];
    if (_ifreeh != (int *)0x0) {
      _ifreeh[0x18] = (int)&_ifreeh;
    }
    piVar2[0x17] = 0;
    piVar2[0x18] = 0;
    _mfs_uncache(piVar2 + 3);
    *(undefined2 *)(piVar2 + 0x11) = 0x8000;
    *(word *)(piVar2 + 0x11) = *(word *)(piVar2 + 0x11) | 1;
    if (*(sword *)((int)piVar2 + 0x12) != 0) {
      _panic(aFreeInodeIsnT);
    }
    *(int *)(*piVar2 + 4) = piVar2[1];
    piVar3 = _ifreeh;
    *(int *)piVar2[1] = *piVar2;
    piVar2 = piVar3;
    iVar7 = _inode_list;
  }
  if (iVar7 != 0) {
    wVar1 = *(word *)(iVar7 + 0x44);
    iVar5 = iVar7;
    while( true ) {
      if ((wVar1 & 0x8000) == 0) {
        iVar6 = *(int *)(iVar5 + 8);
        iVar7 = iVar5;
      }
      else {
        iVar4 = *(int *)(iVar5 + 8);
        iVar6 = iVar4;
        if (iVar7 != iVar5) {
          *(int *)(iVar7 + 8) = iVar4;
          iVar4 = iVar7;
          iVar6 = _inode_list;
        }
        _inode_list = iVar6;
        iVar6 = *(int *)(iVar5 + 8);
        _zfree(_vm_info_zone,*(undefined4 *)(iVar5 + 0xc));
        _zfree(_inode_zone,iVar5);
        iVar7 = iVar4;
      }
      if (iVar6 == 0) break;
      wVar1 = *(word *)(iVar6 + 0x44);
      iVar5 = iVar6;
    }
  }
  return CONCAT44(param_2,param_1);
}
