
/* WARNING: Removing unreachable block (ram,0xf00a179c) */
/* WARNING: Removing unreachable block (ram,0xf00a1790) */
/* WARNING: Removing unreachable block (ram,0xf00a17e0) */
/* WARNING: Removing unreachable block (ram,0xf00a1720) */

undefined8 _update_pte(undefined4 *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint *puVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
  undefined4 unaff_i1;
  uint *puVar5;
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
  piVar4 = (int *)*param_1;
  dword_F013DF3C = dword_F013DF3C + 1;
  if ((param_2 & _page_size - 1U) != 0) {
    _panic(aUpdatePteVaNot);
  }
  if (*(char *)((int)piVar4 + 0xd) == '\x03') {
    iVar2 = *piVar4;
    uVar1 = *(uint *)((int)register0x00000038 + 0x48) >> 10 & 0xfc;
  }
  else if (*(char *)((int)piVar4 + 0xd) == '\x02') {
    iVar2 = *piVar4;
    uVar1 = *(word *)((int)register0x00000038 + 0x48) & 0xfc;
  }
  else {
    iVar2 = *piVar4;
    uVar1 = (uint)*(byte *)((int)register0x00000038 + 0x48) << 2;
  }
  puVar5 = (uint *)(iVar2 + uVar1);
  puVar3 = puVar5 + 1;
  if (*(char *)((int)piVar4 + 0xd) == '\x03') {
    puVar3 = puVar5 + _pmap_info;
  }
  iVar2 = piVar4[2];
  _get_context(iVar2);
  _check_pmap(piVar4);
  if (puVar5 < puVar3) {
    uVar1 = *puVar5;
    while( true ) {
      uVar1 = uVar1 & 0xffffff63 | (param_3 & 7) << 2 | (param_4 & 1) << 7;
      *(uint *)((int)register0x00000038 + -0xc) = uVar1;
      _mmu_writepte(uVar1,puVar5,*(undefined4 *)((int)register0x00000038 + 0x48),
                    *(undefined *)((int)piVar4 + 0xd),iVar2);
      puVar5 = puVar5 + 1;
      if (*(char *)((int)piVar4 + 0xd) == '\x03') {
        *(int *)((int)register0x00000038 + 0x48) = *(int *)((int)register0x00000038 + 0x48) + 0x1000
        ;
      }
      if (puVar3 <= puVar5) break;
      uVar1 = *puVar5;
    }
  }
  return CONCAT44(puVar5,piVar4);
}

