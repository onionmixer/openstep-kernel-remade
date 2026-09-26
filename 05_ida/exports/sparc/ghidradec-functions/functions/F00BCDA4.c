
/* WARNING: Removing unreachable block (ram,0xf00bce6c) */
/* WARNING: Removing unreachable block (ram,0xf00bcddc) */

undefined8 -[kmDevice animationCtl:](int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar3;
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
  bVar1 = false;
  uVar3 = 0;
  if (*(int *)(param_1 + 0x114) == 2) {
    do {
      do {
      } while (dword_F0132070 != 0);
      puVar2 = &dword_F0132070;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    if (param_3 < 2) {
      if (0 < dword_F011FEBC) {
        dword_F011FEBC = -dword_F011FEBC;
        (**(code **)(*(int *)(param_1 + 0x10c) + 0x10))(*(int *)(param_1 + 0x10c),unk_F011FE4C);
      }
    }
    else if (param_3 == 2) {
      if (dword_F011FEBC < 0) {
        dword_F011FEBC = -dword_F011FEBC;
        bVar1 = true;
      }
    }
    else {
      uVar3 = 0x16;
    }
    dword_F0132070 = 0;
    if (bVar1) {
      sub_F00BCB88();
    }
  }
  else {
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}
