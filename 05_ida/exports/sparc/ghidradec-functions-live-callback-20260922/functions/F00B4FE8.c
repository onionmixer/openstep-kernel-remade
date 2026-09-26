
/* WARNING: Removing unreachable block (ram,0xf00b5088) */
/* WARNING: Removing unreachable block (ram,0xf00b50b0) */

undefined8 _esp_phasemanage(int param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
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
  undefined4 auStack_3c [15];
  
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
  *(code **)((int)register0x00000038 + -0x38) = _esp_handle_cmd_start;
  *(code **)((int)register0x00000038 + -0x34) = _esp_handle_cmd_done;
  *(code **)((int)register0x00000038 + -0x30) = _esp_handle_msg_out;
  *(code **)((int)register0x00000038 + -0x2c) = _esp_handle_msg_out_done;
  *(code **)((int)register0x00000038 + -0x28) = _esp_handle_msg_in;
  *(code **)((int)register0x00000038 + -0x24) = _esp_handle_more_msgin;
  *(code **)((int)register0x00000038 + -0x20) = _esp_handle_msg_in_done;
  *(code **)((int)register0x00000038 + -0x1c) = _esp_handle_clearing;
  *(code **)((int)register0x00000038 + -0x18) = _esp_handle_data;
  *(code **)((int)register0x00000038 + -0x14) = _esp_handle_data_done;
  *(code **)((int)register0x00000038 + -0x10) = _esp_handle_c_cmplt;
  bVar1 = *(byte *)(param_1 + 0x41);
  while( true ) {
    uVar2 = (uint)bVar1;
    iVar3 = param_1;
    if (uVar2 == 0x1a) {
      _esp_handle_unknown();
    }
    else if ((uVar2 == 0) || (0xb < uVar2)) {
      _esplog(param_1,3,aLostStateInPha);
      iVar3 = 7;
    }
    else {
      (**(code **)((int)register0x00000038 + uVar2 * 4 + -0x3c))();
    }
    if (iVar3 != 2) break;
    bVar1 = *(byte *)(param_1 + 0x41);
  }
  return CONCAT44(param_2,iVar3);
}

