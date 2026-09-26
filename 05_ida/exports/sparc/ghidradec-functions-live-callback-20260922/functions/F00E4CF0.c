
/* WARNING: Removing unreachable block (ram,0xf00e4d6c) */

undefined8
__NXAudioReplyStreamStatus
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

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
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x24) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_5;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_6;
  *(undefined *)((int)register0x00000038 + -0x45) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x44) = 0x40;
  *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0x6a4;
  *(undefined4 *)((int)register0x00000038 + -0x38) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0x6200018;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0x6200018;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0x2200018;
  puVar1 = (undefined *)((int)register0x00000038 + -0x48);
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x2200018;
  _msg_send(puVar1,0x21,1000);
  return CONCAT44(param_2,puVar1);
}

