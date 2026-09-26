
/* WARNING: Removing unreachable block (ram,0xf00a1688) */
/* WARNING: Removing unreachable block (ram,0xf00a15f0) */
/* WARNING: Removing unreachable block (ram,0xf00a16b0) */
/* WARNING: Removing unreachable block (ram,0xf00a1574) */

undefined8 _set_invalidpte(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar7;
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
  *(uint *)((int)register0x00000038 + 0x48) = param_2;
  piVar7 = (int *)*param_1;
  dword_F013DF38 = dword_F013DF38 + 1;
  if ((param_2 & _page_size - 1U) != 0) {
    _panic(aSetInvalidpteV);
  }
  if (*(char *)((int)piVar7 + 0xd) == '\x03') {
    iVar3 = *piVar7;
    uVar1 = *(uint *)((int)register0x00000038 + 0x48) >> 10 & 0xfc;
  }
  else if (*(char *)((int)piVar7 + 0xd) == '\x02') {
    iVar3 = *piVar7;
    uVar1 = *(word *)((int)register0x00000038 + 0x48) & 0xfc;
  }
  else {
    iVar3 = *piVar7;
    uVar1 = (uint)*(byte *)((int)register0x00000038 + 0x48) << 2;
  }
  uVar1 = iVar3 + uVar1;
  uVar6 = uVar1 + 4;
  if (*(char *)((int)piVar7 + 0xd) == '\x03') {
    uVar6 = uVar1 + (uint)_pmap_info * 4;
  }
  iVar3 = piVar7[2];
  *(char *)((int)piVar7 + 0xf) = *(char *)((int)piVar7 + 0xf) + -1;
  _get_context(iVar3);
  if (*(char *)((int)piVar7 + 0xd) == '\x03') {
    uVar5 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf;
    bVar4 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
  }
  else {
    if (*(char *)((int)piVar7 + 0xd) != '\x02') {
      bVar4 = *(byte *)((int)register0x00000038 + 0x48) >> 5;
      piVar7[bVar4 + 0xc] =
           piVar7[bVar4 + 0xc] & ~(1 << (*(byte *)((int)register0x00000038 + 0x48) & 0x1f));
      goto loc_F00A1688;
    }
    uVar5 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15;
    bVar4 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12) & 0x1f;
  }
  *(uint *)((int)piVar7 + (uVar5 & 4) + 0x18) =
       *(uint *)((int)piVar7 + (uVar5 & 4) + 0x18) & ~(1 << bVar4);
loc_F00A1688:
  _check_pmap(piVar7);
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  if (uVar1 < uVar6) {
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
    do {
      _mmu_writepte(uVar2,uVar1,*(undefined4 *)((int)register0x00000038 + 0x48),
                    *(undefined *)((int)piVar7 + 0xd),iVar3);
      uVar1 = uVar1 + 4;
      if (*(char *)((int)piVar7 + 0xd) == '\x03') {
        *(int *)((int)register0x00000038 + 0x48) = *(int *)((int)register0x00000038 + 0x48) + 0x1000
        ;
      }
      uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
    } while (uVar1 < uVar6);
  }
  return CONCAT44(uVar1,piVar7);
}

