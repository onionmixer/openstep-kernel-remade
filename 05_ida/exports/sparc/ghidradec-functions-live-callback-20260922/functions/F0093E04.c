
/* WARNING: Removing unreachable block (ram,0xf0093eac) */
/* WARNING: Removing unreachable block (ram,0xf0093e8c) */
/* WARNING: Removing unreachable block (ram,0xf0093ea4) */
/* WARNING: Removing unreachable block (ram,0xf0093ec0) */
/* WARNING: Removing unreachable block (ram,0xf0093e20) */

undefined8 _vol_panel_remove(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
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
  puVar3 = (undefined4 *)0x0;
  if (_panel_req_port != 0) {
    puVar3 = (undefined4 *)0x20;
    _kalloc();
    *puVar3 = dword_F0112630;
    puVar3[1] = DAT_f0112634._0_4_;
    puVar3[2] = DAT_f0112634._4_4_;
    puVar3[3] = DAT_f0112634._8_4_;
    puVar3[4] = DAT_f0112634._12_4_;
    puVar3[5] = DAT_f0112634._16_4_;
    puVar3[6] = DAT_f0112634._20_4_;
    puVar3[7] = DAT_f0112634._24_4_;
    uVar2 = dword_F0112518;
    puVar3[7] = param_1;
    iVar1 = _panel_req_port;
    puVar3[3] = uVar2;
    puVar3[4] = iVar1;
    _msg_send_from_kernel();
    if (puVar3 != (undefined4 *)0x0) {
      _printf(aVolPanelRemove,puVar3);
    }
  }
  sub_F0094054();
  if (param_1 != 0) {
    _kfree();
  }
  return CONCAT44(param_2,puVar3);
}

