
/* WARNING: Removing unreachable block (ram,0xf00b07a4) */

undefined8
_apply_range_to_range(undefined4 param_1,int param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
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
  int *piVar3;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar4;
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
  if ((0 < param_2) && (0 < param_4)) {
    piVar3 = (int *)(param_5 + 8);
    do {
      param_4 = param_4 + -1;
      iVar1 = 0;
      bVar4 = param_2 == 0;
      piVar2 = param_3;
      if (0 < param_2) {
        do {
          bVar4 = iVar1 == param_2;
          if (*piVar3 == *piVar2) goto loc_F00B0794;
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 5;
        } while (iVar1 < param_2);
        bVar4 = iVar1 == param_2;
      }
loc_F00B0794:
      if (bVar4) {
        _printf(DAT_f011c45c._0_4_,0xf011c470,param_1);
      }
      else {
        piVar3[1] = piVar3[1] + piVar2[3];
        *piVar3 = piVar2[2];
        piVar3 = piVar3 + 5;
      }
    } while (0 < param_4);
  }
  return CONCAT44(param_2,param_1);
}

