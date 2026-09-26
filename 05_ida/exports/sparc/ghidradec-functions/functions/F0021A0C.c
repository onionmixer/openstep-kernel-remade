
/* WARNING: Removing unreachable block (ram,0xf0021a9c) */
/* WARNING: Removing unreachable block (ram,0xf0021a68) */
/* WARNING: Removing unreachable block (ram,0xf0021ad4) */
/* WARNING: Removing unreachable block (ram,0xf0021a24) */

undefined8 _recvmsg(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar1 = puVar3[1];
  _copyin(uVar1,(undefined *)((int)register0x00000038 + -0x20),0x18);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    if (*(uint *)((int)register0x00000038 + -0x14) < 0x10) {
      uVar1 = *(undefined4 *)((int)register0x00000038 + -0x18);
      _copyin(uVar1,(undefined *)((int)register0x00000038 + -0xa0),
              *(uint *)((int)register0x00000038 + -0x14) << 3);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        *(undefined **)((int)register0x00000038 + -0x18) =
             (undefined *)((int)register0x00000038 + -0xa0);
        if (iVar2 == 0) {
          uVar1 = *puVar3;
        }
        else {
          _useracc(iVar2,*(undefined4 *)((int)register0x00000038 + -0xc),0);
          if (iVar2 == 0) {
            *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
            goto locret_F0021ADC;
          }
          uVar1 = *puVar3;
        }
        _recvit(uVar1,(undefined *)((int)register0x00000038 + -0x20),puVar3[2],puVar3[1] + 4,
                puVar3[1] + 0x14);
      }
    }
    else {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x28;
    }
  }
locret_F0021ADC:
  return CONCAT44(param_2,param_1);
}
