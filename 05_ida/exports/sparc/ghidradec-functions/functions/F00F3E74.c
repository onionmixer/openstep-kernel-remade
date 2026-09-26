
/* WARNING: Removing unreachable block (ram,0xf00f3eb8) */
/* WARNING: Removing unreachable block (ram,0xf00f3e94) */

undefined8 _port_set_allocate_EXTERNAL(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
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
  *(undefined *)((int)register0x00000038 + -0x2d) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0x18;
  uVar1 = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x30);
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x820;
  uVar1 = 0;
  _msg_rpc(puVar2,0,0x28,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x1c) == 0x884) {
      if (((((*(int *)((int)register0x00000038 + -0x2c) == 0x28) &&
            (*(char *)((int)register0x00000038 + -0x2d) == '\x01')) ||
           ((puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x2c) == 0x20 &&
            ((*(char *)((int)register0x00000038 + -0x2d) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x14) != 0)))))) &&
          (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x18) == 0x2200018)
          ) && ((puVar2 = *(undefined **)((int)register0x00000038 + -0x14),
                puVar2 == (undefined *)0x0 &&
                (puVar2 = (undefined *)0xfffffed4,
                *(int *)((int)register0x00000038 + -0x10) == 0x2200018)))) {
        *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
        puVar2 = *(undefined **)((int)register0x00000038 + -0x14);
      }
    }
    else {
      puVar2 = (undefined *)0xfffffed3;
    }
  }
  else if (puVar2 == (undefined *)0xffffff36) {
    _mig_dealloc_reply_port();
    return CONCAT44(uVar1,puVar2);
  }
  return CONCAT44(param_2,puVar2);
}
