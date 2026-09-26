
/* WARNING: Removing unreachable block (ram,0xf00a1cb0) */
/* WARNING: Removing unreachable block (ram,0xf00a1ccc) */
/* WARNING: Removing unreachable block (ram,0xf00a1ca4) */

undefined8 _set_invalidptp(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  dword_F013DF4C = dword_F013DF4C + 1;
  if (*(char *)((int)param_1 + 0xd) == '\x03') {
    iVar3 = *param_1;
    uVar1 = param_2 >> 10 & 0xfc;
  }
  else if (*(char *)((int)param_1 + 0xd) == '\x02') {
    iVar3 = *param_1;
    uVar1 = param_2 >> 0x10 & 0xfc;
  }
  else {
    iVar3 = *param_1;
    uVar1 = (uint)*(byte *)((int)register0x00000038 + 0x48) << 2;
  }
  *(char *)((int)param_1 + 0xf) = *(char *)((int)param_1 + 0xf) + -1;
  if (*(char *)((int)param_1 + 0xd) == '\x03') {
    uVar4 = *(uint *)((int)register0x00000038 + 0x48) & ~_page_mask;
  }
  else {
    if (*(char *)((int)param_1 + 0xd) == '\x02') {
      uVar4 = 0xfffc0000;
    }
    else {
      uVar4 = 0xff000000;
    }
    uVar4 = *(uint *)((int)register0x00000038 + 0x48) & uVar4;
  }
  iVar2 = param_1[2];
  *(uint *)((int)register0x00000038 + 0x48) = uVar4;
  _get_context(iVar2);
  _check_pmap(param_1);
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  _mmu_writeptp(0,iVar3 + uVar1,*(undefined4 *)((int)register0x00000038 + 0x48),
                *(undefined *)((int)param_1 + 0xd),iVar2);
  return CONCAT44(iVar3 + uVar1,param_1);
}

