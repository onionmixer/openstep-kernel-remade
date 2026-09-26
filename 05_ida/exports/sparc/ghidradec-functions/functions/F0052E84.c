
/* WARNING: Removing unreachable block (ram,0xf0052f5c) */
/* WARNING: Removing unreachable block (ram,0xf0052f44) */
/* WARNING: Removing unreachable block (ram,0xf0052ec8) */
/* WARNING: Removing unreachable block (ram,0xf0052ef8) */
/* WARNING: Removing unreachable block (ram,0xf0052f80) */
/* WARNING: Removing unreachable block (ram,0xf0052eb4) */

undefined8 sub_F0052E84(int param_1,undefined *param_2,undefined4 *param_3,undefined *param_4)

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
  *param_3 = 5;
  *(undefined2 *)(param_3 + 0xe) = 0;
  iVar1 = *(int *)(param_1 + 0x30);
  _direnter(iVar1,param_2,0,0,0,param_3,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    param_2 = param_4;
    _strlen();
    if ((param_2 < (undefined *)0x3c) && (_dosymlink != 0)) {
      _bcopy(param_4,*(int *)((int)register0x00000038 + -0xc) + 0x8c,param_2);
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      *(uint *)(iVar2 + 200) = *(uint *)(iVar2 + 200) | 1;
      *(undefined **)(*(int *)(iVar2 + 0xc) + 0x14) = param_2;
      *(undefined **)(iVar2 + 0x70) = param_2;
      *(word *)(iVar2 + 0x44) = *(word *)(iVar2 + 0x44) | 0x42;
    }
    else {
      iVar1 = 1;
      _rdwri(1,*(undefined4 *)((int)register0x00000038 + -0xc),param_4,param_2,0,1,0);
    }
  }
  else if (iVar1 != 0x11) {
    iVar2 = *(int *)(param_1 + 0x30);
    goto loc_F0052F68;
  }
  _iput(*(undefined4 *)((int)register0x00000038 + -0xc));
  iVar2 = *(int *)(param_1 + 0x30);
loc_F0052F68:
  if ((*(word *)(iVar2 + 0x44) & 0x46) != 0) {
    *(word *)(iVar2 + 0x44) = *(word *)(iVar2 + 0x44) | 8;
    param_2 = DAT_f0135000;
    _microtime(&_iuniqtime);
    iVar2 = *(int *)(param_1 + 0x30);
    if ((*(word *)(iVar2 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar2 + 0x74) = _iuniqtime;
      iVar2 = *(int *)(param_1 + 0x30);
    }
    if ((*(word *)(iVar2 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar2 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(*(int *)(param_1 + 0x30) + 0x44) & 0x40) == 0) {
      iVar2 = *(int *)(param_1 + 0x30);
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x4c) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x84) = _iuniqtime;
      iVar2 = *(int *)(param_1 + 0x30);
    }
    *(word *)(iVar2 + 0x44) = *(word *)(iVar2 + 0x44) & 0xffb9;
  }
  return CONCAT44(param_2,iVar1);
}
