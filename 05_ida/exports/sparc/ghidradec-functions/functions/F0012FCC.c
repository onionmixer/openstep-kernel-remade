
/* WARNING: Removing unreachable block (ram,0xf0013034) */
/* WARNING: Removing unreachable block (ram,0xf0012ff0) */
/* WARNING: Removing unreachable block (ram,0xf0013060) */
/* WARNING: Removing unreachable block (ram,0xf0012fd8) */

undefined8 _adjtime(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = dword_F0133DDC;
  _suser();
  if (iVar1 != 0) {
    uVar2 = *puVar3;
    _copyin(uVar2,(undefined *)((int)register0x00000038 + -0x10),8);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      *(undefined4 *)((int)register0x00000038 + -0x20) =
           *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x1c) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      *(undefined4 *)((int)register0x00000038 + -0x30) =
           *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x2c) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      _host_adjust_time(dword_F0135174,(undefined *)((int)register0x00000038 + -0x30),
                        (undefined *)((int)register0x00000038 + -0x28));
      if (puVar3[1] != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x18) =
             *(undefined4 *)((int)register0x00000038 + -0x28);
        *(undefined4 *)((int)register0x00000038 + -0x14) =
             *(undefined4 *)((int)register0x00000038 + -0x24);
        _copyout((undefined *)((int)register0x00000038 + -0x18),puVar3[1],8);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
