
/* WARNING: Removing unreachable block (ram,0xf004c708) */
/* WARNING: Removing unreachable block (ram,0xf004c694) */
/* WARNING: Removing unreachable block (ram,0xf004c59c) */
/* WARNING: Removing unreachable block (ram,0xf004c570) */
/* WARNING: Removing unreachable block (ram,0xf004c670) */
/* WARNING: Removing unreachable block (ram,0xf004c6ac) */
/* WARNING: Removing unreachable block (ram,0xf004c6cc) */
/* WARNING: Removing unreachable block (ram,0xf004c558) */

undefined8 sub_F004C544(int param_1,int *param_2,int *param_3)

{
  sword sVar1;
  word wVar2;
  int iVar3;
  undefined2 uVar5;
  int iVar4;
  uint uVar6;
  undefined4 uVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  int iVar9;
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
  iVar9 = 0;
  if (param_3 == (int *)0x0) {
    _panic(aDirmakeinodeNo);
  }
  iVar8 = *param_3;
  if (iVar8 == 2) {
    uVar7 = *(undefined4 *)(param_1 + 0x50);
    _dirpref(uVar7);
  }
  else {
    uVar7 = *(undefined4 *)(param_1 + 0x48);
  }
  uVar6 = *(uint *)(_vttoif_tab + iVar8 * 4);
  wVar2 = *(word *)(param_3 + 1);
  iVar3 = param_1;
  _ialloc(param_1,uVar7,uVar6 | wVar2);
  if (iVar3 == 0) {
    iVar9 = (int)*(char *)(dword_F0133DDC + 0x38);
  }
  else {
    *(sword *)(iVar3 + 100) = (sword)(uVar6 | wVar2);
    *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 0x46;
    if ((iVar8 - 3U < 2) || (iVar8 == 9)) {
      sVar1 = *(sword *)(param_3 + 0xe);
      *(int *)(iVar3 + 0x8c) = (int)sVar1;
      *(sword *)(iVar3 + 0x38) = sVar1;
    }
    *(int *)(iVar3 + 0x34) = iVar8;
    if (iVar8 == 2) {
      uVar5 = 2;
    }
    else {
      uVar5 = 1;
    }
    *(undefined2 *)(iVar3 + 0x66) = uVar5;
    if (*(sword *)(*(int *)(iVar3 + 0x30) + 0x124) == 0) {
      *(undefined2 *)(iVar3 + 0x68) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
      uVar5 = *(undefined2 *)(param_1 + 0x6a);
    }
    else {
      *(undefined2 *)(iVar3 + 0xe4) = *(undefined2 *)(param_1 + 0xe4);
      *(undefined2 *)(iVar3 + 0xe6) = *(undefined2 *)(param_1 + 0xe6);
      uVar5 = _nogroup;
      *(undefined2 *)(iVar3 + 0x68) = *(undefined2 *)(*(int *)(iVar3 + 0x30) + 0x124);
    }
    *(undefined2 *)(iVar3 + 0x6a) = uVar5;
    if ((*(word *)(iVar3 + 100) & 0x400) != 0) {
      iVar4 = (int)*(sword *)(iVar3 + 0x6a);
      _groupmember();
      if (iVar4 == 0) {
        *(word *)(iVar3 + 100) = *(word *)(iVar3 + 100) & 0xfbff;
      }
    }
    _iupdat(iVar3,1);
    if (iVar8 == 2) {
      iVar9 = iVar3;
      sub_F004C720(iVar3,param_1);
    }
    if (iVar9 == 0) {
      wVar2 = *(word *)(iVar3 + 0x44);
      *(word *)(iVar3 + 0x44) = wVar2 & 0xfffe;
      if ((wVar2 & 0x10) != 0) {
        *(word *)(iVar3 + 0x44) = wVar2 & 0xffee;
        _wakeup(iVar3);
      }
      *param_2 = iVar3;
    }
    else {
      *(undefined2 *)(iVar3 + 0x66) = 0;
      *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 0x40;
      _iput();
    }
  }
  return CONCAT44(param_2,iVar9);
}

