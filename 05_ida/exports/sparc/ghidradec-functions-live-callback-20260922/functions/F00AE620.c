
/* WARNING: Removing unreachable block (ram,0xf00ae770) */
/* WARNING: Removing unreachable block (ram,0xf00ae6f0) */
/* WARNING: Removing unreachable block (ram,0xf00ae670) */
/* WARNING: Removing unreachable block (ram,0xf00ae69c) */

undefined8 __fp_unpack(int param_1,undefined4 param_2,uint param_3,int param_4)

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
  if (param_4 == 1) {
    (**(code **)(param_1 + 0x14))((undefined *)((int)register0x00000038 + -0xc),param_3,param_1);
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    _unpacksingle(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10));
  }
  else if (param_4 < 2) {
    if (param_4 == 0) {
      (**(code **)(param_1 + 0x14))((undefined *)((int)register0x00000038 + -0xc),param_3,param_1);
      sub_F00AE27C(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
    }
  }
  else if (param_4 == 2) {
    (**(code **)(param_1 + 0x14))
              ((undefined *)((int)register0x00000038 + -0xc),param_3 & 0xfffe,param_1);
    (**(code **)(param_1 + 0x14))
              ((undefined *)((int)register0x00000038 + -0x14),(param_3 & 0xfffe) + 1,param_1);
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    _unpackdouble(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10),
                  *(undefined4 *)((int)register0x00000038 + -0x14));
  }
  else if (param_4 == 3) {
    param_3 = param_3 & 0xfffc;
    (**(code **)(param_1 + 0x14))((undefined *)((int)register0x00000038 + -0xc),param_3,param_1);
    (**(code **)(param_1 + 0x14))
              ((undefined *)((int)register0x00000038 + -0x14),param_3 + 1,param_1);
    (**(code **)(param_1 + 0x14))
              ((undefined *)((int)register0x00000038 + -0x18),param_3 + 2,param_1);
    (**(code **)(param_1 + 0x14))
              ((undefined *)((int)register0x00000038 + -0x1c),param_3 + 3,param_1);
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    sub_F00AE504(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10),
                 *(undefined4 *)((int)register0x00000038 + -0x14),
                 *(undefined4 *)((int)register0x00000038 + -0x18),
                 *(undefined4 *)((int)register0x00000038 + -0x1c));
  }
  return CONCAT44(param_2,param_1);
}

