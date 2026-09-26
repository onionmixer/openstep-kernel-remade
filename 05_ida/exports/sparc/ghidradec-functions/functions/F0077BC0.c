
undefined8 sub_F0077BC0(int param_1,int *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  byte bVar5;
  int iVar3;
  int *piVar4;
  int *piVar6;
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
  uint uVar7;
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
  uVar7 = *(uint *)(param_1 + 0x18);
  bVar5 = (byte)*(undefined4 *)(param_1 + 0x10);
  uVar1 = (uint)param_2[1] >> (bVar5 & 0x1f);
  if ((int)uVar7 < (int)uVar1) {
    uVar1 = uVar7;
  }
  uVar2 = param_3 >> (bVar5 & 0x1f);
  if ((int)uVar7 < (int)uVar2) {
    uVar2 = uVar7;
  }
  iVar3 = *(int *)(param_1 + 0x14) + uVar2 * 0x10;
  piVar6 = (int *)(iVar3 + -0x10);
  if (uVar2 == uVar1) {
    if (param_4 != *(int *)(iVar3 + -0x10)) goto locret_F0077CD4;
  }
  else {
    if (param_4 == *(int *)(iVar3 + -0x10)) {
      piVar4 = (int *)*param_2;
      if ((int)uVar2 < (int)uVar7) {
        if (piVar4 == (int *)0x0) {
          *piVar6 = 0;
        }
        else {
          uVar7 = piVar4[1];
          while (uVar7 != param_3) {
            piVar4 = (int *)*piVar4;
            if (piVar4 == (int *)0x0) {
              *piVar6 = 0;
              goto loc_F0077C94;
            }
            uVar7 = piVar4[1];
          }
          *piVar6 = (int)piVar4;
        }
      }
      else if (piVar4 == (int *)0x0) {
        *piVar6 = 0;
      }
      else {
        uVar7 = piVar4[1];
        while (uVar7 < *(uint *)(param_1 + 4)) {
          piVar4 = (int *)*piVar4;
          if (piVar4 == (int *)0x0) {
            *piVar6 = 0;
            goto loc_F0077C94;
          }
          uVar7 = piVar4[1];
        }
        *piVar6 = (int)piVar4;
      }
loc_F0077C94:
      iVar3 = *(int *)(param_1 + 0x14);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x14);
    }
    iVar3 = iVar3 + uVar1 * 0x10;
    if (*(int **)(iVar3 + -0x10) != (int *)0x0) {
      if (param_2 < *(int **)(iVar3 + -0x10)) {
        *(int **)(iVar3 + -0x10) = param_2;
      }
      goto locret_F0077CD4;
    }
  }
  *(int **)(iVar3 + -0x10) = param_2;
locret_F0077CD4:
  return CONCAT44(param_2,param_1);
}
