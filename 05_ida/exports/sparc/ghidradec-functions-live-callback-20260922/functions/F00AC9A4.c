
/* WARNING: Removing unreachable block (ram,0xf00aca50) */
/* WARNING: Removing unreachable block (ram,0xf00acb20) */
/* WARNING: Removing unreachable block (ram,0xf00acaac) */
/* WARNING: Removing unreachable block (ram,0xf00ac9dc) */

undefined8 _fp_emulator(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
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
  *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_5 + 0x80);
  *(int *)(param_1 + 0x10) = param_5;
  *(code **)(param_1 + 0x14) = __fp_read_vfreg;
  *(code **)(param_1 + 0x18) = __fp_write_vfreg;
  *(int *)(param_1 + 0x20) = param_2;
  iVar1 = param_2;
  __fp_read_word(param_2,(undefined *)((int)register0x00000038 + -0xc),param_1);
  uVar2 = *(uint *)((int)register0x00000038 + -0xc);
  if (iVar1 == 0) {
    if ((uVar2 & 0xc0000000) == 0x80000000) {
      if ((uVar2 & 0x1f80000) == 0x1a00000) goto loc_F00ACAA0;
      if ((uVar2 & 0x1f80000) == 0x1a80000) goto loc_F00ACAA0;
    }
    *(undefined4 *)((int)register0x00000038 + -0x14) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    while( true ) {
      iVar1 = param_1;
      __fp_iu_simulator(param_1,(undefined *)((int)register0x00000038 + -0x14),param_3,param_4,
                        param_5);
      while( true ) {
        if (iVar1 != 0) goto locret_F00ACB38;
        iVar1 = *(int *)(param_3 + 4);
        *(int *)(param_1 + 0x20) = iVar1;
        __fp_read_word(iVar1,(undefined *)((int)register0x00000038 + -0xc),param_1);
        uVar2 = *(uint *)((int)register0x00000038 + -0xc);
        if (iVar1 != 0) goto locret_F00ACB38;
        if (((uVar2 & 0xc0000000) != 0x80000000) ||
           (((uVar2 & 0x1f80000) != 0x1a00000 && ((uVar2 & 0x1f80000) != 0x1a80000)))) break;
loc_F00ACAA0:
        *(uint *)((int)register0x00000038 + -0x14) = uVar2;
        iVar1 = param_1;
        sub_F00AC318(param_1,(undefined *)((int)register0x00000038 + -0x14),
                     (undefined *)((int)register0x00000038 + -0x10));
        *(undefined4 *)(param_5 + 0x80) = *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_3 + 8);
        *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + 4;
      }
      if (((uVar2 & 0xc1c00000) != 0xc1000000) &&
         (((uVar2 & 0xc0000000) != 0 || (((int)uVar2 >> 0x15 & 7U) != 6)))) break;
      *(uint *)((int)register0x00000038 + -0x14) = uVar2;
    }
  }
locret_F00ACB38:
  return CONCAT44(param_2,iVar1);
}

