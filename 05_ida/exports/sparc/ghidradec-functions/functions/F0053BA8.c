
/* WARNING: Removing unreachable block (ram,0xf0053e28) */
/* WARNING: Removing unreachable block (ram,0xf0053dd8) */
/* WARNING: Removing unreachable block (ram,0xf0053d5c) */
/* WARNING: Removing unreachable block (ram,0xf0053cf0) */
/* WARNING: Removing unreachable block (ram,0xf0053cd0) */
/* WARNING: Removing unreachable block (ram,0xf0053c04) */
/* WARNING: Removing unreachable block (ram,0xf0053c64) */
/* WARNING: Removing unreachable block (ram,0xf0053d10) */
/* WARNING: Removing unreachable block (ram,0xf0053d7c) */
/* WARNING: Removing unreachable block (ram,0xf0053e00) */
/* WARNING: Removing unreachable block (ram,0xf0053e54) */
/* WARNING: Removing unreachable block (ram,0xf0053bcc) */

undefined8 _ipc_entry_alloc_name(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 unaff_l3;
  int iVar10;
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
  uVar9 = param_2 >> 8;
  do {
    do {
    } while (*(int *)(param_1 + 8) != 0);
    piVar7 = (int *)(param_1 + 8);
    _simple_lock_try();
  } while (piVar7 == (int *)0x0);
  iVar10 = uVar9 * 0x10;
  iVar3 = *(int *)(param_1 + 0xc);
  puVar8 = (undefined4 *)0x0;
loc_F0053BE8:
  if (iVar3 == 0) goto loc_f0053bf4;
  if (uVar9 == 0) {
    iVar3 = *(int *)(param_1 + 0x38);
  }
  else if (uVar9 < *(uint *)(param_1 + 0x18)) {
    iVar3 = *(int *)(param_1 + 0x14);
    piVar7 = (int *)(iVar3 + iVar10);
    if ((*(uint *)(iVar3 + iVar10) & 0x1f0000) == 0) {
      uVar2 = *(uint *)(iVar3 + 8);
      uVar6 = 0;
      while (uVar1 = uVar2, uVar1 != uVar9) {
        uVar6 = uVar1;
        uVar2 = *(uint *)(iVar3 + uVar1 * 0x10 + 8);
      }
      *(undefined4 *)(iVar3 + uVar6 * 0x10 + 8) = *(undefined4 *)(iVar3 + uVar1 * 0x10 + 8);
      *piVar7 = param_2 * 0x1000000;
      piVar7[2] = 0;
      *param_3 = (int)piVar7;
      if (puVar8 == (undefined4 *)0x0) {
loc_F0053E1C:
        iVar3 = 0;
        goto locret_F0053E70;
      }
      _zfree(_ipc_tree_entry_zone,puVar8);
      iVar3 = 0;
      goto locret_F0053E70;
    }
    if ((*(uint *)(iVar3 + iVar10) & 0xff000000) + param_2 * -0x1000000 == 0) {
      *param_3 = (int)piVar7;
      if (puVar8 == (undefined4 *)0x0) goto loc_F0053E1C;
      _zfree(_ipc_tree_entry_zone,puVar8);
      iVar3 = 0;
      goto locret_F0053E70;
    }
    iVar3 = *(int *)(param_1 + 0x38);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x38);
  }
  iVar4 = param_1 + 0x20;
  if (iVar3 != 0) {
    _ipc_splay_tree_lookup(iVar4,param_2);
    if (iVar4 != 0) {
      *param_3 = iVar4;
      if (puVar8 == (undefined4 *)0x0) goto loc_F0053E1C;
      _zfree(_ipc_tree_entry_zone,puVar8);
      iVar3 = 0;
      goto locret_F0053E70;
    }
  }
  puVar5 = _ipc_tree_entry_zone;
  if (((uVar9 < *(uint *)(param_1 + 0x18)) || (uVar6 = **(uint **)(param_1 + 0x1c), uVar6 <= uVar9))
     || ((uint)((*(int *)(param_1 + 0x3c) + 1) * 0x20) <= (uVar6 - *(uint *)(param_1 + 0x18)) * 0x10
        )) {
    if (puVar8 != (undefined4 *)0x0) {
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
      if (uVar9 < *(uint *)(param_1 + 0x18)) {
        *(uint *)(*(int *)(param_1 + 0x14) + iVar10) =
             *(uint *)(*(int *)(param_1 + 0x14) + iVar10) | 0x800000;
      }
      else if ((uVar9 < **(uint **)(param_1 + 0x1c)) &&
              (iVar3 = param_1, _ipc_entry_tree_collision(param_1,param_2), iVar3 == 0)) {
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      }
      _ipc_splay_tree_insert(param_1 + 0x20,param_2,puVar8);
      *puVar8 = 0;
      puVar8[1] = 0;
      puVar8[2] = 0;
      puVar8[5] = param_1;
      *param_3 = (int)puVar8;
      goto loc_F0053E1C;
    }
    *(undefined4 *)(param_1 + 8) = 0;
    _zalloc();
    if (puVar5 == (undefined4 *)0x0) {
      iVar3 = 6;
      goto locret_F0053E70;
    }
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar7 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar7 == (int *)0x0);
    iVar3 = *(int *)(param_1 + 0xc);
    puVar8 = puVar5;
  }
  else {
    iVar3 = param_1;
    _ipc_entry_grow_table();
    if (iVar3 != 0) {
      if (puVar8 != (undefined4 *)0x0) {
        _zfree(_ipc_tree_entry_zone,puVar8);
      }
      goto locret_F0053E70;
    }
    iVar3 = *(int *)(param_1 + 0xc);
  }
  goto loc_F0053BE8;
loc_f0053bf4:
  *(undefined4 *)(param_1 + 8) = 0;
  if (puVar8 != (undefined4 *)0x0) {
    _zfree(_ipc_tree_entry_zone,puVar8);
  }
  iVar3 = 0x10;
locret_F0053E70:
  return CONCAT44(param_2,iVar3);
}
