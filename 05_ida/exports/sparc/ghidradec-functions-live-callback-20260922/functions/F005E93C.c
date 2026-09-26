
/* WARNING: Removing unreachable block (ram,0xf005e9b0) */
/* WARNING: Removing unreachable block (ram,0xf005e988) */
/* WARNING: Removing unreachable block (ram,0xf005ea60) */
/* WARNING: Removing unreachable block (ram,0xf005ea7c) */
/* WARNING: Removing unreachable block (ram,0xf005e9d0) */
/* WARNING: Removing unreachable block (ram,0xf005e9f4) */
/* WARNING: Removing unreachable block (ram,0xf005ea48) */
/* WARNING: Removing unreachable block (ram,0xf005ea1c) */

undefined8 _ipc_splay_traverse_next(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_i1;
  int iVar5;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
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
  iVar3 = *(int *)(param_1 + 8);
  iVar5 = *(int *)(param_1 + 0x10);
  *(int *)((int)register0x00000038 + -0xc) = iVar3;
  if (param_2 == 0) {
    iVar3 = *(int *)((int)register0x00000038 + -0xc);
loc_F005EABC:
    iVar1 = *(int *)(iVar3 + 0x1c);
    bVar6 = iVar5 == 0;
    if (iVar1 == 0) goto loc_F005EAE0;
    *(int *)(iVar3 + 0x1c) = iVar5;
    goto loc_F005EA8C;
  }
  iVar2 = *(int *)(iVar3 + 0x18);
  iVar1 = *(int *)(iVar3 + 0x1c);
  if (iVar2 != 0) {
    if (iVar1 == 0) {
      *(int *)((int)register0x00000038 + -0xc) = iVar2;
      _zfree(_ipc_tree_entry_zone,iVar3);
      bVar6 = iVar5 == 0;
      goto loc_F005EAE0;
    }
    sub_F005E1A4(0xffffffff,iVar2,(undefined *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10),
                 (undefined *)((int)register0x00000038 + -0x14),
                 (undefined *)((int)register0x00000038 + -0x18),
                 (undefined *)((int)register0x00000038 + -0x1c));
    sub_F005E2C8(*(undefined4 *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10),
                 *(undefined4 *)((int)register0x00000038 + -0x14),
                 (undefined *)((int)register0x00000038 + -0x18),
                 *(undefined4 *)((int)register0x00000038 + -0x1c));
    uVar4 = _ipc_tree_entry_zone;
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) = *(undefined4 *)(iVar3 + 0x1c)
    ;
    _zfree(uVar4);
    iVar3 = *(int *)((int)register0x00000038 + -0xc);
    goto loc_F005EABC;
  }
  if (iVar1 == 0) {
    if (iVar5 == 0) {
      _zfree(_ipc_tree_entry_zone,iVar3);
      *(undefined4 *)(param_1 + 4) = 0;
      uVar4 = 0;
      goto locret_F005EB2C;
    }
    if (*(uint *)(iVar3 + 0x10) < *(uint *)(iVar5 + 0x10)) {
      _zfree(_ipc_tree_entry_zone,iVar3);
      *(int *)((int)register0x00000038 + -0xc) = iVar5;
      iVar3 = *(int *)(iVar5 + 0x18);
      *(undefined4 *)(iVar5 + 0x18) = 0;
    }
    else {
      _zfree(_ipc_tree_entry_zone,iVar3);
      *(int *)((int)register0x00000038 + -0xc) = iVar5;
      iVar3 = *(int *)(iVar5 + 0x1c);
      *(undefined4 *)(iVar5 + 0x1c) = 0;
      while( true ) {
        bVar6 = iVar3 == 0;
        iVar5 = iVar3;
loc_F005EAE0:
        iVar1 = *(int *)((int)register0x00000038 + -0xc);
        if (bVar6) {
          uVar4 = 0;
          *(undefined4 *)(param_1 + 4) = *(undefined4 *)((int)register0x00000038 + -0xc);
          goto locret_F005EB2C;
        }
        if (*(uint *)(iVar1 + 0x10) < *(uint *)(iVar5 + 0x10)) break;
        *(int *)((int)register0x00000038 + -0xc) = iVar5;
        iVar3 = *(int *)(iVar5 + 0x1c);
        *(int *)(iVar5 + 0x1c) = iVar1;
      }
      *(int *)((int)register0x00000038 + -0xc) = iVar5;
      iVar3 = *(int *)(iVar5 + 0x18);
      *(int *)(iVar5 + 0x18) = iVar1;
    }
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else {
    *(int *)((int)register0x00000038 + -0xc) = iVar1;
    _zfree(_ipc_tree_entry_zone,iVar3);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    iVar3 = iVar5;
    while( true ) {
      iVar1 = *(int *)(iVar2 + 0x18);
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
      if (iVar1 == 0) break;
      *(int *)(iVar2 + 0x18) = iVar3;
      iVar3 = iVar2;
loc_F005EA8C:
      *(int *)((int)register0x00000038 + -0xc) = iVar1;
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
    }
  }
  *(int *)(param_1 + 0x10) = iVar3;
  *(undefined4 *)(param_1 + 8) = uVar4;
  iVar5 = iVar3;
locret_F005EB2C:
  return CONCAT44(iVar5,uVar4);
}

