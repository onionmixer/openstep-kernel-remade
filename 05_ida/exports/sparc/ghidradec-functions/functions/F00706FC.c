
/* WARNING: Removing unreachable block (ram,0xf00707d8) */
/* WARNING: Removing unreachable block (ram,0xf00707a0) */
/* WARNING: Removing unreachable block (ram,0xf007075c) */
/* WARNING: Removing unreachable block (ram,0xf00707c0) */
/* WARNING: Removing unreachable block (ram,0xf00707ec) */
/* WARNING: Removing unreachable block (ram,0xf007073c) */

undefined8 sub_F00706FC(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar3;
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
  puVar3 = (uint *)((int)register0x00000038 + -0x10);
  dword_F013C40C = param_1;
  do {
    if (dword_F012FF24 == 0) {
      param_1 = 0xf012fc00;
      puVar2 = (uint *)(unk_F012F930 + 0x2d0);
      do {
        sub_F00705C4(dword_F012FF24,puVar2);
        puVar2 = puVar3;
      } while (dword_F012FF24 == 0);
    }
    _bcopy(unk_F012F930 + unk_F012FF1C._0_4_,puVar3,8);
    if ((*puVar3 & 0x1000000) == 0) {
      if ((*puVar3 >> 0x10 & 0xff) == unk_F012F92C._0_1_ - 1) {
        _kdp_en_send_pkt(unk_F012FF28 + DAT_f0130514._0_4_,DAT_f0130514._4_4_);
      }
      else if ((uint)*(byte *)((int)register0x00000038 + -0xf) == (uint)unk_F012F92C._0_1_) {
        puVar1 = unk_F012F930 + unk_F012FF1C._0_4_;
        _kdp_packet(puVar1,0xf012ff20,(undefined *)((int)register0x00000038 + -0x12));
        if (puVar1 != (undefined *)0x0) {
          sub_F0070110(*(undefined2 *)((int)register0x00000038 + -0x12));
        }
      }
      else {
        _safe_prf(aKdpBadSequence);
      }
    }
    dword_F012FF24 = 0;
  } while (DAT_f013c410._0_4_ != 0);
  return CONCAT44(param_2,param_1);
}
