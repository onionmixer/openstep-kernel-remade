/* GHIDRADEC_FUNCTION index=3450 start=0xf004d1b8 */

undefined8 sub_F004D1B8(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
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
  iVar3 = *param_1;
  iVar2 = *(int *)(iVar3 + 0x38);
  iVar1 = iVar3;
  if (iVar2 < param_2) {
    if (*(int *)(iVar3 + 0xc) != 0) {
      for (iVar2 = *(int *)(iVar3 + 0xc);
          ((iVar1 = iVar3, *(int *)(iVar3 + 0x38) <= *(int *)(iVar2 + 0x38) &&
           (*(int *)(iVar2 + 0x38) <= param_2)) && (iVar1 = iVar2, *(int *)(iVar2 + 0xc) != 0));
          iVar2 = *(int *)(iVar2 + 0xc)) {
        iVar3 = iVar2;
      }
    }
  }
  else {
    if (iVar2 < param_1[2]) {
      if (param_2 < iVar2) {
        iVar1 = 0;
        goto locret_F004D2A0;
      }
      iVar1 = *(int *)(iVar3 + 0xc);
    }
    else {
      bVar4 = true;
      if (*(int *)(iVar3 + 0xc) == 0) goto loc_F004D298;
      iVar2 = iVar3;
      for (iVar3 = *(int *)(iVar3 + 0xc); *(int *)(iVar2 + 0x38) <= *(int *)(iVar3 + 0x38);
          iVar3 = *(int *)(iVar3 + 0xc)) {
        if (*(int *)(iVar3 + 0xc) == 0) {
          iVar1 = *(int *)(iVar3 + 0xc);
          goto loc_F004D294;
        }
        iVar2 = iVar3;
      }
      iVar1 = *(int *)(iVar2 + 0xc);
      iVar3 = iVar2;
    }
loc_F004D294:
    while( true ) {
      bVar4 = iVar1 == 0;
      iVar1 = iVar3;
loc_F004D298:
      if ((bVar4) || (iVar3 = *(int *)(iVar1 + 0xc), param_2 < *(int *)(iVar3 + 0x38))) break;
      iVar1 = *(int *)(iVar3 + 0xc);
    }
  }
locret_F004D2A0:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3451 start=0xf004d2a8 */

/* WARNING: Removing unreachable block (ram,0xf004d2e8) */

undefined8 sub_F004D2A8(undefined4 param_1,int *param_2,int param_3)

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
  if (param_2[2] < *(int *)(param_3 + 0x38)) {
    iVar1 = *(int *)(*param_2 + 0x38);
    if ((*(int *)(param_3 + 0x38) < iVar1) || (iVar1 < param_2[2])) {
      *(int *)(param_3 + 0xc) = *param_2;
      *param_2 = param_3;
      goto locret_F004D324;
    }
  }
  piVar2 = param_2;
  sub_F004D1B8();
  if (piVar2 == (int *)0x0) {
    *(int *)(param_3 + 0xc) = *param_2;
    *param_2 = param_3;
  }
  else {
    *(int *)(param_3 + 0xc) = piVar2[3];
    piVar2[3] = param_3;
    if ((int *)param_2[1] == piVar2) {
      param_2[1] = param_3;
    }
  }
locret_F004D324:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3452 start=0xf004d32c */

/* WARNING: Removing unreachable block (ram,0xf004d350) */

undefined8 sub_F004D32C(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
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
  if (*(int *)(param_1 + 0x18) == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    piVar3 = (int *)0x18;
    _kalloc();
    piVar3[3] = 0;
    piVar3[1] = 0;
    *piVar3 = 0;
    piVar3[2] = 0;
  }
  piVar3[1] = param_3;
  *piVar3 = param_3;
  iVar2 = param_1 + 0x10;
  *(undefined4 *)(param_3 + 0xc) = 0;
  if (iVar2 == param_2) {
    iVar2 = *(int *)(param_1 + 0x10);
    if (param_2 == iVar2) {
      *(int **)(param_1 + 0x14) = piVar3;
    }
    else {
      *(int **)(iVar2 + 0x14) = piVar3;
    }
    piVar3[4] = iVar2;
    piVar3[5] = param_1 + 0x10;
    *(int **)(param_1 + 0x10) = piVar3;
  }
  else if (iVar2 == *(int *)(param_2 + 0x10)) {
    iVar1 = *(int *)(param_1 + 0x14);
    if (iVar2 == iVar1) {
      *(int **)(param_1 + 0x10) = piVar3;
    }
    else {
      *(int **)(iVar1 + 0x10) = piVar3;
    }
    piVar3[5] = iVar1;
    piVar3[4] = param_1 + 0x10;
    *(int **)(param_1 + 0x14) = piVar3;
  }
  else {
    piVar3[5] = param_2;
    piVar3[4] = *(int *)(param_2 + 0x10);
    *(int **)(param_2 + 0x10) = piVar3;
    *(int **)(piVar3[4] + 0x14) = piVar3;
  }
  return CONCAT44(param_2,piVar3);
}
/* GHIDRADEC_FUNCTION index=3453 start=0xf004d400 */

/* WARNING: Removing unreachable block (ram,0xf004d408) */

undefined8 sub_F004D400(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
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
  puVar1 = param_1;
  sub_F004D1B8(param_1,param_2 + -1);
  if (puVar1 == (undefined4 *)0x0) {
    param_1[2] = param_2;
  }
  else if (puVar1[3] == 0) {
    param_1[2] = param_2;
  }
  else {
    *(undefined4 *)(param_1[1] + 0xc) = *param_1;
    param_1[1] = puVar1;
    *param_1 = puVar1[3];
    puVar1[3] = 0;
    param_1[2] = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3454 start=0xf004d454 */

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
/* GHIDRADEC_FUNCTION index=3455 start=0xf004f334 */

/* WARNING: Removing unreachable block (ram,0xf004f3a4) */

undefined8 sub_F004F334(uint param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar5;
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
  iVar1 = (param_1 & 0x3f) * 4;
  puVar5 = (uint *)(_lf_svnode_hash + iVar1);
  uVar2 = *(uint *)(_lf_svnode_hash + iVar1);
  puVar3 = puVar5;
  do {
    if (uVar2 == 0) {
      puVar3 = (uint *)0x10;
      _kalloc();
      *puVar3 = param_1;
      puVar3[1] = 0;
      puVar3[2] = 0;
      *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
      puVar3[3] = *puVar5;
      *puVar5 = (uint)puVar3;
loc_F004F3D0:
      uVar2 = *puVar5;
locret_F004F3D4:
      return CONCAT44(param_2,uVar2);
    }
    puVar4 = (uint *)*puVar3;
    if (param_1 == *puVar4) {
      if (puVar3 == puVar5) {
        uVar2 = *puVar5;
        goto locret_F004F3D4;
      }
      *puVar3 = puVar4[3];
      puVar4[3] = *puVar5;
      *puVar5 = (uint)puVar4;
      goto loc_F004F3D0;
    }
    uVar2 = puVar4[3];
    puVar3 = puVar4 + 3;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3456 start=0xf004f3dc */

/* WARNING: Removing unreachable block (ram,0xf004f434) */
/* WARNING: Removing unreachable block (ram,0xf004f450) */
/* WARNING: Removing unreachable block (ram,0xf004f420) */

undefined8 sub_F004F3DC(uint *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint *puVar3;
  undefined4 unaff_l1;
  uint *puVar4;
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
  if ((int)param_1[2] < 1) {
    iVar1 = (*param_1 & 0x3f) * 4;
    puVar4 = (uint *)(_lf_svnode_hash + iVar1);
    uVar2 = *(uint *)(_lf_svnode_hash + iVar1);
    while (uVar2 != 0) {
      puVar3 = (uint *)*puVar4;
      if (puVar3 == param_1) {
        _vn_rele(*puVar3);
        *puVar4 = puVar3[3];
        _kfree(puVar3,0x10);
        goto locret_F004F458;
      }
      puVar4 = puVar3 + 3;
      uVar2 = puVar3[3];
    }
    _panic(aLfFreeSvnodeCa);
  }
locret_F004F458:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3457 start=0xf004f460 */

/* WARNING: Removing unreachable block (ram,0xf004f534) */
/* WARNING: Removing unreachable block (ram,0xf004f504) */
/* WARNING: Removing unreachable block (ram,0xf004f49c) */
/* WARNING: Removing unreachable block (ram,0xf004f600) */
/* WARNING: Removing unreachable block (ram,0xf004f67c) */
/* WARNING: Removing unreachable block (ram,0xf004f70c) */
/* WARNING: Removing unreachable block (ram,0xf004f6cc) */
/* WARNING: Removing unreachable block (ram,0xf004f578) */
/* WARNING: Removing unreachable block (ram,0xf004f740) */
/* WARNING: Removing unreachable block (ram,0xf004f6b0) */
/* WARNING: Removing unreachable block (ram,0xf004f63c) */
/* WARNING: Removing unreachable block (ram,0xf004f778) */
/* WARNING: Removing unreachable block (ram,0xf004f614) */
/* WARNING: Removing unreachable block (ram,0xf004f4dc) */
/* WARNING: Removing unreachable block (ram,0xf004f518) */
/* WARNING: Removing unreachable block (ram,0xf004f53c) */
/* WARNING: Removing unreachable block (ram,0xf004f478) */

undefined4 sub_F004F460(void)

{
  word wVar1;
  bool bVar2;
  word *pwVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_o0_1;
  int iVar7;
  int iVar8;
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
  undefined auStackX_0 [92];
  
  pwVar3 = (word *)((qword)in_o0_1 >> 0x20);
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
  while (iVar4 = sub_F004F92C(pwVar3), iVar4 != 0) {
    iVar8 = 0;
    if ((*pwVar3 & 1) != 0) {
      sub_F004FCE0(pwVar3);
      return 0xb;
    }
    iVar7 = *(int *)(iVar4 + 0xc);
    iVar5 = *(int *)(iVar7 + 0x14);
    while ((iVar5 != 0 && (bVar2 = iVar8 < 0x32, iVar8 = iVar8 + 1, bVar2))) {
      iVar7 = *(int *)(*(int *)(*(int *)(iVar7 + 0x14) + 0x14) + 0xc);
      if (iVar7 == *(int *)(pwVar3 + 6)) {
        sub_F004FCE0(pwVar3);
        return 0x4e;
      }
      iVar5 = *(int *)(iVar7 + 0x14);
    }
    *(int *)(pwVar3 + 10) = iVar4;
    sub_F004FB6C(iVar4);
    *(word **)(*(int *)(pwVar3 + 6) + 0x14) = pwVar3;
    iVar8 = _sleep(pwVar3);
    *(undefined4 *)(*(int *)(pwVar3 + 6) + 0x14) = 0;
    if (iVar8 != 0) {
      sub_F004FBB0(iVar4);
      sub_F004FCE0(pwVar3);
      return 4;
    }
  }
  bVar2 = true;
  *(int *)((int)register0x00000038 + -0xc) = *(int *)(pwVar3 + 8) + 4;
loc_F004F56C:
  uVar6 = sub_F004F98C();
  switch(uVar6) {
  case :
    if (!bVar2) {
      return 0;
    }
    **(undefined4 **)((int)register0x00000038 + -0xc) = pwVar3;
    *(undefined4 *)(pwVar3 + 10) = *(undefined4 *)((int)register0x00000038 + -0x10);
    return 0;
  case :
    iVar4 = *(int *)((int)register0x00000038 + -0x10);
    if (pwVar3[1] == 1) {
      if (*(sword *)(*(int *)((int)register0x00000038 + -0x10) + 2) != 2) {
        wVar1 = pwVar3[1];
        goto loc_F004F610;
      }
      sub_F004FCA4(*(int *)((int)register0x00000038 + -0x10));
      iVar4 = *(int *)((int)register0x00000038 + -0x10);
    }
    wVar1 = pwVar3[1];
loc_F004F610:
    *(word *)(iVar4 + 2) = wVar1;
    sub_F004FCE0();
    return 0;
  case :
    if (*(word *)(*(int *)((int)register0x00000038 + -0x10) + 2) == pwVar3[1]) {
      sub_F004FCE0(pwVar3);
      return 0;
    }
    if (*(int *)(*(int *)((int)register0x00000038 + -0x10) + 4) == *(int *)(pwVar3 + 2)) {
      **(undefined4 **)((int)register0x00000038 + -0xc) = pwVar3;
      iVar4 = *(int *)((int)register0x00000038 + -0x10);
      *(int *)(pwVar3 + 10) = iVar4;
      *(int *)(iVar4 + 4) = *(int *)(pwVar3 + 4) + 1;
    }
    else {
      sub_F004FBF8();
    }
    break;
  case :
    if ((pwVar3[1] == 1) && (*(sword *)(*(int *)((int)register0x00000038 + -0x10) + 2) == 2)) {
      sub_F004FCA4(*(int *)((int)register0x00000038 + -0x10));
    }
    else {
      *(undefined4 *)(pwVar3 + 0xc) =
           *(undefined4 *)(*(int *)((int)register0x00000038 + -0x10) + 0x18);
      sub_F004FB6C(pwVar3);
    }
    if (bVar2) {
      bVar2 = false;
      **(undefined4 **)((int)register0x00000038 + -0xc) = pwVar3;
      uVar6 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0x10) + 0x14);
      *(word **)((int)register0x00000038 + -0xc) = pwVar3 + 10;
      *(undefined4 *)(pwVar3 + 10) = uVar6;
    }
    else {
      *(undefined4 *)*(undefined8 *)((int)register0x00000038 + -0x10) =
           *(undefined4 *)
            ((int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20) + 0x14);
    }
    sub_F004FCE0(*(undefined4 *)((int)register0x00000038 + -0x10));
    goto loc_F004F56C;
  case :
    goto loc_F004F71C;
  case :
    if (bVar2) {
      **(undefined4 **)((int)register0x00000038 + -0xc) = pwVar3;
      *(undefined4 *)(pwVar3 + 10) = *(undefined4 *)((int)register0x00000038 + -0x10);
    }
    *(int *)(*(int *)((int)register0x00000038 + -0x10) + 4) = *(int *)(pwVar3 + 4) + 1;
    break;
  :
    return 0;
  }
  sub_F004FCA4(0);
  return 0;
loc_F004F71C:
  iVar4 = *(int *)((int)register0x00000038 + -0x10);
  *(word **)((int)register0x00000038 + -0xc) = pwVar3 + 10;
  *(undefined4 *)(pwVar3 + 10) = *(undefined4 *)(iVar4 + 0x14);
  *(word **)(iVar4 + 0x14) = pwVar3;
  bVar2 = false;
  *(int *)(iVar4 + 8) = *(int *)(pwVar3 + 2) + -1;
  sub_F004FCA4();
  goto loc_F004F56C;
}
/* GHIDRADEC_FUNCTION index=3458 start=0xf004f78c */

/* WARNING: Removing unreachable block (ram,0xf004f850) */
/* WARNING: Removing unreachable block (ram,0xf004f7e8) */
/* WARNING: Removing unreachable block (ram,0xf004f878) */
/* WARNING: Removing unreachable block (ram,0xf004f82c) */
/* WARNING: Removing unreachable block (ram,0xf004f7d4) */

undefined4 sub_F004F78C(void)

{
  int iVar1;
  int iVar2;
  undefined8 in_o0_1;
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
  undefined auStackX_0 [92];
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  if (*(int *)(*(int *)(iVar1 + 0x10) + 4) != 0) {
    *(int *)((int)register0x00000038 + -0xc) = *(int *)(iVar1 + 0x10) + 4;
    while (iVar2 = sub_F004F98C(), iVar2 != 0) {
      sub_F004FCA4(*(undefined4 *)((int)register0x00000038 + -0x10));
      switch(iVar2) {
      case :
        *(undefined4 *)*(undefined8 *)((int)register0x00000038 + -0x10) =
             *(undefined4 *)
              ((int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20) + 0x14);
        sub_F004FCE0(*(undefined4 *)((int)register0x00000038 + -0x10));
        return 0;
      case :
        if (*(int *)(*(int *)((int)register0x00000038 + -0x10) + 4) != *(int *)(iVar1 + 4)) {
          sub_F004FBF8();
          *(undefined4 *)(*(int *)((int)register0x00000038 + -0x10) + 0x14) =
               *(undefined4 *)(iVar1 + 0x14);
          return 0;
        }
        *(int *)(*(int *)((int)register0x00000038 + -0x10) + 4) = *(int *)(iVar1 + 8) + 1;
        return 0;
      case :
        *(undefined4 *)*(undefined8 *)((int)register0x00000038 + -0x10) =
             *(undefined4 *)
              ((int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20) + 0x14);
        sub_F004FCE0();
        break;
      case :
        iVar2 = *(int *)((int)register0x00000038 + -0x10);
        *(int *)(iVar2 + 8) = *(int *)(iVar1 + 4) + -1;
        *(int *)((int)register0x00000038 + -0xc) = iVar2 + 0x14;
        break;
      case :
        *(int *)(*(int *)((int)register0x00000038 + -0x10) + 4) = *(int *)(iVar1 + 8) + 1;
      :
        goto def_F004F804;
      }
    }
  }
def_F004F804:
  return 0;
}
/* GHIDRADEC_FUNCTION index=3459 start=0xf004f8c0 */

/* WARNING: Removing unreachable block (ram,0xf004f8c4) */

sqword sub_F004F8C0(int param_1,undefined2 *param_2)

{
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
  sub_F004F92C();
  if (param_1 == 0) {
    *param_2 = 3;
  }
  else {
    *param_2 = *(undefined2 *)(param_1 + 2);
    param_2[1] = 0;
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)(param_1 + 4);
    if (*(int *)(param_1 + 8) == -1) {
      *(undefined4 *)(param_2 + 4) = 0;
    }
    else {
      *(int *)(param_2 + 4) = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) + 1;
    }
    *(undefined4 *)(param_2 + 6) = **(undefined4 **)(param_1 + 0xc);
  }
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=3460 start=0xf004f92c */

/* WARNING: Removing unreachable block (ram,0xf004f94c) */

undefined8 sub_F004F92C(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar1 = *(int *)(param_1 + 0x10);
  *(int *)((int)register0x00000038 + -0xc) = iVar1 + 4;
  iVar1 = *(int *)(iVar1 + 4);
  do {
    sub_F004F98C(iVar1,param_1,2,(undefined *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10));
    if (iVar1 == 0) {
      uVar2 = 0;
locret_F004F984:
      return CONCAT44(param_2,uVar2);
    }
    if ((*(sword *)(param_1 + 2) == 2) ||
       (*(sword *)(*(int *)((int)register0x00000038 + -0x10) + 2) == 2)) {
      uVar2 = *(undefined4 *)((int)register0x00000038 + -0x10);
      goto locret_F004F984;
    }
    iVar1 = *(int *)(*(int *)((int)register0x00000038 + -0x10) + 0x14);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3461 start=0xf004f98c */

/* WARNING: Removing unreachable block (ram,0xf004fb4c) */

undefined8 sub_F004F98C(int param_1,int param_2,uint param_3,int *param_4,int *param_5)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  *param_5 = param_1;
  if (param_1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar3 = *(uint *)(param_2 + 4);
    uVar2 = *(uint *)(param_2 + 8);
    do {
      if (((param_3 & 1) == 0) || (*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc))) {
        if ((param_3 & 2) == 0) {
          uVar1 = *(uint *)(param_1 + 8);
        }
        else {
          if (*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc)) goto loc_F004FA4C;
          uVar1 = *(uint *)(param_1 + 8);
        }
        if ((uVar1 != 0xffffffff) && (uVar1 < uVar3)) {
loc_F004FA28:
          if ((((param_3 & 1) == 0) || (uVar2 == 0xffffffff)) || (*(uint *)(param_1 + 4) <= uVar2))
          goto loc_F004FA4C;
          uVar4 = 0;
          goto locret_F004FB64;
        }
        if (uVar2 == 0xffffffff) {
          uVar1 = *(uint *)(param_1 + 4);
        }
        else {
          if (uVar2 < *(uint *)(param_1 + 4)) goto loc_F004FA28;
          uVar1 = *(uint *)(param_1 + 4);
        }
        if ((uVar1 == uVar3) && (*(uint *)(param_1 + 8) == uVar2)) {
          uVar4 = 1;
          goto locret_F004FB64;
        }
        if (uVar3 < uVar1) {
          uVar1 = *(uint *)(param_1 + 4);
        }
        else if (uVar2 == 0xffffffff) {
          uVar1 = *(uint *)(param_1 + 4);
        }
        else {
          if ((uVar2 <= *(uint *)(param_1 + 8)) || (*(uint *)(param_1 + 8) == 0xffffffff)) {
            uVar4 = 2;
            goto locret_F004FB64;
          }
          uVar1 = *(uint *)(param_1 + 4);
        }
        if (uVar1 < uVar3) {
loc_F004FAE4:
          uVar1 = *(uint *)(param_1 + 4);
        }
        else {
          if (uVar2 == 0xffffffff) {
            uVar4 = 3;
            goto locret_F004FB64;
          }
          if (*(uint *)(param_1 + 8) == 0xffffffff) goto loc_F004FAE4;
          if (*(uint *)(param_1 + 8) <= uVar2) {
            uVar4 = 3;
            goto locret_F004FB64;
          }
          uVar1 = *(uint *)(param_1 + 4);
        }
        if (uVar1 < uVar3) {
          if ((uVar3 <= *(uint *)(param_1 + 8)) || (*(uint *)(param_1 + 8) == 0xffffffff)) {
            uVar4 = 4;
            goto locret_F004FB64;
          }
          uVar1 = *(uint *)(param_1 + 4);
        }
        else {
          uVar1 = *(uint *)(param_1 + 4);
        }
        if (((uVar3 < uVar1) && (uVar2 != 0xffffffff)) &&
           ((uVar2 < *(uint *)(param_1 + 8) || (*(uint *)(param_1 + 8) == 0xffffffff)))) {
          uVar4 = 5;
          goto locret_F004FB64;
        }
        _panic(aLfFindoverlapD);
      }
      else {
loc_F004FA4C:
        *param_4 = param_1 + 0x14;
        param_1 = *(int *)(param_1 + 0x14);
        *param_5 = param_1;
      }
    } while (param_1 != 0);
    uVar4 = 0;
  }
locret_F004FB64:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3462 start=0xf004fb6c */

undefined8 sub_F004FB6C(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
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
  if (param_2 != 0) {
    iVar2 = *(int *)(param_1 + 0x18);
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x18) = param_2;
    }
    else {
      iVar1 = *(int *)(iVar2 + 0x18);
      while (iVar1 != 0) {
        iVar2 = *(int *)(iVar2 + 0x18);
        iVar1 = *(int *)(iVar2 + 0x18);
      }
      *(int *)(iVar2 + 0x18) = param_2;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3463 start=0xf004fbb0 */

undefined8 sub_F004FBB0(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar3;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(int *)((int)register0x00000038 + 0x44) = param_1;
  piVar3 = (int *)((int)register0x00000038 + 0x44);
  do {
    if (param_1 == 0) {
      uVar2 = 0;
locret_F004FBF0:
      return CONCAT44(param_2,uVar2);
    }
    iVar1 = *piVar3;
    param_1 = *(int *)(iVar1 + 0x18);
    if (iVar1 == param_2) {
      uVar2 = 1;
      *piVar3 = param_1;
      goto locret_F004FBF0;
    }
    piVar3 = (int *)(iVar1 + 0x18);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3464 start=0xf004fbf8 */

/* WARNING: Removing unreachable block (ram,0xf004fc58) */
/* WARNING: Removing unreachable block (ram,0xf004fc44) */

undefined8 sub_F004FBF8(int param_1,int param_2)

{
  int iVar1;
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
  if (*(int *)(param_1 + 4) == *(int *)(param_2 + 4)) {
    *(int *)(param_1 + 4) = *(int *)(param_2 + 8) + 1;
    *(int *)(param_2 + 0x14) = param_1;
  }
  else {
    if (*(int *)(param_1 + 8) == *(int *)(param_2 + 8)) {
      *(int *)(param_1 + 8) = *(int *)(param_2 + 4) + -1;
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x14);
    }
    else {
      iVar1 = 0x1c;
      _kalloc();
      _bcopy(param_1,iVar1,0x1c);
      *(int *)(*(int *)(iVar1 + 0x10) + 8) = *(int *)(*(int *)(iVar1 + 0x10) + 8) + 1;
      *(int *)(iVar1 + 4) = *(int *)(param_2 + 8) + 1;
      *(undefined4 *)(iVar1 + 0x18) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_2 + 4) + -1;
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
      *(int *)(param_2 + 0x14) = iVar1;
    }
    *(int *)(param_1 + 0x14) = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3465 start=0xf004fca4 */

/* WARNING: Removing unreachable block (ram,0xf004fcc4) */

undefined8 sub_F004FCA4(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  int iVar2;
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
  iVar1 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = 0;
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x18);
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    _wakeup();
    iVar1 = iVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3466 start=0xf004fce0 */

/* WARNING: Removing unreachable block (ram,0xf004fcf8) */

undefined8 sub_F004FCE0(int param_1,undefined4 param_2)

{
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
  *(int *)(*(int *)(param_1 + 0x10) + 8) = *(int *)(*(int *)(param_1 + 0x10) + 8) + -1;
  _kfree(param_1,0x1c);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3467 start=0xf00506e8 */

/* WARNING: Removing unreachable block (ram,0xf005076c) */
/* WARNING: Removing unreachable block (ram,0xf005070c) */
/* WARNING: Removing unreachable block (ram,0xf0050720) */
/* WARNING: Removing unreachable block (ram,0xf0050780) */
/* WARNING: Removing unreachable block (ram,0xf00506f8) */

undefined8 sub_F00506E8(int param_1,undefined4 param_2,undefined *param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
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
  undefined auStackX_0 [92];
  
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
  _copyin(param_3,(undefined *)((int)register0x00000038 + -0xc),4);
  puVar1 = *(undefined **)((int)register0x00000038 + -0xc);
  if ((param_3 == (undefined *)0x0) &&
     (sub_F0051228(puVar1,(undefined *)((int)register0x00000038 + -0xe)), param_3 = puVar1,
     puVar1 == (undefined *)0x0)) {
    iVar2 = (int)*(sword *)((int)register0x00000038 + -0xe);
    _bdevvp();
    uVar3 = *(uint *)(DAT_f011c7c0 + (uint)(*(word *)((int)register0x00000038 + -0xe) >> 8) * 0x18);
    *(int *)((int)register0x00000038 + -0x14) = iVar2;
    if ((uVar3 & 0x400) != 0) {
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 1;
    }
    param_3 = (undefined *)((int)register0x00000038 + -0x14);
    sub_F0050874(param_3,param_2,param_1);
    if (param_3 != (undefined *)0x0) {
      _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x14));
    }
  }
  return CONCAT44(param_2,param_3);
}
/* GHIDRADEC_FUNCTION index=3468 start=0xf0050790 */

/* WARNING: Removing unreachable block (ram,0xf0050858) */
/* WARNING: Removing unreachable block (ram,0xf0050834) */
/* WARNING: Removing unreachable block (ram,0xf0050804) */
/* WARNING: Removing unreachable block (ram,0xf0050820) */
/* WARNING: Removing unreachable block (ram,0xf0050848) */
/* WARNING: Removing unreachable block (ram,0xf0050860) */
/* WARNING: Removing unreachable block (ram,0xf00507cc) */

undefined8 sub_F0050790(int param_1,int *param_2)

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
  int *piVar3;
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
  dword_F010F0B0 = dword_F010F0B0 + 1;
  if (dword_F010F0B0 == 1) {
    iVar1 = (int)_rootdev;
    piVar3 = (int *)0x2;
    if (iVar1 != -1) {
      _bdevvp();
      *param_2 = iVar1;
      if (_rootrw == 0) {
        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 1;
      }
      piVar3 = param_2;
      sub_F0050874(param_2,&unk_F010F0B8,param_1);
      piVar2 = (int *)0x0;
      if (piVar3 == (int *)0x0) {
        _vfs_add(0,param_1,*(uint *)(param_1 + 0xc) & 1);
        if (piVar2 == (int *)0x0) {
          _vfs_unlock(param_1);
          _inittodr(*(undefined4 *)
                     (*(int *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20) + 0x20));
          piVar3 = (int *)0x0;
          goto locret_F005086C;
        }
        sub_F0050E78(param_1,0);
        piVar3 = piVar2;
      }
      _vn_rele(*param_2);
      *param_2 = 0;
    }
  }
  else {
    piVar3 = (int *)0x10;
  }
locret_F005086C:
  return CONCAT44(param_2,piVar3);
}
/* GHIDRADEC_FUNCTION index=3469 start=0xf0050874 */

/* WARNING: Removing unreachable block (ram,0xf0050e50) */
/* WARNING: Removing unreachable block (ram,0xf0050df0) */
/* WARNING: Removing unreachable block (ram,0xf0050db0) */
/* WARNING: Removing unreachable block (ram,0xf0050d4c) */
/* WARNING: Removing unreachable block (ram,0xf0050d18) */
/* WARNING: Removing unreachable block (ram,0xf0050cf8) */
/* WARNING: Removing unreachable block (ram,0xf0050cb0) */
/* WARNING: Removing unreachable block (ram,0xf0050c90) */
/* WARNING: Removing unreachable block (ram,0xf0050c30) */
/* WARNING: Removing unreachable block (ram,0xf0050bec) */
/* WARNING: Removing unreachable block (ram,0xf0050bf4) */
/* WARNING: Removing unreachable block (ram,0xf0050b10) */
/* WARNING: Removing unreachable block (ram,0xf0050af0) */
/* WARNING: Removing unreachable block (ram,0xf0050a50) */
/* WARNING: Removing unreachable block (ram,0xf00509e8) */
/* WARNING: Removing unreachable block (ram,0xf0050950) */
/* WARNING: Removing unreachable block (ram,0xf0050940) */
/* WARNING: Removing unreachable block (ram,0xf0050960) */
/* WARNING: Removing unreachable block (ram,0xf0050a44) */
/* WARNING: Removing unreachable block (ram,0xf0050ad8) */
/* WARNING: Removing unreachable block (ram,0xf0050b64) */
/* WARNING: Removing unreachable block (ram,0xf0050b4c) */
/* WARNING: Removing unreachable block (ram,0xf0050c24) */
/* WARNING: Removing unreachable block (ram,0xf0050c70) */
/* WARNING: Removing unreachable block (ram,0xf0050dc4) */
/* WARNING: Removing unreachable block (ram,0xf0050ccc) */
/* WARNING: Removing unreachable block (ram,0xf0050d10) */
/* WARNING: Removing unreachable block (ram,0xf0050d44) */
/* WARNING: Removing unreachable block (ram,0xf0050d98) */
/* WARNING: Removing unreachable block (ram,0xf0050b94) */
/* WARNING: Removing unreachable block (ram,0xf0050e04) */
/* WARNING: Removing unreachable block (ram,0xf0050898) */
/* WARNING: Removing unreachable block (ram,0xf0050c00) */

undefined8 sub_F0050874(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  sword sVar3;
  bool bVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  undefined *puVar8;
  undefined uVar10;
  int iVar9;
  undefined4 uVar11;
  undefined4 unaff_l0;
  int iVar12;
  int iVar13;
  undefined4 unaff_l1;
  uint uVar14;
  int iVar15;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int *piVar16;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar17;
  undefined4 unaff_i1;
  int iVar18;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  piVar16 = (int *)0x0;
  iVar18 = 0;
  if (dword_F010F0BC == 0) {
    _ihinit();
    dword_F010F0BC = 1;
  }
  uVar11 = 3;
  if ((*(uint *)(param_3 + 0xc) & 1) != 0) {
    uVar11 = 1;
  }
  piVar17 = param_1;
  (*(code *)**(undefined4 **)(*param_1 + 0x1c))(param_1,uVar11,*(undefined4 *)(_active_u + 0x1c));
  iVar7 = iVar18;
  if (piVar17 != (int *)0x0) goto locret_F0050E58;
  iVar5 = *param_1;
  bVar4 = true;
  (**(code **)(*(int *)(iVar5 + 0x1c) + 0x80))();
  uVar11 = 3;
  if (iVar5 == 0) {
    if ((*(uint *)(param_3 + 0xc) & 1) != 0) {
      uVar11 = 1;
    }
    (**(code **)(*(int *)(*param_1 + 0x1c) + 4))
              (*param_1,uVar11,1,*(undefined4 *)(_active_u + 0x1c));
    _binval(*param_1);
    piVar17 = (int *)0xf;
    goto locret_F0050E58;
  }
  uVar11 = 0x2000;
  .udiv(0x2000,iVar5);
  puVar6 = (uint *)*param_1;
  _bread(puVar6,uVar11,0x2000);
  if ((*puVar6 & 4) != 0) goto loc_F0050DD0;
  piVar16 = _mounttab;
  if (_mounttab == (int *)0x0) {
    iVar7 = *param_1;
  }
  else {
    iVar7 = _mounttab[3];
    while( true ) {
      if (iVar7 == 0) {
        piVar16 = (int *)piVar16[8];
      }
      else {
        if (*(sword *)(*param_1 + 0x2c) == *(sword *)(piVar16 + 1)) {
          uVar14 = *(uint *)(param_3 + 0xc);
          if ((uVar14 & 0x40) != 0) goto loc_F0050AFC;
          piVar16 = (int *)0x0;
          piVar17 = (int *)0x10;
          bVar4 = false;
          iVar7 = iVar18;
          goto loc_F0050DD0;
        }
        piVar16 = (int *)piVar16[8];
      }
      if (piVar16 == (int *)0x0) break;
      iVar7 = piVar16[3];
    }
    iVar7 = *param_1;
  }
  _vol_notify_cancel((int)*(sword *)(iVar7 + 0x2c));
  if ((*(uint *)(param_3 + 0xc) & 0x40) == 0) {
    if (_mounttab == (int *)0x0) {
loc_F0050A44:
      piVar16 = (int *)0x24;
      _kalloc();
      _bzero();
      if (piVar16 == (int *)0x0) {
        piVar17 = (int *)0x18;
        iVar7 = iVar18;
        goto loc_F0050DD0;
      }
      piVar16[8] = (int)_mounttab;
      _mounttab = piVar16;
      *(int **)(param_3 + 0x128) = piVar16;
    }
    else {
      iVar7 = _mounttab[3];
      piVar16 = _mounttab;
      while (iVar7 != 0) {
        piVar16 = (int *)piVar16[8];
        if (piVar16 == (int *)0x0) goto loc_F0050A44;
        iVar7 = piVar16[3];
      }
      *(int **)(param_3 + 0x128) = piVar16;
    }
    *piVar16 = param_3;
    piVar16[3] = (int)puVar6;
    *(undefined2 *)(piVar16 + 1) = 0xffff;
    piVar16[2] = *param_1;
    uVar14 = puVar6[8];
    if (*(int *)(uVar14 + 0x55c) == 0x11954) {
      if ((int)*(uint *)(uVar14 + 0x30) < 0x2001) {
        if (*(uint *)(uVar14 + 0x30) < 0x564) {
          piVar17 = (int *)0x16;
          iVar7 = iVar18;
        }
        else {
          iVar7 = *(int *)(uVar14 + 0x68);
          _geteblk();
          piVar16[3] = iVar7;
          _bcopy(puVar6[8],*(undefined4 *)(iVar7 + 0x20),*(undefined4 *)(uVar14 + 0x68));
          uVar14 = *(uint *)(param_3 + 0xc);
loc_F0050AFC:
          if ((uVar14 & 1) == 0) {
            *(undefined *)(dword_F0133DDC + 0x38) = 0;
            _bwrite(puVar6);
            if (*(char *)(dword_F0133DDC + 0x38) == '\x1e') {
              *(undefined *)(dword_F0133DDC + 0x38) = 0;
              if (*param_1 == _rootvp) {
                _panic(aRootDeviceIsPh);
                uVar14 = *(uint *)(param_3 + 0xc);
              }
              else {
                uVar14 = *(uint *)(param_3 + 0xc);
              }
              *(uint *)(param_3 + 0xc) = uVar14 | 1;
              goto loc_F0050B6C;
            }
            uVar14 = *(uint *)(param_3 + 0xc);
          }
          else {
            _brelse(puVar6);
loc_F0050B6C:
            uVar14 = *(uint *)(param_3 + 0xc);
          }
          puVar6 = (uint *)0x0;
          iVar18 = *(int *)(iVar7 + 0x20);
          if ((uVar14 & 1) == 0) {
            uVar10 = 3;
            if (*(char *)(iVar18 + 0xd1) == '\x01') {
              uVar10 = 2;
            }
            *(undefined *)(iVar18 + 0xd1) = uVar10;
            *(undefined *)(iVar18 + 0xd0) = 1;
            *(undefined *)(iVar18 + 0xd2) = 0;
            if ((*(uint *)(param_3 + 0xc) & 0x40) != 0) {
              *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xffffffbf;
              _sbupdate(piVar16);
              piVar17 = (int *)0x0;
              goto locret_F0050E58;
            }
          }
          else {
            if ((uVar14 & 0x40) != 0) {
              puVar8 = aMountfsCanTRem;
              goto loc_F0050B94;
            }
            *(undefined *)(iVar18 + 0xd0) = 0;
            *(undefined *)(iVar18 + 0xd2) = 1;
          }
          *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar18 + 0x30);
          iVar12 = *(int *)(iVar18 + 0x9c);
          iVar5 = iVar12 + -1 + *(int *)(iVar18 + 0x34);
          .div();
          _kalloc();
          iVar13 = 0;
          if (iVar12 != 0) {
            if (iVar5 < 1) {
              cVar1 = *(char *)(iVar18 + 0xd2);
            }
            else {
              iVar9 = *(int *)(iVar18 + 0x38);
              do {
                iVar15 = *(int *)(iVar18 + 0x30);
                if (iVar5 < iVar13 + iVar9) {
                  iVar15 = iVar5 - iVar13;
                  .umul(iVar15,*(undefined4 *)(iVar18 + 0x34));
                }
                puVar6 = (uint *)piVar16[2];
                _bread(puVar6,*(int *)(iVar18 + 0x98) + iVar13 <<
                              ((byte)*(undefined4 *)(iVar18 + 100) & 0x1f),iVar15);
                if ((*puVar6 & 4) != 0) {
                  _kfree(iVar12,*(undefined4 *)(iVar18 + 0x9c));
                  goto loc_F0050DD0;
                }
                _bcopy(puVar6[8],iVar12,iVar15);
                *(int *)((iVar13 >> ((byte)*(undefined4 *)(iVar18 + 0x60) & 0x1f)) * 4 + iVar18 +
                        0x2d8) = iVar12;
                _brelse(puVar6);
                iVar9 = *(int *)(iVar18 + 0x38);
                iVar13 = iVar13 + iVar9;
                iVar12 = iVar12 + iVar15;
              } while (iVar13 < iVar5);
              cVar1 = *(char *)(iVar18 + 0xd2);
            }
            if (cVar1 == '\0') {
              _sbupdate(piVar16);
              bVar2 = *(byte *)(iVar18 + 0xd3);
            }
            else {
              bVar2 = *(byte *)(iVar18 + 0xd3);
            }
            iVar5 = *(int *)(iVar18 + 0x28);
            *(byte *)(iVar18 + 0xd3) = bVar2 & 0xfc;
            .umul(iVar5,*(undefined4 *)(iVar18 + 0x3c));
            .div();
            *(int *)(iVar18 + 0x8c) = iVar5;
            *(int *)(iVar18 + 0x88) = iVar5;
            if (iVar5 < 0x65) {
              iVar5 = iVar5 << 1;
            }
            else {
              iVar5 = iVar5 + 100;
            }
            *(int *)(iVar18 + 0x88) = iVar5;
            iVar5 = *(int *)(iVar18 + 0x2c);
            .umul(iVar5,*(undefined4 *)(iVar18 + 0xb8));
            .div();
            *(int *)(iVar18 + 0x94) = iVar5;
            if (0x32 < iVar5) {
              *(undefined4 *)(iVar18 + 0x94) = 0x32;
            }
            *(undefined4 *)(iVar18 + 0x90) = *(undefined4 *)(iVar18 + 0x94);
            sVar3 = *(sword *)(piVar16[2] + 0x2c);
            *(sword *)(piVar16 + 1) = sVar3;
            *(int *)(param_3 + 0x14) = (int)sVar3;
            *(undefined4 *)(param_3 + 0x18) = 0;
            _copystr(param_2,iVar18 + 0xd4,0x1ff,(undefined *)((int)register0x00000038 + -0x4c));
            _bzero(iVar18 + *(int *)((int)register0x00000038 + -0x4c) + 0xd4,
                   0x200 - *(int *)((int)register0x00000038 + -0x4c));
            piVar17 = (int *)0x0;
            goto locret_F0050E58;
          }
          piVar17 = (int *)0xc;
        }
      }
      else {
        piVar17 = (int *)0x16;
        iVar7 = iVar18;
      }
    }
    else {
      piVar17 = (int *)0x16;
      iVar7 = iVar18;
    }
  }
  else {
    *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xffffffbf;
    puVar8 = aMountfsIllegal;
    iVar7 = iVar18;
loc_F0050B94:
    _printf(puVar8);
    piVar17 = (int *)0x16;
  }
loc_F0050DD0:
  if (piVar17 == (int *)0x0) {
    piVar17 = (int *)0x5;
  }
  if (piVar16 != (int *)0x0) {
    piVar16[3] = 0;
  }
  if (iVar7 != 0) {
    _brelse(iVar7);
  }
  if (puVar6 != (uint *)0x0) {
    _brelse(puVar6);
  }
  uVar11 = 3;
  if (bVar4) {
    if ((*(uint *)(param_3 + 0xc) & 1) != 0) {
      uVar11 = 1;
    }
    (**(code **)(*(int *)(*param_1 + 0x1c) + 4))
              (*param_1,uVar11,1,*(undefined4 *)(_active_u + 0x1c));
    _binval(*param_1);
  }
locret_F0050E58:
  return CONCAT44(iVar7,piVar17);
}
/* GHIDRADEC_FUNCTION index=3470 start=0xf0050e60 */

/* WARNING: Removing unreachable block (ram,0xf0050e68) */

undefined8 sub_F0050E60(undefined4 param_1,undefined4 param_2)

{
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
  sub_F0050E78(param_1,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3471 start=0xf0050e78 */

/* WARNING: Removing unreachable block (ram,0xf0050f3c) */
/* WARNING: Removing unreachable block (ram,0xf0050ef8) */
/* WARNING: Removing unreachable block (ram,0xf0050ee4) */
/* WARNING: Removing unreachable block (ram,0xf0050ef0) */
/* WARNING: Removing unreachable block (ram,0xf0050f34) */
/* WARNING: Removing unreachable block (ram,0xf0050f9c) */
/* WARNING: Removing unreachable block (ram,0xf0050e80) */

undefined8 sub_F0050E78(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  bool bVar5;
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
  iVar4 = *(int *)(param_1 + 0x128);
  iVar1 = (int)*(sword *)(iVar4 + 4);
  _iflush();
  if (iVar1 < 0) {
    if ((param_2 == 0) || (iVar1 < 0)) {
      uVar3 = 0x10;
      goto locret_F0050FA8;
    }
    iVar2 = *(int *)(iVar4 + 0xc);
  }
  else {
    iVar2 = *(int *)(iVar4 + 0xc);
  }
  param_2 = *(int *)(iVar2 + 0x20);
  bVar5 = *(char *)(param_2 + 0xd2) == '\0';
  if (bVar5) {
    if (*(char *)(param_2 + 0xd1) == '\x02') {
      *(undefined *)(param_2 + 0xd1) = 1;
      _sbupdate(iVar4);
      uVar3 = *(undefined4 *)(param_2 + 0x2d8);
    }
    else {
      uVar3 = *(undefined4 *)(param_2 + 0x2d8);
    }
  }
  else {
    uVar3 = *(undefined4 *)(param_2 + 0x2d8);
  }
  _kfree(uVar3,*(undefined4 *)(param_2 + 0x9c));
  _brelse(*(undefined4 *)(iVar4 + 0xc));
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(undefined2 *)(iVar4 + 4) = 0;
  if (iVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(iVar4 + 8) + 0x1c) + 4))
              (*(int *)(iVar4 + 8),bVar5,1,*(undefined4 *)(_active_u + 0x1c));
    _binval(*(undefined4 *)(iVar4 + 8));
    _vn_rele(*(undefined4 *)(iVar4 + 8));
    iVar1 = _mounttab;
    bVar5 = iVar4 == _mounttab;
    *(undefined4 *)(iVar4 + 8) = 0;
    if (bVar5) {
      _mounttab = *(int *)(iVar4 + 0x20);
    }
    else if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x20);
      while( true ) {
        if (iVar2 == iVar4) {
          *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar4 + 0x20);
          iVar1 = *(int *)(iVar1 + 0x20);
        }
        else {
          iVar1 = *(int *)(iVar1 + 0x20);
        }
        if (iVar1 == 0) break;
        iVar2 = *(int *)(iVar1 + 0x20);
      }
    }
    _kfree(iVar4,0x24);
  }
  uVar3 = 0;
locret_F0050FA8:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3472 start=0xf0050fb0 */

/* WARNING: Removing unreachable block (ram,0xf0051010) */
/* WARNING: Removing unreachable block (ram,0xf0050fc4) */

undefined8 sub_F0050FB0(int param_1,int *param_2)

{
  word wVar1;
  int iVar2;
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
  iVar2 = (int)*(sword *)(*(int *)(param_1 + 0x128) + 4);
  _iget(iVar2,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20),2);
  if (iVar2 == 0) {
    iVar2 = (int)*(char *)(dword_F0133DDC + 0x38);
  }
  else {
    wVar1 = *(word *)(iVar2 + 0x44);
    *(word *)(iVar2 + 0x44) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(iVar2 + 0x44) = wVar1 & 0xffee;
      _wakeup(iVar2);
    }
    *param_2 = iVar2 + 0xc;
    iVar2 = 0;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3473 start=0xf005102c */

/* WARNING: Removing unreachable block (ram,0xf00510b8) */
/* WARNING: Removing unreachable block (ram,0xf0051098) */
/* WARNING: Removing unreachable block (ram,0xf0051070) */
/* WARNING: Removing unreachable block (ram,0xf00510a0) */
/* WARNING: Removing unreachable block (ram,0xf00510d4) */
/* WARNING: Removing unreachable block (ram,0xf0051054) */

sqword sub_F005102C(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
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
  iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20);
  if (*(int *)(iVar5 + 0x55c) != 0x11954) {
    _panic(aUfsStatfs);
  }
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(iVar5 + 0x34);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar5 + 0x28);
  iVar1 = *(int *)(iVar5 + 0xc4);
  .umul(iVar1,*(undefined4 *)(iVar5 + 0x38));
  iVar1 = iVar1 + *(int *)(iVar5 + 0xcc);
  *(int *)(param_2 + 0xc) = iVar1;
  iVar4 = *(int *)(iVar5 + 0x28);
  iVar2 = iVar4;
  .umul(iVar4,100 - *(int *)(iVar5 + 0x3c));
  .div();
  *(int *)(param_2 + 0x10) = iVar2 - (iVar4 - iVar1);
  uVar3 = *(undefined4 *)(iVar5 + 0x2c);
  .umul(uVar3,*(undefined4 *)(iVar5 + 0xb8));
  *(undefined4 *)(param_2 + 0x14) = uVar3;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar5 + 200);
  _bcopy(param_1 + 0x14,param_2 + 0x1c,8);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3474 start=0xf00510e4 */

/* WARNING: Removing unreachable block (ram,0xf00510ec) */

sqword sub_F00510E4(undefined4 param_1,uint param_2)

{
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
  _update(0xffffffff,0xffffffff);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3475 start=0xf0051228 */

/* WARNING: Removing unreachable block (ram,0xf005127c) */
/* WARNING: Removing unreachable block (ram,0xf0051290) */
/* WARNING: Removing unreachable block (ram,0xf005123c) */

undefined8 sub_F0051228(uint param_1,word *param_2)

{
  int iVar1;
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
  undefined auStackX_0 [92];
  
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
  _lookupname(param_1,0,1,0,(undefined *)((int)register0x00000038 + -0xc));
  if (param_1 == 0) {
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    if (*(int *)(iVar1 + 0x28) == 3) {
      *param_2 = *(word *)(iVar1 + 0x2c);
      _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
      param_1 = -(uint)(_nblkdev <= (int)(uint)(*param_2 >> 8)) & 6;
    }
    else {
      _vn_rele(iVar1);
      param_1 = 0xf;
    }
  }
  else if (*(char *)(dword_F0133DDC + 0x38) == '\x02') {
    param_1 = 0x13;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3476 start=0xf00512c8 */

/* WARNING: Removing unreachable block (ram,0xf0051308) */
/* WARNING: Removing unreachable block (ram,0xf0051340) */
/* WARNING: Removing unreachable block (ram,0xf00512dc) */

sqword sub_F00512C8(int param_1,int *param_2,int param_3)

{
  word wVar1;
  int iVar2;
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
  iVar2 = (int)*(sword *)(*(int *)(param_1 + 0x128) + 4);
  _iget(iVar2,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20),
        *(undefined4 *)(param_3 + 4));
  if (iVar2 == 0) {
    *param_2 = 0;
  }
  else if (*(int *)(iVar2 + 0xd0) == *(int *)(param_3 + 8)) {
    wVar1 = *(word *)(iVar2 + 0x44);
    *(word *)(iVar2 + 0x44) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(iVar2 + 0x44) = wVar1 & 0xffee;
      _wakeup(iVar2);
    }
    *param_2 = iVar2 + 0xc;
    if ((*(uint *)(iVar2 + 100) & 0x42400000) == 0x2000000) {
      *(word *)(iVar2 + 0x10) = *(word *)(iVar2 + 0x10) | 0x80;
    }
  }
  else {
    _idrop(iVar2);
    *param_2 = 0;
  }
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=3477 start=0xf0051380 */

undefined8 sub_F0051380(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,0x16);
}
/* GHIDRADEC_FUNCTION index=3478 start=0xf005138c */

undefined8 sub_F005138C(int param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x24) + 0x128) + 8);
  (**(code **)(*(int *)(iVar1 + 0x1c) + 0x80))();
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3479 start=0xf00513b4 */

sqword sub_F00513B4(undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3480 start=0xf00513c0 */

/* WARNING: Removing unreachable block (ram,0xf00513dc) */
/* WARNING: Removing unreachable block (ram,0xf00513d0) */

sqword sub_F00513C0(int param_1,uint param_2)

{
  word wVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x30);
  _bflush(param_1,0xffffffff,0xffffffff);
  _microtime(&_iuniqtime);
  if ((*(word *)(iVar2 + 0x44) & 4) != 0) {
    *(undefined4 *)(iVar2 + 0x74) = _iuniqtime;
  }
  if ((*(word *)(iVar2 + 0x44) & 2) != 0) {
    *(undefined4 *)(iVar2 + 0x7c) = _iuniqtime;
  }
  if ((*(word *)(iVar2 + 0x44) & 0x40) == 0) {
    wVar1 = *(word *)(iVar2 + 0x44);
  }
  else {
    *(undefined4 *)(iVar2 + 0x4c) = 0;
    *(undefined4 *)(iVar2 + 0x84) = _iuniqtime;
    wVar1 = *(word *)(iVar2 + 0x44);
  }
  *(word *)(iVar2 + 0x44) = wVar1 & 0xfffd;
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3481 start=0xf0051444 */

/* WARNING: Removing unreachable block (ram,0xf005151c) */
/* WARNING: Removing unreachable block (ram,0xf00514ac) */
/* WARNING: Removing unreachable block (ram,0xf00514f8) */
/* WARNING: Removing unreachable block (ram,0xf00515b0) */
/* WARNING: Removing unreachable block (ram,0xf0051468) */

undefined8 sub_F0051444(undefined4 *param_1,undefined *param_2,int param_3,uint param_4)

{
  bool bVar1;
  word wVar3;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (param_3 == 1) {
    if (*(int *)*param_1 == 0) {
      iVar4 = param_1[0xc];
    }
    else {
      _vnode_uncache(param_1);
      iVar4 = param_1[0xc];
    }
  }
  else {
    iVar4 = param_1[0xc];
  }
  if ((*(word *)(iVar4 + 100) & 0xf000) == 0x8000) {
    wVar3 = *(word *)(iVar4 + 0x44);
    bVar1 = true;
    if ((wVar3 & 1) != 0) {
      do {
        *(word *)(iVar4 + 0x44) = wVar3 | 0x10;
        _sleep(iVar4,10);
        wVar3 = *(word *)(iVar4 + 0x44);
      } while ((wVar3 & 1) != 0);
      wVar3 = *(word *)(iVar4 + 0x44);
    }
    *(word *)(iVar4 + 0x44) = wVar3 | 1;
    if (((param_4 & 2) != 0) && (param_3 == 1)) {
      *(undefined4 *)(param_2 + 8) = *(undefined4 *)(iVar4 + 0x70);
    }
  }
  else {
    bVar1 = false;
  }
  iVar2 = iVar4;
  sub_F00515C0(iVar4,param_2,param_3,param_4);
  if ((*(word *)(iVar4 + 0x44) & 0x46) != 0) {
    *(word *)(iVar4 + 0x44) = *(word *)(iVar4 + 0x44) | 8;
    param_2 = DAT_f0135000;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar4 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar4 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar4 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar4 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar4 + 0x44) & 0x40) == 0) {
      wVar3 = *(word *)(iVar4 + 0x44);
    }
    else {
      *(undefined4 *)(iVar4 + 0x4c) = 0;
      *(undefined4 *)(iVar4 + 0x84) = _iuniqtime;
      wVar3 = *(word *)(iVar4 + 0x44);
    }
    *(word *)(iVar4 + 0x44) = wVar3 & 0xffb9;
  }
  if (bVar1) {
    wVar3 = *(word *)(iVar4 + 0x44);
    *(word *)(iVar4 + 0x44) = wVar3 & 0xfffe;
    if ((wVar3 & 0x10) != 0) {
      *(word *)(iVar4 + 0x44) = wVar3 & 0xffee;
      _wakeup(iVar4);
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3482 start=0xf00515c0 */

/* WARNING: Removing unreachable block (ram,0xf0051b24) */
/* WARNING: Removing unreachable block (ram,0xf0051a9c) */
/* WARNING: Removing unreachable block (ram,0xf0051a78) */
/* WARNING: Removing unreachable block (ram,0xf00516b8) */
/* WARNING: Removing unreachable block (ram,0xf0051948) */
/* WARNING: Removing unreachable block (ram,0xf00518f0) */
/* WARNING: Removing unreachable block (ram,0xf005197c) */
/* WARNING: Removing unreachable block (ram,0xf0051714) */
/* WARNING: Removing unreachable block (ram,0xf005169c) */
/* WARNING: Removing unreachable block (ram,0xf0051628) */
/* WARNING: Removing unreachable block (ram,0xf0051704) */
/* WARNING: Removing unreachable block (ram,0xf005177c) */
/* WARNING: Removing unreachable block (ram,0xf0051968) */
/* WARNING: Removing unreachable block (ram,0xf0051900) */
/* WARNING: Removing unreachable block (ram,0xf0051934) */
/* WARNING: Removing unreachable block (ram,0xf00519bc) */
/* WARNING: Removing unreachable block (ram,0xf0051aac) */
/* WARNING: Removing unreachable block (ram,0xf0051a48) */
/* WARNING: Removing unreachable block (ram,0xf00515e0) */

undefined8 sub_F00515C0(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  word wVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  uint *puVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar11;
  undefined4 unaff_l5;
  uint uVar12;
  undefined4 unaff_l6;
  word wVar13;
  undefined4 unaff_l7;
  uint *puVar14;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar15;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_2 + 0x14);
  if (1 < param_3) {
    _panic(&aRwip);
  }
  wVar13 = *(word *)(param_1 + 100) & 0xf000;
  if (wVar13 == 0x8000) {
    iVar6 = *(int *)(param_2 + 8);
  }
  else if (wVar13 == 0x4000) {
    iVar6 = *(int *)(param_2 + 8);
  }
  else if (wVar13 == 0xa000) {
    iVar6 = *(int *)(param_2 + 8);
  }
  else {
    _panic(aRwipType);
    iVar6 = *(int *)(param_2 + 8);
  }
  if (iVar6 < 0) {
    iVar6 = 0x16;
  }
  else {
    uVar12 = iVar6 + *(int *)(param_2 + 0x14);
    if ((int)uVar12 < 0) {
      iVar6 = 0x16;
    }
    else if (*(int *)(param_2 + 0x14) == 0) {
      iVar6 = 0;
    }
    else {
      if (param_3 == 1) {
        if ((wVar13 == 0x8000) && ((uint)_active_u[0x9a] < uVar12)) {
          _psignal(*_active_u,0x19);
          iVar6 = 0x1b;
          goto locret_F0051B48;
        }
      }
      else {
        *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 4;
      }
      puVar14 = *(uint **)(param_1 + 0x40);
      iVar11 = *(int *)(param_1 + 0x50);
      uVar12 = *(uint *)(iVar11 + 0x30);
      *(uint *)((int)register0x00000038 + -0x1c) = (uint)(param_3 != 1);
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
      iVar6 = *(int *)(param_2 + 8);
      while( true ) {
        iVar1 = iVar6;
        .udiv(iVar6,uVar12);
        iVar2 = iVar6;
        .urem(iVar6,uVar12);
        uVar10 = *(uint *)(param_2 + 0x14);
        if (uVar12 - iVar2 < *(uint *)(param_2 + 0x14)) {
          uVar10 = uVar12 - iVar2;
        }
        if (param_3 == 0) {
          uVar3 = *(int *)(param_1 + 0x70) - iVar6;
          if ((int)uVar3 < 1) {
            iVar6 = 0;
            goto locret_F0051B48;
          }
          if ((int)uVar3 < (int)uVar10) {
            uVar10 = uVar3;
          }
        }
        puVar7 = (undefined *)0x0;
        if ((param_4 & 4) != 0) {
          puVar7 = (undefined *)((int)register0x00000038 + -0xc);
        }
        iVar8 = param_1;
        _bmap(param_1,iVar1,*(undefined4 *)((int)register0x00000038 + -0x1c),iVar2 + uVar10,puVar7);
        iVar8 = iVar8 << ((byte)*(undefined4 *)(iVar11 + 100) & 0x1f);
        if ((((*(char *)(dword_F0133DDC + 0x38) == '\x1c') && (param_3 == 1)) &&
            (0 < *(int *)((int)register0x00000038 + -0x14) - *(int *)(param_2 + 0x14))) &&
           ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0)) break;
        iVar6 = (int)*(char *)(dword_F0133DDC + 0x38);
        if (iVar6 != 0) goto locret_F0051B48;
        bVar15 = iVar1 + -0xb < 0;
        if (param_3 == 1) {
          if (iVar8 < 0) goto locret_F0051B48;
          bVar15 = iVar1 + -0xb < 0;
          if ((*(uint *)(param_1 + 0x70) < *(int *)(param_2 + 8) + uVar10) &&
             (((wVar13 == 0x4000 || (wVar13 == 0x8000)) ||
              (bVar15 = iVar1 + -0xb < 0, wVar13 == 0xa000)))) {
            uVar3 = *(int *)(param_2 + 8) + uVar10;
            *(uint *)(param_1 + 0x70) = uVar3;
            if (*(uint *)(*(int *)(param_1 + 0xc) + 0x14) < uVar3) {
              *(uint *)(*(int *)(param_1 + 0xc) + 0x14) = uVar3;
            }
            if ((param_4 & 4) != 0) {
              *(undefined4 *)((int)register0x00000038 + -0xc) = 1;
            }
            bVar15 = iVar1 + -0xb < 0;
          }
        }
        if (iVar1 == 0xb || bVar15 != SBORROW4(iVar1,0xb)) {
          if (*(uint *)(param_1 + 0x70) <
              (uint)(iVar1 + 1 << ((byte)*(undefined4 *)(iVar11 + 0x50) & 0x1f))) {
            puVar9 = (uint *)(((*(uint *)(param_1 + 0x70) & ~*(uint *)(iVar11 + 0x48)) +
                              *(int *)(iVar11 + 0x34)) - 1 & *(uint *)(iVar11 + 0x4c));
          }
          else {
            puVar9 = *(uint **)(iVar11 + 0x30);
          }
        }
        else {
          puVar9 = *(uint **)(iVar11 + 0x30);
        }
        if (param_3 == 0) {
          if (iVar8 < 0) {
            _geteblk();
            _bzero(puVar9[8],puVar9[5]);
            puVar9[10] = 0;
          }
          else if (*(int *)(param_1 + 0x58) + 1 == iVar1) {
            puVar4 = puVar14;
            _breada(puVar14,iVar8,puVar9,_rablock,_rasize);
            puVar9 = puVar4;
          }
          else {
            puVar4 = puVar14;
            _bread(puVar14,iVar8,puVar9);
            puVar9 = puVar4;
          }
          *(int *)(param_1 + 0x58) = iVar1;
          puVar4 = puVar9;
        }
        else {
          puVar4 = puVar14;
          if (uVar10 == uVar12) {
            _getblk(puVar14,iVar8,puVar9);
          }
          else {
            _bread(puVar14,iVar8,puVar9);
          }
        }
        if ((int)(puVar4[5] - puVar4[10]) < (int)uVar10) {
          uVar10 = puVar4[5] - puVar4[10];
        }
        if ((*puVar4 & 4) != 0) {
          _brelse(puVar4,uVar10);
          iVar6 = 5;
          goto locret_F0051B48;
        }
        iVar6 = puVar4[8] + iVar2;
        _uiomove(iVar6,uVar10,param_3,param_2);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar6;
        if ((((param_4 & 4) != 0) && ((*(word *)(param_1 + 100) & 0x200) != 0)) &&
           ((_stickyhack != 0 && ((*(word *)(param_1 + 100) & 0x49) == 0)))) {
          *puVar4 = *puVar4 | 0x400000;
        }
        if (param_3 == 0) {
          if (uVar10 + iVar2 == uVar12) {
            uVar3 = *puVar4;
loc_F0051A40:
            *puVar4 = uVar3 | 0x80;
          }
          else if (*(int *)(param_2 + 8) == *(int *)(param_1 + 0x70)) {
            uVar3 = *puVar4;
            goto loc_F0051A40;
          }
          _brelse(puVar4);
        }
        else {
          if (((param_4 & 4) == 0) && ((*(word *)(param_1 + 100) & 0xf000) != 0x4000)) {
            if (uVar10 + iVar2 == uVar12) {
              *puVar4 = *puVar4 | 0x80;
              _bawrite();
              wVar5 = *(word *)(param_1 + 0x44);
            }
            else {
              _bdwrite(puVar4);
              wVar5 = *(word *)(param_1 + 0x44);
            }
          }
          else {
            _bwrite(puVar4);
            wVar5 = *(word *)(param_1 + 0x44);
          }
          *(word *)(param_1 + 0x44) = wVar5 | 0x42;
          if (*(sword *)(_active_u[7] + 6) != 0) {
            *(word *)(param_1 + 100) = *(word *)(param_1 + 100) & 0xf3ff;
          }
        }
        iVar6 = *(int *)((int)register0x00000038 + -0xc);
        if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto loc_F0051B18;
        if ((*(int *)(param_2 + 0x14) < 1) || (uVar10 == 0)) goto loc_F0051B14;
        iVar6 = *(int *)(param_2 + 8);
      }
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
loc_F0051B14:
      iVar6 = *(int *)((int)register0x00000038 + -0xc);
loc_F0051B18:
      if (iVar6 != 0) {
        _iupdat(param_1,1);
      }
      iVar6 = (int)*(char *)(dword_F0133DDC + 0x38);
    }
  }
locret_F0051B48:
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=3483 start=0xf0051b50 */

undefined8 sub_F0051B50(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,0x16);
}
/* GHIDRADEC_FUNCTION index=3484 start=0xf0051b5c */

undefined8 sub_F0051B5C(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,0x16);
}
/* GHIDRADEC_FUNCTION index=3485 start=0xf0051b68 */

/* WARNING: Removing unreachable block (ram,0xf0051c9c) */
/* WARNING: Removing unreachable block (ram,0xf0051b88) */

sqword sub_F0051B68(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  word wVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  iVar5 = param_1[0xc];
  if ((*(word *)(iVar5 + 0x44) & 0x46) != 0) {
    *(word *)(iVar5 + 0x44) = *(word *)(iVar5 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar5 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar5 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar5 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar5 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar5 + 0x44) & 0x40) == 0) {
      wVar3 = *(word *)(iVar5 + 0x44);
    }
    else {
      *(undefined4 *)(iVar5 + 0x4c) = 0;
      *(undefined4 *)(iVar5 + 0x84) = _iuniqtime;
      wVar3 = *(word *)(iVar5 + 0x44);
    }
    *(word *)(iVar5 + 0x44) = wVar3 & 0xffb9;
  }
  *param_2 = *(undefined4 *)(_iftovt_tab + (uint)(*(word *)(iVar5 + 100) >> 0xd) * 4);
  *(undefined2 *)(param_2 + 1) = *(undefined2 *)(iVar5 + 100);
  *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)(iVar5 + 0x68);
  *(undefined2 *)(param_2 + 2) = *(undefined2 *)(iVar5 + 0x6a);
  param_2[3] = (int)*(sword *)(iVar5 + 0x46);
  param_2[4] = *(undefined4 *)(iVar5 + 0x48);
  *(undefined2 *)(param_2 + 5) = *(undefined2 *)(iVar5 + 0x66);
  if (param_1[10] == 1) {
    uVar1 = *(undefined4 *)(*param_1 + 0x14);
  }
  else {
    uVar1 = *(undefined4 *)(iVar5 + 0x70);
  }
  param_2[6] = uVar1;
  param_2[8] = *(undefined4 *)(iVar5 + 0x74);
  param_2[9] = 0;
  param_2[10] = *(undefined4 *)(iVar5 + 0x7c);
  param_2[0xb] = 0;
  param_2[0xc] = *(undefined4 *)(iVar5 + 0x84);
  param_2[0xd] = 0;
  *(sword *)(param_2 + 0xe) = (sword)*(undefined4 *)(iVar5 + 0x8c);
  piVar2 = param_1;
  (**(code **)(param_1[7] + 0x80))(param_1);
  uVar4 = *(uint *)(iVar5 + 0xcc);
  .umul(uVar4,piVar2);
  param_2[0xf] = uVar4 >> 9;
  wVar3 = *(word *)(iVar5 + 100) & 0xf000;
  if (wVar3 == 0x2000) {
    param_2[7] = 0x2000;
  }
  else if (wVar3 == 0x6000) {
    (**(code **)(param_1[7] + 0x80))();
    param_2[7] = param_1;
  }
  else {
    param_2[7] = *(undefined4 *)(param_1[9] + 0x10);
  }
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=3486 start=0xf0051d04 */

/* WARNING: Removing unreachable block (ram,0xf0052068) */
/* WARNING: Removing unreachable block (ram,0xf0052010) */
/* WARNING: Removing unreachable block (ram,0xf0051f84) */
/* WARNING: Removing unreachable block (ram,0xf0051f1c) */
/* WARNING: Removing unreachable block (ram,0xf0051f0c) */
/* WARNING: Removing unreachable block (ram,0xf0051ee0) */
/* WARNING: Removing unreachable block (ram,0xf0051e4c) */
/* WARNING: Removing unreachable block (ram,0xf0051da4) */
/* WARNING: Removing unreachable block (ram,0xf0051dd8) */
/* WARNING: Removing unreachable block (ram,0xf0051e9c) */
/* WARNING: Removing unreachable block (ram,0xf0051ef8) */
/* WARNING: Removing unreachable block (ram,0xf0051f14) */
/* WARNING: Removing unreachable block (ram,0xf0051f48) */
/* WARNING: Removing unreachable block (ram,0xf0051fd4) */
/* WARNING: Removing unreachable block (ram,0xf0052048) */
/* WARNING: Removing unreachable block (ram,0xf0052070) */
/* WARNING: Removing unreachable block (ram,0xf0051d20) */

undefined8 sub_F0051D04(int param_1,int *param_2,int param_3)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  word wVar5;
  word wVar6;
  int iVar4;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar8 = 0;
  iVar3 = (int)*(sword *)(*_active_u + 0x30);
  _get_posix_proc();
  iVar9 = 0;
  if (*(sword *)(param_2 + 5) != -1) {
loc_F0051D9C:
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (param_2[7] != -1) {
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (*(sword *)(param_2 + 0xe) != -1) {
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (param_2[0xf] != -1) {
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (param_2[3] != -1) {
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (param_2[4] != -1) {
    iVar9 = 0x16;
    goto locret_F0052078;
  }
  if (*param_2 != -1) goto loc_F0051D9C;
  iVar7 = *(int *)(param_1 + 0x30);
  _ilock(iVar7);
  if (*(sword *)(param_2 + 1) == -1) {
    sVar1 = *(sword *)((int)param_2 + 6);
loc_F0051E7C:
    if (sVar1 == -1) {
      if (*(sword *)(param_2 + 2) != -1) {
        sVar2 = *(sword *)(param_2 + 2);
        goto loc_F0051E9C;
      }
      iVar4 = param_2[6];
    }
    else {
      sVar2 = *(sword *)(param_2 + 2);
loc_F0051E9C:
      iVar9 = iVar7;
      sub_F0052080(iVar7,(int)sVar1,(int)sVar2);
      if (iVar9 != 0) goto loc_F0052068;
      iVar4 = param_2[6];
    }
    if (iVar4 == -1) {
loc_F0051F0C:
      _iunlock(iVar7);
      _mfs_fsync(param_1);
      _ilock(iVar7);
      if (param_2[8] == -1) {
        iVar4 = param_2[10];
      }
      else {
        iVar8 = (int)*(sword *)(iVar7 + 0x68);
        iVar9 = 0;
        if ((*(sword *)(param_3 + 2) != iVar8) && (_suser(), iVar8 == 0)) {
          iVar9 = (int)*(char *)(dword_F0133DDC + 0x38);
        }
        if (iVar9 == 0) {
          iVar4 = param_2[8];
        }
        else {
          if ((-1 < *(int *)(iVar3 + 0x18)) || (iVar9 = iVar7, _iaccess(iVar7,0x80), iVar9 != 0))
          goto loc_F0052068;
          *(undefined *)(dword_F0133DDC + 0x38) = 0;
          iVar4 = param_2[8];
        }
        iVar8 = 1;
        *(int *)(iVar7 + 0x74) = iVar4;
        iVar4 = param_2[10];
      }
      if (iVar4 != -1) {
        iVar4 = (int)*(sword *)(iVar7 + 0x68);
        iVar9 = 0;
        if ((*(sword *)(param_3 + 2) != iVar4) && (_suser(), iVar4 == 0)) {
          iVar9 = (int)*(char *)(dword_F0133DDC + 0x38);
        }
        if (iVar9 == 0) {
          iVar3 = param_2[10];
        }
        else {
          if ((-1 < *(int *)(iVar3 + 0x18)) || (iVar9 = iVar7, _iaccess(iVar7,0x80), iVar9 != 0))
          goto loc_F0052068;
          *(undefined *)(dword_F0133DDC + 0x38) = 0;
          iVar3 = param_2[10];
        }
        iVar8 = iVar8 + 1;
        *(int *)(iVar7 + 0x7c) = iVar3;
      }
      if (iVar8 != 0) {
        _getthetime((undefined *)((int)register0x00000038 + -0x10));
        *(undefined4 *)(iVar7 + 0x84) = *(undefined4 *)((int)register0x00000038 + -0x10);
        *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 8;
      }
    }
    else if ((*(word *)(iVar7 + 100) & 0xf000) == 0x4000) {
      iVar9 = 0x15;
    }
    else {
      iVar9 = iVar7;
      _iaccess(iVar7,0x80);
      if ((iVar9 == 0) && (iVar9 = iVar7, _itrunc(iVar7,param_2[6]), iVar9 == 0)) goto loc_F0051F0C;
    }
  }
  else {
    iVar4 = (int)*(sword *)(iVar7 + 0x68);
    bVar10 = true;
    if (*(sword *)(param_3 + 2) != iVar4) {
      _suser();
      bVar10 = true;
      if (iVar4 == 0) {
        iVar9 = (int)*(char *)(dword_F0133DDC + 0x38);
        bVar10 = iVar9 == 0;
      }
    }
    if (bVar10) {
      wVar5 = *(word *)(iVar7 + 100) & 0xf000;
      *(word *)(iVar7 + 100) = wVar5;
      wVar6 = *(word *)(param_2 + 1);
      *(word *)(iVar7 + 100) = wVar5 | wVar6 & 0xfff;
      if (*(sword *)(param_3 + 2) == 0) {
loc_F0051E6C:
        wVar6 = *(word *)(iVar7 + 0x44);
      }
      else {
        if (wVar5 != 0x4000) {
          *(word *)(iVar7 + 100) = wVar5 | wVar6 & 0xdff;
        }
        iVar4 = (int)*(sword *)(iVar7 + 0x6a);
        _groupmember();
        if (iVar4 == 0) {
          *(word *)(iVar7 + 100) = *(word *)(iVar7 + 100) & 0xfbff;
          goto loc_F0051E6C;
        }
        wVar6 = *(word *)(iVar7 + 0x44);
      }
      *(word *)(iVar7 + 0x44) = wVar6 | 0x40;
      sVar1 = *(sword *)((int)param_2 + 6);
      goto loc_F0051E7C;
    }
  }
loc_F0052068:
  _iupdat(iVar7,1);
  _iunlock(iVar7);
locret_F0052078:
  return CONCAT44(param_2,iVar9);
}
/* GHIDRADEC_FUNCTION index=3487 start=0xf0052080 */

/* WARNING: Removing unreachable block (ram,0xf00520fc) */
/* WARNING: Removing unreachable block (ram,0xf00520e8) */

undefined8 sub_F0052080(int param_1,sword param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  int iVar4;
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
  iVar4 = (int)param_2;
  if (iVar4 == -1) {
    param_2 = *(sword *)(param_1 + 0x68);
  }
  if ((sword)param_3 == -1) {
    param_3 = (uint)*(word *)(param_1 + 0x6a);
  }
  iVar2 = (int)*(sword *)(*(int *)(_active_u + 0x1c) + 2);
  iVar1 = (int)param_2;
  if ((iVar2 == iVar1) && (iVar1 = param_3 << 0x10, iVar2 == *(sword *)(param_1 + 0x68))) {
    iVar2 = iVar1 >> 0x10;
    _groupmember();
    iVar1 = 0;
    if (iVar2 == 0) goto loc_F00520FC;
    *(sword *)(param_1 + 0x68) = param_2;
  }
  else {
loc_F00520FC:
    _suser();
    if (iVar1 == 0) {
      uVar3 = 1;
      goto locret_F0052154;
    }
    *(sword *)(param_1 + 0x68) = param_2;
  }
  *(sword *)(param_1 + 0x6a) = (sword)param_3;
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x40;
  if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
    uVar3 = 0;
  }
  else {
    *(word *)(param_1 + 100) = *(word *)(param_1 + 100) & 0xf3ff;
    uVar3 = 0;
  }
locret_F0052154:
  return CONCAT44(iVar4,uVar3);
}
/* GHIDRADEC_FUNCTION index=3488 start=0xf005215c */

/* WARNING: Removing unreachable block (ram,0xf00521a4) */
/* WARNING: Removing unreachable block (ram,0xf0052198) */
/* WARNING: Removing unreachable block (ram,0xf0052170) */

undefined8 sub_F005215C(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x30);
  while ((*(word *)(iVar2 + 0x44) & 1) != 0) {
    *(word *)(iVar2 + 0x44) = *(word *)(iVar2 + 0x44) | 0x10;
    _sleep(iVar2,10);
  }
  *(word *)(iVar2 + 0x44) = *(word *)(iVar2 + 0x44) | 1;
  iVar1 = iVar2;
  _iaccess(iVar2,param_2);
  _iunlock(iVar2);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3489 start=0xf00521b4 */

/* WARNING: Removing unreachable block (ram,0xf00521e8) */
/* WARNING: Removing unreachable block (ram,0xf0052228) */
/* WARNING: Removing unreachable block (ram,0xf0052204) */

undefined8 sub_F00521B4(int param_1,undefined *param_2)

{
  word wVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  int iVar3;
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
  if (*(int *)(param_1 + 0x28) == 5) {
    iVar3 = *(int *)(param_1 + 0x30);
    iVar2 = iVar3 + 0x8c;
    if ((*(uint *)(iVar3 + 200) & 1) == 0) {
      iVar2 = iVar3;
      sub_F00515C0(iVar3,param_2,0,0);
    }
    else {
      _uiomove(iVar2,*(undefined4 *)(iVar3 + 0x70),0);
    }
    if ((*(word *)(iVar3 + 0x44) & 0x46) != 0) {
      *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 8;
      param_2 = DAT_f0135000;
      _microtime(&_iuniqtime);
      if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
        *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
      }
      if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
        *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
      }
      if ((*(word *)(iVar3 + 0x44) & 0x40) == 0) {
        wVar1 = *(word *)(iVar3 + 0x44);
      }
      else {
        *(undefined4 *)(iVar3 + 0x4c) = 0;
        *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
        wVar1 = *(word *)(iVar3 + 0x44);
      }
      *(word *)(iVar3 + 0x44) = wVar1 & 0xffb9;
    }
  }
  else {
    iVar2 = 0x16;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3490 start=0xf0052294 */

/* WARNING: Removing unreachable block (ram,0xf00522a4) */
/* WARNING: Removing unreachable block (ram,0xf00522ac) */
/* WARNING: Removing unreachable block (ram,0xf005229c) */

sqword sub_F0052294(int param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 uVar1;
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
  uVar1 = *(undefined4 *)(param_1 + 0x30);
  _ilock(uVar1);
  _syncip(uVar1);
  _iunlock(uVar1);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3491 start=0xf00522bc */

/* WARNING: Removing unreachable block (ram,0xf00522c0) */

sqword sub_F00522BC(int param_1,uint param_2)

{
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
  _iinactive(*(undefined4 *)(param_1 + 0x30));
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3492 start=0xf00522d0 */

/* WARNING: Removing unreachable block (ram,0xf005245c) */
/* WARNING: Removing unreachable block (ram,0xf00523cc) */
/* WARNING: Removing unreachable block (ram,0xf0052304) */
/* WARNING: Removing unreachable block (ram,0xf005242c) */
/* WARNING: Removing unreachable block (ram,0xf0052468) */
/* WARNING: Removing unreachable block (ram,0xf00522e0) */

undefined8 sub_F00522D0(int param_1,undefined *param_2,int *param_3)

{
  int iVar1;
  word wVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  undefined auStackX_0 [92];
  
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
  iVar3 = *(int *)(param_1 + 0x30);
  iVar1 = iVar3;
  _dirlook(iVar3,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if ((*(word *)(iVar3 + 0x44) & 0x46) != 0) {
    *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 8;
    param_2 = DAT_f0135000;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar3 + 0x44) & 0x40) == 0) {
      wVar2 = *(word *)(iVar3 + 0x44);
    }
    else {
      *(undefined4 *)(iVar3 + 0x4c) = 0;
      *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
      wVar2 = *(word *)(iVar3 + 0x44);
    }
    *(word *)(iVar3 + 0x44) = wVar2 & 0xffb9;
  }
  iVar3 = *(int *)((int)register0x00000038 + -0xc);
  if (iVar1 == 0) {
    *param_3 = iVar3 + 0xc;
    if ((*(uint *)(iVar3 + 100) & 0x42400000) == 0x2000000) {
      if (_stickyhack == 0) {
        wVar2 = *(word *)(iVar3 + 0x44);
      }
      else {
        *(word *)(iVar3 + 0x10) = *(word *)(iVar3 + 0x10) | 0x80;
        wVar2 = *(word *)(iVar3 + 0x44);
      }
    }
    else {
      wVar2 = *(word *)(iVar3 + 0x44);
    }
    if ((wVar2 & 0x46) != 0) {
      *(word *)(iVar3 + 0x44) = wVar2 | 8;
      param_2 = DAT_f0135000;
      _microtime(&_iuniqtime);
      if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
        *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
      }
      if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
        *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
      }
      if ((*(word *)(iVar3 + 0x44) & 0x40) == 0) {
        wVar2 = *(word *)(iVar3 + 0x44);
      }
      else {
        *(undefined4 *)(iVar3 + 0x4c) = 0;
        *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
        wVar2 = *(word *)(iVar3 + 0x44);
      }
      *(word *)(iVar3 + 0x44) = wVar2 & 0xffb9;
    }
    _iunlock(iVar3);
    iVar3 = *param_3;
    if ((*(int *)(iVar3 + 0x28) - 3U < 2) || (*(int *)(iVar3 + 0x28) - 8U < 2)) {
      _specvp(iVar3,(int)*(sword *)(iVar3 + 0x2c));
      _vn_rele(*param_3);
      *param_3 = iVar3;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3493 start=0xf005247c */

/* WARNING: Removing unreachable block (ram,0xf00526d0) */
/* WARNING: Removing unreachable block (ram,0xf005263c) */
/* WARNING: Removing unreachable block (ram,0xf00525cc) */
/* WARNING: Removing unreachable block (ram,0xf0052500) */
/* WARNING: Removing unreachable block (ram,0xf00525ac) */
/* WARNING: Removing unreachable block (ram,0xf0052608) */
/* WARNING: Removing unreachable block (ram,0xf005269c) */
/* WARNING: Removing unreachable block (ram,0xf00526dc) */
/* WARNING: Removing unreachable block (ram,0xf00524dc) */

undefined8 sub_F005247C(int param_1,int param_2,int *param_3,int param_4,uint param_5,int *param_6)

{
  sword sVar1;
  word wVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  int iVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar3 = *(int *)((int)register0x00000038 + 0x5c);
  if (*param_3 == 2) {
    iVar4 = 0x15;
    goto locret_F005270C;
  }
  sVar1 = *(sword *)(iVar3 + 2);
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  iVar5 = *(int *)(param_1 + 0x30);
  if (sVar1 != 0) {
    *(word *)(param_3 + 1) = *(word *)(param_3 + 1) & 0xfdff;
  }
  iVar4 = iVar5;
  _direnter(iVar5,param_2,0,0,0,param_3,(undefined *)((int)register0x00000038 + -0xc));
  if ((*(word *)(iVar5 + 0x44) & 0x46) != 0) {
    *(word *)(iVar5 + 0x44) = *(word *)(iVar5 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar5 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar5 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar5 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar5 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar5 + 0x44) & 0x40) == 0) {
      wVar2 = *(word *)(iVar5 + 0x44);
    }
    else {
      *(undefined4 *)(iVar5 + 0x4c) = 0;
      *(undefined4 *)(iVar5 + 0x84) = _iuniqtime;
      wVar2 = *(word *)(iVar5 + 0x44);
    }
    *(word *)(iVar5 + 0x44) = wVar2 & 0xffb9;
  }
  iVar5 = *(int *)((int)register0x00000038 + -0xc);
  if (iVar4 == 0x11) {
    if ((param_4 == 0) &&
       (((*(word *)(iVar5 + 100) & 0xf000) != 0x4000 || (iVar4 = 0x15, (param_5 & 0x80) == 0)))) {
      if (param_5 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = iVar5;
        _iaccess(iVar5,param_5);
      }
    }
    if (iVar4 == 0) {
      bVar6 = true;
      if (((*(word *)(iVar5 + 100) & 0xf000) == 0x8000) && (bVar6 = true, param_3[6] == 0)) {
        _itrunc(iVar5,0);
        goto loc_F0052610;
      }
    }
    else {
      _iput(iVar5);
      bVar6 = iVar4 == 0;
    }
  }
  else {
loc_F0052610:
    bVar6 = iVar4 == 0;
  }
  param_2 = iVar4;
  if (bVar6) {
    *param_6 = iVar5 + 0xc;
    if ((*(word *)(iVar5 + 0x44) & 0x46) != 0) {
      *(word *)(iVar5 + 0x44) = *(word *)(iVar5 + 0x44) | 8;
      _microtime(&_iuniqtime);
      if ((*(word *)(iVar5 + 0x44) & 4) != 0) {
        *(undefined4 *)(iVar5 + 0x74) = _iuniqtime;
      }
      if ((*(word *)(iVar5 + 0x44) & 2) != 0) {
        *(undefined4 *)(iVar5 + 0x7c) = _iuniqtime;
      }
      if ((*(word *)(iVar5 + 0x44) & 0x40) == 0) {
        wVar2 = *(word *)(iVar5 + 0x44);
      }
      else {
        *(undefined4 *)(iVar5 + 0x4c) = 0;
        *(undefined4 *)(iVar5 + 0x84) = _iuniqtime;
        wVar2 = *(word *)(iVar5 + 0x44);
      }
      *(word *)(iVar5 + 0x44) = wVar2 & 0xffb9;
    }
    _iunlock(iVar5);
    iVar5 = *param_6;
    if ((*(int *)(iVar5 + 0x28) - 3U < 2) || (*(int *)(iVar5 + 0x28) - 8U < 2)) {
      _specvp(iVar5,(int)*(sword *)(iVar5 + 0x2c));
      _vn_rele(*param_6);
      *param_6 = iVar5;
    }
    if (param_3 != (int *)0x0) {
      (**(code **)(*(int *)(*param_6 + 0x1c) + 0x14))(*param_6,param_3,iVar3);
    }
  }
locret_F005270C:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=3494 start=0xf0052714 */

/* WARNING: Removing unreachable block (ram,0xf005274c) */
/* WARNING: Removing unreachable block (ram,0xf0052728) */

undefined8 sub_F0052714(int param_1,undefined *param_2)

{
  word wVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = *(int *)(param_1 + 0x30);
  iVar2 = iVar3;
  _dirremove(iVar3,param_2,0,0);
  if ((*(word *)(iVar3 + 0x44) & 0x46) != 0) {
    *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 8;
    param_2 = DAT_f0135000;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar3 + 0x44) & 0x40) == 0) {
      wVar1 = *(word *)(iVar3 + 0x44);
    }
    else {
      *(undefined4 *)(iVar3 + 0x4c) = 0;
      *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
      wVar1 = *(word *)(iVar3 + 0x44);
    }
    *(word *)(iVar3 + 0x44) = wVar1 & 0xffb9;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3495 start=0xf00527b4 */

/* WARNING: Removing unreachable block (ram,0xf0052880) */
/* WARNING: Removing unreachable block (ram,0xf005285c) */
/* WARNING: Removing unreachable block (ram,0xf00528fc) */
/* WARNING: Removing unreachable block (ram,0xf005282c) */

undefined8 sub_F00527B4(int param_1,int param_2,undefined4 param_3)

{
  word wVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar3 = param_1;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x70))
            (param_1,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar3 == 0) {
    param_1 = *(int *)((int)register0x00000038 + -0xc);
  }
  iVar3 = *(int *)(param_1 + 0x30);
  if (((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) ||
     ((*(word *)(iVar3 + 100) & 0xf000) != 0x4000)) {
    uVar2 = *(word *)(iVar3 + 100) & 0xf000;
    if ((uVar2 == 0x4000) && (_suser(0x4000,param_3), uVar2 == 0)) {
      uVar4 = 1;
    }
    else {
      uVar4 = *(undefined4 *)(param_2 + 0x30);
      _direnter(uVar4,param_3,1,0,iVar3,0,0);
      if ((*(word *)(iVar3 + 0x44) & 0x46) != 0) {
        *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 8;
        _microtime(&_iuniqtime);
        if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
          *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
        }
        if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
          *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
        }
        if ((*(word *)(iVar3 + 0x44) & 0x40) == 0) {
          wVar1 = *(word *)(iVar3 + 0x44);
        }
        else {
          *(undefined4 *)(iVar3 + 0x4c) = 0;
          *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
          wVar1 = *(word *)(iVar3 + 0x44);
        }
        *(word *)(iVar3 + 0x44) = wVar1 & 0xffb9;
      }
      wVar1 = *(word *)(*(int *)(param_2 + 0x30) + 0x44);
      if ((wVar1 & 0x46) != 0) {
        *(word *)(*(int *)(param_2 + 0x30) + 0x44) = wVar1 | 8;
        _microtime(&_iuniqtime);
        iVar3 = *(int *)(param_2 + 0x30);
        if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
          *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
          iVar3 = *(int *)(param_2 + 0x30);
        }
        if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
          *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
        }
        if ((*(word *)(*(int *)(param_2 + 0x30) + 0x44) & 0x40) == 0) {
          iVar3 = *(int *)(param_2 + 0x30);
        }
        else {
          *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x4c) = 0;
          *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x84) = _iuniqtime;
          iVar3 = *(int *)(param_2 + 0x30);
        }
        *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) & 0xffb9;
      }
    }
  }
  else {
    uVar4 = 1;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3496 start=0xf005297c */

/* WARNING: Removing unreachable block (ram,0xf0052b28) */
/* WARNING: Removing unreachable block (ram,0xf0052a80) */
/* WARNING: Removing unreachable block (ram,0xf0052a28) */
/* WARNING: Removing unreachable block (ram,0xf00529b8) */
/* WARNING: Removing unreachable block (ram,0xf00529a4) */
/* WARNING: Removing unreachable block (ram,0xf0052a10) */
/* WARNING: Removing unreachable block (ram,0xf0052a60) */
/* WARNING: Removing unreachable block (ram,0xf0052ab0) */
/* WARNING: Removing unreachable block (ram,0xf0052b88) */
/* WARNING: Removing unreachable block (ram,0xf005298c) */

undefined8 sub_F005297C(int param_1,undefined *param_2,int param_3,undefined4 param_4)

{
  sword sVar1;
  word wVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar7;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar5 = *(int *)(param_1 + 0x30);
  iVar7 = *(int *)(param_3 + 0x30);
  iVar6 = iVar5;
  _iaccess(iVar5,0x80);
  if ((iVar6 != 0) ||
     (iVar6 = iVar5, _dirlook(iVar5,param_2,(undefined *)((int)register0x00000038 + -0xc)),
     iVar6 != 0)) goto locret_F0052B90;
  _iunlock(*(undefined4 *)((int)register0x00000038 + -0xc));
  if (((*(word *)(iVar5 + 100) & 0x200) == 0) ||
     (((sVar1 = *(sword *)(*(int *)(_active_u + 0x1c) + 2), sVar1 == 0 ||
       (sVar1 == *(sword *)(iVar5 + 0x68))) ||
      (iVar6 = 1, *(sword *)(*(int *)((int)register0x00000038 + -0xc) + 0x68) == sVar1)))) {
    puVar4 = param_2;
    _strcmp(param_2,&asc_F010F208);
    if (puVar4 != (undefined *)0x0) {
      puVar4 = param_2;
      _strcmp(param_2,&asc_F010F210);
      if ((puVar4 != (undefined *)0x0) && (iVar5 != *(int *)((int)register0x00000038 + -0xc))) {
        iVar6 = iVar7;
        _direnter(iVar7,param_4,2,iVar5,*(int *)((int)register0x00000038 + -0xc),0,0);
        iVar3 = iVar6 + 1;
        if (iVar6 == 0) {
          iVar6 = iVar5;
          _dirremove(iVar5,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),0);
          iVar3 = iVar6 + -2;
        }
        if (iVar3 == 0) {
          iVar6 = 0;
        }
        goto loc_F0052A98;
      }
    }
    iVar6 = 0x16;
  }
loc_F0052A98:
  if ((*(word *)(iVar5 + 0x44) & 0x46) != 0) {
    *(word *)(iVar5 + 0x44) = *(word *)(iVar5 + 0x44) | 8;
    param_2 = DAT_f0135000;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar5 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar5 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar5 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar5 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar5 + 0x44) & 0x40) == 0) {
      wVar2 = *(word *)(iVar5 + 0x44);
    }
    else {
      *(undefined4 *)(iVar5 + 0x4c) = 0;
      *(undefined4 *)(iVar5 + 0x84) = _iuniqtime;
      wVar2 = *(word *)(iVar5 + 0x44);
    }
    *(word *)(iVar5 + 0x44) = wVar2 & 0xffb9;
  }
  if ((*(word *)(iVar7 + 0x44) & 0x46) != 0) {
    *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar7 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar7 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar7 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar7 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar7 + 0x44) & 0x40) == 0) {
      wVar2 = *(word *)(iVar7 + 0x44);
    }
    else {
      *(undefined4 *)(iVar7 + 0x4c) = 0;
      *(undefined4 *)(iVar7 + 0x84) = _iuniqtime;
      wVar2 = *(word *)(iVar7 + 0x44);
    }
    *(word *)(iVar7 + 0x44) = wVar2 & 0xffb9;
  }
  _irele(*(undefined4 *)((int)register0x00000038 + -0xc));
locret_F0052B90:
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=3497 start=0xf0052b98 */

/* WARNING: Removing unreachable block (ram,0xf0052c70) */
/* WARNING: Removing unreachable block (ram,0xf0052be0) */
/* WARNING: Removing unreachable block (ram,0xf0052ce4) */
/* WARNING: Removing unreachable block (ram,0xf0052cd0) */
/* WARNING: Removing unreachable block (ram,0xf0052bbc) */

undefined8 sub_F0052B98(int param_1,undefined *param_2,undefined4 param_3,int *param_4)

{
  word wVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  undefined auStackX_0 [92];
  
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
  iVar3 = *(int *)(param_1 + 0x30);
  iVar2 = iVar3;
  _direnter(iVar3,param_2,0,0,0,param_3,(undefined *)((int)register0x00000038 + -0xc));
  if ((*(word *)(iVar3 + 0x44) & 0x46) != 0) {
    *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 8;
    param_2 = DAT_f0135000;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar3 + 0x44) & 0x40) == 0) {
      wVar1 = *(word *)(iVar3 + 0x44);
    }
    else {
      *(undefined4 *)(iVar3 + 0x4c) = 0;
      *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
      wVar1 = *(word *)(iVar3 + 0x44);
    }
    *(word *)(iVar3 + 0x44) = wVar1 & 0xffb9;
  }
  if (iVar2 == 0) {
    iVar3 = *(int *)((int)register0x00000038 + -0xc);
    *param_4 = iVar3 + 0xc;
    if ((*(word *)(iVar3 + 0x44) & 0x46) != 0) {
      *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 8;
      param_2 = DAT_f0135000;
      _microtime(&_iuniqtime);
      if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
        *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
      }
      if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
        *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
      }
      if ((*(word *)(iVar3 + 0x44) & 0x40) == 0) {
        wVar1 = *(word *)(iVar3 + 0x44);
      }
      else {
        *(undefined4 *)(iVar3 + 0x4c) = 0;
        *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
        wVar1 = *(word *)(iVar3 + 0x44);
      }
      *(word *)(iVar3 + 0x44) = wVar1 & 0xffb9;
    }
    _iunlock(iVar3);
  }
  else if (iVar2 == 0x11) {
    _iput(*(undefined4 *)((int)register0x00000038 + -0xc));
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3498 start=0xf0052cf4 */

/* WARNING: Removing unreachable block (ram,0xf0052d2c) */
/* WARNING: Removing unreachable block (ram,0xf0052d08) */

undefined8 sub_F0052CF4(int param_1,undefined *param_2)

{
  word wVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = *(int *)(param_1 + 0x30);
  iVar2 = iVar3;
  _dirremove(iVar3,param_2,0,1);
  if ((*(word *)(iVar3 + 0x44) & 0x46) != 0) {
    *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 8;
    param_2 = DAT_f0135000;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar3 + 0x44) & 0x40) == 0) {
      wVar1 = *(word *)(iVar3 + 0x44);
    }
    else {
      *(undefined4 *)(iVar3 + 0x4c) = 0;
      *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
      wVar1 = *(word *)(iVar3 + 0x44);
    }
    *(word *)(iVar3 + 0x44) = wVar1 & 0xffb9;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3499 start=0xf0052d94 */

/* WARNING: Removing unreachable block (ram,0xf0052e1c) */
/* WARNING: Removing unreachable block (ram,0xf0052df8) */

undefined8 sub_F0052D94(int param_1,undefined *param_2)

{
  word wVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  iVar3 = *(int *)param_2;
  iVar4 = *(int *)(param_1 + 0x30);
  if (*(int *)((int)param_2 + 4) == 1) {
    if (*(uint *)(iVar3 + 4) < 0x400) {
      iVar3 = 0x16;
      goto locret_F0052E7C;
    }
    uVar2 = *(uint *)(iVar3 + 4) & 0xfffffc00;
    if ((*(uint *)((int)param_2 + 8) & 0x3ff) == 0) {
      *(uint *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) - (*(int *)(iVar3 + 4) - uVar2)
      ;
      *(uint *)(iVar3 + 4) = uVar2;
      iVar3 = iVar4;
      sub_F00515C0(iVar4,param_2,0,0);
      if ((*(word *)(iVar4 + 0x44) & 0x46) != 0) {
        *(word *)(iVar4 + 0x44) = *(word *)(iVar4 + 0x44) | 8;
        param_2 = DAT_f0135000;
        _microtime(&_iuniqtime);
        if ((*(word *)(iVar4 + 0x44) & 4) != 0) {
          *(undefined4 *)(iVar4 + 0x74) = _iuniqtime;
        }
        if ((*(word *)(iVar4 + 0x44) & 2) != 0) {
          *(undefined4 *)(iVar4 + 0x7c) = _iuniqtime;
        }
        if ((*(word *)(iVar4 + 0x44) & 0x40) == 0) {
          wVar1 = *(word *)(iVar4 + 0x44);
        }
        else {
          *(undefined4 *)(iVar4 + 0x4c) = 0;
          *(undefined4 *)(iVar4 + 0x84) = _iuniqtime;
          wVar1 = *(word *)(iVar4 + 0x44);
        }
        *(word *)(iVar4 + 0x44) = wVar1 & 0xffb9;
      }
      goto locret_F0052E7C;
    }
  }
  iVar3 = 0x16;
locret_F0052E7C:
  return CONCAT44(param_2,iVar3);
}

