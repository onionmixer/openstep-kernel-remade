
/* WARNING: Removing unreachable block (ram,0xf0053038) */

undefined8
_rdwri(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
      undefined4 param_6)

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
  undefined4 *puVar1;
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
  *(qword *)((int)register0x00000038 + -0x28) = CONCAT44(param_3,param_4);
  *(undefined **)((int)register0x00000038 + -0x20) = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 1;
  *(qword *)((int)register0x00000038 + -0x18) = CONCAT44(param_5,param_6);
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_4;
  param_2 = param_2 + 0xc;
  puVar1 = *(undefined4 **)((int)register0x00000038 + 0x5c);
  sub_F0051444(param_2,(undefined *)((int)register0x00000038 + -0x20),param_1,0,
               *(undefined4 *)(_active_u + 0x1c));
  if (puVar1 == (undefined4 *)0x0) {
    if (*(int *)((int)register0x00000038 + -0xc) != 0) {
      param_2 = 5;
    }
  }
  else {
    *puVar1 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(puVar1,param_2);
}

