
/* WARNING: Removing unreachable block (ram,0xf004da34) */
/* WARNING: Removing unreachable block (ram,0xf004d8b4) */
/* WARNING: Removing unreachable block (ram,0xf004d898) */
/* WARNING: Removing unreachable block (ram,0xf004d9ec) */
/* WARNING: Removing unreachable block (ram,0xf004d8dc) */
/* WARNING: Removing unreachable block (ram,0xf004d868) */

undefined8 _disksort_remove(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l0;
  int *piVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar8;
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
  sub_F004D11C(param_1);
  iVar1 = param_1[3];
  if (iVar1 < 0) {
    (*dword_F013AD90)(param_1,param_2);
    piVar8 = param_1;
  }
  else {
    _spltty();
    do {
      do {
      } while (param_1[9] != 0);
      piVar2 = param_1 + 9;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    piVar2 = (int *)param_1[4];
    if (param_1 + 4 == piVar2) {
      param_1[9] = 0;
      _splx(iVar1);
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)*piVar2;
      while (iVar3 = piVar8[3], piVar7 = piVar8, piVar8 != param_2) {
        while ((piVar8 = (int *)piVar7[3], iVar3 != 0 && (piVar8 != param_2))) {
          iVar3 = piVar8[3];
          piVar7 = piVar8;
        }
        if (piVar8 != (int *)0x0) {
          iVar3 = param_2[3];
          piVar7[3] = iVar3;
          piVar8 = param_2;
          if (iVar3 == 0) {
            piVar2[1] = (int)piVar7;
          }
          goto loc_F004D980;
        }
        piVar2 = (int *)piVar2[4];
        piVar8 = piVar7;
        if (param_1 + 4 == piVar2) goto loc_F004D980;
        piVar8 = (int *)*piVar2;
      }
      *piVar2 = iVar3;
      uVar4 = param_1[3];
      if (piVar2 == (int *)param_1[4]) {
        param_1[3] = uVar4 & 0xefffffff;
        param_1[7] = piVar8[0xe];
loc_F004D980:
        uVar4 = param_1[3];
      }
      piVar2 = (int *)param_1[4];
      if ((((uVar4 & 0x10000000) == 0) && (piVar7 = param_1 + 4, piVar7 != piVar2)) &&
         (*piVar2 == 0)) {
        piVar6 = (int *)piVar2[4];
        while( true ) {
          piVar5 = (int *)piVar2[5];
          if (param_1 + 4 == piVar6) {
            param_1[5] = (int)piVar5;
          }
          else {
            piVar6[5] = (int)piVar5;
          }
          if (piVar7 == piVar5) {
            param_1[4] = (int)piVar6;
          }
          else {
            piVar5[4] = (int)piVar6;
          }
          _kfree(piVar2,0x18);
          piVar2 = (int *)param_1[4];
          param_1[6] = param_1[6] + 1;
          param_2 = piVar7;
          if ((((param_1[3] & 0x10000000U) != 0) || (param_1 + 4 == piVar2)) || (*piVar2 != 0))
          break;
          piVar6 = (int *)piVar2[4];
        }
      }
      param_1[9] = 0;
      _splx(iVar1);
    }
  }
  return CONCAT44(param_2,piVar8);
}

