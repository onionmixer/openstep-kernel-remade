
/* WARNING: Removing unreachable block (ram,0xf002d4bc) */
/* WARNING: Removing unreachable block (ram,0xf002d42c) */

undefined8 _rtinit(undefined2 *param_1,undefined2 *param_2,undefined4 param_3,undefined2 param_4)

{
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
  _bzero((undefined *)((int)register0x00000038 + -0x38),0x30);
  *(undefined2 *)((int)register0x00000038 + -0x34) = *param_1;
  *(undefined2 *)((int)register0x00000038 + -0x32) = param_1[1];
  *(undefined2 *)((int)register0x00000038 + -0x30) = param_1[2];
  *(undefined2 *)((int)register0x00000038 + -0x2e) = param_1[3];
  *(undefined2 *)((int)register0x00000038 + -0x2c) = param_1[4];
  *(undefined2 *)((int)register0x00000038 + -0x2a) = param_1[5];
  *(undefined2 *)((int)register0x00000038 + -0x28) = param_1[6];
  *(undefined2 *)((int)register0x00000038 + -0x26) = param_1[7];
  *(undefined2 *)((int)register0x00000038 + -0x24) = *param_2;
  *(undefined2 *)((int)register0x00000038 + -0x22) = param_2[1];
  *(undefined2 *)((int)register0x00000038 + -0x20) = param_2[2];
  *(undefined2 *)((int)register0x00000038 + -0x1e) = param_2[3];
  *(undefined2 *)((int)register0x00000038 + -0x1c) = param_2[4];
  *(undefined2 *)((int)register0x00000038 + -0x1a) = param_2[5];
  *(undefined2 *)((int)register0x00000038 + -0x18) = param_2[6];
  *(undefined2 *)((int)register0x00000038 + -0x16) = param_2[7];
  *(undefined2 *)((int)register0x00000038 + -0x14) = param_4;
  _rtrequest(param_3,(undefined *)((int)register0x00000038 + -0x38));
  return CONCAT44(param_2,param_1);
}

