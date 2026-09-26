
/* WARNING: Removing unreachable block (ram,0xf00570cc) */
/* WARNING: Removing unreachable block (ram,0xf0057110) */
/* WARNING: Removing unreachable block (ram,0xf00570b4) */

undefined8 _ipc_kmsg_copyout_pseudo(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 unaff_l3;
  uint uVar4;
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
  uVar2 = *(uint *)(param_1 + 0x14);
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  uVar4 = param_2;
  _ipc_kmsg_copyout_object
            (param_2,*(undefined4 *)(param_1 + 0x1c),uVar2 & 0xff,
             (undefined *)((int)register0x00000038 + -0xc));
  uVar1 = param_2;
  _ipc_kmsg_copyout_object
            (param_2,uVar3,(uVar2 & 0xff00) >> 8,(undefined *)((int)register0x00000038 + -0x10));
  uVar4 = uVar4 | uVar1;
  *(uint *)(param_1 + 0x14) = uVar2 & 0xbfffffff;
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)((int)register0x00000038 + -0xc);
  *(undefined4 *)(param_1 + 0x20) = uVar3;
  if ((int)uVar2 < 0) {
    uVar1 = param_1 + 0x2c;
    _ipc_kmsg_copyout_body(uVar1,param_1 + *(int *)(param_1 + 0x18) + 0x14,param_2,param_3);
    uVar4 = uVar4 | uVar1;
  }
  return CONCAT44(param_2,uVar4);
}

