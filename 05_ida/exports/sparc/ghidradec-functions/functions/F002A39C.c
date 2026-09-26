
/* WARNING: Removing unreachable block (ram,0xf002a4c8) */
/* WARNING: Removing unreachable block (ram,0xf002a49c) */
/* WARNING: Removing unreachable block (ram,0xf002a480) */
/* WARNING: Removing unreachable block (ram,0xf002a458) */
/* WARNING: Removing unreachable block (ram,0xf002a440) */
/* WARNING: Removing unreachable block (ram,0xf002a42c) */
/* WARNING: Removing unreachable block (ram,0xf002a3fc) */
/* WARNING: Removing unreachable block (ram,0xf002a3d8) */
/* WARNING: Removing unreachable block (ram,0xf002a3b4) */
/* WARNING: Removing unreachable block (ram,0xf002a3e8) */
/* WARNING: Removing unreachable block (ram,0xf002a420) */
/* WARNING: Removing unreachable block (ram,0xf002a438) */
/* WARNING: Removing unreachable block (ram,0xf002a448) */
/* WARNING: Removing unreachable block (ram,0xf002a470) */
/* WARNING: Removing unreachable block (ram,0xf002a494) */
/* WARNING: Removing unreachable block (ram,0xf002a4b0) */
/* WARNING: Removing unreachable block (ram,0xf002a534) */
/* WARNING: Removing unreachable block (ram,0xf002a3a0) */

undefined8 sub_F002A39C(uint param_1,int param_2,sword *param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
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
  uVar4 = param_1;
  _if_private();
  uVar4 = *(uint *)(uVar4 + 0xc);
  iVar2 = param_2;
  _strcmp(param_2,_IFCONTROL_AUTOADDR);
  if (iVar2 == 0) {
    if (*param_3 == 2) {
      uVar4 = param_1;
      _if_private(param_1);
      _in_bootp(param_1,param_3,uVar4);
    }
    else {
      param_1 = 0x2f;
    }
  }
  else {
    iVar2 = param_2;
    _strcmp(param_2,&_IFCONTROL_SETADDR);
    if (iVar2 == 0) {
      iVar2 = (int)*param_3;
      if (iVar2 == 2) {
        _spltty();
        uVar3 = param_1;
        _if_flags(param_1);
        _if_flags_set(param_1,uVar3 | 0x41);
        _if_init(uVar4);
        uVar4 = param_1;
        _if_private();
        *(undefined4 *)(uVar4 + 8) = *(undefined4 *)(param_3 + 2);
        uVar4 = param_1;
        _if_flags();
        if ((uVar4 & 0x4000) == 0) {
          uVar4 = param_1;
          _if_private();
          *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(uVar4 + 8);
          uVar4 = param_1;
          _if_private(param_1);
          _arpwhohas(param_1,uVar4,(undefined *)((int)register0x00000038 + -0xc),param_3 + 2);
        }
        _splx(iVar2);
        param_1 = 0;
        param_2 = iVar2;
      }
      else {
        param_1 = 0x2f;
      }
    }
    else {
      iVar2 = param_2;
      _strcmp(param_2,_IFCONTROL_ADDMULTICAST);
      if ((iVar2 == 0) || (iVar2 = param_2, _strcmp(param_2,_IFCONTROL_RMVMULTICAST), iVar2 == 0)) {
        param_1 = 0x2f;
        if (param_3[8] != 2) goto locret_F002A540;
        *(undefined *)((int)register0x00000038 + -0x18) = 1;
        *(undefined *)((int)register0x00000038 + -0x17) = 0;
        *(undefined *)((int)register0x00000038 + -0x16) = 0x5e;
        *(byte *)((int)register0x00000038 + -0x15) = *(byte *)((int)param_3 + 0x15) & 0x7f;
        *(undefined *)((int)register0x00000038 + -0x14) = *(undefined *)(param_3 + 0xb);
        puVar1 = (undefined *)((int)param_3 + 0x17);
        param_3 = (sword *)((int)register0x00000038 + -0x18);
        *(undefined *)((int)register0x00000038 + -0x13) = *puVar1;
      }
      _if_control(uVar4,param_2,param_3);
      param_1 = uVar4;
    }
  }
locret_F002A540:
  return CONCAT44(param_2,param_1);
}
