
/* WARNING: Removing unreachable block (ram,0xf0050f3c) */
/* WARNING: Removing unreachable block (ram,0xf0050ef8) */
/* WARNING: Removing unreachable block (ram,0xf0050ee4) */
/* WARNING: Removing unreachable block (ram,0xf0050ef0) */
/* WARNING: Removing unreachable block (ram,0xf0050f34) */
/* WARNING: Removing unreachable block (ram,0xf0050f9c) */
/* WARNING: Removing unreachable block (ram,0xf0050e80) */

undefined8 sub_F0050E78(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
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
  iVar4 = *(int *)(param_1 + 0x128);
  iVar1 = (int)*(sword *)(iVar4 + 4);
  _iflush();
  if (iVar1 < 0) {
    if ((param_2 == 0) || (iVar1 < 0)) {
      uVar3 = 0x10;
      goto locret_F0050FA8;
    }
    iVar2 = *(int *)(iVar4 + 0xc);
  }
  else {
    iVar2 = *(int *)(iVar4 + 0xc);
  }
  param_2 = *(int *)(iVar2 + 0x20);
  bVar5 = *(char *)(param_2 + 0xd2) == '\0';
  if (bVar5) {
    if (*(char *)(param_2 + 0xd1) == '\x02') {
      *(undefined *)(param_2 + 0xd1) = 1;
      _sbupdate(iVar4);
      uVar3 = *(undefined4 *)(param_2 + 0x2d8);
    }
    else {
      uVar3 = *(undefined4 *)(param_2 + 0x2d8);
    }
  }
  else {
    uVar3 = *(undefined4 *)(param_2 + 0x2d8);
  }
  _kfree(uVar3,*(undefined4 *)(param_2 + 0x9c));
  _brelse(*(undefined4 *)(iVar4 + 0xc));
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(undefined2 *)(iVar4 + 4) = 0;
  if (iVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(iVar4 + 8) + 0x1c) + 4))
              (*(int *)(iVar4 + 8),bVar5,1,*(undefined4 *)(_active_u + 0x1c));
    _binval(*(undefined4 *)(iVar4 + 8));
    _vn_rele(*(undefined4 *)(iVar4 + 8));
    iVar1 = _mounttab;
    bVar5 = iVar4 == _mounttab;
    *(undefined4 *)(iVar4 + 8) = 0;
    if (bVar5) {
      _mounttab = *(int *)(iVar4 + 0x20);
    }
    else if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x20);
      while( true ) {
        if (iVar2 == iVar4) {
          *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar4 + 0x20);
          iVar1 = *(int *)(iVar1 + 0x20);
        }
        else {
          iVar1 = *(int *)(iVar1 + 0x20);
        }
        if (iVar1 == 0) break;
        iVar2 = *(int *)(iVar1 + 0x20);
      }
    }
    _kfree(iVar4,0x24);
  }
  uVar3 = 0;
locret_F0050FA8:
  return CONCAT44(param_2,uVar3);
}

