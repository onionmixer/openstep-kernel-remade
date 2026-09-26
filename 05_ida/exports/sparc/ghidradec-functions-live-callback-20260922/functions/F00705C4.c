
/* WARNING: Removing unreachable block (ram,0xf00706b8) */
/* WARNING: Removing unreachable block (ram,0xf0070644) */
/* WARNING: Removing unreachable block (ram,0xf0070600) */
/* WARNING: Removing unreachable block (ram,0xf0070658) */
/* WARNING: Removing unreachable block (ram,0xf00706d0) */
/* WARNING: Removing unreachable block (ram,0xf00705e8) */

undefined8 sub_F00705C4(undefined4 param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar6;
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
  if (dword_F012FF24 != 0) {
    _kdp_panic(aKdpPoll);
  }
  unk_F012FF1C._0_4_ = 0;
  _kdp_en_recv_pkt(unk_F012F930,0xf012ff20,3);
  iVar3 = unk_F012FF1C._0_4_;
  if ((unk_F012FF1C._4_4_ != 0) && (0x29 < unk_F012FF1C._4_4_)) {
    iVar5 = unk_F012FF1C._0_4_ + 0xe;
    puVar6 = unk_F012F930 + unk_F012FF1C._0_4_;
    iVar2 = unk_F012FF1C._0_4_ + 0xc;
    iVar4 = unk_F012FF1C._0_4_ + -0xfed06c2;
    unk_F012FF1C._0_4_ = iVar5;
    if (*(sword *)(unk_F012F930 + iVar2) == 0x800) {
      _bcopy(iVar4,(undefined *)((int)register0x00000038 + -0x28),0x1c);
      _bcopy(unk_F012F930 + unk_F012FF1C._0_4_,(undefined *)((int)register0x00000038 + -0x40),0x14);
      unk_F012FF1C._0_4_ = unk_F012FF1C._0_4_ + 0x1c;
      if (((*(char *)((int)register0x00000038 + -0x1f) == '\x11') &&
          ((*(byte *)((int)register0x00000038 + -0x40) & 0xf) < 6)) &&
         (*(sword *)((int)register0x00000038 + -0x12) == 0x473)) {
        wVar1 = *(word *)((int)register0x00000038 + -0x10);
        if (dword_F013C408 == 0) {
          _bcopy(puVar6,unk_F013C424,6);
          _adr = *(undefined4 *)((int)register0x00000038 + -0x18);
          _bcopy(iVar3 + -0xfed06ca,0xf013c430,6);
          DAT_f013c42c._0_4_ = *(undefined4 *)((int)register0x00000038 + -0x1c);
          wVar1 = *(word *)((int)register0x00000038 + -0x10);
        }
        dword_F012FF24 = 1;
        unk_F012FF1C._4_4_ = wVar1 - 8;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}

