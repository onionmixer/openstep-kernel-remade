
/* WARNING: Removing unreachable block (ram,0xf00709f4) */
/* WARNING: Removing unreachable block (ram,0xf00709a8) */
/* WARNING: Removing unreachable block (ram,0xf0070980) */
/* WARNING: Removing unreachable block (ram,0xf0070988) */
/* WARNING: Removing unreachable block (ram,0xf00709c0) */
/* WARNING: Removing unreachable block (ram,0xf00709fc) */
/* WARNING: Removing unreachable block (ram,0xf0070978) */

undefined8 sub_F0070944(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar1;
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
  iVar1 = 300;
  do {
    unk_F012FF1C._0_4_ = 0x2a;
    _kdp_exception(0xf012f95a,0xf012ff20,(undefined *)((int)register0x00000038 + -10),param_1,
                   param_2,param_3);
    sub_F0070380(*(undefined2 *)((int)register0x00000038 + -10));
    sub_F00705C4();
    if (dword_F012FF24 != 0) {
      _kdp_exception_ack(unk_F012F930 + unk_F012FF1C._0_4_,unk_F012FF1C._4_4_);
    }
    dword_F012FF24 = 0;
    if (iRamf013c418 != 0) {
      _kdp_us_spin(100000);
    }
    if (iRamf013c418 == 0) goto locret_F0070A04;
    iVar1 = iVar1 + -1;
  } while (iVar1 != -1);
  if (iRamf013c418 != 0) {
    _safe_prf(aKdpExceptionAc);
    _kdp_reset();
  }
locret_F0070A04:
  return CONCAT44(param_2,param_1);
}

