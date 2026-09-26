
/* WARNING: Removing unreachable block (ram,0xf003049c) */
/* WARNING: Removing unreachable block (ram,0xf0030480) */
/* WARNING: Removing unreachable block (ram,0xf00304c4) */
/* WARNING: Removing unreachable block (ram,0xf0030454) */

undefined8 sub_F0030434(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  *(word *)(param_2 + 0x10) = *(word *)(param_1 + 0xc) & 0xfffe;
  iVar1 = param_3;
  _ifioctl(param_3,0x80206910,param_2);
  if (iVar1 == 0) {
    *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xbfff;
    _bzero(param_2 + 0x10,0x10);
    *(undefined2 *)(param_2 + 0x10) = 2;
    iVar1 = param_3;
    _ifioctl(param_3,0x80206916,param_2);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x14) = *param_4;
      _ifioctl(param_3,0x8020690c);
      iVar1 = param_3;
      if (param_3 == 0) {
        iVar1 = 0;
        *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x8000;
      }
    }
  }
  return CONCAT44(param_2,iVar1);
}

