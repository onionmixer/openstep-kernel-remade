
/* WARNING: Removing unreachable block (ram,0xf00edb54) */
/* WARNING: Removing unreachable block (ram,0xf00edb28) */
/* WARNING: Removing unreachable block (ram,0xf00eda40) */
/* WARNING: Removing unreachable block (ram,0xf00edabc) */
/* WARNING: Removing unreachable block (ram,0xf00edb48) */
/* WARNING: Removing unreachable block (ram,0xf00edb88) */
/* WARNING: Removing unreachable block (ram,0xf00eda28) */

undefined8 _NXHashInsertIfAbsent(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int *piVar5;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
  int iVar7;
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
  iVar4 = param_1[3];
  piVar5 = (int *)(iVar1 + iVar4);
  iVar3 = *(int *)(iVar1 + iVar4);
  piVar2 = param_1;
  _NXZoneFromPtr();
  iVar7 = param_2;
  if (iVar3 == 0) {
    *(int *)(iVar1 + iVar4) = *(int *)(iVar1 + iVar4) + 1;
    piVar5[1] = param_2;
    param_1[1] = param_1[1] + 1;
    goto locret_F00EDB94;
  }
  if (iVar3 == 1) {
    if (param_2 == piVar5[1]) {
      iVar7 = piVar5[1];
      goto locret_F00EDB94;
    }
    iVar1 = param_1[4];
    (**(code **)(*param_1 + 4))(iVar1,param_2);
    if (iVar1 != 0) {
      iVar7 = piVar5[1];
      goto locret_F00EDB94;
    }
    _NXZoneCalloc(piVar2,2,4);
    piVar2[1] = piVar5[1];
    *piVar2 = param_2;
  }
  else {
    piVar6 = (int *)piVar5[1];
    while (iVar3 = iVar3 + -1, iVar3 != -1) {
      if (param_2 == *piVar6) {
        iVar7 = *piVar6;
        goto locret_F00EDB94;
      }
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      if (iVar1 != 0) {
        iVar7 = *piVar6;
        goto locret_F00EDB94;
      }
      piVar6 = piVar6 + 1;
    }
    _NXZoneCalloc(piVar2,*piVar5 + 1,4);
    if (*piVar5 != 0) {
      _memmove(piVar2 + 1,piVar5[1],*piVar5 << 2);
    }
    *piVar2 = param_2;
    _free(piVar5[1]);
  }
  *piVar5 = *piVar5 + 1;
  piVar5[1] = (int)piVar2;
  iVar1 = param_1[1];
  param_1[1] = iVar1 + 1U;
  if ((uint)param_1[2] < iVar1 + 1U) {
    sub_F00ED78C(param_1);
  }
locret_F00EDB94:
  return CONCAT44(param_2,iVar7);
}

