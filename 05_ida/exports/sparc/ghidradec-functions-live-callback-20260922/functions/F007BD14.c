
/* WARNING: Removing unreachable block (ram,0xf007bd98) */
/* WARNING: Removing unreachable block (ram,0xf007bd54) */
/* WARNING: Removing unreachable block (ram,0xf007bd74) */
/* WARNING: Removing unreachable block (ram,0xf007bd34) */

undefined8
_kern_serv_section_by_name
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
          undefined4 *param_5)

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
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  puVar3 = (undefined *)((int)register0x00000038 + -0x48);
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0xc800018;
  _strncpy((undefined *)((int)register0x00000038 + -0x2c),param_2,0x10);
  *(undefined *)((int)register0x00000038 + -0x1d) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0xc800018;
  _strncpy((undefined *)((int)register0x00000038 + -0x18),param_3,0x10);
  *(undefined *)((int)register0x00000038 + -9) = 0;
  *(undefined *)((int)register0x00000038 + -0x45) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x44) = 0x40;
  uVar1 = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x40) = 0x100;
  *(undefined4 *)((int)register0x00000038 + -0x38) = param_1;
  _mig_get_reply_port();
  *(undefined4 *)((int)register0x00000038 + -0x3c) = uVar1;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0xc9;
  uVar1 = 0;
  puVar2 = puVar3;
  _msg_rpc(puVar3,0,0x30,0,0);
  if (puVar2 == (undefined *)0x0) {
    if (*(int *)((int)register0x00000038 + -0x34) == 0x12d) {
      if (((((*(int *)((int)register0x00000038 + -0x44) == 0x30) &&
            (*(char *)((int)register0x00000038 + -0x45) == '\x01')) ||
           ((puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x44) == 0x20 &&
            ((*(char *)((int)register0x00000038 + -0x45) == '\x01' &&
             (*(int *)((int)register0x00000038 + -0x2c) != 0)))))) &&
          (puVar2 = (undefined *)0xfffffed4, *(int *)((int)register0x00000038 + -0x30) == 0x2200018)
          ) && (((puVar2 = *(undefined **)((int)register0x00000038 + -0x2c),
                 puVar2 == (undefined *)0x0 &&
                 (puVar2 = (undefined *)0xfffffed4,
                 *(int *)((int)register0x00000038 + -0x28) == 0x2200018)) &&
                (*param_4 = *(undefined4 *)((int)register0x00000038 + -0x24),
                *(int *)((int)register0x00000038 + -0x20) == 0x2200018)))) {
        *param_5 = *(undefined4 *)((int)register0x00000038 + -0x1c);
        puVar2 = *(undefined **)((int)register0x00000038 + -0x2c);
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
  return CONCAT44(puVar3,puVar2);
}

