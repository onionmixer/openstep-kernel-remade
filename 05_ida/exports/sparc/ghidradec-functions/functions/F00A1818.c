
/* WARNING: Removing unreachable block (ram,0xf00a18dc) */
/* WARNING: Removing unreachable block (ram,0xf00a18d0) */
/* WARNING: Removing unreachable block (ram,0xf00a193c) */
/* WARNING: Removing unreachable block (ram,0xf00a1854) */

undefined8
_set_pte(undefined4 *param_1,uint param_2,int param_3,uint param_4,uint param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar5;
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
  piVar5 = (int *)*param_1;
  *(uint *)((int)register0x00000038 + 0x48) = param_2;
  uVar4 = *(uint *)((int)register0x00000038 + 0x5c);
  dword_F013DF40 = dword_F013DF40 + 1;
  if ((param_2 & _page_size - 1U) != 0) {
    _panic(aSetPteVaNotAli);
  }
  if (*(char *)((int)piVar5 + 0xd) == '\x03') {
    iVar2 = *piVar5;
    uVar1 = *(uint *)((int)register0x00000038 + 0x48) >> 10 & 0xfc;
  }
  else if (*(char *)((int)piVar5 + 0xd) == '\x02') {
    iVar2 = *piVar5;
    uVar1 = *(word *)((int)register0x00000038 + 0x48) & 0xfc;
  }
  else {
    iVar2 = *piVar5;
    uVar1 = (uint)*(byte *)((int)register0x00000038 + 0x48) << 2;
  }
  uVar1 = iVar2 + uVar1;
  uVar3 = uVar1 + 4;
  if (*(char *)((int)piVar5 + 0xd) == '\x03') {
    uVar3 = uVar1 + (uint)_pmap_info * 4;
  }
  iVar2 = piVar5[2];
  *(char *)((int)piVar5 + 0xf) = *(char *)((int)piVar5 + 0xf) + '\x01';
  _get_context(iVar2);
  _check_pmap(piVar5);
  *(uint *)((int)register0x00000038 + -0xc) =
       (uVar4 & 1) << 5 |
       (param_5 & 1) << 7 | param_3 << 8 | (param_4 & 7) << 2 | (param_6 & 1) << 6 | 2;
  while (uVar1 < uVar3) {
    _mmu_writepte(*(undefined4 *)((int)register0x00000038 + -0xc),uVar1,
                  *(undefined4 *)((int)register0x00000038 + 0x48),*(undefined *)((int)piVar5 + 0xd),
                  iVar2);
    uVar1 = uVar1 + 4;
    if (*(char *)((int)piVar5 + 0xd) == '\x03') {
      *(int *)((int)register0x00000038 + 0x48) = *(int *)((int)register0x00000038 + 0x48) + 0x1000;
    }
    *(uint *)((int)register0x00000038 + -0xc) =
         *(uint *)((int)register0x00000038 + -0xc) & 0xff |
         (*(uint *)((int)register0x00000038 + -0xc) & 0xffffff00) + 0x100;
  }
  return CONCAT44(uVar1,piVar5);
}
