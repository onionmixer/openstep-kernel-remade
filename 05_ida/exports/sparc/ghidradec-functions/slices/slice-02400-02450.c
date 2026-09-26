/* GHIDRADEC_FUNCTION index=2400 start=0xf009f75c */

/* WARNING: Removing unreachable block (ram,0xf009f810) */
/* WARNING: Removing unreachable block (ram,0xf009f7ec) */
/* WARNING: Removing unreachable block (ram,0xf009f798) */
/* WARNING: Removing unreachable block (ram,0xf009f7fc) */
/* WARNING: Removing unreachable block (ram,0xf009f81c) */
/* WARNING: Removing unreachable block (ram,0xf009f760) */

undefined8 _pmap_zero_page(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
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
  uVar2 = param_1;
  _splvm();
  dword_F013DF14 = dword_F013DF14 + 1;
  do {
    do {
    } while (unk_F013E010 != 0);
    puVar3 = &unk_F013E010;
    _simple_lock_try();
    uVar1 = dword_F013E00C;
  } while (puVar3 == (undefined4 *)0x0);
  *(undefined4 *)((int)register0x00000038 + -0xc) = DAT_f013e008;
  _set_pte((undefined *)((int)register0x00000038 + -0xc),dword_F013E00C,
           (param_1 & ~_page_mask) >> 0xc,7,1,0,0);
  _bzero(uVar1,_page_size);
  _pmap_vacflush((param_1 & ~_page_mask) >> 0xc);
  unk_F013E010 = 0;
  _splx(uVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2401 start=0xf009f82c */

/* WARNING: Removing unreachable block (ram,0xf009f920) */
/* WARNING: Removing unreachable block (ram,0xf009f8f8) */
/* WARNING: Removing unreachable block (ram,0xf009f868) */
/* WARNING: Removing unreachable block (ram,0xf009f8c8) */
/* WARNING: Removing unreachable block (ram,0xf009f90c) */
/* WARNING: Removing unreachable block (ram,0xf009f92c) */
/* WARNING: Removing unreachable block (ram,0xf009f830) */

undefined8 _pmap_copy_page(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 *puVar5;
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
  uVar4 = param_1;
  _splvm();
  dword_F013DF18 = dword_F013DF18 + 1;
  do {
    do {
    } while (unk_F013E004._0_4_ != 0);
    puVar5 = &unk_F013E004;
    _simple_lock_try();
    uVar3 = unk_F013DFF4._12_4_;
    uVar2 = unk_F013DFF4._8_4_;
    uVar1 = unk_F013DFF4._0_4_;
  } while (puVar5 == (undefined8 *)0x0);
  *(undefined4 *)((int)register0x00000038 + -0xc) = _tmp_maps;
  _set_pte((undefined *)((int)register0x00000038 + -0xc),unk_F013DFF4._0_4_,
           (param_1 & ~_page_mask) >> 0xc,7,1,0,0);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uVar2;
  _set_pte((undefined *)((int)register0x00000038 + -0xc),uVar3,(param_2 & ~_page_mask) >> 0xc,7,1,0,
           0);
  _bcopy(uVar1,uVar3,_page_size);
  _pmap_vacflush((param_2 & ~_page_mask) >> 0xc);
  unk_F013E004._0_4_ = 0;
  _splx(uVar4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2402 start=0xf009f93c */

/* WARNING: Removing unreachable block (ram,0xf009fa30) */
/* WARNING: Removing unreachable block (ram,0xf009fa0c) */
/* WARNING: Removing unreachable block (ram,0xf009f9b8) */
/* WARNING: Removing unreachable block (ram,0xf009f978) */
/* WARNING: Removing unreachable block (ram,0xf009f9f8) */
/* WARNING: Removing unreachable block (ram,0xf009fa1c) */
/* WARNING: Removing unreachable block (ram,0xf009fa4c) */
/* WARNING: Removing unreachable block (ram,0xf009f940) */

undefined8 _copy_to_phys(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
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
  undefined4 unaff_i1;
  uint uVar7;
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
  iVar4 = param_1;
  _splvm();
  dword_F013DF1C = dword_F013DF1C + 1;
  do {
    do {
    } while (dword_F013E01C != 0);
    puVar5 = &dword_F013E01C;
    _simple_lock_try();
    iVar3 = DAT_f013e018;
    uVar2 = dword_F013E014;
    iVar1 = _page_size;
  } while (puVar5 == (undefined4 *)0x0);
  for (; _page_size = iVar1, param_3 != 0; param_3 = param_3 - uVar6) {
    uVar7 = param_2;
    .urem(param_2,iVar1);
    uVar6 = iVar1 - uVar7;
    if (param_3 < iVar1 - uVar7) {
      uVar6 = param_3;
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = uVar2;
    _set_pte((undefined *)((int)register0x00000038 + -0xc),iVar3,(param_2 & ~_page_mask) >> 0xc,7,1,
             0,0);
    _pmap_vacflush((param_2 & ~_page_mask) >> 0xc);
    uVar7 = param_2 + uVar6;
    .urem(param_2,_page_size);
    _bcopy(param_1,iVar3 + param_2,uVar6);
    param_1 = param_1 + uVar6;
    param_2 = uVar7;
    iVar1 = _page_size;
  }
  dword_F013E01C = 0;
  _splx(iVar4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2403 start=0xf009fa5c */

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
    .urem(param_1,iVar1);
    uVar6 = iVar1 - uVar7;
    if (param_3 < iVar1 - uVar7) {
      uVar6 = param_3;
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = uVar2;
    _set_pte((undefined *)((int)register0x00000038 + -0xc),iVar3,(param_1 & ~_page_mask) >> 0xc,7,1,
             0,0);
    uVar7 = param_1 + uVar6;
    .urem(param_1,_page_size);
    _bcopy(iVar3 + param_1,param_2,uVar6);
    param_2 = param_2 + uVar6;
    param_1 = uVar7;
    iVar1 = _page_size;
  }
  dword_F013E028 = 0;
  _splx(uVar4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2404 start=0xf009fb64 */

/* WARNING: Removing unreachable block (ram,0xf009fb6c) */

undefined8 _pmap_update_interrupt(undefined4 param_1,undefined4 param_2)

{
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
  _panic(aPmapUpdateInte);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2405 start=0xf009fb7c */

undefined8 _pmap_copy(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2406 start=0xf009fb88 */

undefined8 _pmap_update(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2407 start=0xf009fb94 */

undefined8 _pmap_pageable(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2408 start=0xf009fba0 */

/* WARNING: Removing unreachable block (ram,0xf00a1104) */
/* WARNING: Removing unreachable block (ram,0xf00a103c) */
/* WARNING: Removing unreachable block (ram,0xf00a0f74) */
/* WARNING: Removing unreachable block (ram,0xf00a0eac) */
/* WARNING: Removing unreachable block (ram,0xf00a0de4) */
/* WARNING: Removing unreachable block (ram,0xf00a0d1c) */
/* WARNING: Removing unreachable block (ram,0xf00a0c54) */
/* WARNING: Removing unreachable block (ram,0xf00a0b8c) */
/* WARNING: Removing unreachable block (ram,0xf00a0ac4) */
/* WARNING: Removing unreachable block (ram,0xf00a09fc) */
/* WARNING: Removing unreachable block (ram,0xf00a0934) */
/* WARNING: Removing unreachable block (ram,0xf00a086c) */
/* WARNING: Removing unreachable block (ram,0xf00a07a4) */
/* WARNING: Removing unreachable block (ram,0xf00a0730) */
/* WARNING: Removing unreachable block (ram,0xf00a06a4) */
/* WARNING: Removing unreachable block (ram,0xf00a05dc) */
/* WARNING: Removing unreachable block (ram,0xf00a0514) */
/* WARNING: Removing unreachable block (ram,0xf00a044c) */
/* WARNING: Removing unreachable block (ram,0xf00a0384) */
/* WARNING: Removing unreachable block (ram,0xf00a02bc) */
/* WARNING: Removing unreachable block (ram,0xf00a01f4) */
/* WARNING: Removing unreachable block (ram,0xf00a012c) */
/* WARNING: Removing unreachable block (ram,0xf00a0064) */
/* WARNING: Removing unreachable block (ram,0xf009fff0) */
/* WARNING: Removing unreachable block (ram,0xf009ff64) */
/* WARNING: Removing unreachable block (ram,0xf009fe9c) */
/* WARNING: Removing unreachable block (ram,0xf009fdd4) */
/* WARNING: Removing unreachable block (ram,0xf009fd0c) */
/* WARNING: Removing unreachable block (ram,0xf009fce4) */
/* WARNING: Removing unreachable block (ram,0xf009fcc0) */
/* WARNING: Removing unreachable block (ram,0xf009fca0) */
/* WARNING: Removing unreachable block (ram,0xf009fc78) */
/* WARNING: Removing unreachable block (ram,0xf009fc54) */
/* WARNING: Removing unreachable block (ram,0xf009fc34) */
/* WARNING: Removing unreachable block (ram,0xf009fc0c) */
/* WARNING: Removing unreachable block (ram,0xf009fbec) */
/* WARNING: Removing unreachable block (ram,0xf009fbdc) */
/* WARNING: Removing unreachable block (ram,0xf009fbfc) */
/* WARNING: Removing unreachable block (ram,0xf009fc20) */
/* WARNING: Removing unreachable block (ram,0xf009fc44) */
/* WARNING: Removing unreachable block (ram,0xf009fc64) */
/* WARNING: Removing unreachable block (ram,0xf009fc8c) */
/* WARNING: Removing unreachable block (ram,0xf009fcb0) */
/* WARNING: Removing unreachable block (ram,0xf009fcd0) */
/* WARNING: Removing unreachable block (ram,0xf009fcf8) */
/* WARNING: Removing unreachable block (ram,0xf009fd70) */
/* WARNING: Removing unreachable block (ram,0xf009fe38) */
/* WARNING: Removing unreachable block (ram,0xf009ff00) */
/* WARNING: Removing unreachable block (ram,0xf009ffc8) */
/* WARNING: Removing unreachable block (ram,0xf00a0000) */
/* WARNING: Removing unreachable block (ram,0xf00a00c8) */
/* WARNING: Removing unreachable block (ram,0xf00a0190) */
/* WARNING: Removing unreachable block (ram,0xf00a0258) */
/* WARNING: Removing unreachable block (ram,0xf00a0320) */
/* WARNING: Removing unreachable block (ram,0xf00a03e8) */
/* WARNING: Removing unreachable block (ram,0xf00a04b0) */
/* WARNING: Removing unreachable block (ram,0xf00a0578) */
/* WARNING: Removing unreachable block (ram,0xf00a0640) */
/* WARNING: Removing unreachable block (ram,0xf00a0708) */
/* WARNING: Removing unreachable block (ram,0xf00a0740) */
/* WARNING: Removing unreachable block (ram,0xf00a0808) */
/* WARNING: Removing unreachable block (ram,0xf00a08d0) */
/* WARNING: Removing unreachable block (ram,0xf00a0998) */
/* WARNING: Removing unreachable block (ram,0xf00a0a60) */
/* WARNING: Removing unreachable block (ram,0xf00a0b28) */
/* WARNING: Removing unreachable block (ram,0xf00a0bf0) */
/* WARNING: Removing unreachable block (ram,0xf00a0cb8) */
/* WARNING: Removing unreachable block (ram,0xf00a0d80) */
/* WARNING: Removing unreachable block (ram,0xf00a0e48) */
/* WARNING: Removing unreachable block (ram,0xf00a0f10) */
/* WARNING: Removing unreachable block (ram,0xf00a0fd8) */
/* WARNING: Removing unreachable block (ram,0xf00a10a0) */
/* WARNING: Removing unreachable block (ram,0xf00a1168) */
/* WARNING: Removing unreachable block (ram,0xf009fbc8) */

undefined8 _pmap_print_info(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
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
  if (_pmap_var_info != 0) {
    _printf(aDRegTblsVmPage,word_F013DE72,word_F013DE74);
    _printf(aDRegPoolsVmPag,word_F013DE76,word_F013DE78);
    _printf(aTksegtblsD,DAT_f013de7c._0_4_);
    _printf(aNksegtblsInuse,DAT_f013de7c._8_4_);
    _printf(aTksegpoolsD,DAT_f013de7c._4_4_);
    _printf(aKsegActiveCoun,dword_F013DE38);
    _printf(aKsegSemiActive,dword_F013DE48);
    _printf(aNuregtblsAlloc,DAT_f013de7c._28_4_);
    _printf(aNuregtblsInuse,DAT_f013de7c._24_4_);
    _printf(aNuregpoolsD,DAT_f013de7c._32_4_);
    _printf(aRegFreeCountD,dword_F013DFA8);
    _printf(aRegSemiActiveC,dword_F013DFB8);
    _printf(aRegActiveCount,dword_F013DF98);
    _printf(aNusegtblsAlloc,DAT_f013de7c._16_4_);
    _printf(aNusegtblsInuse,DAT_f013de7c._12_4_);
    _printf(aNusegpoolsD,DAT_f013de7c._20_4_);
    _printf(aSegFreeCountD,dword_F013DFD8);
    _printf(aSegSemiActiveC,dword_F013DFE8);
    _printf(aSegActiveCount,dword_F013DFC8);
  }
  if ((dword_F013DEA0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapVacflushD;
    iVar2 = 0;
loc_F009FD70:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEA0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapVacflushD_0;
    iVar2 = dword_F013DEA0;
    goto loc_F009FD70;
  }
  if ((dword_F013DEA4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapMapD;
    iVar2 = 0;
loc_F009FDD4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEA4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapMapD_0;
    iVar2 = dword_F013DEA4;
    goto loc_F009FDD4;
  }
  if ((dword_F013DEA8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapChangeProt;
    iVar2 = 0;
loc_F009FE38:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEA8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapChangeProt_0;
    iVar2 = dword_F013DEA8;
    goto loc_F009FE38;
  }
  if ((dword_F013DEAC == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapCreateD;
    iVar2 = 0;
loc_F009FE9C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEAC != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapCreateD_0;
    iVar2 = dword_F013DEAC;
    goto loc_F009FE9C;
  }
  if ((dword_F013DEB0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapDestroyD;
    iVar2 = 0;
loc_F009FF00:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEB0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapDestroyD_0;
    iVar2 = dword_F013DEB0;
    goto loc_F009FF00;
  }
  if ((dword_F013DEB4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapReferenceD;
    iVar2 = 0;
loc_F009FF64:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEB4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapReferenceD_0;
    iVar2 = dword_F013DEB4;
    goto loc_F009FF64;
  }
  if ((dword_F013DEB8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapPageTableE_3;
    iVar2 = 0;
loc_F009FFC8:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEB8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapPageTableE_4;
    iVar2 = dword_F013DEB8;
    goto loc_F009FFC8;
  }
  if (_pmap_opt_info != 0) {
    _printf(aPmapPageTableE_5,dword_F013DEB8);
    _printf(aPmapPageTableE_6,DAT_f013debc);
  }
  if ((dword_F013DEC0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapGetpteD;
    iVar2 = 0;
loc_F00A0064:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEC0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapGetpteD_0;
    iVar2 = dword_F013DEC0;
    goto loc_F00A0064;
  }
  if ((dword_F013DEC4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapRemoveD;
    iVar2 = 0;
loc_F00A00C8:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEC4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapRemoveD_0;
    iVar2 = dword_F013DEC4;
    goto loc_F00A00C8;
  }
  if ((dword_F013DEC8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapRemoveAllD;
    iVar2 = 0;
loc_F00A012C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEC8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapRemoveAllD_0;
    iVar2 = dword_F013DEC8;
    goto loc_F00A012C;
  }
  if ((dword_F013DECC == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapExpandD;
    iVar2 = 0;
loc_F00A0190:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DECC != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapExpandD_0;
    iVar2 = dword_F013DECC;
    goto loc_F00A0190;
  }
  if ((dword_F013DED0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapEnterDevD;
    iVar2 = 0;
loc_F00A01F4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DED0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapEnterDevD_0;
    iVar2 = dword_F013DED0;
    goto loc_F00A01F4;
  }
  if ((dword_F013DED4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapEnterCache;
    iVar2 = 0;
loc_F00A0258:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DED4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapEnterCache_0;
    iVar2 = dword_F013DED4;
    goto loc_F00A0258;
  }
  if ((dword_F013DED8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapEnterShare;
    iVar2 = 0;
loc_F00A02BC:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DED8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapEnterShare_0;
    iVar2 = dword_F013DED8;
    goto loc_F00A02BC;
  }
  if ((dword_F013DEDC == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapCopyOnWrit;
    iVar2 = 0;
loc_F00A0320:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEDC != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapCopyOnWrit_0;
    iVar2 = dword_F013DEDC;
    goto loc_F00A0320;
  }
  if ((dword_F013DEE0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapMovePageD;
    iVar2 = 0;
loc_F00A0384:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEE0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapMovePageD_0;
    iVar2 = dword_F013DEE0;
    goto loc_F00A0384;
  }
  if ((dword_F013DEE4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapProtectD;
    iVar2 = 0;
loc_F00A03E8:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEE4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapProtectD_0;
    iVar2 = dword_F013DEE4;
    goto loc_F00A03E8;
  }
  if ((dword_F013DEE8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapPageProtec;
    iVar2 = 0;
loc_F00A044C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEE8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapPageProtec_0;
    iVar2 = dword_F013DEE8;
    goto loc_F00A044C;
  }
  if ((dword_F013DEEC == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapChangeWiri_0;
    iVar2 = 0;
loc_F00A04B0:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEEC != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapChangeWiri_1;
    iVar2 = dword_F013DEEC;
    goto loc_F00A04B0;
  }
  if ((dword_F013DEF0 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapResidentEx;
    iVar2 = 0;
loc_F00A0514:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEF0 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapResidentEx_0;
    iVar2 = dword_F013DEF0;
    goto loc_F00A0514;
  }
  if ((dword_F013DEF4 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapExtractD;
    iVar2 = 0;
loc_F00A0578:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEF4 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapExtractD_0;
    iVar2 = dword_F013DEF4;
    goto loc_F00A0578;
  }
  if ((dword_F013DEF8 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapClearPageA;
    iVar2 = 0;
loc_F00A05DC:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEF8 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapClearPageA_0;
    iVar2 = dword_F013DEF8;
    goto loc_F00A05DC;
  }
  if ((dword_F013DEFC == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapCheckPageA_0;
    iVar2 = 0;
loc_F00A0640:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DEFC != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapCheckPageA_1;
    iVar2 = dword_F013DEFC;
    goto loc_F00A0640;
  }
  if ((dword_F013DF00 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapCollectD;
    iVar2 = 0;
loc_F00A06A4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF00 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapCollectD_0;
    iVar2 = dword_F013DF00;
    goto loc_F00A06A4;
  }
  if ((dword_F013DF04 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapActivateD;
    iVar2 = 0;
loc_F00A0708:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF04 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapActivateD_0;
    iVar2 = dword_F013DF04;
    goto loc_F00A0708;
  }
  if (_pmap_opt_info != 0) {
    _printf(aPmapActivateD_1,dword_F013DF04);
    _printf(aPmapActivateAc,DAT_f013df08);
  }
  if ((dword_F013DF0C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapDeactivate;
    iVar2 = 0;
loc_F00A07A4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF0C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapDeactivate_0;
    iVar2 = dword_F013DF0C;
    goto loc_F00A07A4;
  }
  if ((dword_F013DF10 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapKernelD;
    iVar2 = 0;
loc_F00A0808:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF10 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapKernelD_0;
    iVar2 = dword_F013DF10;
    goto loc_F00A0808;
  }
  if ((dword_F013DF14 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapZeroPageD;
    iVar2 = 0;
loc_F00A086C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF14 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapZeroPageD_0;
    iVar2 = dword_F013DF14;
    goto loc_F00A086C;
  }
  if ((dword_F013DF18 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapCopyPageD;
    iVar2 = 0;
loc_F00A08D0:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF18 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapCopyPageD_0;
    iVar2 = dword_F013DF18;
    goto loc_F00A08D0;
  }
  if ((dword_F013DF1C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aCopyToPhysD;
    iVar2 = 0;
loc_F00A0934:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF1C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aCopyToPhysD_0;
    iVar2 = dword_F013DF1C;
    goto loc_F00A0934;
  }
  if ((dword_F013DF20 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aCopyFromPhysD;
    iVar2 = 0;
loc_F00A0998:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF20 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aCopyFromPhysD_0;
    iVar2 = dword_F013DF20;
    goto loc_F00A0998;
  }
  if ((dword_F013DF24 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aAddPoolD;
    iVar2 = 0;
loc_F00A09FC:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF24 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aAddPoolD_0;
    iVar2 = dword_F013DF24;
    goto loc_F00A09FC;
  }
  if ((dword_F013DF28 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aDelFirstPoolD;
    iVar2 = 0;
loc_F00A0A60:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF28 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aDelFirstPoolD_0;
    iVar2 = dword_F013DF28;
    goto loc_F00A0A60;
  }
  if ((dword_F013DF2C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aDelAnyPoolD;
    iVar2 = 0;
loc_F00A0AC4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF2C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aDelAnyPoolD_0;
    iVar2 = dword_F013DF2C;
    goto loc_F00A0AC4;
  }
  if ((dword_F013DF30 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aVmToSrmmuProtD;
    iVar2 = 0;
loc_F00A0B28:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF30 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aVmToSrmmuProtD_0;
    iVar2 = dword_F013DF30;
    goto loc_F00A0B28;
  }
  if ((dword_F013DF34 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSrmmuToVmProtD;
    iVar2 = 0;
loc_F00A0B8C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF34 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSrmmuToVmProtD_0;
    iVar2 = dword_F013DF34;
    goto loc_F00A0B8C;
  }
  if ((dword_F013DF38 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSetInvalidpteD;
    iVar2 = 0;
loc_F00A0BF0:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF38 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSetInvalidpteD_0;
    iVar2 = dword_F013DF38;
    goto loc_F00A0BF0;
  }
  if ((dword_F013DF3C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aUpdatePteD;
    iVar2 = 0;
loc_F00A0C54:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF3C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aUpdatePteD_0;
    iVar2 = dword_F013DF3C;
    goto loc_F00A0C54;
  }
  if ((dword_F013DF40 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSetPteD;
    iVar2 = 0;
loc_F00A0CB8:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF40 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSetPteD_0;
    iVar2 = dword_F013DF40;
    goto loc_F00A0CB8;
  }
  if ((dword_F013DF44 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSetPteModrefD;
    iVar2 = 0;
loc_F00A0D1C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF44 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSetPteModrefD_0;
    iVar2 = dword_F013DF44;
    goto loc_F00A0D1C;
  }
  if ((dword_F013DF48 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSetPtpD;
    iVar2 = 0;
loc_F00A0D80:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF48 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSetPtpD_0;
    iVar2 = dword_F013DF48;
    goto loc_F00A0D80;
  }
  if ((dword_F013DF4C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aSetInvalidptpD;
    iVar2 = 0;
loc_F00A0DE4:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF4C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aSetInvalidptpD_0;
    iVar2 = dword_F013DF4C;
    goto loc_F00A0DE4;
  }
  if ((dword_F013DF50 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapAllocRegEn;
    iVar2 = 0;
loc_F00A0E48:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF50 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapAllocRegEn_0;
    iVar2 = dword_F013DF50;
    goto loc_F00A0E48;
  }
  if ((dword_F013DF54 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapDeallocReg;
    iVar2 = 0;
loc_F00A0EAC:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF54 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapDeallocReg_0;
    iVar2 = dword_F013DF54;
    goto loc_F00A0EAC;
  }
  if ((dword_F013DF58 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapSegEntryD;
    iVar2 = 0;
loc_F00A0F10:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF58 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapSegEntryD_0;
    iVar2 = dword_F013DF58;
    goto loc_F00A0F10;
  }
  if ((dword_F013DF5C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapAllocKsegE;
    iVar2 = 0;
loc_F00A0F74:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF5C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapAllocKsegE_0;
    iVar2 = dword_F013DF5C;
    goto loc_F00A0F74;
  }
  if ((dword_F013DF60 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapDeallocKse;
    iVar2 = 0;
loc_F00A0FD8:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF60 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapDeallocKse_0;
    iVar2 = dword_F013DF60;
    goto loc_F00A0FD8;
  }
  if ((dword_F013DF64 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapAllocSegEn;
    iVar2 = 0;
loc_F00A103C:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF64 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapAllocSegEn_0;
    iVar2 = dword_F013DF64;
    goto loc_F00A103C;
  }
  if ((dword_F013DF68 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapDeallocSeg;
    iVar2 = 0;
loc_F00A10A0:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF68 != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapDeallocSeg_0;
    iVar2 = dword_F013DF68;
    goto loc_F00A10A0;
  }
  if ((dword_F013DF6C == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aPmapAllocConte;
    iVar2 = 0;
loc_F00A1104:
    _printf(puVar1,iVar2);
  }
  else if ((dword_F013DF6C != 0) && (_pmap_func_info1 != 0)) {
    puVar1 = aPmapAllocConte_0;
    iVar2 = dword_F013DF6C;
    goto loc_F00A1104;
  }
  if ((dword_F013DF70 == 0) && (_pmap_func_info0 != 0)) {
    puVar1 = aGarbageCollect;
    iVar2 = 0;
  }
  else {
    if ((dword_F013DF70 == 0) || (_pmap_func_info1 == 0)) goto locret_F00A1170;
    puVar1 = aGarbageCollect_0;
    iVar2 = dword_F013DF70;
  }
  _printf(puVar1,iVar2);
locret_F00A1170:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2409 start=0xf00a1178 */

/* WARNING: Removing unreachable block (ram,0xf00a1220) */
/* WARNING: Removing unreachable block (ram,0xf00a11c8) */
/* WARNING: Removing unreachable block (ram,0xf00a11f8) */
/* WARNING: Removing unreachable block (ram,0xf00a123c) */
/* WARNING: Removing unreachable block (ram,0xf00a11ac) */

undefined8 _pmap_attribute(int param_1,uint param_2,int param_3,int param_4,int *param_5)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if (param_4 == 1) {
    uVar4 = 0;
    if (param_1 == 0) {
      uVar4 = 0;
    }
    else {
      param_2 = param_2 & ~_page_mask;
      uVar1 = _page_mask;
      _splvm();
      do {
        do {
        } while (*(int *)(param_1 + 0x18) != 0);
        piVar2 = (int *)(param_1 + 0x18);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      if (*param_5 < 9) {
        if (*param_5 < 6) {
          uVar4 = 4;
        }
        else {
          iVar3 = param_1;
          _get_context();
          uVar5 = param_2 + param_3;
          if (iVar3 != -1) {
            for (; param_2 < uVar5; param_2 = param_2 + 0x1000) {
              _vac_pagectxflush(param_2,iVar3);
            }
          }
        }
      }
      else {
        uVar4 = 4;
      }
      *(undefined4 *)(param_1 + 0x18) = 0;
      _splx(uVar1);
    }
  }
  else {
    uVar4 = 4;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=2410 start=0xf00a1250 */

undefined8 _get_context(int param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else if (*(int *)(iVar1 + 8) == param_1) {
    iVar1 = (iVar1 - _context_table) * -0x55555555 >> 2;
  }
  else {
    iVar1 = -1;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2411 start=0xf00a12b0 */

/* WARNING: Removing unreachable block (ram,0xf00a1384) */
/* WARNING: Removing unreachable block (ram,0xf00a130c) */
/* WARNING: Removing unreachable block (ram,0xf00a1300) */
/* WARNING: Removing unreachable block (ram,0xf00a135c) */
/* WARNING: Removing unreachable block (ram,0xf00a13ac) */
/* WARNING: Removing unreachable block (ram,0xf00a12ec) */

undefined8 _pmap_vacflush(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 *puVar5;
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
  bool bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  dword_F013DEA0 = dword_F013DEA0 + 1;
  if (((_vac != 0) && (bVar6 = param_1 < _physmaxpfn, param_1 = param_1 << 0xc, bVar6)) &&
     (uVar1 = param_1, _vm_valid_page(), uVar1 != 0)) {
    _splvm();
    uVar2 = param_1;
    _vm_mem_ppi();
    puVar5 = (undefined4 *)(_pg_desc_tbl + uVar2 * 0x14);
    if ((puVar5[1] != 0) && (puVar5 != (undefined4 *)0x0)) {
      uVar2 = puVar5[2];
      do {
        iVar4 = 0;
        param_1 = puVar5[1];
        iVar3 = (uVar2 >> 8) << 0xc;
        _get_context();
        if (param_1 == 0xffffffff) {
          puVar5 = (undefined4 *)*puVar5;
        }
        else {
          do {
            if ((int)(uint)_pmap_info <= iVar4) break;
            _vac_pagectxflush(iVar3,param_1);
            iVar3 = iVar3 + 0x1000;
            iVar4 = iVar4 + 1;
          } while (param_1 != 0xffffffff);
          puVar5 = (undefined4 *)*puVar5;
        }
        if (puVar5 == (undefined4 *)0x0) break;
        uVar2 = puVar5[2];
      } while( true );
    }
    _splx(uVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2412 start=0xf00a13bc */

undefined8 _add_pool(int *param_1,int param_2)

{
  int *piVar1;
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
  dword_F013DF24 = dword_F013DF24 + 1;
  piVar1 = (int *)*param_1;
  if (param_1 == piVar1) {
    param_1[1] = param_2;
  }
  else {
    piVar1[4] = param_2;
  }
  *(int **)(param_2 + 0xc) = piVar1;
  *(int **)(param_2 + 0x10) = param_1;
  *param_1 = param_2;
  param_1[2] = param_1[2] + 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2413 start=0xf00a1408 */

undefined8 _del_first_pool(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
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
  dword_F013DF28 = dword_F013DF28 + 1;
  iVar2 = *param_1;
  piVar1 = *(int **)(iVar2 + 0xc);
  if (param_1 == piVar1) {
    param_1[1] = (int)param_1;
  }
  else {
    piVar1[4] = (int)param_1;
  }
  *param_1 = (int)piVar1;
  param_1[2] = param_1[2] + -1;
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=2414 start=0xf00a1450 */

undefined8 _del_any_pool(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
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
  dword_F013DF2C = dword_F013DF2C + 1;
  piVar2 = *(int **)(param_2 + 0xc);
  piVar1 = *(int **)(param_2 + 0x10);
  if (param_1 == piVar2) {
    param_1[1] = (int)piVar1;
  }
  else {
    piVar2[4] = (int)piVar1;
  }
  if (param_1 == piVar1) {
    *param_1 = (int)piVar2;
  }
  else {
    piVar1[3] = (int)piVar2;
  }
  param_1[2] = param_1[2] + -1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2415 start=0xf00a14a8 */

/* WARNING: Removing unreachable block (ram,0xf00a14cc) */

undefined8 _vm_to_srmmu_prot(int param_1,int param_2)

{
  undefined *puVar1;
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
  dword_F013DF30 = dword_F013DF30 + 1;
  if (param_2 == 0) {
    _panic(aVmToSrmmuProtV);
  }
  if (param_1 == _kernel_pmap) {
    puVar1 = unk_F0118DB4;
  }
  else {
    puVar1 = DAT_f0118d94;
  }
  return CONCAT44(param_2,*(undefined4 *)(puVar1 + param_2 * 4));
}
/* GHIDRADEC_FUNCTION index=2416 start=0xf00a1508 */

undefined8 _srmmu_to_vm_prot(uint param_1,undefined4 param_2)

{
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
  dword_F013DF34 = dword_F013DF34 + 1;
  return CONCAT44(param_2,*(undefined4 *)(unk_F0118DF8 + (param_1 & 7) * 4));
}
/* GHIDRADEC_FUNCTION index=2417 start=0xf00a153c */

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
/* GHIDRADEC_FUNCTION index=2418 start=0xf00a16e8 */

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
/* GHIDRADEC_FUNCTION index=2419 start=0xf00a1818 */

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
/* GHIDRADEC_FUNCTION index=2420 start=0xf00a1988 */

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
/* GHIDRADEC_FUNCTION index=2421 start=0xf00a1b04 */

/* WARNING: Removing unreachable block (ram,0xf00a1bcc) */
/* WARNING: Removing unreachable block (ram,0xf00a1be4) */
/* WARNING: Removing unreachable block (ram,0xf00a1bc0) */

undefined8 _set_ptp(int *param_1,uint param_2,uint param_3)

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
  dword_F013DF48 = dword_F013DF48 + 1;
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
  *(char *)((int)param_1 + 0xf) = *(char *)((int)param_1 + 0xf) + '\x01';
  *(uint *)((int)register0x00000038 + -0xc) = (param_3 >> 6) << 2 | 1;
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
  _mmu_writeptp(*(undefined4 *)((int)register0x00000038 + -0xc),iVar3 + uVar1,
                *(undefined4 *)((int)register0x00000038 + 0x48),*(undefined *)((int)param_1 + 0xd),
                iVar2);
  return CONCAT44(iVar3 + uVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=2422 start=0xf00a1bf4 */

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
/* GHIDRADEC_FUNCTION index=2423 start=0xf00a1cdc */

/* WARNING: Removing unreachable block (ram,0xf00a1d44) */
/* WARNING: Removing unreachable block (ram,0xf00a1d64) */
/* WARNING: Removing unreachable block (ram,0xf00a1d0c) */

undefined8 _fill_pmapinfo(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
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
  _pmap_info = (undefined2)(_page_size >> 0xc);
  if (0x40 < (_page_size >> 0xc & 0xffff)) {
    _panic(aFillPmapinfoVi);
  }
  uVar2 = _page_size;
  word_F013DE72 = (undefined2)(_page_size >> 10);
  uVar3 = _page_size >> 8;
  word_F013DE74 = (undefined2)(_page_size >> 8);
  uVar1 = _page_size;
  .udiv(_page_size,(_page_size >> 10 & 0xffff) * 0x54);
  word_F013DE76 = (undefined2)uVar1;
  .udiv(uVar2,(uVar3 & 0xffff) * 0x28);
  word_F013DE78 = (sword)uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2424 start=0xf00a1d78 */

/* WARNING: Removing unreachable block (ram,0xf00a1e74) */
/* WARNING: Removing unreachable block (ram,0xf00a1df4) */
/* WARNING: Removing unreachable block (ram,0xf00a1e38) */
/* WARNING: Removing unreachable block (ram,0xf00a1e9c) */
/* WARNING: Removing unreachable block (ram,0xf00a1de8) */

undefined8 _init_kernel_page_tables(int param_1,undefined *param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  int iVar4;
  int *piVar5;
  undefined4 unaff_l3;
  int *piVar6;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  int iVar8;
  undefined4 unaff_l6;
  int iVar9;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  uint auStackX_0 [23];
  
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
  DAT_f013de34 = &_kseg_active;
  _kseg_active._0_4_ = &_kseg_active;
  dword_F013DE38 = 0;
  DAT_f013de44 = &_kseg_semi_active;
  _kseg_semi_active._0_4_ = &_kseg_semi_active;
  dword_F013DE48 = 0;
  iVar10 = 0;
  if (0 < param_1) {
    param_2 = DAT_f013dc00;
    piVar6 = (int *)(_kernel_seg_pools + 0x18);
    piVar5 = _kernel_seg_entries;
    iVar7 = _kernel_seg_tables;
    iVar8 = _kernel_seg_pools;
    iVar9 = _kernel_seg_tables_phys;
    do {
      _bzero(iVar7,_page_size);
      _bzero(iVar8,0x20);
      piVar6[-4] = iVar7;
      piVar6[-5] = iVar9;
      *(word *)(piVar6 + 1) = word_F013DE74;
      *(word *)((int)piVar6 + 6) = word_F013DE74;
      *piVar6 = (int)piVar5;
      iVar4 = 0;
      if (word_F013DE74 != 0) {
        puVar3 = (undefined *)((int)piVar5 + 0xe);
        do {
          _bzero(piVar5,0x28);
          *(int *)(puVar3 + -10) = iVar8;
          puVar3[-1] = 0;
          *puVar3 = (char)iVar4;
          *piVar5 = iVar7;
          iVar7 = iVar7 + 0x100;
          iVar9 = iVar9 + 0x100;
          puVar3 = puVar3 + 0x28;
          iVar4 = iVar4 + 1;
          piVar5 = piVar5 + 10;
        } while (iVar4 < (int)(uint)word_F013DE74);
      }
      _add_pool(&_kseg_semi_active,iVar8);
      iVar10 = iVar10 + 1;
      piVar6 = piVar6 + 8;
      iVar8 = iVar8 + 0x20;
    } while (iVar10 < param_1);
  }
  _bzero(_kernel_reg_entry,0x54);
  DAT_f013e07d[0] = 1;
  _kernel_pmap = _kernel_pmap_store;
  _kernel_pmap_store._0_4_ = _kernel_reg_entry;
  DAT_f013e078._0_4_ = _kernel_pmap_store;
  _active_pmap = _kernel_pmap_store;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0;
  iVar10 = 0;
  _kernel_reg_entry._0_4_ = _kernel_region;
  _kernel_pmap_store._20_4_ = _context_table;
  *(undefined **)(_context_table + 8) = _kernel_pmap_store;
  _kernel_pmap_store._28_4_ = 1;
  _kernel_pmap_store._36_4_ = 1;
  _kernel_pmap_store._32_4_ = 1;
  _kernel_pmap_store._24_4_ = 0;
  *(undefined *)((int)register0x00000038 + -0x23) = 3;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  do {
    if (*(char *)((int)register0x00000038 + -0x23) == '\x03') {
      uVar2 = *(uint *)((int)register0x00000038 + -0x34) >> 0xf & 4;
      bVar1 = (byte)(*(uint *)((int)register0x00000038 + -0x34) >> 0xc) & 0x1e;
    }
    else {
      bVar1 = *(byte *)((int)register0x00000038 + -0x34);
      if (*(char *)((int)register0x00000038 + -0x23) == '\x02') {
        bVar1 = (byte)(*(uint *)((int)register0x00000038 + -0x34) >> 0x12);
        uVar2 = *(uint *)((int)register0x00000038 + -0x34) >> 0x15 & 4;
      }
      else {
        uVar2 = (uint)(bVar1 >> 5) << 2;
      }
      bVar1 = bVar1 & 0x1f;
    }
    *(uint *)((int)register0x00000038 + (uVar2 - 0x20)) =
         *(uint *)((int)register0x00000038 + (uVar2 - 0x20)) | 1 << bVar1;
    if (*(char *)((int)register0x00000038 + -0x23) == '\x03') {
      uVar2 = *(uint *)((int)register0x00000038 + -0x34) >> 0xf;
      bVar1 = (byte)(*(uint *)((int)register0x00000038 + -0x34) >> 0xc) & 0x1e;
loc_F00A1FDC:
      *(uint *)((int)register0x00000038 + ((uVar2 & 4) - 0x18)) =
           *(uint *)((int)register0x00000038 + ((uVar2 & 4) - 0x18)) | 1 << bVar1;
    }
    else {
      if (*(char *)((int)register0x00000038 + -0x23) == '\x02') {
        uVar2 = *(uint *)((int)register0x00000038 + -0x34) >> 0x15;
        bVar1 = (byte)(*(uint *)((int)register0x00000038 + -0x34) >> 0x12) & 0x1f;
        goto loc_F00A1FDC;
      }
      iVar7 = (uint)(*(byte *)((int)register0x00000038 + -0x34) >> 5) * 4;
      *(uint *)((int)register0x00000038 + iVar7) =
           *(uint *)((int)register0x00000038 + iVar7) |
           1 << (*(byte *)((int)register0x00000038 + -0x34) & 0x1f);
    }
    iVar10 = iVar10 + 1;
    *(int *)((int)register0x00000038 + -0x34) = *(int *)((int)register0x00000038 + -0x34) + 0x1000;
    if (0x3f < iVar10) {
      _wmap0 = *(undefined4 *)((int)register0x00000038 + -0x20);
      _wmap1 = *(undefined4 *)((int)register0x00000038 + -0x1c);
      _mmap0 = *(undefined4 *)((int)register0x00000038 + -0x18);
      _mmap1 = *(undefined4 *)((int)register0x00000038 + -0x14);
      return CONCAT44(param_2,iVar10);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2425 start=0xf00a2060 */

/* WARNING: Removing unreachable block (ram,0xf00a225c) */
/* WARNING: Removing unreachable block (ram,0xf00a21f4) */
/* WARNING: Removing unreachable block (ram,0xf00a21ac) */
/* WARNING: Removing unreachable block (ram,0xf00a217c) */
/* WARNING: Removing unreachable block (ram,0xf00a23f4) */
/* WARNING: Removing unreachable block (ram,0xf00a2380) */
/* WARNING: Removing unreachable block (ram,0xf00a2338) */
/* WARNING: Removing unreachable block (ram,0xf00a2120) */
/* WARNING: Removing unreachable block (ram,0xf00a20b8) */
/* WARNING: Removing unreachable block (ram,0xf00a2308) */
/* WARNING: Removing unreachable block (ram,0xf00a2344) */
/* WARNING: Removing unreachable block (ram,0xf00a23b8) */
/* WARNING: Removing unreachable block (ram,0xf00a2164) */
/* WARNING: Removing unreachable block (ram,0xf00a2198) */
/* WARNING: Removing unreachable block (ram,0xf00a21bc) */
/* WARNING: Removing unreachable block (ram,0xf00a21fc) */
/* WARNING: Removing unreachable block (ram,0xf00a22d0) */
/* WARNING: Removing unreachable block (ram,0xf00a22f4) */
/* WARNING: Removing unreachable block (ram,0xf00a2090) */

undefined8 _pmap_alloc_reg_entry(int *param_1)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  int *piVar9;
  undefined4 unaff_l4;
  int iVar10;
  int iVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  int iVar12;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar13;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
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
  dword_F013DF50 = dword_F013DF50 + 1;
  piVar13 = param_1;
  while (dword_F013DFB8 == 0) {
    if (dword_F013DFA8 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      iVar8 = _kernel_map;
      _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),_page_size);
      if (iVar8 != 0) {
        _panic(aPmapAllocRegEn_3);
      }
      iVar8 = 0;
      iVar11 = 0;
      iVar10 = *(int *)((int)register0x00000038 + -0xc);
      if (word_F013DE76 != 0) {
        piVar13 = (int *)0x1;
        iVar12 = iVar8;
        do {
          iVar8 = _pool_zone;
          _zalloc();
          _bzero();
          *(int *)(iVar8 + 0x18) = iVar10;
          *(word *)(iVar8 + 0x1c) = word_F013DE72;
          *(word *)(iVar8 + 0x1e) = word_F013DE72;
          iVar7 = 0;
          if (word_F013DE72 == 0) {
            *(int *)(iVar8 + 0x14) = iVar12;
          }
          else {
            puVar6 = (undefined *)(iVar10 + 0xe);
            do {
              _bzero(iVar10,0x54);
              *(int *)(puVar6 + -10) = iVar8;
              puVar6[-1] = 1;
              *puVar6 = (char)iVar7;
              puVar6 = puVar6 + 0x54;
              iVar7 = iVar7 + 1;
              iVar10 = iVar10 + 0x54;
            } while (iVar7 < (int)(uint)word_F013DE72);
            *(int *)(iVar8 + 0x14) = iVar12;
          }
          _add_pool(&_reg_free,iVar8);
          iVar11 = iVar11 + 1;
          iVar12 = iVar8;
        } while (iVar11 < (int)(uint)word_F013DE76);
      }
      DAT_f013de94._8_4_ = DAT_f013de94._8_4_ + (uint)word_F013DE76;
      puVar5 = _garbage_zone;
      _zalloc();
      puVar5[2] = iVar8;
      puVar1 = puVar5;
      if ((undefined4 **)dword_F013DE1C != &_garbage) {
        *dword_F013DE1C = puVar5;
        puVar1 = _garbage;
      }
      _garbage = puVar1;
      puVar5[1] = dword_F013DE1C;
      *puVar5 = &_garbage;
      dword_F013DE1C = puVar5;
    }
    else {
      piVar4 = (int *)&_reg_free;
      _del_first_pool();
      if (piVar4 == (int *)0x0) {
        _panic(aPmapAllocRegEn_1);
        uRam00000008 = 0;
      }
      else {
        piVar4[2] = 0;
      }
      iVar8 = _kernel_map;
      _kmem_alloc_wired(_kernel_map,piVar4 + 2,_page_size);
      if (iVar8 != 0) {
        _panic(aPmapAllocRegEn_2);
      }
      iVar8 = _kernel_pmap;
      _pmap_resident_extract(_kernel_pmap,piVar4[2]);
      bVar14 = _mxcc == 0;
      piVar4[1] = iVar8;
      if (bVar14) {
        _pmap_enter_dev(_kernel_pmap,piVar4[2],iVar8,0,7,0,1);
      }
      iVar8 = piVar4[1];
      _vm_mem_ppi();
      iVar10 = _pg_desc_tbl + iVar8 * 0x14;
      if (((*(int *)(iVar10 + 4) != _kernel_pmap) ||
          ((*(uint *)(iVar10 + 8) >> 8) * 0x1000 - piVar4[2] != 0)) ||
         (*(int *)(_pg_desc_tbl + iVar8 * 0x14) != 0)) {
        _panic(aPmapAllocRegEn_5);
      }
      *piVar4 = iVar10;
      *(int **)(iVar10 + 0xc) = piVar4;
      piVar9 = (int *)piVar4[6];
      *(sword *)((int)piVar4 + 0x1e) = *(sword *)((int)piVar4 + 0x1e) + -1;
      iVar10 = 0;
      iVar8 = piVar4[2];
      if (word_F013DE72 != 0) {
        do {
          *piVar9 = iVar8;
          iVar8 = iVar8 + 0x400;
          iVar10 = iVar10 + 1;
          piVar9 = piVar9 + 0x15;
        } while (iVar10 < (int)(uint)word_F013DE72);
      }
      DAT_f013de94._4_4_ = DAT_f013de94._4_4_ + (uint)word_F013DE72;
      _add_pool(&_reg_semi_active,piVar4);
    }
  }
  puVar2 = &_reg_semi_active;
  _del_first_pool();
  if ((puVar2 == (undefined8 *)0x0) || (*(sword *)((int)puVar2 + 0x1e) == 0)) {
    _panic(aPmapAllocRegEn_4);
    iVar8 = *(int *)(puVar2 + 3);
  }
  else {
    iVar8 = *(int *)(puVar2 + 3);
  }
  iVar10 = *(word *)((int)puVar2 + 0x1c) - 1;
  *(sword *)((int)puVar2 + 0x1e) = *(sword *)((int)puVar2 + 0x1e) + -1;
  if (iVar10 != -1) {
    puVar6 = (undefined *)(iVar8 + 0xf);
    do {
      if (*(int *)(puVar6 + -7) == 0) {
        *(int **)(puVar6 + -7) = param_1;
        *puVar6 = 0;
        puVar3 = &_reg_semi_active;
        if (*(sword *)((int)puVar2 + 0x1e) == 0) {
          puVar3 = &_reg_active;
        }
        _add_pool(puVar3,puVar2);
        *param_1 = iVar8;
        DAT_f013de94._0_4_ = DAT_f013de94._0_4_ + 1;
        break;
      }
      puVar6 = puVar6 + 0x54;
      iVar10 = iVar10 + -1;
      iVar8 = iVar8 + 0x54;
    } while (iVar10 != -1);
  }
  return CONCAT44(param_1,piVar13);
}
/* GHIDRADEC_FUNCTION index=2426 start=0xf00a2444 */

/* WARNING: Removing unreachable block (ram,0xf00a2584) */
/* WARNING: Removing unreachable block (ram,0xf00a2510) */
/* WARNING: Removing unreachable block (ram,0xf00a24cc) */
/* WARNING: Removing unreachable block (ram,0xf00a24bc) */
/* WARNING: Removing unreachable block (ram,0xf00a2508) */
/* WARNING: Removing unreachable block (ram,0xf00a2574) */
/* WARNING: Removing unreachable block (ram,0xf00a25b4) */
/* WARNING: Removing unreachable block (ram,0xf00a2484) */

undefined8 _pmap_dealloc_reg_entry(int *param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 unaff_l0;
  int iVar2;
  int iVar3;
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
  dword_F013DF54 = dword_F013DF54 + 1;
  iVar2 = *param_1;
  if (param_1 != _kernel_pmap) {
    if (0x10 < *(byte *)(iVar2 + 0xf)) {
      _panic(aPmapDeallocReg_1,*(undefined *)(iVar2 + 0xf));
    }
    *(undefined4 *)(iVar2 + 8) = 0;
    DAT_f013de94._0_4_ = DAT_f013de94._0_4_ + -1;
    param_1 = *(int **)(iVar2 + 4);
    if (*(sword *)((int)param_1 + 0x1e) == 0) {
      *(undefined2 *)((int)param_1 + 0x1e) = 1;
      _del_any_pool(&_reg_active,param_1);
      _add_pool(&_reg_semi_active,param_1);
      sVar1 = *(sword *)((int)param_1 + 0x1e);
    }
    else {
      *(sword *)((int)param_1 + 0x1e) = *(sword *)((int)param_1 + 0x1e) + 1;
      sVar1 = *(sword *)((int)param_1 + 0x1e);
    }
    if ((sVar1 == *(sword *)(param_1 + 7)) && (10 < dword_F013DFB8)) {
      _del_any_pool(&_reg_semi_active,param_1);
      iVar2 = param_1[1];
      _vm_mem_ppi();
      iVar3 = _pg_desc_tbl + iVar2 * 0x14;
      if ((*(int **)(iVar3 + 4) != _kernel_pmap) ||
         (((*(uint *)(iVar3 + 8) >> 8) * 0x1000 - param_1[2] != 0 ||
          (*(int *)(_pg_desc_tbl + iVar2 * 0x14) != 0)))) {
        _panic(aPmapDeallocReg_2);
      }
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *param_1 = 0;
      _kmem_free(param_1[2]);
      DAT_f013de94._4_4_ = DAT_f013de94._4_4_ - (uint)word_F013DE72;
      param_1[2] = 0;
      param_1[1] = 0;
      _add_pool(&_reg_free);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2427 start=0xf00a25c4 */

/* WARNING: Removing unreachable block (ram,0xf00a2694) */
/* WARNING: Removing unreachable block (ram,0xf00a2610) */
/* WARNING: Removing unreachable block (ram,0xf00a262c) */

undefined8 _pmap_seg_entry(uint param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint uVar4;
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
  dword_F013DF58 = dword_F013DF58 + 1;
  uVar4 = param_1 & ~_page_mask;
  if ((param_1 < _kernel_seg_tables_phys) ||
     (iVar1 = uVar4 - _kernel_seg_tables_phys, _kernel_seg_end < param_1)) {
    uVar2 = uVar4;
    _vm_mem_ppi();
    iVar1 = _pg_desc_tbl + uVar2 * 0x14;
    iVar3 = *(int *)(iVar1 + 0xc);
    if ((*(int *)(iVar1 + 4) != _kernel_pmap) ||
       (((*(uint *)(iVar1 + 8) >> 8) * 0x1000 - *(int *)(iVar3 + 8) != 0 ||
        (*(int *)(_pg_desc_tbl + uVar2 * 0x14) != 0)))) {
      _panic(aPmapSegEntryWr);
    }
  }
  else {
    .udiv(iVar1,_page_size);
    iVar3 = _kernel_seg_pools + iVar1 * 0x20;
  }
  return CONCAT44(param_2,*(int *)(iVar3 + 0x18) + ((int)(param_1 - uVar4) >> 8) * 0x28);
}
/* GHIDRADEC_FUNCTION index=2428 start=0xf00a26bc */

/* WARNING: Removing unreachable block (ram,0xf00a2794) */
/* WARNING: Removing unreachable block (ram,0xf00a2714) */
/* WARNING: Removing unreachable block (ram,0xf00a27c4) */
/* WARNING: Removing unreachable block (ram,0xf00a26ec) */

undefined8 _pmap_alloc_kseg_entry(int param_1,undefined4 param_2,undefined param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  dword_F013DF5C = dword_F013DF5C + 1;
  iVar5 = param_1;
  if (dword_F013DE48 != 0) {
    puVar1 = &_kseg_semi_active;
    _del_first_pool();
    if ((puVar1 == (undefined8 *)0x0) || (*(sword *)((int)puVar1 + 0x1e) == 0)) {
      _panic(aPmapAllocKsegE_2);
      iVar5 = *(int *)(puVar1 + 3);
    }
    else {
      iVar5 = *(int *)(puVar1 + 3);
    }
    iVar3 = *(word *)((int)puVar1 + 0x1c) - 1;
    *(sword *)((int)puVar1 + 0x1e) = *(sword *)((int)puVar1 + 0x1e) + -1;
    if (iVar3 != -1) {
      puVar4 = (undefined *)(iVar5 + 0xd);
      do {
        if (*(int *)(puVar4 + -5) == 0) {
          *(int *)(puVar4 + -5) = param_1;
          puVar4[2] = 0;
          *(undefined4 *)(puVar4 + 3) = 0;
          *(undefined4 *)(puVar4 + 7) = 0;
          *(undefined4 *)(puVar4 + 0xb) = 0;
          *(undefined4 *)(puVar4 + 0xf) = 0;
          *(undefined4 *)(puVar4 + 0x13) = 0;
          *(undefined4 *)(puVar4 + 0x17) = param_2;
          puVar2 = &_kseg_semi_active;
          if (*(sword *)((int)puVar1 + 0x1e) == 0) {
            puVar2 = &_kseg_active;
          }
          _add_pool(puVar2,puVar1);
          *puVar4 = param_3;
          DAT_f013de84._0_4_ = DAT_f013de84._0_4_ + 1;
          goto locret_F00A27CC;
        }
        puVar4 = puVar4 + 0x28;
        iVar3 = iVar3 + -1;
        iVar5 = iVar5 + 0x28;
      } while (iVar3 != -1);
    }
  }
  _panic(aPmapAllocKsegE_1);
locret_F00A27CC:
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=2429 start=0xf00a27d4 */

/* WARNING: Removing unreachable block (ram,0xf00a2930) */
/* WARNING: Removing unreachable block (ram,0xf00a2884) */
/* WARNING: Removing unreachable block (ram,0xf00a2840) */
/* WARNING: Removing unreachable block (ram,0xf00a2824) */
/* WARNING: Removing unreachable block (ram,0xf00a282c) */
/* WARNING: Removing unreachable block (ram,0xf00a28f0) */
/* WARNING: Removing unreachable block (ram,0xf00a289c) */
/* WARNING: Removing unreachable block (ram,0xf00a2940) */
/* WARNING: Removing unreachable block (ram,0xf00a27fc) */

undefined8 _pmap_dealloc_kseg_entry(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
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
  dword_F013DF60 = dword_F013DF60 + 1;
  if (*(char *)(param_1 + 0xf) != '\0') {
    _panic(aPmapDeallocKse_1);
  }
  if ((*(int *)(param_1 + 0x10) != 0) || (*(int *)(param_1 + 0x14) != 0)) {
    _panic(aPampDeallocKse);
  }
  iVar1 = param_1;
  _check_ptbl();
  if (iVar1 != 0) {
    _panic(aPmapDeallocKse_2);
  }
  if (*(char *)(param_1 + 0xd) == '\x03') {
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x10) = 0xfff;
    *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
    iVar1 = *(int *)(param_1 + 0x20);
    if (iVar1 == 0) {
loc_F00A28F8:
      *(undefined4 *)(param_1 + 8) = 0;
    }
    else {
      _set_invalidptp(iVar1,*(uint *)(param_1 + 0x24) & 0xfffc0000);
      if (*(char *)(iVar1 + 0xf) == '\0') {
        _pmap_dealloc_seg_entry(iVar1);
        *(undefined4 *)(param_1 + 8) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 8) = 0;
      }
    }
  }
  else {
    if (*(char *)(param_1 + 0xd) == '\x02') {
      if (0xefffffff < *(uint *)(param_1 + 0x24)) goto locret_F00A2950;
      *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = 0xfff;
      *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0;
      if (*(int *)(param_1 + 0x20) != 0) {
        _set_invalidptp(*(int *)(param_1 + 0x20),*(uint *)(param_1 + 0x24) & 0xff000000);
      }
      goto loc_F00A28F8;
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  DAT_f013de84._0_4_ = DAT_f013de84._0_4_ + -1;
  param_1 = *(int *)(param_1 + 4);
  if (*(sword *)(param_1 + 0x1e) == 0) {
    *(undefined2 *)(param_1 + 0x1e) = 1;
    _del_any_pool(&_kseg_active,param_1);
    _add_pool(&_kseg_semi_active,param_1);
  }
  else {
    *(sword *)(param_1 + 0x1e) = *(sword *)(param_1 + 0x1e) + 1;
  }
locret_F00A2950:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2430 start=0xf00a2958 */

/* WARNING: Removing unreachable block (ram,0xf00a29f0) */
/* WARNING: Removing unreachable block (ram,0xf00a2c20) */
/* WARNING: Removing unreachable block (ram,0xf00a2b4c) */
/* WARNING: Removing unreachable block (ram,0xf00a2b0c) */
/* WARNING: Removing unreachable block (ram,0xf00a2ae8) */
/* WARNING: Removing unreachable block (ram,0xf00a2ab4) */
/* WARNING: Removing unreachable block (ram,0xf00a2d08) */
/* WARNING: Removing unreachable block (ram,0xf00a2c98) */
/* WARNING: Removing unreachable block (ram,0xf00a2c58) */
/* WARNING: Removing unreachable block (ram,0xf00a2c8c) */
/* WARNING: Removing unreachable block (ram,0xf00a2cd4) */
/* WARNING: Removing unreachable block (ram,0xf00a2d40) */
/* WARNING: Removing unreachable block (ram,0xf00a2acc) */
/* WARNING: Removing unreachable block (ram,0xf00a2afc) */
/* WARNING: Removing unreachable block (ram,0xf00a2b44) */
/* WARNING: Removing unreachable block (ram,0xf00a2bac) */
/* WARNING: Removing unreachable block (ram,0xf00a29c8) */
/* WARNING: Removing unreachable block (ram,0xf00a2a70) */
/* WARNING: Removing unreachable block (ram,0xf00a2c44) */
/* WARNING: Removing unreachable block (ram,0xf00a29a4) */

undefined8 _pmap_alloc_seg_entry(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  int iVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  int *piVar11;
  int iVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
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
  dword_F013DF64 = dword_F013DF64 + 1;
  if ((param_1 == _kernel_pmap) || (0xefffffff < param_2)) {
    _pmap_alloc_kseg_entry(param_1,param_2,param_3);
    iVar10 = param_1;
  }
  else {
    while (dword_F013DFE8 == 0) {
      if (dword_F013DFD8 == 0) {
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
        iVar10 = _kernel_map;
        _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),_page_size);
        if (iVar10 != 0) {
          _panic(aPmapAllocSegEn_3);
        }
        iVar10 = 0;
        iVar9 = 0;
        iVar12 = *(int *)((int)register0x00000038 + -0xc);
        iVar8 = iVar10;
        if (word_F013DE78 != 0) {
          do {
            iVar10 = _pool_zone;
            _zalloc();
            _bzero();
            *(int *)(iVar10 + 0x18) = iVar12;
            *(word *)(iVar10 + 0x1c) = word_F013DE74;
            *(word *)(iVar10 + 0x1e) = word_F013DE74;
            iVar7 = 0;
            if (word_F013DE74 == 0) {
              *(int *)(iVar10 + 0x14) = iVar8;
            }
            else {
              puVar6 = (undefined *)(iVar12 + 0xe);
              do {
                _bzero(iVar12,0x28);
                *(int *)(puVar6 + -10) = iVar10;
                puVar6[-1] = 0;
                *puVar6 = (char)iVar7;
                puVar6 = puVar6 + 0x28;
                iVar7 = iVar7 + 1;
                iVar12 = iVar12 + 0x28;
              } while (iVar7 < (int)(uint)word_F013DE74);
              *(int *)(iVar10 + 0x14) = iVar8;
            }
            _add_pool(&_seg_free,iVar10);
            iVar9 = iVar9 + 1;
            iVar8 = iVar10;
          } while (iVar9 < (int)(uint)word_F013DE78);
        }
        DAT_f013de88._8_4_ = DAT_f013de88._8_4_ + (uint)word_F013DE78;
        puVar5 = _garbage_zone;
        _zalloc();
        puVar5[2] = iVar10;
        puVar1 = puVar5;
        if ((undefined4 **)dword_F013DE1C != &_garbage) {
          *dword_F013DE1C = puVar5;
          puVar1 = _garbage;
        }
        _garbage = puVar1;
        puVar5[1] = dword_F013DE1C;
        *puVar5 = &_garbage;
        dword_F013DE1C = puVar5;
      }
      else {
        piVar4 = (int *)&_seg_free;
        _del_first_pool();
        if (piVar4 == (int *)0x0) {
          _panic(aPmapAllocSegEn_1);
          uRam00000008 = 0;
        }
        else {
          piVar4[2] = 0;
        }
        iVar10 = _kernel_map;
        _kmem_alloc_wired(_kernel_map,piVar4 + 2,_page_size);
        if (iVar10 != 0) {
          _panic(aPmapAllocSegEn_2);
        }
        iVar10 = _kernel_pmap;
        _pmap_resident_extract(_kernel_pmap,piVar4[2]);
        bVar13 = _mxcc == 0;
        piVar4[1] = iVar10;
        if (bVar13) {
          _pmap_enter_dev(_kernel_pmap,piVar4[2],iVar10,0,7,0,1);
        }
        iVar10 = piVar4[1];
        _vm_mem_ppi();
        iVar8 = _pg_desc_tbl + iVar10 * 0x14;
        if (((*(int *)(iVar8 + 4) != _kernel_pmap) ||
            ((*(uint *)(iVar8 + 8) >> 8) * 0x1000 - piVar4[2] != 0)) ||
           (*(int *)(_pg_desc_tbl + iVar10 * 0x14) != 0)) {
          _panic(aPmapAllocSegEn_5);
        }
        *piVar4 = iVar8;
        *(int **)(iVar8 + 0xc) = piVar4;
        piVar11 = (int *)piVar4[6];
        *(sword *)((int)piVar4 + 0x1e) = *(sword *)((int)piVar4 + 0x1e) + -1;
        iVar8 = 0;
        iVar10 = piVar4[2];
        if (word_F013DE74 != 0) {
          do {
            *piVar11 = iVar10;
            iVar10 = iVar10 + 0x100;
            iVar8 = iVar8 + 1;
            piVar11 = piVar11 + 10;
          } while (iVar8 < (int)(uint)word_F013DE74);
        }
        DAT_f013de88._4_4_ = DAT_f013de88._4_4_ + (uint)word_F013DE74;
        _add_pool(&_seg_semi_active,piVar4);
      }
    }
    puVar2 = &_seg_semi_active;
    _del_first_pool();
    if ((puVar2 == (undefined8 *)0x0) || (*(sword *)((int)puVar2 + 0x1e) == 0)) {
      _panic(aPmapAllocSegEn_4);
      iVar10 = *(int *)(puVar2 + 3);
    }
    else {
      iVar10 = *(int *)(puVar2 + 3);
    }
    iVar8 = *(word *)((int)puVar2 + 0x1c) - 1;
    *(sword *)((int)puVar2 + 0x1e) = *(sword *)((int)puVar2 + 0x1e) + -1;
    if (iVar8 != -1) {
      puVar6 = (undefined *)(iVar10 + 0xd);
      do {
        if (*(int *)(puVar6 + -5) == 0) {
          *(int *)(puVar6 + -5) = param_1;
          puVar6[2] = 0;
          *(undefined4 *)(puVar6 + 3) = 0;
          *(undefined4 *)(puVar6 + 7) = 0;
          *(undefined4 *)(puVar6 + 0xb) = 0;
          *(undefined4 *)(puVar6 + 0xf) = 0;
          *(undefined4 *)(puVar6 + 0x13) = 0;
          *(uint *)(puVar6 + 0x17) = param_2;
          puVar3 = &_seg_semi_active;
          if (*(sword *)((int)puVar2 + 0x1e) == 0) {
            puVar3 = &_seg_active;
          }
          _add_pool(puVar3,puVar2);
          *puVar6 = (char)param_3;
          DAT_f013de88._0_4_ = DAT_f013de88._0_4_ + 1;
          break;
        }
        puVar6 = puVar6 + 0x28;
        iVar8 = iVar8 + -1;
        iVar10 = iVar10 + 0x28;
      } while (iVar8 != -1);
    }
  }
  return CONCAT44(param_2,iVar10);
}
/* GHIDRADEC_FUNCTION index=2431 start=0xf00a2d90 */

/* WARNING: Removing unreachable block (ram,0xf00a2fe4) */
/* WARNING: Removing unreachable block (ram,0xf00a2f70) */
/* WARNING: Removing unreachable block (ram,0xf00a2f2c) */
/* WARNING: Removing unreachable block (ram,0xf00a2e9c) */
/* WARNING: Removing unreachable block (ram,0xf00a2edc) */
/* WARNING: Removing unreachable block (ram,0xf00a2e18) */
/* WARNING: Removing unreachable block (ram,0xf00a2e00) */
/* WARNING: Removing unreachable block (ram,0xf00a2e40) */
/* WARNING: Removing unreachable block (ram,0xf00a2e84) */
/* WARNING: Removing unreachable block (ram,0xf00a2f1c) */
/* WARNING: Removing unreachable block (ram,0xf00a2f68) */
/* WARNING: Removing unreachable block (ram,0xf00a2fd4) */
/* WARNING: Removing unreachable block (ram,0xf00a3014) */
/* WARNING: Removing unreachable block (ram,0xf00a2dec) */
/* WARNING: Removing unreachable block (ram,0xf00a2de0) */

undefined8 _pmap_dealloc_seg_entry(undefined4 *param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  int iVar3;
  int iVar4;
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
  dword_F013DF68 = dword_F013DF68 + 1;
  if ((param_1[2] == _kernel_pmap) ||
     ((_kernel_seg_entries <= param_1 && (param_1 <= _kernel_seg_entries_end)))) {
    _pmap_dealloc_kseg_entry(param_1);
    goto locret_F00A301C;
  }
  puVar2 = param_1;
  _check_ptbl();
  if (puVar2 != (undefined4 *)0x0) {
    _panic(aPmapDeallocSeg_1);
  }
  if (*(char *)((int)param_1 + 0xf) != '\0') {
    _panic(aPmapDeallocSeg_2);
  }
  if ((param_1[4] != 0) || (param_1[5] != 0)) {
    _panic(aPampDeallocSeg);
  }
  if (*(char *)((int)param_1 + 0xd) == '\x03') {
    *(undefined4 *)(param_1[2] + 0x10) = 0xfff;
    *(undefined4 *)(param_1[2] + 8) = 0;
    iVar3 = param_1[8];
    if (iVar3 == 0) {
loc_F00A2EE4:
      param_1[2] = 0;
    }
    else {
      _set_invalidptp(iVar3,param_1[9] & 0xfffc0000);
      if (*(char *)(iVar3 + 0xf) == '\0') {
        _pmap_dealloc_seg_entry(iVar3);
        param_1[2] = 0;
      }
      else {
        param_1[2] = 0;
      }
    }
  }
  else {
    if (*(char *)((int)param_1 + 0xd) == '\x02') {
      *(undefined4 *)(param_1[2] + 0xc) = 0xfff;
      *(undefined4 *)(param_1[2] + 4) = 0;
      if (param_1[8] != 0) {
        _set_invalidptp(param_1[8],param_1[9] & 0xff000000);
      }
      goto loc_F00A2EE4;
    }
    param_1[2] = 0;
  }
  DAT_f013de88._0_4_ = DAT_f013de88._0_4_ + -1;
  param_1 = (undefined4 *)param_1[1];
  if (*(sword *)((int)param_1 + 0x1e) == 0) {
    *(undefined2 *)((int)param_1 + 0x1e) = 1;
    _del_any_pool(&_seg_active,param_1);
    _add_pool(&_seg_semi_active,param_1);
    sVar1 = *(sword *)((int)param_1 + 0x1e);
  }
  else {
    *(sword *)((int)param_1 + 0x1e) = *(sword *)((int)param_1 + 0x1e) + 1;
    sVar1 = *(sword *)((int)param_1 + 0x1e);
  }
  if ((sVar1 == *(sword *)(param_1 + 7)) && (100 < dword_F013DFE8)) {
    _del_any_pool(&_seg_semi_active,param_1);
    iVar3 = param_1[1];
    _vm_mem_ppi();
    iVar4 = _pg_desc_tbl + iVar3 * 0x14;
    if ((*(int *)(iVar4 + 4) != _kernel_pmap) ||
       (((*(uint *)(iVar4 + 8) >> 8) * 0x1000 - param_1[2] != 0 ||
        (*(int *)(_pg_desc_tbl + iVar3 * 0x14) != 0)))) {
      _panic(aPmapDeallocSeg_3);
    }
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *param_1 = 0;
    _kmem_free(param_1[2]);
    DAT_f013de88._4_4_ = DAT_f013de88._4_4_ - (uint)word_F013DE74;
    param_1[2] = 0;
    param_1[1] = 0;
    _add_pool(&_seg_free);
  }
locret_F00A301C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2432 start=0xf00a3024 */

undefined8 _init_context_table(void)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  undefined8 *puVar5;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  uVar1 = _nctxs;
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
  DAT_f013e10c = &_lru_context;
  _lru_context._0_4_ = &_lru_context;
  uVar4 = 1;
  puVar5 = (undefined8 *)&DAT_f013e000;
  puVar3 = _context_table;
  if (1 < _nctxs) {
    do {
      puVar2 = (undefined8 *)((int)puVar3 + 0xc);
      *(undefined4 *)((int)puVar3 + 0x14) = 0;
      puVar5 = puVar2;
      if (_lru_context._0_4_ != &_lru_context) {
        *(undefined8 **)((int)_lru_context._0_4_ + 4) = puVar2;
        puVar5 = DAT_f013e10c;
      }
      DAT_f013e10c = puVar5;
      *(undefined8 **)puVar2 = _lru_context._0_4_;
      *(undefined8 **)(puVar3 + 2) = &_lru_context;
      uVar4 = uVar4 + 1;
      puVar5 = &_lru_context;
      puVar3 = puVar2;
      _lru_context._0_4_ = puVar2;
    } while (uVar4 < uVar1);
  }
  return CONCAT44(puVar5,uVar4);
}
/* GHIDRADEC_FUNCTION index=2433 start=0xf00a309c */

undefined8 _pmap_alloc_context(int param_1)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int *piVar2;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  piVar1 = DAT_f013e10c;
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
  dword_F013DF6C = dword_F013DF6C + 1;
  piVar2 = *(int **)(param_1 + 0x14);
  if ((piVar2 == (int *)0x0) || (piVar2[2] != param_1)) {
    piVar2 = (int *)DAT_f013e10c[1];
    if (piVar2 == (int *)&_lru_context) {
      _lru_context._0_4_ = (int *)&_lru_context;
    }
    else {
      *piVar2 = (int)&_lru_context;
    }
    *(int **)(param_1 + 0x14) = DAT_f013e10c;
    DAT_f013e10c = piVar2;
    piVar1[2] = param_1;
    piVar2 = piVar1;
  }
  else {
    *(int *)(*piVar2 + 4) = piVar2[1];
    *(int *)piVar2[1] = *piVar2;
  }
  *(int **)((int)_lru_context._0_4_ + 4) = piVar2;
  *piVar2 = (int)_lru_context._0_4_;
  piVar2[1] = (int)&_lru_context;
  _lru_context._0_4_ = piVar2;
  return CONCAT44(piVar2,((int)piVar2 - _context_table) * -0x55555555 >> 2);
}
/* GHIDRADEC_FUNCTION index=2434 start=0xf00a3180 */

/* WARNING: Removing unreachable block (ram,0xf00a3288) */
/* WARNING: Removing unreachable block (ram,0xf00a320c) */
/* WARNING: Removing unreachable block (ram,0xf00a324c) */
/* WARNING: Removing unreachable block (ram,0xf00a3290) */
/* WARNING: Removing unreachable block (ram,0xf00a3234) */

undefined8 _garbage_collect(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  bool bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar5 = 0;
  dword_F013DF70 = dword_F013DF70 + 1;
  iVar3 = param_1[2];
  bVar6 = iVar3 == 0;
  if (!bVar6) {
    iVar2 = *(int *)(iVar3 + 8);
    iVar4 = iVar3;
    while (bVar6 = iVar4 == 0, iVar2 == 0) {
      iVar4 = *(int *)(iVar4 + 0x14);
      if (iVar4 == 0) {
        bVar6 = true;
        break;
      }
      iVar2 = *(int *)(iVar4 + 8);
    }
  }
  if (bVar6) {
    if (iVar3 == 0) {
      iVar3 = *param_1;
    }
    else {
      iVar4 = *(int *)(iVar3 + 0x18);
      while( true ) {
        if (*(char *)(iVar4 + 0xd) == '\x01') {
          _del_any_pool(&_reg_free,iVar3);
          DAT_f013de9c = DAT_f013de9c + -1;
        }
        else if ((byte)(*(char *)(iVar4 + 0xd) - 2U) < 2) {
          _del_any_pool(&_seg_free,iVar3);
          DAT_f013de90._0_4_ = DAT_f013de90._0_4_ + -1;
        }
        _zfree(_pool_zone,iVar3);
        uVar5 = *(undefined4 *)(iVar3 + 0x18);
        iVar3 = *(int *)(iVar3 + 0x14);
        if (iVar3 == 0) break;
        iVar4 = *(int *)(iVar3 + 0x18);
      }
      iVar3 = *param_1;
    }
    *(int *)(iVar3 + 4) = param_1[1];
    uVar1 = _garbage_zone;
    *(int *)param_1[1] = *param_1;
    _zfree(uVar1);
    _kmem_free(uVar5);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2435 start=0xf00a32a0 */

undefined8 _simple_lock_init(undefined4 *param_1,undefined4 param_2)

{
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
  *param_1 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2436 start=0xf00a32b0 */

/* WARNING: Removing unreachable block (ram,0xf00a32c4) */

undefined8 _simple_lock(int *param_1,undefined4 param_2)

{
  int *piVar1;
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
  do {
    do {
    } while (*param_1 != 0);
    piVar1 = param_1;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2437 start=0xf00a32e0 */

undefined8 _simple_unlock(undefined4 *param_1,undefined4 param_2)

{
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
  *param_1 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2438 start=0xf00a32f0 */

undefined8 _print_debug_msg(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2439 start=0xf00a32fc */

/* WARNING: Removing unreachable block (ram,0xf00a3320) */
/* WARNING: Removing unreachable block (ram,0xf00a3328) */
/* WARNING: Removing unreachable block (ram,0xf00a3304) */

undefined8 _bootflags(undefined4 param_1,undefined4 param_2)

{
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
  _getargs(aRootdevEn);
  if ((_boothowto & 8) != 0) {
    _prom_printf(aHaltedByHFlag);
    _prom_enter_mon();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2440 start=0xf00a3338 */

/* WARNING: Removing unreachable block (ram,0xf00a3710) */
/* WARNING: Removing unreachable block (ram,0xf00a3700) */
/* WARNING: Removing unreachable block (ram,0xf00a3664) */
/* WARNING: Removing unreachable block (ram,0xf00a3598) */
/* WARNING: Removing unreachable block (ram,0xf00a3588) */
/* WARNING: Removing unreachable block (ram,0xf00a362c) */
/* WARNING: Removing unreachable block (ram,0xf00a35e0) */
/* WARNING: Removing unreachable block (ram,0xf00a3534) */
/* WARNING: Removing unreachable block (ram,0xf00a350c) */
/* WARNING: Removing unreachable block (ram,0xf00a34bc) */
/* WARNING: Removing unreachable block (ram,0xf00a33d8) */
/* WARNING: Removing unreachable block (ram,0xf00a33b8) */
/* WARNING: Removing unreachable block (ram,0xf00a33a8) */
/* WARNING: Removing unreachable block (ram,0xf00a3398) */
/* WARNING: Removing unreachable block (ram,0xf00a3368) */
/* WARNING: Removing unreachable block (ram,0xf00a3360) */
/* WARNING: Removing unreachable block (ram,0xf00a3384) */
/* WARNING: Removing unreachable block (ram,0xf00a33a0) */
/* WARNING: Removing unreachable block (ram,0xf00a33b0) */
/* WARNING: Removing unreachable block (ram,0xf00a33c0) */
/* WARNING: Removing unreachable block (ram,0xf00a34a8) */
/* WARNING: Removing unreachable block (ram,0xf00a3504) */
/* WARNING: Removing unreachable block (ram,0xf00a3514) */
/* WARNING: Removing unreachable block (ram,0xf00a3550) */
/* WARNING: Removing unreachable block (ram,0xf00a35e8) */
/* WARNING: Removing unreachable block (ram,0xf00a3618) */
/* WARNING: Removing unreachable block (ram,0xf00a3590) */
/* WARNING: Removing unreachable block (ram,0xf00a35bc) */
/* WARNING: Removing unreachable block (ram,0xf00a36dc) */
/* WARNING: Removing unreachable block (ram,0xf00a3708) */
/* WARNING: Removing unreachable block (ram,0xf00a3728) */
/* WARNING: Removing unreachable block (ram,0xf00a333c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _sparc_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
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
  bool bVar8;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  sub_F00A379C();
  iVar2 = *(int *)(__bootops + 0x3c);
  if (iVar2 != 0) {
    _bcopy(iVar2,&_static_KERNBOOTSTRUCT,0xd128);
  }
  _getlastaddr();
  iVar2 = iVar2 + *(int *)(__bootops + 0x40);
  _end = iVar2;
  sub_F00A377C();
  _etext = iVar2;
  _prom_init(aNextstep_0);
  _map_wellknown_devices();
  _fill_machinfo();
  _fill_hostidinfo();
  _setcputype();
  sub_F00A3740(_mach_info);
  _cpu = _mach_info;
  _setcpudelay();
  uVar4 = DAT_f0112a7c._20_4_;
  uVar1 = DAT_f0112a7c._16_4_;
  if (DAT_f0112a7c._0_4_ != 0) {
    if (DAT_f0112a7c._8_4_ == 0) {
      _cache = 1;
      _vac = 1;
    }
    else if (DAT_f0112a7c._76_4_ == 0) {
      _cache = 2;
    }
    else {
      _cache = 3;
    }
  }
  _iom = DAT_f0112a44._0_4_;
  _bcopy_buf = DAT_f0112a7c._44_4_;
  if ((_nctxs == 0) && (_nctxs = DAT_f0112a7c._32_4_, 0x1000 < (uint)DAT_f0112a7c._32_4_)) {
    _nctxs = 0x1000;
  }
  uVar3 = 0x1000;
  if (_vac != 0) {
    _vac_linesize = DAT_f0112a7c._16_4_;
    _vac_nlines = DAT_f0112a7c._20_4_;
    .div(0x1000,DAT_f0112a7c._16_4_);
    _vac_pglines = uVar3;
    .umul(uVar4,uVar1);
    _vac_size = uVar4;
  }
  if (_bcopy_buf != 0) {
    if (_use_bcopy == 0) {
      _bcopy_res = 0xffffffff;
    }
    else {
      _bcopy_res = 0;
    }
  }
  _init_mon_clock();
  _splzs();
  _bootflags();
  if (_page_size == 0) {
    _page_size = 0x2000;
  }
  _vm_set_page_size();
  if (dword_F013155C != 0) {
    dword_F013155C = dword_F013155C << 10;
  }
  _srmmu_init(dword_F013155C);
  dword_F013155C = _mem_size;
  if (_vac == 0) {
    if (_use_cache == 0) {
      _vac = 0;
      _cache = 0;
    }
    else {
      _vac_init();
      _setcpudelay();
      if (_no_mix == 0) {
        if (_use_mix == 0) {
          _bpt_reg(0,0x1000);
        }
        else {
          _bpt_reg(0x1000,0);
        }
      }
    }
  }
  else {
    if (_use_cache != 0) {
      _vac_mode = 0;
      _vac_init();
      _cache_on();
      _setcpudelay();
      _shm_alignment = _vac_size;
      goto loc_F00A3650;
    }
    _cache = 0;
    _vac = 0;
    _setcpudelay();
  }
  _shm_alignment = 0x1000;
loc_F00A3650:
  if (_debug_msg != 0) {
    _print_debug_msg();
  }
  iVar2 = _nmod;
  iVar6 = 0;
  if (0 < _nmod) {
    iVar5 = 0;
    do {
      *(undefined4 *)((int)&_a_head + iVar5) = 0x3f;
      *(undefined4 *)((int)&_a_tail + iVar5) = 0x3f;
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar6 < iVar2);
  }
  uVar7 = 1;
  if (dword_F0112A40 != 0) {
    do {
      bVar8 = uVar7 < dword_F0112A40;
      uVar7 = uVar7 + 1;
    } while (bVar8);
  }
  sub_F00A3804();
  _pmap_bootstrap(_mem_region,_num_regions,&_virtual_avail,&_virtual_end);
  _start_mon_clock();
  _memerr_init();
  uVar7 = _page_mask + 0x1000 & ~_page_mask;
  _vm_alloc_from_regions();
  _pmsgbuf = uVar7;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2441 start=0xf00a3844 */

/* WARNING: Removing unreachable block (ram,0xf00a3a44) */
/* WARNING: Removing unreachable block (ram,0xf00a3a3c) */
/* WARNING: Removing unreachable block (ram,0xf00a39fc) */
/* WARNING: Removing unreachable block (ram,0xf00a3990) */
/* WARNING: Removing unreachable block (ram,0xf00a3878) */
/* WARNING: Removing unreachable block (ram,0xf00a38c8) */
/* WARNING: Removing unreachable block (ram,0xf00a39a8) */
/* WARNING: Removing unreachable block (ram,0xf00a3a10) */
/* WARNING: Removing unreachable block (ram,0xf00a3858) */
/* WARNING: Removing unreachable block (ram,0xf00a3a90) */
/* WARNING: Removing unreachable block (ram,0xf00a3ab0) */
/* WARNING: Removing unreachable block (ram,0xf00a3a74) */

undefined8 _getargs(char *param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  undefined4 unaff_l0;
  byte *pbVar6;
  char *pcVar7;
  undefined4 unaff_l1;
  undefined5 **ppuVar8;
  undefined *puVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar10;
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
  _strncpy(_boot_file,aMachKernel,0x40);
  if (*param_1 == '\0') {
    uVar10 = 1;
  }
  else {
    while( true ) {
      iVar4 = (int)*param_1;
      _isargsep();
      if (iVar4 == 0) break;
      param_1 = param_1 + 1;
    }
    cVar2 = *param_1;
    if (*param_1 != '\0') {
loc_F00A38B0:
      pcVar7 = param_1;
      if (cVar2 == '-') {
        pbVar6 = (byte *)&_init_args;
        _argstrcpy(param_1,&_init_args);
        bVar3 = _init_args._0_1_;
        while( true ) {
          switch((int)((bVar3 - 0x61) * 0x1000000) >> 0x18) {
          case :
            _boothowto = _boothowto | 1;
            break;
          case :
            _boothowto = _boothowto | 4;
            break;
          case :
            _boothowto = _boothowto | 0x200000;
            break;
          case :
            _boothowto = _boothowto | 8;
            break;
          case :
            _boothowto = _boothowto | 2;
          }
          iVar4 = (int)(char)*pbVar6;
          if (iVar4 == 0) break;
          pbVar6 = pbVar6 + 1;
          _isargsep();
          if (iVar4 != 0) break;
          bVar3 = *pbVar6;
        }
      }
      else {
        while( true ) {
          iVar4 = (int)*pcVar7;
          _isargsep();
          if ((iVar4 != 0) || (*pcVar7 == '=')) break;
          pcVar7 = pcVar7 + 1;
        }
        if ((*pcVar7 == '=') && (ppuVar8 = &_kernargs, _kernargs != (undefined5 *)0x0)) {
          puVar9 = DAT_f011926c;
          do {
            pcVar5 = param_1;
            _strncmp(param_1,*ppuVar8,(int)pcVar7 - (int)param_1);
            if (pcVar5 == (char *)0x0) goto loc_F00A3A10;
            ppuVar8 = ppuVar8 + 2;
            puVar9 = (undefined *)((int)puVar9 + 8);
          } while (*ppuVar8 != (undefined5 *)0x0);
        }
      }
      goto loc_F00A3A90;
    }
loc_F00A3AE8:
    uVar10 = 0;
  }
  return CONCAT44(param_2,uVar10);
loc_F00A3A10:
  while( true ) {
    iVar4 = (int)*pcVar7;
    _isargsep();
    if (iVar4 == 0) break;
    pcVar7 = pcVar7 + 1;
  }
  pcVar5 = pcVar7;
  _getval(pcVar7,(undefined *)((int)register0x00000038 + -0xc));
  if (pcVar5 == (char *)0x0) {
    **(undefined4 **)puVar9 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else if (pcVar5 == (char *)0x1) {
    _argstrcpy(pcVar7 + 1,*(undefined4 *)puVar9);
  }
loc_F00A3A90:
  while( true ) {
    iVar4 = (int)*param_1;
    _isargsep();
    if (iVar4 != 0) break;
    param_1 = param_1 + 1;
  }
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    iVar4 = (int)*param_1;
    _isargsep();
    if (iVar4 == 0) {
      cVar1 = *param_1;
      goto loc_F00A3ADC;
    }
    param_1 = param_1 + 1;
    cVar2 = *param_1;
  }
  cVar1 = *param_1;
loc_F00A3ADC:
  cVar2 = *param_1;
  if (cVar1 == '\0') goto loc_F00A3AE8;
  goto loc_F00A38B0;
}
/* GHIDRADEC_FUNCTION index=2442 start=0xf00a3af4 */

undefined8 _isargsep(char param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if ((((param_1 == ' ') || (param_1 == '\0')) || (param_1 == '\t')) || (uVar1 = 0, param_1 == ','))
  {
    uVar1 = 1;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2443 start=0xf00a3b30 */

/* WARNING: Removing unreachable block (ram,0xf00a3b38) */

undefined8 _argstrcpy(char *param_1,char *param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = 0;
  while( true ) {
    iVar1 = (int)*param_1;
    _isargsep();
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 1;
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  *param_2 = '\0';
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=2444 start=0xf00a3b6c */

/* WARNING: Removing unreachable block (ram,0xf00a3ca4) */
/* WARNING: Removing unreachable block (ram,0xf00a3c64) */
/* WARNING: Removing unreachable block (ram,0xf00a3c90) */
/* WARNING: Removing unreachable block (ram,0xf00a3bfc) */

undefined8 _getval(char *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 uVar5;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  char *pcVar6;
  byte *pbVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar5 = 1;
  if (*param_1 != '=') {
    *param_2 = 1;
loc_F00A3CC0:
    uVar5 = 0;
    goto locret_F00A3CC4;
  }
  pcVar6 = param_1 + 1;
  iVar1 = (int)*pcVar6;
  uVar4 = 10;
  if (iVar1 == 0x2d) {
    uVar5 = 0xffffffff;
    pcVar6 = param_1 + 2;
    iVar1 = (int)*pcVar6;
  }
  iVar1 = iVar1 + -0x30;
  pbVar7 = (byte *)(pcVar6 + 1);
  if (iVar1 == 0) {
    iVar2 = (int)(char)*pbVar7;
    if (iVar2 < 0x30) {
loc_F00A3BFC:
      iVar2 = (int)(char)*pbVar7;
      _isargsep();
      if (iVar2 == 0) {
        uVar5 = 1;
        goto locret_F00A3CC4;
      }
    }
    else if (iVar2 < 0x38) {
      iVar1 = iVar2 + -0x30;
      pbVar7 = (byte *)(pcVar6 + 2);
      uVar4 = 8;
    }
    else if (iVar2 == 0x62) {
      uVar4 = 2;
      pbVar7 = (byte *)(pcVar6 + 2);
    }
    else {
      if (iVar2 != 0x78) goto loc_F00A3BFC;
      uVar4 = 0x10;
      pbVar7 = (byte *)(pcVar6 + 2);
    }
  }
  while( true ) {
    uVar3 = (uint)*pbVar7;
    pbVar7 = pbVar7 + 1;
    if ((uVar3 < 0x30) || (0x39 < uVar3)) {
      if ((uVar3 - 0x61 & 0xff) < 6) {
        uVar3 = uVar3 - 0x57;
      }
      else {
        if (5 < (uVar3 - 0x41 & 0xff)) {
          _isargsep();
          if (uVar3 != 0) {
            .umul(iVar1,uVar5);
            *param_2 = iVar1;
            goto loc_F00A3CC0;
          }
          uVar5 = 1;
          goto locret_F00A3CC4;
        }
        uVar3 = uVar3 - 0x37;
      }
    }
    else {
      uVar3 = uVar3 - 0x30;
    }
    if (uVar4 <= (uVar3 & 0xff)) break;
    .umul(iVar1,uVar4);
    iVar1 = iVar1 + (uVar3 & 0xff);
  }
  uVar5 = 1;
locret_F00A3CC4:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=2445 start=0xf00a3ccc */

/* WARNING: Removing unreachable block (ram,0xf00a3dc8) */
/* WARNING: Removing unreachable block (ram,0xf00a3d84) */
/* WARNING: Removing unreachable block (ram,0xf00a3d54) */
/* WARNING: Removing unreachable block (ram,0xf00a3d20) */
/* WARNING: Removing unreachable block (ram,0xf00a3cfc) */
/* WARNING: Removing unreachable block (ram,0xf00a3d10) */
/* WARNING: Removing unreachable block (ram,0xf00a3d48) */
/* WARNING: Removing unreachable block (ram,0xf00a3d70) */
/* WARNING: Removing unreachable block (ram,0xf00a3d94) */
/* WARNING: Removing unreachable block (ram,0xf00a3e08) */
/* WARNING: Removing unreachable block (ram,0xf00a3ce0) */

undefined8 _setcpudelay(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  uint uVar5;
  uint uVar6;
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
  _Cpudelay = 1;
  _us_spin();
  do {
    iVar2 = _Cpudelay << 1;
    _Cpudelay = iVar2;
    do {
      _spl8();
      uVar5 = *(uint *)(_utimersp + 4);
      _us_spin(0x32);
      uVar4 = *(uint *)(_utimersp + 4);
      _splx(iVar2);
      uVar6 = uVar4 - uVar5;
    } while (uVar4 < uVar5);
  } while (uVar6 < 0xc800);
  iVar2 = _Cpudelay;
  .umul(_Cpudelay,0xc800);
  iVar2 = iVar2 + uVar6;
  .udiv(iVar2,uVar6);
  _Cpudelay = iVar2;
  if (iVar2 < 0) {
    _Cpudelay = 0;
  }
  do {
    _spl8();
    uVar5 = *(uint *)(_utimersp + 4);
    _us_spin(0x32);
    uVar4 = *(uint *)(_utimersp + 4);
    _splx(iVar2);
  } while (uVar4 < uVar5);
  _cpudelay = 0xb;
  do {
    iVar2 = _cpudelay + -1;
    _cpudelay = iVar2;
    do {
      _spl8();
      uVar4 = 800 >> ((byte)_cpudelay & 0x1f);
      uVar5 = *(uint *)(_utimersp + 4);
      if (0 < (int)(uVar4 - 1)) {
        iVar3 = uVar4 - 2;
        do {
          bVar1 = 0 < iVar3;
          iVar3 = iVar3 + -1;
        } while (bVar1);
      }
      uVar4 = *(uint *)(_utimersp + 4);
      _splx(iVar2);
    } while (uVar4 < uVar5);
  } while ((uVar4 - uVar5 < 0xc800) && (0 < _cpudelay));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2446 start=0xf00a3e40 */

/* WARNING: Removing unreachable block (ram,0xf00a4474) */
/* WARNING: Removing unreachable block (ram,0xf00a4430) */
/* WARNING: Removing unreachable block (ram,0xf00a440c) */
/* WARNING: Removing unreachable block (ram,0xf00a43d0) */
/* WARNING: Removing unreachable block (ram,0xf00a4334) */
/* WARNING: Removing unreachable block (ram,0xf00a4300) */
/* WARNING: Removing unreachable block (ram,0xf00a42c4) */
/* WARNING: Removing unreachable block (ram,0xf00a424c) */
/* WARNING: Removing unreachable block (ram,0xf00a4214) */
/* WARNING: Removing unreachable block (ram,0xf00a41c0) */
/* WARNING: Removing unreachable block (ram,0xf00a416c) */
/* WARNING: Removing unreachable block (ram,0xf00a4130) */
/* WARNING: Removing unreachable block (ram,0xf00a40d4) */
/* WARNING: Removing unreachable block (ram,0xf00a409c) */
/* WARNING: Removing unreachable block (ram,0xf00a4078) */
/* WARNING: Removing unreachable block (ram,0xf00a3fe8) */
/* WARNING: Removing unreachable block (ram,0xf00a3fc4) */
/* WARNING: Removing unreachable block (ram,0xf00a3f2c) */
/* WARNING: Removing unreachable block (ram,0xf00a3ef4) */
/* WARNING: Removing unreachable block (ram,0xf00a3e74) */
/* WARNING: Removing unreachable block (ram,0xf00a3e50) */
/* WARNING: Removing unreachable block (ram,0xf00a3e58) */
/* WARNING: Removing unreachable block (ram,0xf00a3eec) */
/* WARNING: Removing unreachable block (ram,0xf00a3f10) */
/* WARNING: Removing unreachable block (ram,0xf00a3f58) */
/* WARNING: Removing unreachable block (ram,0xf00a3fcc) */
/* WARNING: Removing unreachable block (ram,0xf00a4008) */
/* WARNING: Removing unreachable block (ram,0xf00a4080) */
/* WARNING: Removing unreachable block (ram,0xf00a40b4) */
/* WARNING: Removing unreachable block (ram,0xf00a4128) */
/* WARNING: Removing unreachable block (ram,0xf00a414c) */
/* WARNING: Removing unreachable block (ram,0xf00a419c) */
/* WARNING: Removing unreachable block (ram,0xf00a420c) */
/* WARNING: Removing unreachable block (ram,0xf00a4230) */
/* WARNING: Removing unreachable block (ram,0xf00a42bc) */
/* WARNING: Removing unreachable block (ram,0xf00a42e0) */
/* WARNING: Removing unreachable block (ram,0xf00a432c) */
/* WARNING: Removing unreachable block (ram,0xf00a4364) */
/* WARNING: Removing unreachable block (ram,0xf00a43f4) */
/* WARNING: Removing unreachable block (ram,0xf00a4414) */
/* WARNING: Removing unreachable block (ram,0xf00a4444) */
/* WARNING: Removing unreachable block (ram,0xf00a44a8) */
/* WARNING: Removing unreachable block (ram,0xf00a3e44) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _srmmu_init(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l3;
  uint uVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar7;
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
  _mmu_getsyncflt();
  _mmu_getasyncflt(_afsrbuf);
  _init_mem_installed();
  _econtig = _end + 0xfffU & 0xfffff000;
  _fill_pmapinfo();
  if ((_viking == 0) || (uVar4 = _nctxs << 2, uVar4 < 0x4000)) {
    uVar4 = 0x4000;
  }
  uVar3 = __bootops;
  (**(code **)(__bootops + 0x1c))(__bootops,_econtig,_nctxs << 2,uVar4);
  _contexts = uVar3;
  if (uVar3 != _econtig) {
    _panic(aCannotAllocate);
  }
  uVar3 = _contexts;
  _va_to_pa();
  _pcontexts = uVar3;
  if (uVar3 == 0xffffffff) {
    _panic(aInvalidPhysica);
  }
  if ((_pcontexts & uVar4 - 1) != 0) {
    _panic(aPhysicalAddres_0);
  }
  uVar3 = _econtig + (_nctxs + 0x3ffU >> 10) * 0x1000;
  uVar4 = _mem_size;
  _econtig = uVar3;
  .udiv(_mem_size,200);
  if (0x400000 < uVar4) {
    uVar4 = 0x400000;
  }
  uVar7 = uVar4 + _page_mask & ~_page_mask;
  iVar5 = (uVar7 >> 8) * 0x100;
  uVar4 = __bootops;
  (**(code **)(__bootops + 0x1c))(__bootops,uVar3,iVar5,_page_size);
  _kernel_seg_tables = uVar4;
  if (uVar4 != _econtig) {
    _panic(aCannotAllocate_0);
  }
  uVar4 = _kernel_seg_tables;
  _va_to_pa();
  _kernel_seg_tables_phys = uVar4;
  if (uVar4 == 0xffffffff) {
    _panic(aInvalidPhysica_0);
  }
  if ((_kernel_seg_tables_phys & _page_size - 1U) != 0) {
    _panic(aPhysicalAddres_1);
  }
  _econtig = _econtig + ((uVar7 >> 8) + 0xf >> 4) * 0x1000;
  _kernel_seg_end = _kernel_seg_tables_phys + iVar5;
  _kernel_seg_tables_end = _kernel_seg_tables + iVar5;
  uVar4 = __bootops;
  (**(code **)(__bootops + 0x1c))(__bootops,_econtig,0x2000,0x1000);
  _kernel_region = uVar4;
  if (uVar4 != _econtig) {
    _panic(aCannotAllocate_1);
  }
  uVar4 = _kernel_region;
  _va_to_pa();
  _Nl1ptbl_addr = uVar4;
  if (uVar4 == 0xffffffff) {
    _panic(aInvalidPhysica_1);
  }
  if ((_Nl1ptbl_addr & 0xfff) != 0) {
    _panic(aPhysicalAddres_2);
  }
  iVar5 = _page_size;
  uVar3 = _econtig + 0x2000;
  _econtig = uVar3;
  .udiv(uVar7,_page_size);
  uVar6 = (uVar7 * 0x20 + _page_mask & ~_page_mask) >> 5;
  uVar4 = __bootops;
  (**(code **)(__bootops + 0x1c))(__bootops,uVar3,uVar6 << 5,iVar5);
  _kernel_seg_pools = uVar4;
  if (uVar4 != _econtig) {
    _panic(aCannotAllocate_2);
  }
  uVar4 = _kernel_seg_pools;
  _va_to_pa();
  if (uVar4 == 0xffffffff) {
    _panic(aInvalidPhysica_2);
  }
  if ((uVar4 & _page_size - 1U) != 0) {
    _panic(aPhysicalAddres_3);
  }
  uVar6 = _econtig + (uVar6 + 0x7f >> 7) * 0x1000;
  uVar4 = uVar7;
  _econtig = uVar6;
  DAT_f013de80._0_4_ = uVar7;
  .umul(uVar7,word_F013DE74);
  uVar3 = uVar4 * 0x28 + _page_mask & ~_page_mask;
  .udiv(uVar3,0x28);
  iVar5 = uVar3 * 0x28;
  uVar3 = __bootops;
  (**(code **)(__bootops + 0x1c))(__bootops,uVar6,iVar5,_page_size);
  _kernel_seg_entries = uVar3;
  if (uVar3 != _econtig) {
    _panic(aCannotAllocate_3);
  }
  uVar3 = _kernel_seg_entries;
  _va_to_pa();
  if (uVar3 == 0xffffffff) {
    _panic(aInvalidPhysica_3);
  }
  if ((uVar3 & _page_size - 1U) != 0) {
    _panic(aPhysicalAddres_4);
  }
  _econtig = _econtig + (iVar5 + 0xfffU & 0xfffff000);
  _kernel_seg_entries_end = _kernel_seg_entries + iVar5;
  uVar3 = __bootops;
  DAT_f013de7c._0_4_ = uVar4;
  (**(code **)(__bootops + 0x1c))(__bootops,_econtig,_nctxs * 0xc,_page_size);
  _context_table = uVar3;
  if (uVar3 != _econtig) {
    _panic(aCannotAllocate_4);
  }
  uVar4 = _context_table;
  _va_to_pa();
  if (uVar4 == 0xffffffff) {
    _panic(aInvalidPhysica_4);
  }
  if ((uVar4 & _page_size - 1U) != 0) {
    _panic(aPhysicalAddres_5);
  }
  _econtig = _econtig + (_nctxs * 0xc + 0xfffU & 0xfffff000);
  _init_kernel_page_tables(uVar7);
  _init_context_table();
  if ((_viking != 0) && (_mxcc == 0)) {
    _bpt_reg(0,0x1000);
  }
  uVar4 = __bootops;
  (**(code **)(__bootops + 0x30))(__bootops,aMemoryUpdate);
  if (uVar4 == 0) {
    (**(code **)(__bootops + 0x34))(__bootops,aMemoryUpdate_0,0);
  }
  _phys_avail = _cur_memlist;
  _copy_memlist(*(undefined4 *)(*(int *)(__bootops + 8) + 4),&_cur_memlist,_old_memlist);
  _virt_avail = _cur_memlist;
  _copy_memlist(*(undefined4 *)(*(int *)(__bootops + 8) + 8),&_cur_memlist,_old_memlist);
  (**(code **)(__bootops + 0x2c))();
  _init_mem_regions(param_1);
  _copy_page_tables();
  uVar1 = 0x2000;
  if (_iom != 0) {
    _get_from_mem_regions(0x2000,4);
    uVar2 = 0x4000;
    _first_page = uVar1;
    _get_from_mem_regions(0x4000,0x4000);
    _ioptes = _econtig;
    _phys_iopte = uVar2;
    _pmap_map(_econtig,uVar2,0,0x4000,7,0);
    _econtig = _ioptes + 0x4000;
    _eioptes = _econtig;
    if (_viking != 0) {
      _pac_flush(_ioptes,_econtig - _ioptes);
    }
  }
  return CONCAT44(DAT_f0134000,uVar7);
}
/* GHIDRADEC_FUNCTION index=2447 start=0xf00a44b8 */

/* WARNING: Removing unreachable block (ram,0xf00a44e4) */

undefined8 _address_in_memlist(undefined8 *param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar2;
  undefined8 in_i0_1;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  if (param_1 != (undefined8 *)0x0) {
    do {
      if (param_2 < *(uint *)((int)param_1 + 4)) {
        param_1 = *(undefined8 **)(param_1 + 2);
      }
      else {
        uVar3 = (uint)*param_1;
        uVar1 = (uint)param_1[1];
        uVar4 = uVar3 + uVar1;
        uVar2 = 1;
        if (((int)((qword)*param_1 >> 0x20) + (int)((qword)param_1[1] >> 0x20) +
             (uint)CARRY4(uVar3,uVar1) != 0) || (param_2 + param_3 <= uVar4)) goto locret_F00A4548;
        param_1 = *(undefined8 **)(param_1 + 2);
      }
    } while (param_1 != (undefined8 *)0x0);
  }
  uVar4 = 0;
  uVar2 = 0;
locret_F00A4548:
  return CONCAT44(uVar4,uVar2);
}
/* GHIDRADEC_FUNCTION index=2448 start=0xf00a4550 */

undefined8 _copy_memlist(qword *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  qword qVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  qword *pqVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar4;
  undefined4 unaff_i3;
  qword *pqVar5;
  undefined4 unaff_i4;
  undefined4 *puVar6;
  undefined4 unaff_i5;
  qword *pqVar7;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  pqVar5 = (qword *)*param_2;
  if (param_3 == 0) {
    if (param_1 == (qword *)0x0) {
      *param_2 = pqVar5;
      goto locret_F00A4640;
    }
    puVar1 = (undefined4 *)((int)pqVar5 + 0x14);
    qVar2 = *param_1;
    pqVar3 = param_1;
    pqVar7 = pqVar5;
    while( true ) {
      *pqVar5 = qVar2;
      *(qword *)(puVar1 + -3) = pqVar3[1];
      puVar1[-1] = 0;
      if (pqVar7 == pqVar5) {
        *puVar1 = 0;
      }
      else {
        *puVar1 = pqVar7;
        *(qword **)(pqVar7 + 2) = pqVar5;
        pqVar7 = pqVar7 + 3;
      }
      pqVar5 = pqVar5 + 3;
      puVar1 = puVar1 + 6;
      pqVar3 = *(qword **)(pqVar3 + 2);
      param_1 = (qword *)0x0;
      if (pqVar3 == (qword *)0x0) break;
      qVar2 = *pqVar3;
    }
  }
  else {
    puVar6 = (undefined4 *)((int)pqVar5 + 0x14);
    puVar1 = param_2;
    if (param_1 != (qword *)0x0) {
      uVar4 = *(uint *)param_1;
      pqVar3 = pqVar5;
      while( true ) {
        *pqVar5 = (qword)uVar4;
        puVar1 = *(undefined4 **)((int)param_1 + 4);
        *(qword *)(puVar6 + -3) = ZEXT48(puVar1);
        puVar6[-1] = 0;
        if (pqVar3 == pqVar5) {
          *puVar6 = 0;
        }
        else {
          *puVar6 = pqVar3;
          *(qword **)(pqVar3 + 2) = pqVar5;
          pqVar3 = pqVar3 + 3;
        }
        puVar6 = puVar6 + 6;
        pqVar5 = pqVar5 + 3;
        param_1 = *(qword **)(param_1 + 1);
        if (param_1 == (qword *)0x0) break;
        uVar4 = *(uint *)param_1;
      }
      *param_2 = pqVar5;
      param_1 = (qword *)0x0;
      param_2 = puVar1;
      goto locret_F00A4640;
    }
  }
  *param_2 = pqVar5;
  param_2 = puVar1;
locret_F00A4640:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2449 start=0xf00a4648 */

undefined8 _installed_top_size(undefined8 *param_1,uint *param_2,int *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar5;
  uint *puVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar7;
  undefined8 in_i4_5;
  uint uVar8;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(int *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = (int)((qword)in_i4_5 >> 0x20);
    *(int *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = (int)in_i4_5;
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
  uVar3 = 0;
  iVar4 = 0;
  puVar6 = param_2;
  for (puVar2 = param_1; puVar2 != (undefined8 *)0x0; puVar2 = *(undefined8 **)(puVar2 + 2)) {
    uVar5 = (uint)*puVar2;
    uVar8 = (uint)puVar2[1];
    iVar1 = uVar5 + uVar8;
    iVar7 = (int)((qword)puVar2[1] >> 0x20);
    uVar5 = ((int)((qword)*puVar2 >> 0x20) + iVar7 + (uint)CARRY4(uVar5,uVar8) + -1 +
            (uint)(iVar1 != 0)) * 0x100000 | iVar1 - 1U >> 0xc;
    if ((int)uVar3 < (int)uVar5) {
      uVar3 = uVar5;
    }
    puVar6 = (uint *)(iVar7 << 0x14);
    param_1 = (undefined8 *)(uVar8 >> 0xc);
    iVar4 = iVar4 + ((uint)puVar6 | (uint)param_1);
  }
  *param_2 = uVar3;
  *param_3 = iVar4;
  return CONCAT44(puVar6,param_1);
}

