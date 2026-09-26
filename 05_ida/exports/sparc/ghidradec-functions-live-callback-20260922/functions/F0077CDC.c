
undefined8 sub_F0077CDC(int param_1,int *param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bVar6;
  int *piVar5;
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
  uint uVar7;
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
  uVar7 = *(uint *)(param_1 + 0x18);
  bVar6 = (byte)*(undefined4 *)(param_1 + 0x10);
  uVar2 = (uint)param_2[1] >> (bVar6 & 0x1f);
  if ((int)uVar7 < (int)uVar2) {
    uVar2 = uVar7;
  }
  uVar3 = param_3 >> (bVar6 & 0x1f);
  if ((int)uVar7 < (int)uVar3) {
    uVar3 = uVar7;
  }
  if (uVar3 != uVar2) {
    iVar4 = *(int *)(param_1 + 0x14) + uVar3 * 0x10;
    piVar1 = (int *)(iVar4 + -0x10);
    if (param_2 == *(int **)(iVar4 + -0x10)) {
      piVar5 = (int *)*param_2;
      if ((int)uVar3 < (int)uVar7) {
        if (piVar5 == (int *)0x0) {
          *piVar1 = 0;
        }
        else {
          uVar7 = piVar5[1];
          while (uVar7 != param_3) {
            piVar5 = (int *)*piVar5;
            if (piVar5 == (int *)0x0) {
              *piVar1 = 0;
              goto loc_F0077DAC;
            }
            uVar7 = piVar5[1];
          }
          *piVar1 = (int)piVar5;
        }
      }
      else if (piVar5 == (int *)0x0) {
        *piVar1 = 0;
      }
      else {
        uVar7 = piVar5[1];
        while (uVar7 < *(uint *)(param_1 + 4)) {
          piVar5 = (int *)*piVar5;
          if (piVar5 == (int *)0x0) {
            *piVar1 = 0;
            goto loc_F0077DAC;
          }
          uVar7 = piVar5[1];
        }
        *piVar1 = (int)piVar5;
      }
    }
loc_F0077DAC:
    iVar4 = *(int *)(param_1 + 0x14) + uVar2 * 0x10;
    piVar1 = *(int **)(iVar4 + -0x10);
    if ((piVar1 == (int *)0x0) || (param_2 < piVar1)) {
      *(int **)(iVar4 + -0x10) = param_2;
    }
  }
  return CONCAT44(param_2,param_1);
}

