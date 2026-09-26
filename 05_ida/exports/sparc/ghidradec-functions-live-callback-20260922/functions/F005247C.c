
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

