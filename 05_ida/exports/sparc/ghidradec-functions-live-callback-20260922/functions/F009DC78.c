
/* WARNING: Removing unreachable block (ram,0xf009de54) */
/* WARNING: Removing unreachable block (ram,0xf009defc) */
/* WARNING: Removing unreachable block (ram,0xf009ded0) */
/* WARNING: Removing unreachable block (ram,0xf009deb0) */
/* WARNING: Removing unreachable block (ram,0xf009de94) */
/* WARNING: Removing unreachable block (ram,0xf009de7c) */
/* WARNING: Removing unreachable block (ram,0xf009dde4) */
/* WARNING: Removing unreachable block (ram,0xf009dd9c) */
/* WARNING: Removing unreachable block (ram,0xf009dd7c) */
/* WARNING: Removing unreachable block (ram,0xf009dd6c) */
/* WARNING: Removing unreachable block (ram,0xf009dd50) */
/* WARNING: Removing unreachable block (ram,0xf009dd38) */
/* WARNING: Removing unreachable block (ram,0xf009dd18) */
/* WARNING: Removing unreachable block (ram,0xf009dd40) */
/* WARNING: Removing unreachable block (ram,0xf009dd58) */
/* WARNING: Removing unreachable block (ram,0xf009dd74) */
/* WARNING: Removing unreachable block (ram,0xf009dd94) */
/* WARNING: Removing unreachable block (ram,0xf009ddc0) */
/* WARNING: Removing unreachable block (ram,0xf009de70) */
/* WARNING: Removing unreachable block (ram,0xf009de8c) */
/* WARNING: Removing unreachable block (ram,0xf009dea8) */
/* WARNING: Removing unreachable block (ram,0xf009deb8) */
/* WARNING: Removing unreachable block (ram,0xf009ded8) */
/* WARNING: Removing unreachable block (ram,0xf009df20) */
/* WARNING: Removing unreachable block (ram,0xf009df28) */
/* WARNING: Removing unreachable block (ram,0xf009dc98) */

undefined8 _pmap_expand(int *param_1,int *param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar7;
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
  piVar6 = (int *)0x0;
  *(int **)((int)register0x00000038 + 0x48) = param_2;
  if (param_3 == 1) goto locret_F009DF30;
  piVar2 = (int *)((int)dword_F013DECC + 1);
  dword_F013DECC = piVar2;
  _splvm();
  param_2 = (int *)*param_1;
  bVar1 = *(byte *)((int)register0x00000038 + 0x48);
  iVar4 = *param_2;
  uVar5 = *(uint *)(iVar4 + (uint)bVar1 * 4);
  uVar3 = uVar5 & 3;
  if (uVar3 == 1) {
    param_2 = (int *)0xff000000;
    if ((*(uint *)((int)register0x00000038 + 0x48) & 0xff000000) == param_1[3]) {
      piVar6 = (int *)param_1[1];
    }
    else {
      piVar6 = (int *)((uVar5 >> 2) << 6);
      _pmap_seg_entry();
      uVar3 = *(uint *)((int)register0x00000038 + 0x48);
      param_1[1] = (int)piVar6;
      param_1[3] = uVar3 & 0xff000000;
    }
  }
  else {
    if (uVar3 < 2) {
      if (uVar3 == 0) {
loc_F009DD40:
        _splx(piVar2);
        piVar6 = param_1;
        _pmap_alloc_seg_entry(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),2);
        piVar2 = piVar6;
        _check_ptbl();
        if (piVar2 != (int *)0x0) {
          _panic(aPmapExpandPage);
        }
        piVar2 = piVar6;
        _check_pmap(piVar6);
        _splvm();
        if ((*(uint *)(iVar4 + (uint)bVar1 * 4) & 3) != 0) {
          _splx();
          _pmap_dealloc_seg_entry(piVar6);
          goto locret_F009DF30;
        }
        _set_ptp(param_2,*(undefined4 *)((int)register0x00000038 + 0x48),
                 *(int *)(piVar6[1] + 4) + (uint)*(byte *)((int)piVar6 + 0xe) * 0x100);
        piVar6[8] = (int)param_2;
        param_1[1] = (int)piVar6;
        param_1[3] = *(uint *)((int)register0x00000038 + 0x48) & 0xff000000;
        goto loc_F009DDEC;
      }
    }
    else if (uVar3 == 2) {
      _panic(aPmapExpandPteI);
      goto loc_F009DD40;
    }
    _panic(aPmapExpandPteR);
  }
loc_F009DDEC:
  if (param_3 == 2) goto locret_F009DF30;
  iVar4 = *piVar6;
  uVar7 = *(uint *)((int)register0x00000038 + 0x48) >> 0x10 & 0xfc;
  uVar5 = *(uint *)(iVar4 + uVar7);
  uVar3 = uVar5 & 3;
  if (uVar3 == 1) {
    if ((*(uint *)((int)register0x00000038 + 0x48) & 0xfffc0000) != param_1[4]) {
      iVar4 = (uVar5 >> 2) << 6;
      _pmap_seg_entry();
      uVar3 = *(uint *)((int)register0x00000038 + 0x48);
      param_1[2] = iVar4;
      param_1[4] = uVar3 & 0xfffc0000;
    }
  }
  else {
    if (uVar3 < 2) {
      if (uVar3 == 0) {
        _splx(piVar2);
        param_2 = param_1;
        _pmap_alloc_seg_entry(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),3);
        piVar2 = param_2;
        _check_ptbl();
        if (piVar2 != (int *)0x0) {
          _panic(aPmapExpandPage_0);
        }
        piVar2 = param_2;
        _check_pmap(param_2);
        _splvm();
        if ((*(uint *)(iVar4 + uVar7) & 3) != 0) {
          _splx();
          _pmap_dealloc_seg_entry(param_2);
          goto locret_F009DF30;
        }
        _set_ptp(piVar6,*(undefined4 *)((int)register0x00000038 + 0x48),
                 *(int *)(param_2[1] + 4) + (uint)*(byte *)((int)param_2 + 0xe) * 0x100);
        param_2[8] = (int)piVar6;
        param_1[2] = (int)param_2;
        param_1[4] = *(uint *)((int)register0x00000038 + 0x48) & 0xfffc0000;
        goto loc_F009DF28;
      }
    }
    else if (uVar3 == 2) {
      _panic(aPmapExpandPteI_0);
      goto locret_F009DF30;
    }
    _panic(aPmapExpandPteR_0);
  }
loc_F009DF28:
  _splx(piVar2);
locret_F009DF30:
  return CONCAT44(param_2,param_1);
}

