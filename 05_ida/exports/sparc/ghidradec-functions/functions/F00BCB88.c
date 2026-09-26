
/* WARNING: Removing unreachable block (ram,0xf00bcc6c) */
/* WARNING: Removing unreachable block (ram,0xf00bcbac) */

undefined8 sub_F00BCB88(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
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
    } while (dword_F0132070 != 0);
    puVar1 = &dword_F0132070;
    _simple_lock_try();
    iVar3 = 1;
  } while (puVar1 == (undefined4 *)0x0);
  if (DAT_f0121588._0_4_ != 0) {
    iVar3 = 2;
  }
  iVar2 = _basicConsole;
  if (iVar3 == 2) {
    iVar2 = _prettyp;
  }
  if (0 < dword_F011FEBC) {
    if (iVar3 == 2) {
      if (iVar2 != 0) {
        (**(code **)(iVar2 + 0xc))(iVar2,unk_F011FE1C + dword_F011FEBC * 0xc);
      }
      dword_F011FEBC = dword_F011FEBC + 1;
      if (3 < dword_F011FEBC) {
        dword_F011FEBC = 1;
      }
      _ns_timeout(sub_F00BCB88,0,0,0x69f6bc7,4);
    }
    else {
      dword_F011FEBC = -dword_F011FEBC;
    }
  }
  dword_F0132070 = 0;
  return CONCAT44(param_2,param_1);
}
