
/* WARNING: Removing unreachable block (ram,0xf007bbd8) */

undefined8 _kern_serv_handler(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined *puVar1;
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
  *(undefined *)((int)register0x00000038 + -0x25) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0x20;
  *(undefined4 *)((int)register0x00000038 + -0x20) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x10);
  *(int *)((int)register0x00000038 + -0x14) = *(int *)(param_1 + 0x14) + 100;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0x2200018;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0xfffffed1;
  puVar1 = (undefined *)((int)register0x00000038 + -0x28);
  if ((*(int *)(param_1 + 0x14) - 100U < 0xd) &&
     (*(code **)(unk_F00F4C58 + *(int *)(param_1 + 0x14) * 4) != (code *)0x0)) {
    (**(code **)(unk_F00F4C58 + *(int *)(param_1 + 0x14) * 4))(param_1,puVar1,param_2);
    if (*(int *)((int)register0x00000038 + -0xc) == -0x131) {
      puVar1 = (undefined *)0x0;
    }
    else {
      _msg_send(puVar1,~*(uint *)(param_2 + 4) >> 0x1f);
    }
  }
  else {
    puVar1 = (undefined *)0xfffffed1;
  }
  return CONCAT44(param_2,puVar1);
}
