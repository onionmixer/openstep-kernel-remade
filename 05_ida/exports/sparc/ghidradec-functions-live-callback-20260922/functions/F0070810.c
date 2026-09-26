
/* WARNING: Removing unreachable block (ram,0xf0070910) */
/* WARNING: Removing unreachable block (ram,0xf00708bc) */
/* WARNING: Removing unreachable block (ram,0xf0070894) */
/* WARNING: Removing unreachable block (ram,0xf0070864) */
/* WARNING: Removing unreachable block (ram,0xf0070824) */
/* WARNING: Removing unreachable block (ram,0xf007088c) */
/* WARNING: Removing unreachable block (ram,0xf007089c) */
/* WARNING: Removing unreachable block (ram,0xf00708fc) */
/* WARNING: Removing unreachable block (ram,0xf0070934) */
/* WARNING: Removing unreachable block (ram,0xf0070818) */

undefined8 sub_F0070810(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar4;
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
  _safe_prf(aWaitingForRemo);
  _safe_prf(aTypeCToContinu);
  unk_F012F92C._0_1_ = '\0';
  puVar4 = (uint *)((int)register0x00000038 + -0x10);
  do {
    puVar1 = (uint *)(unk_F012F930 + 0x2d0);
    iVar2 = dword_F012FF24;
    while (dword_F012FF24 = iVar2, iVar2 == 0) {
      _kmtrygetc(0,puVar1);
      if (iVar2 == 99) {
        puVar3 = aContinuing_1;
        goto loc_F0070934;
      }
      if (iVar2 == 0x72) {
        _safe_prf(aRebooting_0);
        _kdp_reboot();
      }
      sub_F00705C4();
      puVar1 = puVar4;
      iVar2 = dword_F012FF24;
    }
    _bcopy(unk_F012F930 + unk_F012FF1C._0_4_,puVar4,8);
    if (((*puVar4 & 0xff000000) == 0) &&
       (*(char *)((int)register0x00000038 + -0xf) == unk_F012F92C._0_1_)) {
      puVar3 = unk_F012F930 + unk_F012FF1C._0_4_;
      _kdp_packet(puVar3,0xf012ff20,(undefined *)((int)register0x00000038 + -0x12));
      if (puVar3 != (undefined *)0x0) {
        sub_F0070110(*(undefined2 *)((int)register0x00000038 + -0x12));
      }
    }
    dword_F012FF24 = 0;
  } while (dword_F013C408 == 0);
  puVar3 = aConnectedToRem;
loc_F0070934:
  _safe_prf(puVar3);
  return CONCAT44(param_2,param_1);
}

