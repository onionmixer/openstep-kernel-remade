
/* WARNING: Removing unreachable block (ram,0xf00bbb7c) */
/* WARNING: Removing unreachable block (ram,0xf00bbb0c) */
/* WARNING: Removing unreachable block (ram,0xf00bbac4) */
/* WARNING: Removing unreachable block (ram,0xf00bba90) */
/* WARNING: Removing unreachable block (ram,0xf00bbb44) */
/* WARNING: Removing unreachable block (ram,0xf00bbaa4) */
/* WARNING: Removing unreachable block (ram,0xf00bbafc) */
/* WARNING: Removing unreachable block (ram,0xf00bbad8) */
/* WARNING: Removing unreachable block (ram,0xf00bbc14) */
/* WARNING: Removing unreachable block (ram,0xf00bbb98) */

undefined8 _kmioctl(undefined4 param_1,uint param_2,undefined4 *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined (*pauVar3) [12];
  undefined (*pauVar4) [14];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  
  iVar2 = _cons_tp;
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
  if (param_2 == 0x20006b02) {
    _basicConsoleMode = 1;
    (**(code **)(_basicConsole + 4))(_basicConsole,1,1,1,_mach_title);
    iVar5 = 0;
    goto locret_F00BBC2C;
  }
  iVar5 = _kmId;
  if ((int)param_2 < 0x20006b03) {
    if (param_2 == 0x80087467) {
      iVar5 = 0x16;
      goto locret_F00BBC2C;
    }
    if ((int)param_2 < -0x7ff78b98) {
      if (param_2 == 0x80046b09) {
        param_3 = (undefined4 *)*param_3;
        pauVar4 = paAnimationctl;
loc_F00BBB7C:
        _objc_msgSend(_kmId,pauVar4,param_3);
        goto locret_F00BBC2C;
      }
    }
    else {
      if (param_2 == 0x800c6b05) {
        uVar1 = (uint)(*(word *)(param_3 + 1) >> 2);
        umul(uVar1,*(undefined2 *)((int)param_3 + 6));
        iVar5 = 0;
        if (-1 < (int)uVar1) {
          param_2 = uVar1;
          _kalloc();
          if (param_2 == 0) {
            iVar5 = -1;
          }
          else {
            iVar2 = param_3[2];
            _copyin(iVar2,param_2,uVar1);
            if (iVar2 == 0) {
              param_3[2] = param_2;
              iVar5 = _kmId;
              _objc_msgSend(_kmId,paDrawrect,param_3);
              _kfree(param_2,uVar1);
            }
            else {
              _kfree(param_2,uVar1);
              iVar5 = -1;
            }
          }
        }
        goto locret_F00BBC2C;
      }
      pauVar4 = (undefined (*) [14])paEraserect;
      if (param_2 == 0x800c6b06) goto loc_F00BBB7C;
    }
  }
  else {
    pauVar3 = paDisablecons;
    if (param_2 == 0x20006b08) {
loc_F00BBB44:
      _objc_msgSend(_kmId,pauVar3);
      goto locret_F00BBC2C;
    }
    if ((int)param_2 < 0x20006b09) {
      pauVar3 = (undefined (*) [12])paDumpmsgbuf;
      if (param_2 == 0x20006b03) goto loc_F00BBB44;
    }
    else {
      pauVar4 = (undefined (*) [14])paGetstatus;
      if (param_2 == 0x40046b0a) goto loc_F00BBB7C;
      if (param_2 == 0x40086b0b) {
        _objc_msgSend(_kmId,paGetscreensize,(undefined *)((int)register0x00000038 + -0x10));
        *(undefined2 *)param_3 = *(undefined2 *)((int)register0x00000038 + -0x10);
        *(undefined2 *)((int)param_3 + 2) = *(undefined2 *)((int)register0x00000038 + -0xe);
        *(undefined2 *)(param_3 + 1) = *(undefined2 *)((int)register0x00000038 + -0xc);
        iVar5 = 0;
        *(undefined2 *)((int)param_3 + 6) = *(undefined2 *)((int)register0x00000038 + -10);
        goto locret_F00BBC2C;
      }
    }
  }
  iVar5 = _cons_tp;
  (**(code **)(DAT_f010b8dc + *(char *)(_cons_tp + 0x47) * 0x30))(_cons_tp,param_2,param_3,param_4);
  if ((iVar5 < 0) && (_ttioctl(iVar2,param_2,param_3,param_4), iVar5 = iVar2, iVar2 < 0)) {
    iVar5 = 0x19;
  }
locret_F00BBC2C:
  return CONCAT44(param_2,iVar5);
}

