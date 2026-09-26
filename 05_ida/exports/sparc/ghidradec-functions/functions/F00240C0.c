
/* WARNING: Removing unreachable block (ram,0xf0024170) */
/* WARNING: Removing unreachable block (ram,0xf0024194) */
/* WARNING: Removing unreachable block (ram,0xf0024160) */
/* WARNING: Removing unreachable block (ram,0xf0024178) */
/* WARNING: Removing unreachable block (ram,0xf00240dc) */

undefined8 _vfs_remove(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  if (param_1 == _rootvfs) {
    _panic(aVfsRemoveUnmou);
  }
  if (_rootvfs == (undefined4 *)0x0) {
loc_F0024190:
    _panic(aVfsRemoveVfsNo);
  }
  else {
    puVar5 = (undefined4 *)*_rootvfs;
    puVar3 = _rootvfs;
    while (puVar2 = puVar5, puVar2 != param_1) {
      if (puVar2 == (undefined4 *)0x0) goto loc_F0024190;
      puVar3 = puVar2;
      puVar5 = (undefined4 *)*puVar2;
    }
    *puVar3 = *puVar2;
    iVar6 = puVar2[2];
    if (*(int *)(iVar6 + 0xc) == 0) {
      puVar5 = (undefined4 *)(iVar6 + 0x10);
      iVar1 = *(int *)(iVar6 + 0x10);
      while (iVar1 != 0) {
        puVar3 = (undefined4 *)*puVar5;
        if (puVar3 == param_1) {
          puVar3 = (undefined4 *)*puVar5;
          goto loc_F0024154;
        }
        puVar5 = puVar3 + 0x48;
        iVar1 = puVar3[0x48];
      }
      puVar3 = (undefined4 *)*puVar5;
loc_F0024154:
      if (puVar3 == param_1) {
        uVar4 = param_1[0x48];
      }
      else {
        _panic(aVfsRemoveCanTF);
        uVar4 = param_1[0x48];
      }
      *puVar5 = uVar4;
      _microtime(iVar6 + 0x14);
    }
    else {
      *(undefined4 *)(iVar6 + 0xc) = 0;
    }
    _vfs_unlock(param_1);
  }
  return CONCAT44(param_2,param_1);
}
