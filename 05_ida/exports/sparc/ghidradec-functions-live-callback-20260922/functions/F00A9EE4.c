
/* WARNING: Removing unreachable block (ram,0xf00a9f70) */
/* WARNING: Removing unreachable block (ram,0xf00a9f2c) */
/* WARNING: Removing unreachable block (ram,0xf00a9f04) */
/* WARNING: Removing unreachable block (ram,0xf00a9fb0) */
/* WARNING: Removing unreachable block (ram,0xf00a9f14) */

undefined8 _fix_addr(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 uVar4;
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
  puVar1 = *(undefined4 **)(param_1 + 4);
  bVar5 = &dword_F0000000 < puVar1;
  if (bVar5) {
    puVar1 = (undefined4 *)*puVar1;
    _flush_windows();
  }
  else {
    _fuword();
    if (puVar1 == (undefined4 *)0xffffffff) {
      iVar3 = -1;
      goto locret_F00A9FD4;
    }
    _flush_user_windows_to_stack();
  }
  if ((uint)puVar1 >> 0x1e != 3) {
    iVar3 = -1;
    goto locret_F00A9FD4;
  }
  iVar2 = param_1 + 0xc;
  if (((uint)puVar1 >> 0x17 & 3) == 3) {
loc_F00A9FC4:
    iVar3 = -1;
  }
  else {
    uVar4 = *(undefined4 *)(param_1 + 0x44);
    iVar3 = iVar2;
    sub_F00A9FDC(iVar2,uVar4,(uint)puVar1 >> 0xe & 0x1f,
                 (undefined *)((int)register0x00000038 + -0xc),bVar5);
    if (iVar3 != 0) {
      iVar3 = -1;
      goto locret_F00A9FD4;
    }
    if (((uint)puVar1 >> 0xd & 1) == 0) {
      sub_F00A9FDC(iVar2,uVar4,(uint)puVar1 & 0x1f,(undefined *)((int)register0x00000038 + -0x10),
                   bVar5);
      iVar3 = *(int *)((int)register0x00000038 + -0xc);
      if (iVar2 != 0) goto loc_F00A9FC4;
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
    }
    else {
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      iVar3 = ((int)puVar1 << 0x13) >> 0x13;
    }
    iVar3 = iVar3 + iVar2;
  }
locret_F00A9FD4:
  return CONCAT44(param_2,iVar3);
}

