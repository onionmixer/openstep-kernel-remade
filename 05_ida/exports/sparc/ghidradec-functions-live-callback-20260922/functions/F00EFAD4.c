
/* WARNING: Removing unreachable block (ram,0xf00efb34) */
/* WARNING: Removing unreachable block (ram,0xf00efb08) */
/* WARNING: Removing unreachable block (ram,0xf00efb90) */
/* WARNING: Removing unreachable block (ram,0xf00efaf0) */

undefined8 __class_install_relationships(undefined4 *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int *piVar4;
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
  piVar4 = (int *)*param_1;
  piVar4[3] = param_2;
  iVar2 = param_1[1];
  bVar1 = false;
  if (iVar2 != 0) {
    _objc_getClass();
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      param_1[1] = iVar2;
    }
  }
  piVar3 = (int *)*piVar4;
  _objc_getClass();
  if (piVar3 == (int *)0x0) {
    bVar1 = true;
  }
  else {
    *piVar4 = *piVar3;
  }
  piVar3 = (int *)piVar4[1];
  if (piVar3 == (int *)0x0) {
    piVar4[1] = (int)param_1;
  }
  else {
    _objc_getClass();
    if (piVar3 == (int *)0x0) {
      bVar1 = true;
    }
    else {
      piVar4[1] = *piVar3;
    }
  }
  if (param_1[8] == 0) {
    param_1[8] = _emptyCache;
    iVar2 = piVar4[8];
  }
  else {
    iVar2 = piVar4[8];
  }
  if (iVar2 == 0) {
    piVar4[8] = (int)_emptyCache;
  }
  if (bVar1) {
    __objc_fatal(aPleaseLinkAppr);
  }
  return CONCAT44(param_2,param_1);
}

