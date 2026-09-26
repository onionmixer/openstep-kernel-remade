
/* WARNING: Removing unreachable block (ram,0xf0094398) */
/* WARNING: Removing unreachable block (ram,0xf0094320) */

undefined8
_kdp_exception(undefined4 param_1,uint *param_2,undefined2 *param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

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
  _bcopy(param_1,(undefined4 *)((int)register0x00000038 + -0x18),0xc);
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(undefined4 *)((int)register0x00000038 + -8) = param_4;
  *(undefined4 *)((int)register0x00000038 + -4) = param_5;
  *(undefined4 *)register0x00000038 = param_6;
  *(uint *)((int)register0x00000038 + -0x18) =
       *(uint *)((int)register0x00000038 + -0x18) & 0xffffff | 0x1a000000;
  *(undefined *)((int)register0x00000038 + -0x17) = byte_F013C416;
  *(undefined2 *)((int)register0x00000038 + -0x16) = 0xc;
  *(undefined2 *)((int)register0x00000038 + -0x16) = 0x1c;
  _bcopy((undefined4 *)((int)register0x00000038 + -0x18),param_1,
         *(uint *)((int)register0x00000038 + -0x18) & 0xffff);
  uRamf013c418 = 1;
  *param_3 = DAT_f013c414;
  *param_2 = *(uint *)((int)register0x00000038 + -0x18) & 0xffff;
  return CONCAT44(param_2,param_1);
}

