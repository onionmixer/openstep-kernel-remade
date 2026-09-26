
/* WARNING: Removing unreachable block (ram,0xf009fb38) */
/* WARNING: Removing unreachable block (ram,0xf009fb18) */
/* WARNING: Removing unreachable block (ram,0xf009fa98) */
/* WARNING: Removing unreachable block (ram,0xf009fad8) */
/* WARNING: Removing unreachable block (ram,0xf009fb28) */
/* WARNING: Removing unreachable block (ram,0xf009fb54) */
/* WARNING: Removing unreachable block (ram,0xf009fa60) */

undefined8 _copy_from_phys(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar7;
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
  uVar4 = param_1;
  _splvm();
  dword_F013DF20 = dword_F013DF20 + 1;
  do {
    do {
    } while (dword_F013E028 != 0);
    puVar5 = &dword_F013E028;
    _simple_lock_try();
    iVar3 = DAT_f013e024;
    uVar2 = dword_F013E020;
    iVar1 = _page_size;
  } while (puVar5 == (undefined4 *)0x0);
  for (; _page_size = iVar1, param_3 != 0; param_3 = param_3 - uVar6) {
    uVar7 = param_1;
    urem(param_1,iVar1);
    uVar6 = iVar1 - uVar7;
    if (param_3 < iVar1 - uVar7) {
      uVar6 = param_3;
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = uVar2;
    _set_pte((undefined *)((int)register0x00000038 + -0xc),iVar3,(param_1 & ~_page_mask) >> 0xc,7,1,
             0,0);
    uVar7 = param_1 + uVar6;
    urem(param_1,_page_size);
    _bcopy(iVar3 + param_1,param_2,uVar6);
    param_2 = param_2 + uVar6;
    param_1 = uVar7;
    iVar1 = _page_size;
  }
  dword_F013E028 = 0;
  _splx(uVar4);
  return CONCAT44(param_2,param_1);
}

