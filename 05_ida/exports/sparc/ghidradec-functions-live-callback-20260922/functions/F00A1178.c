
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

