
/* WARNING: Removing unreachable block (ram,0xf002ac20) */
/* WARNING: Removing unreachable block (ram,0xf002acec) */
/* WARNING: Removing unreachable block (ram,0xf002acc4) */
/* WARNING: Removing unreachable block (ram,0xf002acac) */
/* WARNING: Removing unreachable block (ram,0xf002ac8c) */
/* WARNING: Removing unreachable block (ram,0xf002ac70) */
/* WARNING: Removing unreachable block (ram,0xf002ac44) */
/* WARNING: Removing unreachable block (ram,0xf002abfc) */
/* WARNING: Removing unreachable block (ram,0xf002ad14) */
/* WARNING: Removing unreachable block (ram,0xf002ac84) */
/* WARNING: Removing unreachable block (ram,0xf002aca0) */
/* WARNING: Removing unreachable block (ram,0xf002acb4) */
/* WARNING: Removing unreachable block (ram,0xf002acdc) */
/* WARNING: Removing unreachable block (ram,0xf002ad00) */
/* WARNING: Removing unreachable block (ram,0xf002ac30) */
/* WARNING: Removing unreachable block (ram,0xf002abe8) */

undefined8 sub_F002ABE4(uint param_1,int param_2,sword *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
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
  uVar3 = param_1;
  _if_private();
  uVar3 = *(uint *)(uVar3 + 0x14);
  iVar1 = param_2;
  _strcmp(param_2,_IFCONTROL_AUTOADDR);
  if (iVar1 == 0) {
    if (*param_3 == 2) {
      uVar3 = param_1;
      _if_private(param_1);
      _in_bootp(param_1,param_3,uVar3 + 8);
      uVar3 = param_1;
    }
    else {
      uVar3 = 0x2f;
    }
  }
  else {
    iVar1 = param_2;
    _strcmp(param_2,&_IFCONTROL_SETADDR);
    if (iVar1 == 0) {
      if (*param_3 == 2) {
        uVar2 = param_1;
        _if_flags(param_1);
        _if_flags_set(param_1,uVar2 | 0x8001);
        _if_init();
        if (uVar3 == 0) {
          uVar3 = param_1;
          _if_flags(param_1);
          _if_flags_set(param_1,uVar3 | 0x40);
        }
        uVar3 = param_1;
        _if_private();
        *(undefined4 *)(uVar3 + 0x10) = *(undefined4 *)(param_3 + 2);
        uVar3 = param_1;
        _if_flags();
        if ((uVar3 & 0x4000) == 0) {
          uVar3 = param_1;
          _if_private();
          *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(uVar3 + 0x10);
          uVar3 = param_1;
          _if_private(param_1);
          _arpwhohas(param_1,uVar3 + 8,(undefined *)((int)register0x00000038 + -0xc),param_3 + 2);
          uVar3 = 0;
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0x2f;
      }
    }
    else {
      _if_control(uVar3,param_2,param_3);
    }
  }
  return CONCAT44(param_2,uVar3);
}
