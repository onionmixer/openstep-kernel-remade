
/* WARNING: Removing unreachable block (ram,0xf009d068) */
/* WARNING: Removing unreachable block (ram,0xf009cfc4) */
/* WARNING: Removing unreachable block (ram,0xf009d088) */
/* WARNING: Removing unreachable block (ram,0xf009cf3c) */

undefined8 _pmap_gather_pte(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined *puVar1;
  uint uVar2;
  byte bVar3;
  undefined4 unaff_l0;
  uint *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar5;
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
  puVar1 = (undefined *)((int)register0x00000038 + -0x14);
  param_2 = (undefined4 *)*param_2;
  *(undefined4 **)((int)register0x00000038 + -0x14) = param_2;
  _is_ptes_contiguous(puVar1,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
  if (puVar1 == (undefined *)0x0) goto locret_F009D090;
  iVar5 = param_2[8];
  if (*(char *)(iVar5 + 0xd) == '\x03') {
    uVar2 = *(uint *)((int)register0x00000038 + 0x4c) & ~_page_mask;
  }
  else {
    if (*(char *)(iVar5 + 0xd) == '\x02') {
      uVar2 = 0xfffc0000;
    }
    else {
      uVar2 = 0xff000000;
    }
    uVar2 = *(uint *)((int)register0x00000038 + 0x4c) & uVar2;
  }
  *(uint *)((int)register0x00000038 + 0x4c) = uVar2;
  puVar4 = (uint *)*param_2;
  *(int *)((int)register0x00000038 + -0x14) = iVar5;
  uVar2 = *puVar4;
  _set_pte((undefined *)((int)register0x00000038 + -0x14),
           *(undefined4 *)((int)register0x00000038 + 0x4c),uVar2 >> 8,uVar2 >> 2 & 7,uVar2 >> 7 & 1,
           *(undefined4 *)((int)register0x00000038 + -0xc),
           *(undefined4 *)((int)register0x00000038 + -0x10));
  *(char *)(iVar5 + 0xf) = *(char *)(iVar5 + 0xf) + -1;
  if (*(char *)(iVar5 + 0xd) == '\x03') {
    uVar2 = *(uint *)((int)register0x00000038 + 0x4c) >> 0xf;
    bVar3 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0xc) & 0x1e;
loc_F009D02C:
    iVar5 = (uVar2 & 4) + iVar5;
    *(uint *)(iVar5 + 0x10) = *(uint *)(iVar5 + 0x10) | 1 << bVar3;
  }
  else {
    if (*(char *)(iVar5 + 0xd) == '\x02') {
      uVar2 = *(uint *)((int)register0x00000038 + 0x4c) >> 0x15;
      bVar3 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0x12) & 0x1f;
      goto loc_F009D02C;
    }
    iVar5 = (uint)(*(byte *)((int)register0x00000038 + 0x4c) >> 5) * 4 + iVar5;
    *(uint *)(iVar5 + 0x10) =
         *(uint *)(iVar5 + 0x10) | 1 << (*(byte *)((int)register0x00000038 + 0x4c) & 0x1f);
  }
  _bzero(puVar4,0x100);
  *(undefined *)((int)param_2 + 0xf) = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  _pmap_dealloc_seg_entry(param_2);
locret_F009D090:
  return CONCAT44(param_2,param_1);
}
