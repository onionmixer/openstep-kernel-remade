
/* WARNING: Removing unreachable block (ram,0xf007b350) */
/* WARNING: Removing unreachable block (ram,0xf007b33c) */

undefined8 _port_request_notification(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  *(undefined4 *)((int)register0x00000038 + -0x38) = dword_F0110E44;
  *(undefined4 *)((int)register0x00000038 + -0x34) = DAT_f0110e48._0_4_;
  *(undefined4 *)((int)register0x00000038 + -0x30) = DAT_f0110e48._4_4_;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = DAT_f0110e48._8_4_;
  *(undefined4 *)((int)register0x00000038 + -0x28) = DAT_f0110e48._12_4_;
  *(undefined4 *)((int)register0x00000038 + -0x24) = DAT_f0110e48._16_4_;
  *(undefined4 *)((int)register0x00000038 + -0x20) = DAT_f0110e48._20_4_;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = DAT_f0110e48._24_4_;
  puVar1 = (undefined *)((int)register0x00000038 + -0x38);
  *(undefined4 *)((int)register0x00000038 + -0x18) = DAT_f0110e48._28_4_;
  *(undefined4 *)((int)register0x00000038 + -0x14) = DAT_f0110e48._32_4_;
  *(undefined4 *)((int)register0x00000038 + -0x10) = DAT_f0110e48._36_4_;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x28) = _pn_register_port_k;
  _msg_send_from_kernel(puVar1,1,0);
  if (puVar1 != (undefined *)0x0) {
    _printf(aPortRequestNot,puVar1);
  }
  return CONCAT44(param_2,param_1);
}
