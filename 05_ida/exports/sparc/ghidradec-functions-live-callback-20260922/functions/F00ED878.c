
/* WARNING: Removing unreachable block (ram,0xf00ed9c4) */
/* WARNING: Removing unreachable block (ram,0xf00ed998) */
/* WARNING: Removing unreachable block (ram,0xf00ed8a8) */
/* WARNING: Removing unreachable block (ram,0xf00ed928) */
/* WARNING: Removing unreachable block (ram,0xf00ed9b8) */
/* WARNING: Removing unreachable block (ram,0xf00ed9f8) */
/* WARNING: Removing unreachable block (ram,0xf00ed890) */

undefined8 _NXHashInsert(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int iVar3;
  int *piVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  int *piVar6;
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
  iVar1 = param_1[4];
  (**(code **)*param_1)(iVar1,param_2);
  urem();
  iVar1 = iVar1 * 8;
  iVar3 = param_1[3];
  piVar6 = (int *)(iVar1 + iVar3);
  iVar5 = *(int *)(iVar1 + iVar3);
  piVar2 = param_1;
  _NXZoneFromPtr();
  if (iVar5 == 0) {
    *(int *)(iVar1 + iVar3) = *(int *)(iVar1 + iVar3) + 1;
    piVar6[1] = param_2;
    param_1[1] = param_1[1] + 1;
  }
  else {
    if (iVar5 == 1) {
      if (param_2 == piVar6[1]) {
        iVar1 = piVar6[1];
      }
      else {
        iVar1 = param_1[4];
        (**(code **)(*param_1 + 4))(iVar1,param_2);
        if (iVar1 == 0) {
          _NXZoneCalloc(piVar2,2,4);
          piVar2[1] = piVar6[1];
          *piVar2 = param_2;
          goto loc_F00ED9CC;
        }
        iVar1 = piVar6[1];
      }
      piVar6[1] = param_2;
      goto locret_F00EDA04;
    }
    piVar4 = (int *)piVar6[1];
    while (iVar5 = iVar5 + -1, iVar5 != -1) {
      if (param_2 == *piVar4) {
        iVar1 = *piVar4;
loc_F00ED974:
        *piVar4 = param_2;
        goto locret_F00EDA04;
      }
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      if (iVar1 != 0) {
        iVar1 = *piVar4;
        goto loc_F00ED974;
      }
      piVar4 = piVar4 + 1;
    }
    _NXZoneCalloc(piVar2,*piVar6 + 1,4);
    if (*piVar6 != 0) {
      _memmove(piVar2 + 1,piVar6[1],*piVar6 << 2);
    }
    *piVar2 = param_2;
    _free(piVar6[1]);
loc_F00ED9CC:
    *piVar6 = *piVar6 + 1;
    piVar6[1] = (int)piVar2;
    iVar1 = param_1[1];
    param_1[1] = iVar1 + 1U;
    if (iVar1 + 1U <= (uint)param_1[2]) {
      iVar1 = 0;
      goto locret_F00EDA04;
    }
    sub_F00ED78C(param_1);
  }
  iVar1 = 0;
locret_F00EDA04:
  return CONCAT44(param_2,iVar1);
}

