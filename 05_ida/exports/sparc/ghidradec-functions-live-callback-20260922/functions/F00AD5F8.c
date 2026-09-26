
/* WARNING: Removing unreachable block (ram,0xf00ad610) */

undefined8 sub_F00AD5F8(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
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
  uVar3 = 0;
  if (param_2[8] != 0 || param_2[7] != 0) {
    _fpu_set_exception(param_1,0);
    uVar1 = *(uint *)(param_1 + 4);
    if (uVar1 == 1) {
      uVar3 = 0;
    }
    else if (uVar1 < 2) {
      uVar3 = param_2[7];
    }
    else if (uVar1 == 2) {
      uVar3 = (uint)(*param_2 == 0);
    }
    else if (uVar1 == 3) {
      uVar3 = (uint)(*param_2 != 0);
    }
    if (uVar3 == 0) {
      iVar2 = *(int *)(param_1 + 4);
    }
    else {
      iVar2 = param_2[6];
      param_2[6] = iVar2 + 1;
      if ((((iVar2 + 1 == 0) && (iVar2 = param_2[5], param_2[5] = iVar2 + 1, iVar2 + 1 == 0)) &&
          (iVar2 = param_2[4], param_2[4] = iVar2 + 1, iVar2 + 1 == 0)) &&
         (iVar2 = param_2[3], param_2[3] = iVar2 + 1, iVar2 + 1 == 0x20000)) {
        param_2[3] = 0x10000;
        param_2[2] = param_2[2] + 1;
      }
      iVar2 = *(int *)(param_1 + 4);
    }
    if (((iVar2 == 0) && (param_2[8] == 0)) && (uVar3 != 0)) {
      param_2[6] = param_2[6] & 0xfffffffe;
    }
  }
  return CONCAT44(param_2,param_1);
}

