
/* WARNING: Removing unreachable block (ram,0xf00a4e78) */

undefined8 _rmalloc(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
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
  piVar4 = param_1 + 2;
  if (param_2 < 1) {
    _panic(&aRmalloc);
  }
  if (param_1[2] != 0) {
    iVar1 = *piVar4;
    iVar2 = iVar1 - param_2;
    do {
      if (iVar2 < 0 == SBORROW4(iVar1,param_2)) {
        iVar1 = piVar4[1];
        iVar2 = *piVar4;
        piVar4[1] = iVar1 + param_2;
        *piVar4 = iVar2 - param_2;
        if (iVar2 - param_2 == 0) {
          piVar3 = piVar4 + 1;
          do {
            *piVar4 = piVar3[1];
            piVar4 = piVar4 + 2;
            *piVar3 = piVar3[2];
            piVar3 = piVar3 + 2;
          } while (*piVar4 != 0);
          *param_1 = *param_1 + 1;
        }
        goto locret_F00A4F0C;
      }
      piVar4 = piVar4 + 2;
      iVar1 = *piVar4;
      iVar2 = iVar1 - param_2;
    } while (iVar1 != 0);
  }
  iVar1 = 0;
locret_F00A4F0C:
  return CONCAT44(param_2,iVar1);
}

