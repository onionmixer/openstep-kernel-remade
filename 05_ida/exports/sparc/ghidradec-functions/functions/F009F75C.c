
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
