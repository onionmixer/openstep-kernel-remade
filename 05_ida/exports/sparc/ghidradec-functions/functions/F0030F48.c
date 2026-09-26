
undefined8
_in_pcblookup(int *param_1,uint *param_2,uint param_3,int *param_4,uint param_5,uint param_6)

{
  word wVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
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
  uint uVar7;
  undefined4 unaff_i2;
  uint uVar8;
  undefined4 unaff_i3;
  int iVar9;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
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
  piVar2 = (int *)*param_1;
  piVar6 = (int *)0x0;
  uVar7 = *param_2;
  uVar5 = 3;
  iVar9 = *param_4;
  piVar3 = piVar6;
  if (piVar2 != param_1) {
    wVar1 = *(word *)(piVar2 + 6);
    piVar3 = piVar2;
    do {
      if ((uint)wVar1 == (param_5 & 0xffff)) {
        uVar4 = 0;
        if (piVar3[5] == 0) {
          if (iVar9 != 0) goto loc_F0030FCC;
          uVar8 = piVar3[3];
        }
        else {
          if (iVar9 != 0) {
            if (piVar3[5] == iVar9) {
              uVar8 = piVar3[3];
              goto loc_F0030FD4;
            }
            piVar2 = (int *)*piVar3;
            goto loc_F0031058;
          }
loc_F0030FCC:
          uVar4 = 1;
          uVar8 = piVar3[3];
        }
loc_F0030FD4:
        if (uVar8 == 0) {
          bVar10 = uVar4 == 0;
          if (uVar7 != 0) goto loc_F0031028;
        }
        else {
          if (uVar7 != 0) {
            if ((uint)*(word *)(piVar3 + 4) == (param_3 & 0xffff)) {
              if ((uVar8 & 0xf0000000) == 0xe0000000) {
                piVar2 = (int *)*piVar3;
              }
              else {
                if (uVar8 == uVar7) {
                  bVar10 = uVar4 == 0;
                  goto loc_F003102C;
                }
                piVar2 = (int *)*piVar3;
              }
            }
            else {
              piVar2 = (int *)*piVar3;
            }
            goto loc_F0031058;
          }
loc_F0031028:
          uVar4 = uVar4 + 1;
          bVar10 = uVar4 == 0;
        }
loc_F003102C:
        if ((bVar10) || ((param_6 & 1) != 0)) {
          if (uVar4 < uVar5) {
            if (uVar4 == 0) break;
            piVar2 = (int *)*piVar3;
            uVar5 = uVar4;
            piVar6 = piVar3;
          }
          else {
            piVar2 = (int *)*piVar3;
          }
        }
        else {
          piVar2 = (int *)*piVar3;
        }
      }
      else {
        piVar2 = (int *)*piVar3;
      }
loc_F0031058:
      piVar3 = piVar6;
      if (piVar2 == param_1) break;
      wVar1 = *(word *)(piVar2 + 6);
      piVar3 = piVar2;
    } while( true );
  }
  return CONCAT44(uVar7,piVar3);
}
