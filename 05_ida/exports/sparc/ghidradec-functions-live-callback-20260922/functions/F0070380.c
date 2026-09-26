
/* WARNING: Removing unreachable block (ram,0xf0070594) */
/* WARNING: Removing unreachable block (ram,0xf0070550) */
/* WARNING: Removing unreachable block (ram,0xf0070438) */
/* WARNING: Removing unreachable block (ram,0xf00703c4) */
/* WARNING: Removing unreachable block (ram,0xf0070424) */
/* WARNING: Removing unreachable block (ram,0xf0070584) */
/* WARNING: Removing unreachable block (ram,0xf00705b4) */
/* WARNING: Removing unreachable block (ram,0xf00703a4) */

undefined8 sub_F0070380(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  sword sVar7;
  byte *pbVar6;
  int iVar8;
  byte *pbVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  byte *pbVar10;
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
  bool bVar11;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  byte abStack_40 [64];
  
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
  pbVar10 = (byte *)((int)register0x00000038 + -0x40);
  if (dword_F012FF24 != 0) {
    _kdp_panic(aKdpSend);
  }
  puVar4 = DAT_f012f914 + unk_F012FF1C._0_4_;
  unk_F012FF1C._0_4_ = unk_F012FF1C._0_4_ + -0x1c;
  _bcopy(puVar4,(undefined *)((int)register0x00000038 + -0x28),0x1c);
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
  *(undefined *)((int)register0x00000038 + -0x20) = 0;
  *(undefined *)((int)register0x00000038 + -0x1f) = 0x11;
  *(undefined2 *)((int)register0x00000038 + -0x14) = 0x473;
  *(sword *)((int)register0x00000038 + -0x12) = (sword)param_1;
  *(undefined2 *)((int)register0x00000038 + -0xe) = 0;
  sVar7 = (sword)unk_F012FF1C._4_4_ + 8;
  *(sword *)((int)register0x00000038 + -0x1e) = sVar7;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = _adr;
  *(undefined4 *)((int)register0x00000038 + -0x18) = DAT_f013c42c._0_4_;
  *(sword *)((int)register0x00000038 + -0x10) = sVar7;
  _bcopy((undefined *)((int)register0x00000038 + -0x28),unk_F012F930 + unk_F012FF1C._0_4_,0x1c);
  _bcopy(unk_F012F930 + unk_F012FF1C._0_4_,pbVar10,0x14);
  *(undefined2 *)((int)register0x00000038 + -0x36) = 0;
  iVar3 = 0;
  iVar2 = 0;
  *(sword *)((int)register0x00000038 + -0x3e) = (sword)unk_F012FF1C._4_4_ + 0x1c;
  *(sword *)((int)register0x00000038 + -0x3c) = _ip_id;
  *(char *)((int)register0x00000038 + -0x38) = (char)_udp_ttl;
  uVar5 = *(uint *)((int)register0x00000038 + -0x40);
  *(uint *)((int)register0x00000038 + -0x40) = uVar5 & 0xfffffff | 0x40000000;
  *(uint *)((int)register0x00000038 + -0x40) = uVar5 & 0xffffff | 0x45000000;
  pbVar6 = (byte *)((int)register0x00000038 + -0x3e);
  iVar8 = 4;
  pbVar9 = pbVar10;
  do {
    bVar11 = iVar8 != 0;
    bVar1 = *pbVar9;
    iVar3 = iVar3 + (uint)pbVar6[-1] + (uint)pbVar6[1];
    pbVar9 = pbVar9 + 4;
    iVar2 = iVar2 + (uint)bVar1 + (uint)*pbVar6;
    pbVar6 = pbVar6 + 4;
    iVar8 = iVar8 + -1;
  } while (bVar11);
  uVar5 = iVar2 * 0x100 + iVar3;
  uVar5 = (uVar5 >> 0x10) + (uVar5 & 0xffff);
  if (0xffff < uVar5) {
    uVar5 = uVar5 + 1;
  }
  *(word *)((int)register0x00000038 + -0x36) = ~(word)uVar5;
  _ip_id = _ip_id + 1;
  _bcopy(pbVar10,unk_F012F930 + unk_F012FF1C._0_4_,0x14);
  iVar8 = unk_F012FF1C._0_4_;
  unk_F012FF1C._4_4_ = unk_F012FF1C._4_4_ + 0x1c;
  iVar3 = unk_F012FF1C._0_4_ + -0xfed06de;
  iVar2 = (int)&dword_F012F928 + unk_F012FF1C._0_4_;
  unk_F012FF1C._0_4_ = unk_F012FF1C._0_4_ + -0xe;
  _bcopy(unk_F013C424,iVar2,6);
  _bcopy(0xf013c430,iVar3,6);
  *(undefined2 *)((int)&DAT_f012f92e + iVar8) = 0x800;
  unk_F012FF1C._4_4_ = unk_F012FF1C._4_4_ + 0xe;
  _kdp_en_send_pkt(unk_F012F930 + unk_F012FF1C._0_4_);
  return CONCAT44(param_2,param_1);
}

