
/* WARNING: Removing unreachable block (ram,0xf00e5fb0) */
/* WARNING: Removing unreachable block (ram,0xf00e5f40) */
/* WARNING: Removing unreachable block (ram,0xf00e5e80) */
/* WARNING: Removing unreachable block (ram,0xf00e5dd8) */
/* WARNING: Removing unreachable block (ram,0xf00e5f08) */
/* WARNING: Removing unreachable block (ram,0xf00e5f58) */
/* WARNING: Removing unreachable block (ram,0xf00e5fc8) */
/* WARNING: Removing unreachable block (ram,0xf00e5dd0) */

undefined8 _sparcfbSaveRect(uint param_1,word *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined *puVar8;
  undefined4 unaff_l1;
  uint uVar9;
  uint uVar10;
  undefined4 unaff_l3;
  int iVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar12;
  undefined4 unaff_l6;
  uint uVar13;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar14;
  undefined *puVar15;
  undefined4 *puVar16;
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
  uVar9 = (uint)param_2[2];
  uVar10 = (uint)param_2[3];
  uVar13 = (uint)*param_2;
  iVar1 = param_1 * 0x44 + 8;
  uVar12 = (uint)param_2[1];
  iVar11 = _sparcfbs + iVar1;
  if ((0xf < param_1) || (*(int *)(_sparcfbs + iVar1) == 0)) {
    uVar14 = 0xfffffd40;
    goto locret_F00E601C;
  }
  uVar2 = uVar9;
  .umul(uVar9,*(undefined4 *)(iVar11 + 0x34));
  .umul();
  iVar7 = uVar2 + 4;
  *(int *)((int)register0x00000038 + -0xc) = dword_F012EF6C;
  iVar1 = 0;
  iVar6 = dword_F012EF6C;
  while (iVar6 != 0) {
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    iVar6 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar7 <= *(int *)(iVar4 + 0x18)) goto loc_F00E5E28;
    iVar6 = *(int *)(iVar4 + 8);
    *(int *)((int)register0x00000038 + -0xc) = iVar6;
    iVar1 = iVar4;
  }
  iVar6 = *(int *)((int)register0x00000038 + -0xc);
loc_F00E5E28:
  if (iVar6 == 0) {
    if (dword_F012EF78 < iVar7) {
      iVar1 = _kernel_map;
      _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar2 + 0x20);
      if (iVar1 != 0) {
        uVar14 = 0xffffffff;
        goto locret_F00E601C;
      }
    }
    else {
      *(undefined **)((int)register0x00000038 + -0xc) = unk_F01330E4;
      dword_F012EF78 = 0;
    }
  }
  else {
    dword_F012EF74 = dword_F012EF74 + -1;
    if (iVar1 == 0) {
      dword_F012EF6C = *(int *)(iVar6 + 8);
    }
    else {
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar6 + 8);
    }
  }
  piVar5 = *(int **)((int)register0x00000038 + -0xc);
  DAT_f012ef70 = DAT_f012ef70 + 1;
  *piVar5 = DAT_f012ef70;
  piVar5[6] = iVar7;
  piVar5[1] = param_1;
  piVar5[2] = (int)dword_F012EF68;
  piVar5[3] = *(int *)(iVar11 + 0x34);
  *(word *)(piVar5 + 4) = *param_2;
  *(word *)((int)piVar5 + 0x12) = param_2[1];
  *(word *)(piVar5 + 5) = param_2[2];
  *(word *)((int)piVar5 + 0x16) = param_2[3];
  iVar1 = *(int *)(iVar11 + 0x38);
  dword_F012EF68 = piVar5;
  .div(iVar1,*(undefined4 *)(iVar11 + 0x34));
  if (*(int *)(iVar11 + 0x34) == 1) {
    puVar15 = (undefined *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
    .umul(uVar12,*(undefined4 *)(iVar11 + 0x38));
    iVar6 = *(int *)(iVar11 + 0x14);
    .umul(uVar13,*(undefined4 *)(iVar11 + 0x34));
    puVar8 = (undefined *)(iVar6 + uVar12 + uVar13);
    iVar11 = uVar10 - 1;
    if ((int)(uVar10 - 1) < 0) goto loc_F00E6014;
    do {
      uVar10 = (uint)param_2[2];
      while (uVar10 = uVar10 - 1, -1 < (int)uVar10) {
        *puVar15 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar15 = puVar15 + 1;
      }
      iVar6 = iVar11 + -1;
      puVar8 = puVar8 + (iVar1 - uVar9);
      iVar11 = iVar11 + -1;
    } while (-1 < iVar6);
    puVar3 = *(undefined4 **)((int)register0x00000038 + -0xc);
  }
  else if (*(int *)(iVar11 + 0x34) == 4) {
    puVar16 = (undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
    .umul(uVar12,*(undefined4 *)(iVar11 + 0x38));
    iVar6 = *(int *)(iVar11 + 0x18);
    .umul(uVar13,*(undefined4 *)(iVar11 + 0x34));
    puVar3 = (undefined4 *)(iVar6 + uVar12 + uVar13);
    while (uVar10 = uVar10 - 1, -1 < (int)uVar10) {
      uVar12 = (uint)param_2[2];
      while (uVar12 = uVar12 - 1, -1 < (int)uVar12) {
        *puVar16 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar16 = puVar16 + 1;
      }
      puVar3 = puVar3 + (iVar1 - uVar9);
    }
loc_F00E6014:
    puVar3 = *(undefined4 **)((int)register0x00000038 + -0xc);
  }
  else {
    puVar3 = *(undefined4 **)((int)register0x00000038 + -0xc);
  }
  uVar14 = *puVar3;
locret_F00E601C:
  return CONCAT44(param_2,uVar14);
}
