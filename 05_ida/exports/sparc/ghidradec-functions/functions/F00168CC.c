
/* WARNING: Removing unreachable block (ram,0xf0016960) */
/* WARNING: Removing unreachable block (ram,0xf00168d0) */

undefined8 _ttychars(int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _ttynty();
  *(undefined *)(param_1 + 0x4d) = _ttydefaults[0];
  *(undefined *)(param_1 + 0x4e) = _ttydefaults[1];
  *(undefined *)(param_1 + 0x4f) = _ttydefaults[2];
  *(undefined *)(param_1 + 0x50) = _ttydefaults[3];
  *(undefined *)(param_1 + 0x51) = _ttydefaults[4];
  *(undefined *)(param_1 + 0x52) = _ttydefaults[5];
  *(undefined *)(param_1 + 0x53) = _ttydefaults[6];
  *(undefined *)(param_1 + 0x54) = _ttydefaults[7];
  *(undefined *)(param_1 + 0x55) = _ttydefaults[8];
  *(undefined *)(param_1 + 0x56) = _ttydefaults[9];
  *(undefined *)(param_1 + 0x57) = _ttydefaults[10];
  *(undefined *)(param_1 + 0x58) = _ttydefaults[0xb];
  *(undefined *)(param_1 + 0x59) = _ttydefaults[0xc];
  *(undefined *)(param_1 + 0x5a) = _ttydefaults[0xd];
  *(undefined *)(iVar1 + 0x14) = 0x5c;
  *(undefined *)(iVar1 + 0x15) = 1;
  *(undefined *)(iVar1 + 0x16) = 0;
  _ttysetspec();
  return CONCAT44(param_2,param_1);
}
