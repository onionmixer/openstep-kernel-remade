
/* WARNING: Removing unreachable block (ram,0xf00123d0) */
/* WARNING: Removing unreachable block (ram,0xf0012404) */
/* WARNING: Removing unreachable block (ram,0xf00123bc) */

undefined8 _uiomove(int param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  iVar4 = 0;
  while ((0 < (int)param_2 && (param_4[5] != 0))) {
    piVar3 = (int *)*param_4;
    uVar2 = piVar3[1];
    if (uVar2 == 0) {
      *param_4 = piVar3 + 2;
      param_4[1] = param_4[1] + -1;
    }
    else {
      if (param_2 < uVar2) {
        uVar2 = param_2;
      }
      iVar1 = param_4[3];
      if (iVar1 == 1) {
        if (param_3 == 0) {
          iVar1 = *piVar3;
          iVar4 = param_1;
        }
        else {
          iVar4 = *piVar3;
          iVar1 = param_1;
        }
        _copywithin(iVar4,iVar1,uVar2);
        iVar1 = *piVar3;
      }
      else if (iVar1 < 2) {
        if (iVar1 == 0) {
loc_F00123AC:
          if (param_3 == 0) {
            iVar4 = param_1;
            _copyout(param_1,*piVar3,uVar2);
          }
          else {
            iVar4 = *piVar3;
            _copyin(iVar4,param_1,uVar2);
          }
          if (iVar4 != 0) break;
          iVar1 = *piVar3;
        }
        else {
          iVar1 = *piVar3;
        }
      }
      else {
        if (iVar1 == 2) goto loc_F00123AC;
        iVar1 = *piVar3;
      }
      param_1 = param_1 + uVar2;
      *piVar3 = iVar1 + uVar2;
      piVar3[1] = piVar3[1] - uVar2;
      param_2 = param_2 - uVar2;
      param_4[5] = param_4[5] - uVar2;
      param_4[2] = param_4[2] + uVar2;
    }
  }
  return CONCAT44(param_2,iVar4);
}
