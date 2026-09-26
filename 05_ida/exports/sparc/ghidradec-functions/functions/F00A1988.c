
/* WARNING: Removing unreachable block (ram,0xf00a1a40) */
/* WARNING: Removing unreachable block (ram,0xf00a1a34) */
/* WARNING: Removing unreachable block (ram,0xf00a1acc) */
/* WARNING: Removing unreachable block (ram,0xf00a19c0) */

undefined8 _set_pte_modref(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  uint *puVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  uint *puVar6;
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
  *(uint *)((int)register0x00000038 + 0x48) = param_2;
  piVar3 = (int *)*param_1;
  dword_F013DF44 = dword_F013DF44 + 1;
  if ((param_2 & _page_size - 1U) != 0) {
    _panic(aSetPteModrefVa);
  }
  if (*(char *)((int)piVar3 + 0xd) == '\x03') {
    iVar2 = *piVar3;
    uVar1 = *(uint *)((int)register0x00000038 + 0x48) >> 10 & 0xfc;
  }
  else if (*(char *)((int)piVar3 + 0xd) == '\x02') {
    iVar2 = *piVar3;
    uVar1 = *(word *)((int)register0x00000038 + 0x48) & 0xfc;
  }
  else {
    iVar2 = *piVar3;
    uVar1 = (uint)*(byte *)((int)register0x00000038 + 0x48) << 2;
  }
  puVar6 = (uint *)(iVar2 + uVar1);
  puVar4 = puVar6 + 1;
  if (*(char *)((int)piVar3 + 0xd) == '\x03') {
    puVar4 = puVar6 + _pmap_info;
  }
  iVar2 = piVar3[2];
  uVar5 = 0;
  _get_context(iVar2);
  _check_pmap(piVar3);
  if (puVar4 <= puVar6) {
locret_F00A1AFC:
    return CONCAT44(puVar6,uVar5);
  }
  uVar1 = *puVar6;
  do {
    *(uint *)((int)register0x00000038 + -0xc) = uVar1;
    if ((param_3 == 0) || (param_4 == 0)) {
      if (param_3 == 0) {
        uVar1 = *(uint *)((int)register0x00000038 + -0xc);
        if ((param_4 == 0) ||
           (*(uint *)((int)register0x00000038 + -0xc) = uVar1 & 0xffffffdf, (uVar1 & 0x40) == 0))
        goto loc_F00A1ABC;
        uVar5 = 2;
        uVar1 = uVar1 & 0xffffff9f;
      }
      else {
        uVar5 = 1;
        uVar1 = *(uint *)((int)register0x00000038 + -0xc) & 0xffffffbf;
      }
      *(uint *)((int)register0x00000038 + -0xc) = uVar1;
    }
    else {
      *(uint *)((int)register0x00000038 + -0xc) = uVar1 & 0xffffff9f;
      uVar5 = 1;
    }
loc_F00A1ABC:
    _mmu_writepte(*(undefined4 *)((int)register0x00000038 + -0xc),puVar6,
                  *(undefined4 *)((int)register0x00000038 + 0x48),*(undefined *)((int)piVar3 + 0xd),
                  iVar2);
    puVar6 = puVar6 + 1;
    if (*(char *)((int)piVar3 + 0xd) == '\x03') {
      *(int *)((int)register0x00000038 + 0x48) = *(int *)((int)register0x00000038 + 0x48) + 0x1000;
    }
    if (puVar4 <= puVar6) goto locret_F00A1AFC;
    uVar1 = *puVar6;
  } while( true );
}
