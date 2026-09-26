
/* WARNING: Removing unreachable block (ram,0xf0054038) */
/* WARNING: Removing unreachable block (ram,0xf0053fac) */
/* WARNING: Removing unreachable block (ram,0xf0053f80) */
/* WARNING: Removing unreachable block (ram,0xf0053f54) */
/* WARNING: Removing unreachable block (ram,0xf0053ef4) */
/* WARNING: Removing unreachable block (ram,0xf0053edc) */
/* WARNING: Removing unreachable block (ram,0xf0053f40) */
/* WARNING: Removing unreachable block (ram,0xf0053f64) */
/* WARNING: Removing unreachable block (ram,0xf0053fa0) */
/* WARNING: Removing unreachable block (ram,0xf0053fdc) */
/* WARNING: Removing unreachable block (ram,0xf0053ffc) */
/* WARNING: Removing unreachable block (ram,0xf0053ec8) */

undefined8 _ipc_entry_dealloc(int param_1,uint param_2,int param_3)

{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  undefined4 unaff_l3;
  int iVar8;
  undefined4 unaff_l4;
  int iVar9;
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
  bool bVar10;
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
  uVar6 = *(uint *)(param_1 + 0x18);
  uVar4 = param_2 >> 8;
  iVar5 = *(int *)(param_1 + 0x14);
  if ((uVar4 < uVar6) && (iVar8 = uVar4 * 0x10, param_3 == iVar5 + iVar8)) {
    iVar9 = param_1 + 0x20;
    if ((*(uint *)(iVar5 + iVar8) & 0x800000) == 0) {
      *(uint *)(iVar5 + iVar8) = *(uint *)(iVar5 + iVar8) & 0xff000000;
      *(undefined4 *)(param_3 + 8) = *(undefined4 *)(iVar5 + 8);
      *(uint *)(iVar5 + 8) = uVar4;
    }
    else {
      puVar7 = (undefined *)((int)register0x00000038 + -0x38);
      _ipc_splay_tree_split(iVar9,(uVar4 + 1) * 0x100,puVar7);
      _ipc_splay_tree_split(puVar7,uVar4 << 8,(undefined *)((int)register0x00000038 + -0x20));
      _ipc_splay_tree_pick
                (puVar7,(undefined *)((int)register0x00000038 + -0x3c),
                 (undefined *)((int)register0x00000038 + -0x40));
      puVar2 = *(uint **)((int)register0x00000038 + -0x40);
      iVar3 = *(int *)((int)register0x00000038 + -0x3c);
      uVar6 = *puVar2;
      *(uint *)(iVar5 + iVar8) = uVar6 | iVar3 << 0x18;
      param_2 = puVar2[1];
      *(uint *)(param_3 + 4) = param_2;
      *(uint *)(param_3 + 8) = puVar2[2];
      if ((uVar6 & 0x1f0000) == 0x10000) {
        _ipc_hash_global_delete(param_1,param_2,iVar3);
        _ipc_hash_local_insert(param_1,param_2,uVar4,param_3);
      }
      _ipc_splay_tree_delete
                (puVar7,*(undefined4 *)((int)register0x00000038 + -0x3c),
                 *(undefined4 *)((int)register0x00000038 + -0x40));
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
      puVar1 = puVar7;
      _ipc_splay_tree_pick
                (puVar7,(undefined *)((int)register0x00000038 + -0x3c),
                 (undefined *)((int)register0x00000038 + -0x40));
      if (puVar1 != (undefined *)0x0) {
        *(uint *)(iVar5 + iVar8) = *(uint *)(iVar5 + iVar8) | 0x800000;
        _ipc_splay_tree_join(iVar9,puVar7);
      }
      _ipc_splay_tree_join(iVar9,(undefined *)((int)register0x00000038 + -0x20));
    }
  }
  else {
    _ipc_splay_tree_delete(param_1 + 0x20,param_2,param_3);
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
    if (uVar4 < uVar6) {
      _ipc_entry_tree_collision(param_1,param_2);
      bVar10 = param_1 == 0;
      param_1 = uVar4 * 0x10;
      if (bVar10) {
        *(uint *)(iVar5 + param_1) = *(uint *)(iVar5 + param_1) & 0xff7fffff;
      }
    }
    else if ((uVar4 < **(uint **)(param_1 + 0x1c)) &&
            (iVar5 = param_1, _ipc_entry_tree_collision(param_1,param_2), iVar5 == 0)) {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
    }
  }
  return CONCAT44(param_2,param_1);
}

