
/* WARNING: Removing unreachable block (ram,0xf0059fe0) */
/* WARNING: Removing unreachable block (ram,0xf005a02c) */
/* WARNING: Removing unreachable block (ram,0xf005a01c) */

undefined8 _ipc_object_copyout_dest(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
  undefined4 uVar4;
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
  uVar3 = 0;
  iVar1 = param_2[1];
  param_2[1] = iVar1 + -1;
  if (param_3 != 0x11) {
    if (param_3 == 0x12) {
      if (param_2[3] != param_1) {
        param_2[1] = iVar1;
        *param_2 = 0;
        _ipc_notify_send_once(param_2);
        *param_4 = 0;
        goto locret_F005A038;
      }
      *param_2 = 0;
      uVar3 = param_2[4];
      param_2[8] = param_2[8] + -1;
    }
    else {
      _panic(aIpcObjectCopyo_0);
    }
    *param_4 = uVar3;
    goto locret_F005A038;
  }
  iVar2 = 0;
  iVar1 = param_2[7];
  uVar3 = 0;
  param_2[7] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    iVar2 = param_2[9];
    if (iVar2 != 0) {
      param_2[9] = 0;
      uVar3 = param_2[6];
      goto loc_F0059FBC;
    }
    iVar1 = param_2[3];
  }
  else {
loc_F0059FBC:
    iVar1 = param_2[3];
  }
  uVar4 = 0;
  if (iVar1 == param_1) {
    uVar4 = param_2[4];
  }
  *param_2 = 0;
  if (iVar2 == 0) {
    *param_4 = uVar4;
  }
  else {
    _ipc_notify_no_senders(iVar2,uVar3);
    *param_4 = uVar4;
  }
locret_F005A038:
  return CONCAT44(param_2,param_1);
}
