
/* WARNING: Removing unreachable block (ram,0xf003a4b4) */
/* WARNING: Removing unreachable block (ram,0xf003a4a4) */
/* WARNING: Removing unreachable block (ram,0xf003a4c0) */
/* WARNING: Removing unreachable block (ram,0xf003a478) */

undefined8 _exportfree(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  word *pwVar2;
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
  if (param_1[2] == 1) {
    if (param_1[3] == 0) {
      uVar1 = *param_1;
      goto loc_F003A484;
    }
    _kfree(param_1[4],param_1[3] << 4);
  }
  uVar1 = *param_1;
loc_F003A484:
  if ((uVar1 & 2) == 0) {
    pwVar2 = (word *)param_1[10];
  }
  else if (param_1[6] == 0) {
    pwVar2 = (word *)param_1[10];
  }
  else {
    _kfree(param_1[7],param_1[6] << 4);
    pwVar2 = (word *)param_1[10];
  }
  _kfree(pwVar2,*pwVar2 + 2);
  _kfree(param_1,0x30);
  return CONCAT44(param_2,param_1);
}

