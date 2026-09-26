
/* WARNING: Removing unreachable block (ram,0xf001846c) */
/* WARNING: Removing unreachable block (ram,0xf0018368) */
/* WARNING: Removing unreachable block (ram,0xf001832c) */
/* WARNING: Removing unreachable block (ram,0xf0018304) */
/* WARNING: Removing unreachable block (ram,0xf00182b4) */
/* WARNING: Removing unreachable block (ram,0xf00183e4) */
/* WARNING: Removing unreachable block (ram,0xf0018314) */
/* WARNING: Removing unreachable block (ram,0xf0018340) */
/* WARNING: Removing unreachable block (ram,0xf001844c) */
/* WARNING: Removing unreachable block (ram,0xf0018484) */
/* WARNING: Removing unreachable block (ram,0xf0018288) */
/* WARNING: Type propagation algorithm not settling */

undefined8 _ttyblkin(undefined *param_1,undefined *param_2,int *param_3)

{
  undefined uVar1;
  int *piVar2;
  undefined *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
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
  piVar2 = param_3;
  _ttynty();
  if ((piVar2[4] & 0x800U) == 0) goto locret_F001848C;
  if ((param_3[0xf] & 0x20000000U) != 0) {
    _ttypend(param_3);
  }
  _tk_nin = _tk_nin + (int)param_2;
  if ((param_3[0xf] & 0x20U) == 0) {
    param_2 = param_2 + -1;
    if ((int)param_2 < 0) {
      iVar5 = *param_3;
      goto loc_F00183FC;
    }
    uVar1 = *param_1;
    while( true ) {
      param_1 = param_1 + 1;
      _ttcooked(uVar1,piVar2);
      param_2 = param_2 + -1;
      if ((int)param_2 < 0) break;
      uVar1 = *param_1;
    }
loc_F00183F8:
    iVar5 = *param_3;
  }
  else {
    if (0x400 < (int)(param_2 + *param_3)) {
      param_2 = (undefined *)(0x400 - *param_3);
      if ((int)param_2 < 0) {
        param_2 = (undefined *)0x0;
      }
      _log(4,aTtyDRawInputOv_0,(int)*(sword *)(param_3 + 0xe));
    }
    puVar3 = param_1;
    _b_to_q(param_1,param_2,param_3);
    if (param_2 == puVar3 || (int)param_2 - (int)puVar3 < 0) {
      uVar6 = param_3[0xf];
    }
    else {
      piVar4 = piVar2;
      _ttcheckwakeup();
      if (piVar4 == (int *)0x0) {
        uVar6 = param_3[0xf];
      }
      else {
        _ttwakeup(param_3);
        uVar6 = param_3[0xf];
      }
    }
    param_3[0xf] = uVar6 & 0xff7fffff;
    if ((uVar6 & 8) != 0) {
      puVar3 = param_1;
      _b_to_q(param_1,param_2,param_3 + 6);
      _tk_nout = _tk_nout + (int)puVar3;
    }
    if ((piVar2[4] & 0x10U) == 0) goto loc_F00183F8;
    if ((param_3[0xf] & 0x40000000U) == 0) {
      uVar6 = param_3[0x10];
loc_F00183C4:
      param_3[0x10] = uVar6 & 0xfffffeff;
      goto loc_F00183F8;
    }
    if (*(char *)((int)param_3 + 0x52) == -1) {
      iVar5 = *param_3;
    }
    else {
      if (*(char *)((int)param_3 + 0x52) == *(char *)((int)param_3 + 0x51)) {
        uVar6 = param_3[0x10];
        goto loc_F00183C4;
      }
      iVar5 = *param_3;
    }
  }
loc_F00183FC:
  if ((0x1ff < iVar5 + param_3[3]) && (((param_3[0xf] & 0x22U) != 0 || (0 < param_3[3])))) {
    if ((param_3[0xf] & 1U) == 0) {
      uVar6 = param_3[0x10];
    }
    else if (*(char *)((int)param_3 + 0x52) == -1) {
      uVar6 = param_3[0x10];
    }
    else {
      iVar5 = (int)*(char *)((int)param_3 + 0x52);
      _putc(iVar5,param_3 + 6);
      if (iVar5 == 0) {
        param_3[0x10] = param_3[0x10] | 0x400;
        _ttstart(param_3);
        uVar6 = param_3[0x10];
      }
      else {
        uVar6 = param_3[0x10];
      }
    }
    param_3[0x10] = uVar6 | 0x800000;
  }
  _ttstart(param_3);
locret_F001848C:
  return CONCAT44(param_2,param_1);
}
