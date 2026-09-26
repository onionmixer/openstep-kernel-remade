
/* WARNING: Removing unreachable block (ram,0xf0070350) */
/* WARNING: Removing unreachable block (ram,0xf0070318) */
/* WARNING: Removing unreachable block (ram,0xf00702d8) */
/* WARNING: Removing unreachable block (ram,0xf00701c0) */
/* WARNING: Removing unreachable block (ram,0xf0070154) */
/* WARNING: Removing unreachable block (ram,0xf00701ac) */
/* WARNING: Removing unreachable block (ram,0xf0070308) */
/* WARNING: Removing unreachable block (ram,0xf0070328) */
/* WARNING: Removing unreachable block (ram,0xf0070360) */
/* WARNING: Removing unreachable block (ram,0xf0070134) */

undefined8 sub_F0070110(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  sword sVar7;
  byte *pbVar6;
  undefined4 uVar8;
  int iVar9;
  byte *pbVar10;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  byte *pbVar11;
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
  bool bVar12;
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
  pbVar11 = (byte *)((int)register0x00000038 + -0x40);
  if (dword_F012FF24 == 0) {
    _kdp_panic(aKdpReply);
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
  uVar8 = *(undefined4 *)((int)register0x00000038 + -0x1c);
  sVar7 = (sword)unk_F012FF1C._4_4_ + 8;
  *(sword *)((int)register0x00000038 + -0x1e) = sVar7;
  *(undefined4 *)((int)register0x00000038 + -0x1c) =
       *(undefined4 *)((int)register0x00000038 + -0x18);
  *(undefined4 *)((int)register0x00000038 + -0x18) = uVar8;
  *(sword *)((int)register0x00000038 + -0x10) = sVar7;
  _bcopy((undefined *)((int)register0x00000038 + -0x28),unk_F012F930 + unk_F012FF1C._0_4_,0x1c);
  _bcopy(unk_F012F930 + unk_F012FF1C._0_4_,pbVar11,0x14);
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
  iVar9 = 4;
  pbVar10 = pbVar11;
  do {
    bVar12 = iVar9 != 0;
    bVar1 = *pbVar10;
    iVar3 = iVar3 + (uint)pbVar6[-1] + (uint)pbVar6[1];
    pbVar10 = pbVar10 + 4;
    iVar2 = iVar2 + (uint)bVar1 + (uint)*pbVar6;
    pbVar6 = pbVar6 + 4;
    iVar9 = iVar9 + -1;
  } while (bVar12);
  uVar5 = iVar2 * 0x100 + iVar3;
  uVar5 = (uVar5 >> 0x10) + (uVar5 & 0xffff);
  if (0xffff < uVar5) {
    uVar5 = uVar5 + 1;
  }
  *(word *)((int)register0x00000038 + -0x36) = ~(word)uVar5;
  _ip_id = _ip_id + 1;
  _bcopy(pbVar11,unk_F012F930 + unk_F012FF1C._0_4_,0x14);
  iVar9 = unk_F012FF1C._0_4_;
  unk_F012FF1C._4_4_ = unk_F012FF1C._4_4_ + 0x1c;
  iVar2 = unk_F012FF1C._0_4_ + -0xfed06de;
  iVar3 = (int)&dword_F012F928 + unk_F012FF1C._0_4_;
  unk_F012FF1C._0_4_ = unk_F012FF1C._0_4_ + -0xe;
  _bcopy(iVar3,(undefined *)((int)register0x00000038 + -0x48),6);
  _bcopy(iVar2,iVar3,6);
  _bcopy((undefined *)((int)register0x00000038 + -0x48),iVar2,6);
  *(undefined2 *)((int)&unk_F012F92C + iVar9 + 2) = 0x800;
  unk_F012FF1C._4_4_ = unk_F012FF1C._4_4_ + 0xe;
  _bcopy(unk_F012F930,unk_F012FF28,0x5f8);
  _kdp_en_send_pkt(unk_F012F930 + unk_F012FF1C._0_4_,unk_F012FF1C._4_4_);
  unk_F012F92C._0_1_ = unk_F012F92C._0_1_ + '\x01';
  return CONCAT44(param_2,param_1);
}
