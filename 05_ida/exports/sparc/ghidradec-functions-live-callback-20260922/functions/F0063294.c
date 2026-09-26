
/* WARNING: Removing unreachable block (ram,0xf00632e4) */
/* WARNING: Removing unreachable block (ram,0xf0063310) */
/* WARNING: Removing unreachable block (ram,0xf00632c8) */

undefined8 _port_set_backup(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
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
  uint uVar2;
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
  if (param_1 == 0) {
    param_1 = 4;
  }
  else {
    if (param_3 == 0xffffffff) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      if (param_3 != 0) {
        uVar2 = param_3 | 1;
      }
    }
    _port_translate_compat(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      _ipc_port_pdrequest(*(undefined4 *)((int)register0x00000038 + -0xc),uVar2,
                          (undefined *)((int)register0x00000038 + -0x10));
      uVar2 = *(uint *)((int)register0x00000038 + -0x10);
      uVar1 = 0;
      if (uVar2 != 0) {
        if ((uVar2 & 1) == 0) {
          _ipc_notify_send_once();
          *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
        }
        else {
          *(uint *)((int)register0x00000038 + -0x10) = uVar2 & 0xfffffffe;
        }
        uVar1 = *(undefined4 *)((int)register0x00000038 + -0x10);
      }
      param_1 = 0;
      *param_4 = uVar1;
    }
  }
  return CONCAT44(param_2,param_1);
}

