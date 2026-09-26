
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
