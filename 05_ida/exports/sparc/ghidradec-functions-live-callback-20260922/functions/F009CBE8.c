
/* WARNING: Removing unreachable block (ram,0xf009cdd0) */
/* WARNING: Removing unreachable block (ram,0xf009cc04) */
/* WARNING: Removing unreachable block (ram,0xf009cc5c) */
/* WARNING: Removing unreachable block (ram,0xf009cde4) */
/* WARNING: Removing unreachable block (ram,0xf009cbfc) */

undefined8 _pmap_scatter_pte(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  undefined uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int *piVar9;
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
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  piVar9 = (int *)*param_2;
  _pmap_alloc_seg_entry(param_1,param_3,3);
  piVar1 = param_1;
  _splvm();
  param_1[8] = (int)piVar9;
  iVar8 = *param_1;
  iVar7 = 0;
  iVar5 = 0;
  uVar3 = *(uint *)(*piVar9 + (*(word *)((int)register0x00000038 + 0x4c) & 0xfc));
  do {
    *(uint *)(iVar5 + iVar8) = uVar3;
    uVar3 = uVar3 & 0xff | (uVar3 & 0xffffff00) + 0x100;
    iVar7 = iVar7 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar7 < 0x40);
  uVar2 = 0x40;
  div(0x40,_pmap_info);
  *(undefined *)((int)param_1 + 0xf) = uVar2;
  iVar5 = _wmap1;
  param_1[4] = _wmap0;
  param_1[5] = iVar5;
  iVar5 = _mmap1;
  if (*(char *)((int)piVar9 + 0xd) == '\x03') {
    uVar3 = *(uint *)((int)register0x00000038 + 0x4c) >> 0xf;
    bVar6 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0xc) & 0x1e;
loc_F009CCD4:
    if ((*(uint *)((int)piVar9 + (uVar3 & 4) + 0x18) & 1 << bVar6) == 0) {
      uVar4 = *(undefined4 *)((int)register0x00000038 + 0x4c);
      goto loc_F009CDBC;
    }
loc_F009CD18:
    param_1[6] = _mmap0;
    param_1[7] = iVar5;
    if (*(char *)((int)piVar9 + 0xd) == '\x03') {
      uVar3 = *(uint *)((int)register0x00000038 + 0x4c) >> 0xf;
      bVar6 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0xc) & 0x1e;
    }
    else {
      if (*(char *)((int)piVar9 + 0xd) != '\x02') {
        bVar6 = *(byte *)((int)register0x00000038 + 0x4c) >> 5;
        piVar9[bVar6 + 0xc] =
             piVar9[bVar6 + 0xc] & ~(1 << (*(byte *)((int)register0x00000038 + 0x4c) & 0x1f));
        goto loc_F009CDB8;
      }
      uVar3 = *(uint *)((int)register0x00000038 + 0x4c) >> 0x15;
      bVar6 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0x12) & 0x1f;
    }
    *(uint *)((int)piVar9 + (uVar3 & 4) + 0x18) =
         *(uint *)((int)piVar9 + (uVar3 & 4) + 0x18) & ~(1 << bVar6);
  }
  else {
    if (*(char *)((int)piVar9 + 0xd) == '\x02') {
      uVar3 = *(uint *)((int)register0x00000038 + 0x4c) >> 0x15;
      bVar6 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0x12) & 0x1f;
      goto loc_F009CCD4;
    }
    if ((piVar9[(*(byte *)((int)register0x00000038 + 0x4c) >> 5) + 0xc] &
        1 << (*(byte *)((int)register0x00000038 + 0x4c) & 0x1f)) != 0) goto loc_F009CD18;
  }
loc_F009CDB8:
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x4c);
loc_F009CDBC:
  _set_ptp(piVar9,uVar4,*(int *)(param_1[1] + 4) + (uint)*(byte *)((int)param_1 + 0xe) * 0x100);
  *(char *)((int)piVar9 + 0xf) = *(char *)((int)piVar9 + 0xf) + -1;
  _splx(piVar1);
  return CONCAT44(piVar9,param_1);
}

