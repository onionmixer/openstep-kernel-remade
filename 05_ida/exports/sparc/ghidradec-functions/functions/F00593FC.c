
/* WARNING: Removing unreachable block (ram,0xf0059420) */
/* WARNING: Removing unreachable block (ram,0xf00594a4) */
/* WARNING: Removing unreachable block (ram,0xf0059428) */
/* WARNING: Removing unreachable block (ram,0xf0059400) */

undefined8 _ipc_notify_port_deleted_compat(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = 0x34;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aDroppedPortDel_0,param_1,param_2);
    _ipc_port_release_send(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_port_deleted_template;
    *(undefined4 *)(iVar1 + 0x18) = DAT_f013bfd4._0_4_;
    *(undefined4 *)(iVar1 + 0x1c) = DAT_f013bfd4._4_4_;
    *(undefined4 *)(iVar1 + 0x20) = DAT_f013bfd4._8_4_;
    *(undefined4 *)(iVar1 + 0x24) = DAT_f013bfd4._12_4_;
    *(undefined4 *)(iVar1 + 0x28) = DAT_f013bfd4._16_4_;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_f013bfd4._20_4_;
    *(undefined4 *)(iVar1 + 0x30) = DAT_f013bfd4._24_4_;
    *(undefined4 *)(iVar1 + 0x14) = 0x11;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return CONCAT44(param_2,param_1);
}
