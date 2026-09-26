
/* WARNING: Removing unreachable block (ram,0xf009cb60) */
/* WARNING: Removing unreachable block (ram,0xf009cbb8) */
/* WARNING: Removing unreachable block (ram,0xf009caf0) */
/* WARNING: Removing unreachable block (ram,0xf009ca58) */
/* WARNING: Removing unreachable block (ram,0xf009cad4) */
/* WARNING: Removing unreachable block (ram,0xf009ca88) */
/* WARNING: Removing unreachable block (ram,0xf009cb9c) */
/* WARNING: Removing unreachable block (ram,0xf009cb50) */
/* WARNING: Removing unreachable block (ram,0xf009cbd4) */
/* WARNING: Removing unreachable block (ram,0xf009cab8) */

undefined8 _pmap_page_table_entry(undefined4 *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  word wVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar4;
  int iVar5;
  undefined4 unaff_l3;
  int *piVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int *piVar7;
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
  piVar4 = (int *)0x0;
  piVar6 = (int *)0x0;
  *(uint *)((int)register0x00000038 + 0x48) = param_2;
  dword_F013DEB8 = dword_F013DEB8 + 1;
  piVar7 = (int *)(param_2 & 0xfffc0000);
  if (piVar7 == (int *)param_1[4]) {
    piVar4 = (int *)param_1[2];
    goto locret_F009CBE0;
  }
  DAT_f013debc = DAT_f013debc + 1;
  piVar7 = (int *)*param_1;
  bVar1 = *(byte *)((int)register0x00000038 + 0x48);
  iVar5 = *piVar7;
  uVar3 = *(uint *)(iVar5 + (uint)bVar1 * 4) & 3;
  if (uVar3 != 1) {
    if (uVar3 < 2) {
      if (uVar3 != 0) {
loc_F009CAD4:
        _panic(aPmapPageTableE_8);
        goto loc_F009CADC;
      }
    }
    else {
      if (uVar3 != 2) goto loc_F009CAD4;
      piVar4 = piVar7;
      if (param_3 < 2) goto locret_F009CBE0;
      _panic(aPmapPageTableE_7);
    }
    piVar4 = (int *)((uint)piVar7 & (param_3 != 1) - 1);
    goto locret_F009CBE0;
  }
  if (param_3 == 1) {
    _panic(aPmapPageTableE);
    uVar3 = *(uint *)((int)register0x00000038 + 0x48);
  }
  else {
    uVar3 = *(uint *)((int)register0x00000038 + 0x48);
  }
  if ((uVar3 & 0xff000000) == param_1[3]) {
    piVar4 = (int *)param_1[1];
  }
  else {
    piVar4 = (int *)((*(uint *)(iVar5 + (uint)bVar1 * 4) >> 2) << 6);
    _pmap_seg_entry();
    uVar3 = *(uint *)((int)register0x00000038 + 0x48);
    param_1[1] = piVar4;
    param_1[3] = uVar3 & 0xff000000;
  }
loc_F009CADC:
  if (*piVar4 == 0) {
    _panic(aPmapPageTableE_0);
    wVar2 = *(word *)((int)register0x00000038 + 0x48);
  }
  else {
    wVar2 = *(word *)((int)register0x00000038 + 0x48);
  }
  iVar5 = *piVar4;
  piVar7 = (int *)(wVar2 & 0xfc);
  uVar3 = *(uint *)(iVar5 + (int)piVar7) & 3;
  if (uVar3 == 1) {
    if (param_3 == 2) {
      _panic(aPmapPageTableE_1);
      uVar3 = *(uint *)(iVar5 + (int)piVar7);
    }
    else {
      uVar3 = *(uint *)(iVar5 + (int)piVar7);
    }
    piVar6 = (int *)((uVar3 >> 2) << 6);
    _pmap_seg_entry();
    param_1[2] = piVar6;
    param_1[4] = *(uint *)((int)register0x00000038 + 0x48) & 0xfffc0000;
loc_F009CBC0:
    piVar4 = piVar6;
    if (*piVar6 == 0) {
      _panic(aPmapPageTableE_2);
    }
  }
  else {
    if (uVar3 < 2) {
      if (uVar3 != 0) {
loc_F009CBB8:
        _panic(aPmapPageTableE_10);
        goto loc_F009CBC0;
      }
    }
    else {
      if (uVar3 != 2) goto loc_F009CBB8;
      if ((param_3 == 2) || (param_3 == 0)) goto locret_F009CBE0;
      _panic(aPmapPageTableE_9);
    }
    piVar4 = (int *)((uint)piVar4 & (param_3 != 2) - 1);
  }
locret_F009CBE0:
  return CONCAT44(piVar7,piVar4);
}

