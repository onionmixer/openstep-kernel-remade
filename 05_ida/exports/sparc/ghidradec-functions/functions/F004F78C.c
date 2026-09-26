
/* WARNING: Removing unreachable block (ram,0xf004f850) */
/* WARNING: Removing unreachable block (ram,0xf004f7e8) */
/* WARNING: Removing unreachable block (ram,0xf004f878) */
/* WARNING: Removing unreachable block (ram,0xf004f82c) */
/* WARNING: Removing unreachable block (ram,0xf004f7d4) */

undefined4 sub_F004F78C(void)

{
  int iVar1;
  int iVar2;
  undefined8 in_o0_1;
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
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  if (*(int *)(*(int *)(iVar1 + 0x10) + 4) != 0) {
    *(int *)((int)register0x00000038 + -0xc) = *(int *)(iVar1 + 0x10) + 4;
    while (iVar2 = sub_F004F98C(), iVar2 != 0) {
      sub_F004FCA4(*(undefined4 *)((int)register0x00000038 + -0x10));
      switch(iVar2) {
      case :
        *(undefined4 *)*(undefined8 *)((int)register0x00000038 + -0x10) =
             *(undefined4 *)
              ((int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20) + 0x14);
        sub_F004FCE0(*(undefined4 *)((int)register0x00000038 + -0x10));
        return 0;
      case :
        if (*(int *)(*(int *)((int)register0x00000038 + -0x10) + 4) != *(int *)(iVar1 + 4)) {
          sub_F004FBF8();
          *(undefined4 *)(*(int *)((int)register0x00000038 + -0x10) + 0x14) =
               *(undefined4 *)(iVar1 + 0x14);
          return 0;
        }
        *(int *)(*(int *)((int)register0x00000038 + -0x10) + 4) = *(int *)(iVar1 + 8) + 1;
        return 0;
      case :
        *(undefined4 *)*(undefined8 *)((int)register0x00000038 + -0x10) =
             *(undefined4 *)
              ((int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20) + 0x14);
        sub_F004FCE0();
        break;
      case :
        iVar2 = *(int *)((int)register0x00000038 + -0x10);
        *(int *)(iVar2 + 8) = *(int *)(iVar1 + 4) + -1;
        *(int *)((int)register0x00000038 + -0xc) = iVar2 + 0x14;
        break;
      case :
        *(int *)(*(int *)((int)register0x00000038 + -0x10) + 4) = *(int *)(iVar1 + 8) + 1;
      :
        goto def_F004F804;
      }
    }
  }
def_F004F804:
  return 0;
}
