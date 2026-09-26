
/* WARNING: Removing unreachable block (ram,0xf002bd44) */

undefined8 _if_ioctl(int param_1,uint param_2,undefined *param_3)

{
  undefined *puVar1;
  code *pcVar2;
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
  pcVar2 = *(code **)(param_1 + 0x38);
  if (pcVar2 == (code *)0x0) {
    param_1 = 6;
    goto locret_F002BD84;
  }
  if (param_2 == 0x80206931) {
    _if_control(param_1,_IFCONTROL_ADDMULTICAST);
    goto locret_F002BD84;
  }
  if (param_2 < 0x80206932) {
    if (param_2 == 0x8020690c) {
      puVar1 = (undefined *)&_IFCONTROL_SETADDR;
    }
    else {
      if (param_2 != 0x80206910) {
        *(uint *)((int)register0x00000038 + -0x10) = param_2;
        goto loc_F002BD60;
      }
      puVar1 = _IFCONTROL_SETFLAGS;
      param_3 = param_3 + 0x10;
    }
  }
  else if (param_2 == 0xc020690d) {
    puVar1 = (undefined *)&_IFCONTROL_GETADDR;
    param_3 = param_3 + 0x10;
  }
  else if (param_2 < 0xc020690e) {
    if (param_2 == 0x80206932) {
      puVar1 = _IFCONTROL_RMVMULTICAST;
    }
    else {
      *(uint *)((int)register0x00000038 + -0x10) = param_2;
loc_F002BD60:
      *(undefined **)((int)register0x00000038 + -0xc) = param_3;
      puVar1 = _IFCONTROL_UNIXIOCTL;
      pcVar2 = *(code **)(param_1 + 0x38);
      param_3 = (undefined *)((int)register0x00000038 + -0x10);
    }
  }
  else {
    if (param_2 != 0xc0206921) {
      *(uint *)((int)register0x00000038 + -0x10) = param_2;
      goto loc_F002BD60;
    }
    puVar1 = _IFCONTROL_AUTOADDR;
    param_3 = param_3 + 0x10;
  }
  (*pcVar2)(param_1,puVar1,param_3);
locret_F002BD84:
  return CONCAT44(param_2,param_1);
}
