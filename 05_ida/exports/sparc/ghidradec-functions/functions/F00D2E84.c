
/* WARNING: Removing unreachable block (ram,0xf00d2eb4) */
/* WARNING: Removing unreachable block (ram,0xf00d2ecc) */
/* WARNING: Removing unreachable block (ram,0xf00d2ea8) */

undefined8 -[EventDriver setEventPort:](int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
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
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x144) = 0;
  }
  else {
    if (param_3 == *(int *)(param_1 + 0x114)) {
      iVar1 = *(int *)(param_1 + 0x14c);
      goto loc_F00D2EC0;
    }
    iVar1 = param_3;
    _IOGetKernPort();
    *(int *)(param_1 + 0x144) = iVar1;
    _port_request_notification();
  }
  iVar1 = *(int *)(param_1 + 0x14c);
loc_F00D2EC0:
  if (iVar1 == 0) {
    uVar2 = 0x1c;
    _IOMalloc();
    *(undefined4 *)(param_1 + 0x14c) = uVar2;
    *(int *)(param_1 + 0x114) = param_3;
  }
  else {
    *(int *)(param_1 + 0x114) = param_3;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x14c);
  *puVar3 = dword_F012EEE0;
  puVar3[1] = DAT_f012eee4._0_4_;
  puVar3[2] = DAT_f012eee4._4_4_;
  puVar3[3] = DAT_f012eee4._8_4_;
  puVar3[4] = DAT_f012eee4._12_4_;
  puVar3[5] = DAT_f012eee4._16_4_;
  puVar3[6] = DAT_f012eee4._20_4_;
  *(int *)(*(int *)(param_1 + 0x14c) + 0x10) = param_3;
  return CONCAT44(param_2,param_1);
}
