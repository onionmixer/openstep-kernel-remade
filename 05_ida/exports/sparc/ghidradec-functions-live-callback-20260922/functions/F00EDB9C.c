
/* WARNING: Removing unreachable block (ram,0xf00edd9c) */
/* WARNING: Removing unreachable block (ram,0xf00edd64) */
/* WARNING: Removing unreachable block (ram,0xf00edbcc) */
/* WARNING: Removing unreachable block (ram,0xf00edd30) */
/* WARNING: Removing unreachable block (ram,0xf00edd94) */
/* WARNING: Removing unreachable block (ram,0xf00edcc4) */
/* WARNING: Removing unreachable block (ram,0xf00edbb4) */

undefined8 _NXHashRemove(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar6;
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
  iVar1 = param_1[4];
  (**(code **)*param_1)(iVar1,param_2);
  urem();
  piVar5 = (int *)(iVar1 * 8 + param_1[3]);
  iVar1 = *(int *)(iVar1 * 8 + param_1[3]);
  piVar4 = param_1;
  _NXZoneFromPtr();
  if (iVar1 == 0) {
loc_F00EDDD8:
    iVar6 = 0;
    goto locret_F00EDDDC;
  }
  if (iVar1 == 1) {
    if (param_2 == piVar5[1]) {
      iVar6 = piVar5[1];
    }
    else {
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      if (iVar1 == 0) {
        iVar6 = 0;
        goto locret_F00EDDDC;
      }
      iVar6 = piVar5[1];
    }
    param_1[1] = param_1[1] + -1;
    *piVar5 = *piVar5 + -1;
    piVar5[1] = 0;
    param_2 = iVar6;
    goto locret_F00EDDDC;
  }
  piVar3 = (int *)piVar5[1];
  if (iVar1 != 2) {
    while (iVar1 = iVar1 + -1, iVar1 != -1) {
      if (param_2 == *piVar3) {
        iVar2 = *piVar5;
loc_F00EDD1C:
        iVar6 = *piVar3;
        if (iVar2 == 1) {
          piVar4 = (int *)0x0;
        }
        else {
          _NXZoneCalloc(piVar4,iVar2 + -1,4);
        }
        if (*piVar5 + -1 != iVar1) {
          _memmove(piVar4,piVar5[1],((*piVar5 - iVar1) + -1) * 4);
        }
        if (iVar1 != 0) {
          _memmove(piVar4 + *piVar5 + (-1 - iVar1),*piVar5 * 4 + piVar5[1] + iVar1 * -4);
        }
        _free(piVar5[1]);
        param_1[1] = param_1[1] + -1;
        *piVar5 = *piVar5 + -1;
        piVar5[1] = (int)piVar4;
        param_2 = iVar6;
        goto locret_F00EDDDC;
      }
      iVar6 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar6,param_2);
      if (iVar6 != 0) {
        iVar2 = *piVar5;
        goto loc_F00EDD1C;
      }
      piVar3 = piVar3 + 1;
    }
    goto loc_F00EDDD8;
  }
  if (param_2 == *piVar3) {
    iVar1 = piVar3[1];
loc_F00EDC80:
    piVar5[1] = iVar1;
    iVar6 = *piVar3;
  }
  else {
    iVar1 = param_1[4];
    (**(code **)(*param_1 + 4))(iVar1,param_2);
    if (iVar1 != 0) {
      iVar1 = piVar3[1];
      goto loc_F00EDC80;
    }
    if (param_2 == piVar3[1]) {
      iVar1 = *piVar3;
    }
    else {
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      if (iVar1 == 0) {
        iVar6 = 0;
        goto locret_F00EDDDC;
      }
      iVar1 = *piVar3;
    }
    piVar5[1] = iVar1;
    iVar6 = piVar3[1];
  }
  _free(piVar3);
  param_1[1] = param_1[1] + -1;
  *piVar5 = *piVar5 + -1;
  param_2 = iVar6;
locret_F00EDDDC:
  return CONCAT44(param_2,iVar6);
}

