
undefined8 sub_F0077B04(uint param_1,int *param_2)

{
  uint *puVar1;
  uint uVar2;
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
  uint uVar4;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  int *piVar5;
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
  puVar1 = (uint *)(param_2 + 1);
  uVar4 = *(uint *)(param_1 + 0x18);
  uVar2 = *puVar1 >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
  if ((int)uVar4 < (int)uVar2) {
    uVar2 = uVar4;
  }
  iVar3 = *(int *)(param_1 + 0x14) + uVar2 * 0x10;
  piVar5 = (int *)(iVar3 + -0x10);
  if (param_2 == *(int **)(iVar3 + -0x10)) {
    param_2 = (int *)*param_2;
    if ((int)uVar2 < (int)uVar4) {
      if (param_2 == (int *)0x0) {
loc_F0077BB4:
        *piVar5 = (int)param_2;
      }
      else {
        uVar2 = param_2[1];
        while (uVar2 != *puVar1) {
          param_2 = (int *)*param_2;
          if (param_2 == (int *)0x0) {
            *piVar5 = 0;
            goto locret_F0077BB8;
          }
          uVar2 = param_2[1];
        }
        *piVar5 = (int)param_2;
      }
    }
    else if (param_2 == (int *)0x0) {
      *piVar5 = 0;
    }
    else {
      param_1 = *(uint *)(param_1 + 4);
      uVar2 = param_2[1];
      while (uVar2 < param_1) {
        param_2 = (int *)*param_2;
        if (param_2 == (int *)0x0) goto loc_F0077BB4;
        uVar2 = param_2[1];
      }
      *piVar5 = (int)param_2;
    }
  }
locret_F0077BB8:
  return CONCAT44(param_2,param_1);
}
