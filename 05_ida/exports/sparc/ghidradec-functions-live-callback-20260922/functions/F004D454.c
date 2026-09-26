
/* WARNING: Removing unreachable block (ram,0xf004d5b4) */
/* WARNING: Removing unreachable block (ram,0xf004d5f0) */
/* WARNING: Removing unreachable block (ram,0xf004d644) */
/* WARNING: Removing unreachable block (ram,0xf004d4a0) */
/* WARNING: Removing unreachable block (ram,0xf004d478) */
/* WARNING: Removing unreachable block (ram,0xf004d530) */
/* WARNING: Removing unreachable block (ram,0xf004d658) */
/* WARNING: Removing unreachable block (ram,0xf004d6a4) */
/* WARNING: Removing unreachable block (ram,0xf004d6c4) */
/* WARNING: Removing unreachable block (ram,0xf004d45c) */

undefined8 sub_F004D454(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
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
  iVar5 = param_2[0xf];
  piVar1 = param_1;
  _spltty();
  do {
    do {
    } while (param_1[9] != 0);
    piVar2 = param_1 + 9;
    _simple_lock_try();
    piVar3 = param_1 + 4;
  } while (piVar2 == (int *)0x0);
  piVar2 = (int *)param_1[4];
  if (piVar3 == piVar2) {
    piVar2 = param_1;
    sub_F004D32C(param_1,piVar3,param_2);
    piVar2[3] = iVar5;
    piVar2[2] = param_1[7];
    param_1[9] = 0;
    goto loc_F004D6C4;
  }
  if (((((param_1[3] & 0x10000000U) != 0) &&
       (piVar2[2] = *(int *)(*piVar2 + 0x38), (param_1[3] & 0x10000000U) != 0)) &&
      (piVar2[3] < iVar5)) && (0 < param_1[6])) {
    iVar4 = *piVar2;
    if (iVar4 == piVar2[1]) {
      piVar2[3] = iVar5;
    }
    else {
      *piVar2 = *(int *)(iVar4 + 0xc);
      piVar2 = param_1;
      sub_F004D32C(param_1,piVar3,iVar4);
      piVar2[3] = iVar5;
      piVar2[2] = *(int *)(iVar4 + 0x38);
    }
  }
  if (piVar2 != param_1 + 4) {
    iVar4 = piVar2[3];
    while ((iVar5 < iVar4 && (piVar2 = (int *)piVar2[4], piVar2 != param_1 + 4))) {
      iVar4 = piVar2[3];
    }
  }
  if ((param_1 + 4 == piVar2) && (param_1[6] == 0)) {
    sub_F004D2A8(param_1,param_1[5],param_2,(uint)param_1[3] >> 0x1c & 1);
  }
  else {
    if (param_1[6] == 0) {
loc_F004D630:
      sub_F004D2A8(param_1,piVar2,param_2,(uint)param_1[3] >> 0x1c & 1);
    }
    else {
      if (param_1 + 4 == piVar2) {
        piVar2 = (int *)param_1[5];
      }
      if (piVar2[3] < iVar5) {
        piVar3 = piVar2 + 5;
        piVar2 = param_1;
        sub_F004D32C(param_1,*piVar3,param_2);
        piVar2[3] = iVar5;
        if (param_1 + 4 == (int *)piVar2[5]) {
          iVar5 = param_1[7];
        }
        else {
          iVar5 = *(int *)(((int *)piVar2[5])[1] + 0x38);
        }
        piVar2[2] = iVar5;
      }
      else {
        if (piVar2[3] == iVar5) goto loc_F004D630;
        piVar3 = param_1;
        sub_F004D32C(param_1,piVar2,param_2);
        piVar3[3] = iVar5;
        piVar3[2] = *(int *)(piVar2[1] + 0x38);
      }
    }
    piVar3 = param_1 + 4;
    if ((piVar3 != piVar2) && (param_2 = (int *)piVar2[4], piVar3 != param_2)) {
      iVar5 = piVar2[1];
      piVar2 = param_2;
      while( true ) {
        sub_F004D400(piVar2,*(undefined4 *)(iVar5 + 0x38));
        param_2 = (int *)piVar2[4];
        if (piVar3 == param_2) break;
        iVar5 = piVar2[1];
        piVar2 = param_2;
      }
    }
  }
  param_1[9] = 0;
loc_F004D6C4:
  _splx(piVar1);
  return CONCAT44(param_2,param_1);
}

