
/* WARNING: Removing unreachable block (ram,0xf00a5144) */

undefined8 _rmget(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
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
  piVar3 = param_1 + 2;
  if (param_2 < 1) {
    _panic(&aRmget);
  }
  if (param_1[2] != 0) {
    uVar2 = param_1[3];
    piVar4 = piVar3;
    while( true ) {
      if ((uVar2 <= param_3) && (param_3 < uVar2 + *piVar4)) {
        iVar1 = *piVar4;
        goto loc_F00A5198;
      }
      piVar3 = piVar4 + 2;
      if (*piVar3 == 0) break;
      uVar2 = piVar4[3];
      piVar4 = piVar3;
    }
  }
  iVar1 = *piVar3;
  piVar4 = piVar3;
loc_F00A5198:
  if (iVar1 != 0) {
    uVar2 = piVar4[1];
    if (param_3 <= uVar2) {
      if (uVar2 == param_3) {
        if (iVar1 == param_2) {
          piVar3 = piVar4 + 1;
          do {
            *piVar4 = piVar3[1];
            piVar4 = piVar4 + 2;
            *piVar3 = piVar3[2];
            piVar3 = piVar3 + 2;
          } while (*piVar4 != 0);
          *param_1 = *param_1 + 1;
          goto locret_F00A52BC;
        }
        piVar4[1] = param_3 + param_2;
        iVar1 = *piVar4 - param_2;
      }
      else if (uVar2 + iVar1 == param_3 + param_2) {
        iVar1 = iVar1 - param_2;
      }
      else {
        piVar3 = piVar4;
        if (*param_1 == 0) goto loc_F00A5230;
        do {
          piVar5 = piVar3;
          piVar3 = piVar5 + 2;
        } while (piVar5[2] != 0);
        piVar5[4] = 0;
        if (piVar5 == piVar4) {
          iVar1 = *param_1;
        }
        else {
          piVar3 = piVar5 + 3;
          do {
            piVar3[-1] = *piVar5;
            *piVar3 = piVar3[-2];
            piVar5 = piVar5 + -2;
            piVar3 = piVar3 + -2;
          } while (piVar5 != piVar4);
          iVar1 = *param_1;
        }
        *param_1 = iVar1 + -1;
        piVar4[3] = param_3 + param_2;
        piVar4[2] = (piVar4[1] + *piVar4) - (param_3 + param_2);
        iVar1 = param_3 - piVar4[1];
      }
      *piVar4 = iVar1;
      goto locret_F00A52BC;
    }
  }
loc_F00A5230:
  param_3 = 0;
locret_F00A52BC:
  return CONCAT44(param_2,param_3);
}

