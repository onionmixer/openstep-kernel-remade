
/* WARNING: Removing unreachable block (ram,0xf0077e08) */

undefined8 sub_F0077DDC(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
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
  piVar5 = *(int **)(param_1 + 8);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else if ((uint)piVar5[1] < param_2) {
    uVar3 = *(uint *)(param_1 + 0x18);
    uVar1 = param_2 >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
    if ((int)uVar3 < (int)uVar1) {
      uVar1 = uVar3;
    }
    piVar4 = (int *)(*(int *)(param_1 + 0x14) + uVar1 * 0x10 + -0x10);
    if ((int)uVar1 < (int)uVar3) {
      do {
        piVar5 = (int *)*piVar4;
        if (piVar5 != (int *)0x0) {
          piVar6 = (int *)*piVar5;
          if (piVar6 != (int *)0x0) {
            iVar2 = piVar6[1];
            goto loc_F0077E74;
          }
          *piVar4 = 0;
          goto locret_F0077F30;
        }
        uVar1 = uVar1 + 1;
        piVar4 = piVar4 + 4;
      } while ((int)uVar1 < *(int *)(param_1 + 0x18));
    }
    piVar5 = (int *)*piVar4;
    if (piVar5 != (int *)0x0) {
      piVar6 = (int *)*piVar5;
      if ((uint)piVar5[1] < param_2) {
        piVar5 = piVar6;
        if (piVar6 != (int *)0x0) {
          uVar1 = piVar6[1];
          while ((uVar1 < param_2 && (piVar5 = (int *)*piVar5, piVar5 != (int *)0x0))) {
            uVar1 = piVar5[1];
          }
        }
      }
      else if (piVar6 == (int *)0x0) {
        *piVar4 = 0;
      }
      else {
        uVar1 = piVar6[1];
        while (uVar1 < *(uint *)(param_1 + 4)) {
          piVar6 = (int *)*piVar6;
          if (piVar6 == (int *)0x0) {
            *piVar4 = 0;
            goto locret_F0077F30;
          }
          uVar1 = piVar6[1];
        }
        *piVar4 = (int)piVar6;
      }
    }
  }
  else {
    sub_F0077B04(param_1,piVar5);
  }
locret_F0077F30:
  return CONCAT44(param_2,piVar5);
loc_F0077E74:
  if (iVar2 == piVar5[1]) goto loc_f0077e78;
  piVar6 = (int *)*piVar6;
  if (piVar6 == (int *)0x0) {
    *piVar4 = 0;
    goto locret_F0077F30;
  }
  iVar2 = piVar6[1];
  goto loc_F0077E74;
loc_f0077e78:
  *piVar4 = (int)piVar6;
  goto locret_F0077F30;
}

