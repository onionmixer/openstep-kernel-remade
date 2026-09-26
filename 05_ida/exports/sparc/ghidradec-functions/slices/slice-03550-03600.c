/* GHIDRADEC_FUNCTION index=3550 start=0xf0070088 */

/* WARNING: Removing unreachable block (ram,0xf00700c0) */

undefined8 sub_F0070088(uint *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
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
  uVar1 = *param_2;
  if (0xf < uVar1) {
    uVar2 = param_1[2];
    *param_1 = *param_1 | 0x1000000;
    *(undefined2 *)((int)param_1 + 2) = 0xc;
    _kdp_machine_read_regs
              (uVar2,param_1[3],param_1 + 3,(undefined *)((int)register0x00000038 + -0xc));
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0xc);
    param_1[2] = uVar2;
    *(sword *)((int)param_1 + 2) = (sword)*param_1 + (sword)uVar3;
    *param_3 = _kdp;
    *param_2 = *param_1 & 0xffff;
  }
  return CONCAT44(param_2,(uint)(0xf < uVar1));
}
/* GHIDRADEC_FUNCTION index=3551 start=0xf0070110 */

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
/* GHIDRADEC_FUNCTION index=3552 start=0xf0070380 */

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
/* GHIDRADEC_FUNCTION index=3553 start=0xf00705c4 */

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
/* GHIDRADEC_FUNCTION index=3554 start=0xf00706fc */

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
/* GHIDRADEC_FUNCTION index=3555 start=0xf0070810 */

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
/* GHIDRADEC_FUNCTION index=3556 start=0xf0070944 */

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
/* GHIDRADEC_FUNCTION index=3557 start=0xf007673c */

/* WARNING: Removing unreachable block (ram,0xf0076784) */
/* WARNING: Removing unreachable block (ram,0xf00767c8) */
/* WARNING: Removing unreachable block (ram,0xf0076740) */

undefined8 sub_F007673C(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  uint uVar4;
  uint uVar6;
  undefined8 uVar7;
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
  undefined8 uVar5;
  
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
  uVar2 = 1;
  uVar4 = param_2;
  _clock_value();
  if ((*(uint *)(param_1 + 0x18) < uVar2) ||
     ((uVar2 == *(uint *)(param_1 + 0x18) && (*(uint *)(param_1 + 0x1c) < uVar4)))) {
    uVar5 = 0;
  }
  else {
    puVar3 = (undefined8 *)0x0;
    _timer_attributes();
    uVar7 = *puVar3;
    uVar6 = (uint)*(undefined8 *)(param_1 + 0x18);
    uVar1 = uVar6 - uVar4;
    uVar4 = ((int)((qword)*(undefined8 *)(param_1 + 0x18) >> 0x20) - uVar2) - (uint)(uVar6 < uVar4);
    uVar5 = CONCAT44(uVar4,uVar1);
    uVar2 = (uint)((qword)uVar7 >> 0x20);
    if ((uVar2 < uVar4) || ((uVar4 == uVar2 && ((uint)uVar7 < uVar1)))) {
      uVar5 = uVar7;
    }
  }
  _set_timer(0,(int)((qword)uVar5 >> 0x20),(int)uVar5);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3558 start=0xf00767d8 */

undefined8 sub_F00767D8(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar2 = 0;
  if ((undefined4 **)dword_F0130F2C != &dword_F0130F2C) {
    iVar1 = dword_F0130F2C[2];
    puVar3 = dword_F0130F2C;
    do {
      if (iVar1 == param_1) {
        if (puVar3[3] == param_2) {
          puVar4 = (undefined4 *)*puVar3;
          puVar4[1] = puVar3[1];
          dword_F0130F3C = dword_F0130F3C + -1;
          *(undefined4 *)puVar3[1] = *puVar3;
          puVar3[8] = 0;
          if ((unk_F0130520 <= puVar3) && (puVar3 < &dword_F0130F20)) {
            *puVar3 = &dword_F0130F24;
            puVar3[1] = DAT_f0130f28;
            *DAT_f0130f28 = puVar3;
            DAT_f0130f28 = puVar3;
          }
          uVar2 = 1;
          if (param_3 == 0) break;
        }
        else {
          puVar4 = (undefined4 *)*puVar3;
        }
      }
      else {
        puVar4 = (undefined4 *)*puVar3;
      }
      if ((undefined4 **)puVar4 == &dword_F0130F2C) break;
      iVar1 = puVar4[2];
      puVar3 = puVar4;
    } while( true );
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3559 start=0xf00768a8 */

undefined8 sub_F00768A8(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar2 = 0;
  if ((undefined4 **)dword_F0130F34 != &dword_F0130F34) {
    iVar1 = dword_F0130F34[2];
    puVar3 = dword_F0130F34;
    do {
      if (iVar1 == param_1) {
        if (puVar3[3] == param_2) {
          puVar4 = (undefined4 *)*puVar3;
          puVar4[1] = puVar3[1];
          *(undefined4 *)puVar3[1] = *puVar3;
          puVar3[8] = 0;
          if ((unk_F0130520 <= puVar3) && (puVar3 < &dword_F0130F20)) {
            *puVar3 = &dword_F0130F24;
            puVar3[1] = DAT_f0130f28;
            *DAT_f0130f28 = puVar3;
            DAT_f0130f28 = puVar3;
          }
          uVar2 = 1;
          if (param_3 == 0) break;
        }
        else {
          puVar4 = (undefined4 *)*puVar3;
        }
      }
      else {
        puVar4 = (undefined4 *)*puVar3;
      }
      if ((undefined4 **)puVar4 == &dword_F0130F34) break;
      iVar1 = puVar4[2];
      puVar3 = puVar4;
    } while( true );
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3560 start=0xf00773a8 */

/* WARNING: Removing unreachable block (ram,0xf0077404) */
/* WARNING: Removing unreachable block (ram,0xf00773ec) */

undefined8 sub_F00773A8(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
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
  dword_F0130F20 = 0;
  bVar1 = dword_F0130F44 < dword_F0130F40 + dword_F0130F3C;
  _thread_wakeup_prim(&dword_F0130F3C,1,0);
  if (bVar1) {
    _thread_wakeup_prim(&dword_F0130F44,1,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3561 start=0xf0077414 */

/* WARNING: Removing unreachable block (ram,0xf00775b8) */
/* WARNING: Removing unreachable block (ram,0xf0077598) */
/* WARNING: Removing unreachable block (ram,0xf0077534) */
/* WARNING: Removing unreachable block (ram,0xf0077508) */
/* WARNING: Removing unreachable block (ram,0xf007743c) */
/* WARNING: Removing unreachable block (ram,0xf007751c) */
/* WARNING: Removing unreachable block (ram,0xf0077584) */
/* WARNING: Removing unreachable block (ram,0xf00775b0) */
/* WARNING: Removing unreachable block (ram,0xf00775c0) */
/* WARNING: Removing unreachable block (ram,0xf007741c) */

undefined8 sub_F0077414(undefined4 *param_1,undefined *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  int *piVar3;
  int *piVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  code *pcVar6;
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
  
  uVar1 = _active_threads;
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
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (0 < dword_F0130F3C) {
    param_1 = &dword_F0130F2C;
    param_2 = unk_F0130520;
    do {
      if ((int **)dword_F0130F2C == &dword_F0130F2C) {
        piVar3 = (int *)0x0;
      }
      else {
        *(int ***)(*dword_F0130F2C + 4) = &dword_F0130F2C;
        piVar3 = dword_F0130F2C;
        dword_F0130F2C = (int *)*dword_F0130F2C;
      }
      piVar3[8] = 0;
      pcVar6 = (code *)piVar3[2];
      iVar5 = piVar3[3];
      dword_F0130F3C = dword_F0130F3C + -1;
      piVar4 = piVar3;
      if ((unk_F0130520 <= piVar3) && (piVar3 < &dword_F0130F20)) {
        *piVar3 = (int)&dword_F0130F24;
        piVar3[1] = (int)DAT_f0130f28;
        *DAT_f0130f28 = (int)piVar3;
        piVar4 = (int *)0x0;
        DAT_f0130f28 = piVar3;
      }
      dword_F0130F20 = 0;
      dword_F0130F40 = dword_F0130F40 + 1;
      _spl0();
      (*pcVar6)(iVar5,piVar4);
      _splusclock();
      do {
        do {
        } while (dword_F0130F20 != 0);
        puVar2 = &dword_F0130F20;
        _simple_lock_try();
      } while (puVar2 == (undefined4 *)0x0);
      dword_F0130F40 = dword_F0130F40 + -1;
    } while (0 < dword_F0130F3C);
  }
  if (dword_F0130F44 - dword_F0130F40 < 5) {
    _assert_wait(&dword_F0130F3C,0);
    dword_F0130F20 = 0;
    _thread_block_with_continuation(sub_F0077414);
  }
  dword_F0130F20 = 0;
  dword_F0130F44 = dword_F0130F44 + -1;
  _spl0();
  _thread_terminate(uVar1);
  _thread_halt_self();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3562 start=0xf00775d0 */

/* WARNING: Removing unreachable block (ram,0xf00775e0) */
/* WARNING: Removing unreachable block (ram,0xf00775d8) */

undefined8 sub_F00775D0(undefined4 param_1,undefined4 param_2)

{
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
  _stack_privilege(_active_threads);
  sub_F0077414();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3563 start=0xf00775f0 */

/* WARNING: Removing unreachable block (ram,0xf0077684) */
/* WARNING: Removing unreachable block (ram,0xf007766c) */
/* WARNING: Removing unreachable block (ram,0xf0077618) */
/* WARNING: Removing unreachable block (ram,0xf0077678) */
/* WARNING: Removing unreachable block (ram,0xf0077698) */
/* WARNING: Removing unreachable block (ram,0xf00775f8) */

undefined8 sub_F00775F0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
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
  
  iVar1 = _active_threads;
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
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar2 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (dword_F0130F44 < dword_F0130F40 + dword_F0130F3C) {
    dword_F0130F44 = dword_F0130F44 + 1;
    dword_F0130F20 = 0;
    _kernel_thread(*(undefined4 *)(iVar1 + 0xc),sub_F00775D0,0);
    _thread_block_with_continuation(sub_F00775F0);
  }
  _assert_wait(&dword_F0130F44,0);
  dword_F0130F20 = 0;
  _thread_block_with_continuation(sub_F00775F0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3564 start=0xf00776a8 */

/* WARNING: Removing unreachable block (ram,0xf00776b8) */
/* WARNING: Removing unreachable block (ram,0xf00776b0) */

undefined8 sub_F00776A8(undefined4 param_1,undefined4 param_2)

{
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
  _stack_privilege(_active_threads);
  sub_F00775F0();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3565 start=0xf00776c8 */

/* WARNING: Removing unreachable block (ram,0xf0077878) */
/* WARNING: Removing unreachable block (ram,0xf00778b0) */
/* WARNING: Removing unreachable block (ram,0xf0077708) */
/* WARNING: Removing unreachable block (ram,0xf00776e4) */
/* WARNING: Removing unreachable block (ram,0xf00777b8) */
/* WARNING: Removing unreachable block (ram,0xf007785c) */
/* WARNING: Removing unreachable block (ram,0xf0077890) */
/* WARNING: Removing unreachable block (ram,0xf00776cc) */

undefined8 sub_F00776C8(undefined4 param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
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
  uVar2 = 1;
  uVar6 = param_2;
  _clock_value();
  *(undefined **)((int)register0x00000038 + -0xc) = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined **)((int)register0x00000038 + -0x10) = (undefined *)((int)register0x00000038 + -0x10);
  uVar3 = uVar2;
  _splusclock();
  do {
    do {
    } while (dword_F0130F20 != 0);
    puVar5 = &dword_F0130F20;
    _simple_lock_try();
  } while (puVar5 == (undefined4 *)0x0);
  if ((int **)dword_F0130F34 != &dword_F0130F34) {
    uVar4 = dword_F0130F34[6];
    while (piVar7 = dword_F0130F34, uVar4 <= uVar2) {
      if (uVar4 == uVar2) {
        if (uVar6 < (uint)dword_F0130F34[7]) break;
        iVar8 = *dword_F0130F34;
      }
      else {
        iVar8 = *dword_F0130F34;
      }
      *(int *)(iVar8 + 4) = dword_F0130F34[1];
      *(int *)piVar7[1] = *piVar7;
      piVar7[8] = 0;
      *piVar7 = (int)((int)register0x00000038 + -0x10);
      puVar5 = *(undefined4 **)((int)register0x00000038 + -0xc);
      piVar7[1] = (int)puVar5;
      *puVar5 = piVar7;
      *(int **)((int)register0x00000038 + -0xc) = piVar7;
      if ((int **)dword_F0130F34 == &dword_F0130F34) break;
      uVar4 = dword_F0130F34[6];
    }
  }
  if ((int **)dword_F0130F34 != &dword_F0130F34) {
    sub_F007673C(dword_F0130F34);
  }
  piVar7 = *(int **)((int)register0x00000038 + -0x10);
  while( true ) {
    if (piVar7 == (int *)((int)register0x00000038 + -0x10)) {
      piVar7 = (int *)0x0;
    }
    else {
      *(int **)(*piVar7 + 4) = (int *)((int)register0x00000038 + -0x10);
      *(int *)((int)register0x00000038 + -0x10) = *piVar7;
    }
    if (piVar7 == (int *)0x0) break;
    *piVar7 = (int)&dword_F0130F2C;
    piVar7[1] = (int)DAT_f0130f30;
    *DAT_f0130f30 = (int)piVar7;
    iVar8 = dword_F0130F3C + 1;
    DAT_f0130f30 = piVar7;
    dword_F0130F3C = iVar8;
    piVar7[8] = 1;
    dword_F0130F20 = 0;
    bVar1 = dword_F0130F44 < dword_F0130F40 + iVar8;
    _thread_wakeup_prim(&dword_F0130F3C,1,0);
    if (bVar1) {
      _thread_wakeup_prim(&dword_F0130F44,1,0);
    }
    do {
      do {
      } while (dword_F0130F20 != 0);
      puVar5 = &dword_F0130F20;
      _simple_lock_try();
      piVar7 = *(int **)((int)register0x00000038 + -0x10);
    } while (puVar5 == (undefined4 *)0x0);
  }
  dword_F0130F20 = 0;
  _splx(uVar3,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3566 start=0xf0077b04 */

undefined8 sub_F0077B04(uint param_1,int *param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
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
  uint uVar4;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  int *piVar5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  puVar1 = (uint *)(param_2 + 1);
  uVar4 = *(uint *)(param_1 + 0x18);
  uVar2 = *puVar1 >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
  if ((int)uVar4 < (int)uVar2) {
    uVar2 = uVar4;
  }
  iVar3 = *(int *)(param_1 + 0x14) + uVar2 * 0x10;
  piVar5 = (int *)(iVar3 + -0x10);
  if (param_2 == *(int **)(iVar3 + -0x10)) {
    param_2 = (int *)*param_2;
    if ((int)uVar2 < (int)uVar4) {
      if (param_2 == (int *)0x0) {
loc_F0077BB4:
        *piVar5 = (int)param_2;
      }
      else {
        uVar2 = param_2[1];
        while (uVar2 != *puVar1) {
          param_2 = (int *)*param_2;
          if (param_2 == (int *)0x0) {
            *piVar5 = 0;
            goto locret_F0077BB8;
          }
          uVar2 = param_2[1];
        }
        *piVar5 = (int)param_2;
      }
    }
    else if (param_2 == (int *)0x0) {
      *piVar5 = 0;
    }
    else {
      param_1 = *(uint *)(param_1 + 4);
      uVar2 = param_2[1];
      while (uVar2 < param_1) {
        param_2 = (int *)*param_2;
        if (param_2 == (int *)0x0) goto loc_F0077BB4;
        uVar2 = param_2[1];
      }
      *piVar5 = (int)param_2;
    }
  }
locret_F0077BB8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3567 start=0xf0077bc0 */

undefined8 sub_F0077BC0(int param_1,int *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  byte bVar5;
  int iVar3;
  int *piVar4;
  int *piVar6;
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
  uint uVar7;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar7 = *(uint *)(param_1 + 0x18);
  bVar5 = (byte)*(undefined4 *)(param_1 + 0x10);
  uVar1 = (uint)param_2[1] >> (bVar5 & 0x1f);
  if ((int)uVar7 < (int)uVar1) {
    uVar1 = uVar7;
  }
  uVar2 = param_3 >> (bVar5 & 0x1f);
  if ((int)uVar7 < (int)uVar2) {
    uVar2 = uVar7;
  }
  iVar3 = *(int *)(param_1 + 0x14) + uVar2 * 0x10;
  piVar6 = (int *)(iVar3 + -0x10);
  if (uVar2 == uVar1) {
    if (param_4 != *(int *)(iVar3 + -0x10)) goto locret_F0077CD4;
  }
  else {
    if (param_4 == *(int *)(iVar3 + -0x10)) {
      piVar4 = (int *)*param_2;
      if ((int)uVar2 < (int)uVar7) {
        if (piVar4 == (int *)0x0) {
          *piVar6 = 0;
        }
        else {
          uVar7 = piVar4[1];
          while (uVar7 != param_3) {
            piVar4 = (int *)*piVar4;
            if (piVar4 == (int *)0x0) {
              *piVar6 = 0;
              goto loc_F0077C94;
            }
            uVar7 = piVar4[1];
          }
          *piVar6 = (int)piVar4;
        }
      }
      else if (piVar4 == (int *)0x0) {
        *piVar6 = 0;
      }
      else {
        uVar7 = piVar4[1];
        while (uVar7 < *(uint *)(param_1 + 4)) {
          piVar4 = (int *)*piVar4;
          if (piVar4 == (int *)0x0) {
            *piVar6 = 0;
            goto loc_F0077C94;
          }
          uVar7 = piVar4[1];
        }
        *piVar6 = (int)piVar4;
      }
loc_F0077C94:
      iVar3 = *(int *)(param_1 + 0x14);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x14);
    }
    iVar3 = iVar3 + uVar1 * 0x10;
    if (*(int **)(iVar3 + -0x10) != (int *)0x0) {
      if (param_2 < *(int **)(iVar3 + -0x10)) {
        *(int **)(iVar3 + -0x10) = param_2;
      }
      goto locret_F0077CD4;
    }
  }
  *(int **)(iVar3 + -0x10) = param_2;
locret_F0077CD4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3568 start=0xf0077cdc */

undefined8 sub_F0077CDC(int param_1,int *param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bVar6;
  int *piVar5;
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
  uint uVar7;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar7 = *(uint *)(param_1 + 0x18);
  bVar6 = (byte)*(undefined4 *)(param_1 + 0x10);
  uVar2 = (uint)param_2[1] >> (bVar6 & 0x1f);
  if ((int)uVar7 < (int)uVar2) {
    uVar2 = uVar7;
  }
  uVar3 = param_3 >> (bVar6 & 0x1f);
  if ((int)uVar7 < (int)uVar3) {
    uVar3 = uVar7;
  }
  if (uVar3 != uVar2) {
    iVar4 = *(int *)(param_1 + 0x14) + uVar3 * 0x10;
    piVar1 = (int *)(iVar4 + -0x10);
    if (param_2 == *(int **)(iVar4 + -0x10)) {
      piVar5 = (int *)*param_2;
      if ((int)uVar3 < (int)uVar7) {
        if (piVar5 == (int *)0x0) {
          *piVar1 = 0;
        }
        else {
          uVar7 = piVar5[1];
          while (uVar7 != param_3) {
            piVar5 = (int *)*piVar5;
            if (piVar5 == (int *)0x0) {
              *piVar1 = 0;
              goto loc_F0077DAC;
            }
            uVar7 = piVar5[1];
          }
          *piVar1 = (int)piVar5;
        }
      }
      else if (piVar5 == (int *)0x0) {
        *piVar1 = 0;
      }
      else {
        uVar7 = piVar5[1];
        while (uVar7 < *(uint *)(param_1 + 4)) {
          piVar5 = (int *)*piVar5;
          if (piVar5 == (int *)0x0) {
            *piVar1 = 0;
            goto loc_F0077DAC;
          }
          uVar7 = piVar5[1];
        }
        *piVar1 = (int)piVar5;
      }
    }
loc_F0077DAC:
    iVar4 = *(int *)(param_1 + 0x14) + uVar2 * 0x10;
    piVar1 = *(int **)(iVar4 + -0x10);
    if ((piVar1 == (int *)0x0) || (param_2 < piVar1)) {
      *(int **)(iVar4 + -0x10) = param_2;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3569 start=0xf0077ddc */

/* WARNING: Removing unreachable block (ram,0xf0077e08) */

undefined8 sub_F0077DDC(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  piVar5 = *(int **)(param_1 + 8);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else if ((uint)piVar5[1] < param_2) {
    uVar3 = *(uint *)(param_1 + 0x18);
    uVar1 = param_2 >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
    if ((int)uVar3 < (int)uVar1) {
      uVar1 = uVar3;
    }
    piVar4 = (int *)(*(int *)(param_1 + 0x14) + uVar1 * 0x10 + -0x10);
    if ((int)uVar1 < (int)uVar3) {
      do {
        piVar5 = (int *)*piVar4;
        if (piVar5 != (int *)0x0) {
          piVar6 = (int *)*piVar5;
          if (piVar6 != (int *)0x0) {
            iVar2 = piVar6[1];
            goto loc_F0077E74;
          }
          *piVar4 = 0;
          goto locret_F0077F30;
        }
        uVar1 = uVar1 + 1;
        piVar4 = piVar4 + 4;
      } while ((int)uVar1 < *(int *)(param_1 + 0x18));
    }
    piVar5 = (int *)*piVar4;
    if (piVar5 != (int *)0x0) {
      piVar6 = (int *)*piVar5;
      if ((uint)piVar5[1] < param_2) {
        piVar5 = piVar6;
        if (piVar6 != (int *)0x0) {
          uVar1 = piVar6[1];
          while ((uVar1 < param_2 && (piVar5 = (int *)*piVar5, piVar5 != (int *)0x0))) {
            uVar1 = piVar5[1];
          }
        }
      }
      else if (piVar6 == (int *)0x0) {
        *piVar4 = 0;
      }
      else {
        uVar1 = piVar6[1];
        while (uVar1 < *(uint *)(param_1 + 4)) {
          piVar6 = (int *)*piVar6;
          if (piVar6 == (int *)0x0) {
            *piVar4 = 0;
            goto locret_F0077F30;
          }
          uVar1 = piVar6[1];
        }
        *piVar4 = (int)piVar6;
      }
    }
  }
  else {
    sub_F0077B04(param_1,piVar5);
  }
locret_F0077F30:
  return CONCAT44(param_2,piVar5);
loc_F0077E74:
  if (iVar2 == piVar5[1]) goto loc_f0077e78;
  piVar6 = (int *)*piVar6;
  if (piVar6 == (int *)0x0) {
    *piVar4 = 0;
    goto locret_F0077F30;
  }
  iVar2 = piVar6[1];
  goto loc_F0077E74;
loc_f0077e78:
  *piVar4 = (int)piVar6;
  goto locret_F0077F30;
}
/* GHIDRADEC_FUNCTION index=3570 start=0xf00789f0 */

/* WARNING: Removing unreachable block (ram,0xf0078a90) */
/* WARNING: Removing unreachable block (ram,0xf0078aa0) */
/* WARNING: Removing unreachable block (ram,0xf0078a34) */

undefined8 sub_F00789F0(uint param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  if (_zone_free_space_count < 8) {
    puVar4 = __zone_default_space;
    puVar3 = &_zone_free_space + _zone_free_space_count;
    _zone_free_space_count = _zone_free_space_count + 1;
    _zget_space(__zone_default_space,0x1c,0);
    *(uint *)puVar4 = param_1;
    *(uint *)((int)puVar4 + 4) = param_2;
    *(uint *)((int)puVar4 + 8) = 0;
    *(uint *)((int)puVar4 + 0xc) = 0;
    *(uint *)((int)puVar4 + 0x10) = 0;
    for (; (param_1 & 1) == 0; param_1 = param_1 >> 1) {
      *(uint *)((int)puVar4 + 0x10) = *(uint *)((int)puVar4 + 0x10) + 1;
    }
    puVar1 = __zone_default_space;
    uVar2 = *(uint *)((int)puVar4 + 4) >> ((byte)*(uint *)((int)puVar4 + 0x10) & 0x1f);
    *(uint *)((int)puVar4 + 0x18) = uVar2;
    _zget_space(__zone_default_space,uVar2 << 4,0);
    *(undefined **)((int)puVar4 + 0x14) = puVar1;
    _bzero();
    *puVar3 = puVar4;
  }
  else {
    puVar4 = (undefined *)0x0;
  }
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=3571 start=0xf0078ab4 */

undefined8 sub_F0078AB4(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined *puVar4;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  puVar4 = unk_F013CBB4;
  uVar3 = param_1;
  if ((*(int *)(param_1 + 0x14) == 0) && (param_2 = 1, 1 < _zone_free_space_count)) {
    do {
      iVar2 = **(int **)puVar4;
      uVar3 = (*(int **)puVar4)[1];
      uVar1 = *(int *)(param_1 + 0x1c) + -1 + iVar2 & -iVar2;
      param_2 = param_2 + 1;
      if (uVar1 <= uVar3) {
        *(uint *)(param_1 + 0x1c) = uVar1;
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)puVar4;
        break;
      }
      puVar4 = (undefined *)((int)puVar4 + 4);
    } while (param_2 < _zone_free_space_count);
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3572 start=0xf0078c2c */

/* WARNING: Removing unreachable block (ram,0xf00790a4) */
/* WARNING: Removing unreachable block (ram,0xf0079014) */
/* WARNING: Removing unreachable block (ram,0xf0078ffc) */
/* WARNING: Removing unreachable block (ram,0xf0078f7c) */
/* WARNING: Removing unreachable block (ram,0xf0078f3c) */
/* WARNING: Removing unreachable block (ram,0xf0078f24) */
/* WARNING: Removing unreachable block (ram,0xf0078f00) */
/* WARNING: Removing unreachable block (ram,0xf0078e7c) */
/* WARNING: Removing unreachable block (ram,0xf0078ea0) */
/* WARNING: Removing unreachable block (ram,0xf0078e2c) */
/* WARNING: Removing unreachable block (ram,0xf0078d7c) */
/* WARNING: Removing unreachable block (ram,0xf0078d64) */
/* WARNING: Removing unreachable block (ram,0xf0078d30) */
/* WARNING: Removing unreachable block (ram,0xf0078d14) */
/* WARNING: Removing unreachable block (ram,0xf0078c58) */
/* WARNING: Removing unreachable block (ram,0xf0078c68) */
/* WARNING: Removing unreachable block (ram,0xf0078c84) */
/* WARNING: Removing unreachable block (ram,0xf0078d20) */
/* WARNING: Removing unreachable block (ram,0xf0078d3c) */
/* WARNING: Removing unreachable block (ram,0xf0078d5c) */
/* WARNING: Removing unreachable block (ram,0xf007907c) */
/* WARNING: Removing unreachable block (ram,0xf0078d98) */
/* WARNING: Removing unreachable block (ram,0xf0078e60) */
/* WARNING: Removing unreachable block (ram,0xf0078eac) */
/* WARNING: Removing unreachable block (ram,0xf0078ee0) */
/* WARNING: Removing unreachable block (ram,0xf0078f14) */
/* WARNING: Removing unreachable block (ram,0xf0078e8c) */
/* WARNING: Removing unreachable block (ram,0xf0078f58) */
/* WARNING: Removing unreachable block (ram,0xf0078fc4) */
/* WARNING: Removing unreachable block (ram,0xf0078fec) */
/* WARNING: Removing unreachable block (ram,0xf0079030) */
/* WARNING: Removing unreachable block (ram,0xf00790b8) */
/* WARNING: Removing unreachable block (ram,0xf0078c40) */

undefined8 sub_F0078C2C(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if (param_1 == (int *)0x0) {
    _panic(aZallocNullZone);
    iVar1 = iRam0000002c;
  }
  else {
    iVar1 = param_1[0xb];
  }
  if (iVar1 < 0) {
    _lock_write(param_1 + 0xc);
    piVar3 = (int *)param_1[4];
  }
  else {
    _splusclock();
    do {
      do {
      } while (*param_1 != 0);
      piVar3 = param_1;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    param_1[1] = iVar1;
    piVar3 = (int *)param_1[4];
  }
  *(int **)((int)register0x00000038 + -0xc) = piVar3;
  if (piVar3 != (int *)0x0) {
    param_1[2] = param_1[2] + 1;
    param_1[4] = *piVar3;
    if ((int *)param_1[3] == piVar3) {
      param_1[3] = 0;
    }
  }
  if (*(int *)((int)register0x00000038 + -0xc) == 0) {
    iVar1 = param_1[9];
loc_F0078CE8:
    if (iVar1 != 0) {
      if (param_2 == 0) {
        if ((param_1[0xb] & 0x80000000U) == 0) {
          *param_1 = 0;
          uVar4 = 0;
          _splx(param_1[1]);
        }
        else {
          _lock_done(param_1 + 0xc);
          uVar4 = 0;
        }
        goto locret_F00790C4;
      }
      _assert_wait(param_1 + 9,1);
      if ((param_1[0xb] & 0x80000000U) == 0) {
        *param_1 = 0;
        _splx(param_1[1]);
      }
      else {
        _lock_done(param_1 + 0xc);
      }
      _thread_block_with_continuation(0);
      uVar2 = param_1[0xb];
      if ((uVar2 & 0x80000000) == 0) {
        _splusclock();
        do {
          do {
          } while (*param_1 != 0);
          piVar3 = param_1;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        param_1[1] = uVar2;
      }
      else {
        _lock_write(param_1 + 0xc);
      }
loc_F0079084:
      if (*(int *)((int)register0x00000038 + -0xc) == 0) goto loc_f007908c;
      goto loc_F0079094;
    }
    if ((param_1[0xb] & 0x80000000U) == 0) {
      if ((uint)param_1[6] < (uint)(param_1[5] + param_1[7])) {
        uVar2 = param_1[0xb];
        goto loc_F0078DFC;
      }
      uVar2 = param_1[0xb];
    }
    else if ((uint)param_1[6] < (uint)(param_1[5] + param_1[8])) {
      uVar2 = param_1[0xb];
loc_F0078DFC:
      if ((uVar2 & 0x20000000) != 0) goto loc_F0079094;
      if ((uVar2 & 0x10000000) == 0) {
        if (_zone_ignore_overflow != 0) {
          uVar2 = param_1[0xb];
          goto loc_F0078EB8;
        }
        if ((uVar2 & 0x80000000) == 0) {
          *param_1 = 0;
          _splx(param_1[1]);
        }
        else {
          _lock_done(param_1 + 0xc);
        }
        if (param_2 == 0) {
          uVar4 = 0;
          goto locret_F00790C4;
        }
        _printf(aZoneSEmpty,param_1[10]);
        _panic(&aZalloc);
      }
      else {
        param_1[6] = param_1[6] + ((uint)param_1[6] >> 1);
      }
      uVar2 = param_1[0xb];
    }
    else {
      uVar2 = param_1[0xb];
    }
loc_F0078EB8:
    if ((uVar2 & 0x80000000) != 0) {
      param_1[9] = 1;
    }
    if ((param_1[0xb] & 0x80000000U) == 0) {
      *param_1 = 0;
      _splx(param_1[1]);
      uVar2 = param_1[0xb];
    }
    else {
      _lock_done(param_1 + 0xc);
      uVar2 = param_1[0xb];
    }
    if ((uVar2 & 0x80000000) != 0) {
      iVar1 = _zone_map;
      _kmem_alloc_pageable(_zone_map,(undefined *)((int)register0x00000038 + -0xc),param_1[8]);
      if (iVar1 != 0) {
        _panic(&aZalloc_0);
      }
      _zcram(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),param_1[8]);
      uVar2 = param_1[0xb];
      if ((uVar2 & 0x80000000) == 0) {
        _splusclock();
        do {
          do {
          } while (*param_1 != 0);
          piVar3 = param_1;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        param_1[1] = uVar2;
        param_1[9] = 0;
      }
      else {
        _lock_write(param_1 + 0xc);
        param_1[9] = 0;
      }
      _thread_wakeup_prim(param_1 + 9,0,0);
      piVar3 = (int *)param_1[4];
      *(int **)((int)register0x00000038 + -0xc) = piVar3;
      if (piVar3 != (int *)0x0) {
        param_1[2] = param_1[2] + 1;
        param_1[4] = *piVar3;
        if ((int *)param_1[3] == piVar3) {
          param_1[3] = 0;
        }
      }
      goto loc_F0079084;
    }
    iVar1 = param_1[0xf];
    _zget_space(iVar1,param_1[7],param_2);
    *(int *)((int)register0x00000038 + -0xc) = iVar1;
    if (iVar1 == 0) {
      if (param_2 == 0) {
        uVar4 = 0;
        goto locret_F00790C4;
      }
      _panic(&aZalloc_1);
    }
    uVar2 = param_1[0xb];
    if ((uVar2 & 0x80000000) == 0) {
      _splusclock();
      do {
        do {
        } while (*param_1 != 0);
        piVar3 = param_1;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      param_1[1] = uVar2;
      iVar1 = param_1[2];
    }
    else {
      _lock_write(param_1 + 0xc);
      iVar1 = param_1[2];
    }
    param_1[2] = iVar1 + 1;
    param_1[5] = param_1[5] + param_1[7];
    if ((param_1[0xb] & 0x80000000U) != 0) goto loc_F00790A4;
    iVar1 = param_1[1];
    goto loc_F00790B4;
  }
  iVar1 = param_1[0xb];
loc_F0079098:
  if (iVar1 < 0) {
loc_F00790A4:
    _lock_done(param_1 + 0xc);
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else {
    iVar1 = param_1[1];
loc_F00790B4:
    *param_1 = 0;
    _splx(iVar1);
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
locret_F00790C4:
  return CONCAT44(param_2,uVar4);
loc_f007908c:
  iVar1 = param_1[9];
  goto loc_F0078CE8;
loc_F0079094:
  iVar1 = param_1[0xb];
  goto loc_F0079098;
}
/* GHIDRADEC_FUNCTION index=3573 start=0xf007a350 */

/* WARNING: Removing unreachable block (ram,0xf007a3bc) */
/* WARNING: Removing unreachable block (ram,0xf007a3cc) */
/* WARNING: Removing unreachable block (ram,0xf007a37c) */

undefined8 sub_F007A350(int param_1,int param_2)

{
  int iVar1;
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
  if (*(int *)(param_2 + 0xc) == 0) {
    (**(code **)(param_2 + 4))(param_1,*(undefined4 *)(param_2 + 8));
  }
  else {
    iVar1 = 0x2000;
    _kalloc();
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 8);
    (**(code **)(param_2 + 4))(param_1,iVar1);
    if (*(int *)(iVar1 + 0x1c) == -0x131) {
      param_1 = 0;
    }
    else {
      param_1 = iVar1;
      _msg_send(iVar1,0,0);
    }
    _kfree(iVar1,0x2000);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3574 start=0xf007a3dc */

/* WARNING: Removing unreachable block (ram,0xf007a46c) */

undefined8 sub_F007A3DC(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar1 = *(int *)(param_2 + 0x4b4);
  iVar4 = -200;
  if (param_2 == 0) {
    iVar4 = -0x12f;
    goto locret_F007A490;
  }
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 == *(int *)(param_2 + 0x4ac)) {
    iVar4 = -0x12f;
loc_F007A478:
    iVar3 = iVar4 + 200;
  }
  else {
    if (iVar2 == *(int *)(param_2 + 0x4b0)) {
loc_F007A460:
      iVar4 = param_1;
      sub_F007A350(param_1,param_2 + iVar1 * 0x10 + 0x18c);
      goto loc_F007A478;
    }
    iVar1 = 0;
    iVar3 = param_2;
    do {
      if (*(int *)(iVar3 + 0x18c) == iVar2) break;
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x10;
    } while (iVar1 < 0x32);
    iVar3 = 0;
    if (iVar1 != 0x32) {
      *(int *)(param_2 + 0x4b0) = iVar2;
      *(int *)(param_2 + 0x4b4) = iVar1;
      goto loc_F007A460;
    }
  }
  if (iVar3 == 0) {
    iVar4 = -0x12f;
    *(undefined4 *)(param_2 + 0x4ac) = *(undefined4 *)(param_1 + 0xc);
  }
locret_F007A490:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=3575 start=0xf007ab90 */

/* WARNING: Removing unreachable block (ram,0xf007ac64) */
/* WARNING: Removing unreachable block (ram,0xf007ac40) */
/* WARNING: Removing unreachable block (ram,0xf007ac24) */
/* WARNING: Removing unreachable block (ram,0xf007abe8) */
/* WARNING: Removing unreachable block (ram,0xf007abc8) */
/* WARNING: Removing unreachable block (ram,0xf007ac08) */
/* WARNING: Removing unreachable block (ram,0xf007ac30) */
/* WARNING: Removing unreachable block (ram,0xf007ac48) */
/* WARNING: Removing unreachable block (ram,0xf007ac84) */
/* WARNING: Removing unreachable block (ram,0xf007abac) */

undefined8 sub_F007AB90(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint uVar4;
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
  uVar1 = (param_1[10] - param_1[9]) + _page_mask;
  uVar4 = uVar1 & ~_page_mask;
  _splusclock();
  do {
    do {
    } while (*param_1 != 0);
    piVar2 = param_1;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *param_1 = 0;
  iVar3 = param_1[6];
  param_1[6] = 0;
  _splx(uVar1);
  if (iVar3 != 0) {
    _vm_read_EXTERNAL(param_1[0x133],param_1[9],uVar4,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
    _kern_serv_log_data(iVar3,*(undefined4 *)((int)register0x00000038 + -0xc),
                        param_1[10] - param_1[9] >> 5);
    _port_deallocate_EXTERNAL(param_1[2],iVar3);
    iVar3 = param_1[2];
    _vm_deallocate_EXTERNAL(iVar3,*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
    _splusclock();
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *param_1 = 0;
    param_1[10] = param_1[9];
    _splx(iVar3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3576 start=0xf007ac94 */

/* WARNING: Removing unreachable block (ram,0xf007acdc) */
/* WARNING: Removing unreachable block (ram,0xf007acac) */

undefined8 sub_F007AC94(uint *param_1,int param_2)

{
  uint uVar1;
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
  uint uVar3;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  uVar3 = param_2 * 0x20 + _page_mask;
  uVar1 = uVar3 & ~_page_mask;
  uVar2 = uVar1;
  _kalloc();
  *param_1 = uVar2;
  param_1[2] = uVar2 + (uVar1 & 0xffffffe0);
  param_1[1] = *param_1;
  _printf(aKernServLogIni,param_1,param_1[2],*param_1);
  return CONCAT44(uVar3,param_1);
}
/* GHIDRADEC_FUNCTION index=3577 start=0xf007acec */

/* WARNING: Removing unreachable block (ram,0xf007ad08) */

undefined8 sub_F007ACEC(int *param_1,undefined4 param_2)

{
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
  _kfree(*param_1,(param_1[2] - *param_1) + _page_mask & ~_page_mask);
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3578 start=0xf007ae28 */

/* WARNING: Removing unreachable block (ram,0xf007ae34) */

undefined8 sub_F007AE28(int param_1,undefined4 param_2)

{
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
  _send_notification(*(undefined4 *)(param_1 + 0xc),0x42,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3579 start=0xf007b0c8 */

/* WARNING: Removing unreachable block (ram,0xf007b0e4) */
/* WARNING: Removing unreachable block (ram,0xf007b0d8) */

undefined8 sub_F007B0C8(undefined4 param_1,undefined4 param_2)

{
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
  _printf(aNotificationSe,param_2,param_1);
  _panic(aNotificationSe_0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3580 start=0xf007b0f4 */

/* WARNING: Removing unreachable block (ram,0xf007b110) */
/* WARNING: Removing unreachable block (ram,0xf007b16c) */

undefined8 sub_F007B0F4(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
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
  if (*(int *)(param_1 + 0x14) == 0x76543) {
    puVar2 = (undefined4 *)0x14;
    _kalloc();
    puVar2[2] = *(undefined4 *)(param_1 + 0x1c);
    puVar2[3] = *(undefined4 *)(param_1 + 0x20);
    puVar2[4] = *(undefined4 *)(param_1 + 0x28);
    puVar1 = puVar2;
    if ((undefined4 **)dword_F0130F58 != &dword_F0130F54) {
      *dword_F0130F58 = puVar2;
      puVar1 = dword_F0130F54;
    }
    dword_F0130F54 = puVar1;
    puVar2[1] = dword_F0130F58;
    *puVar2 = &dword_F0130F54;
    dword_F0130F58 = puVar2;
  }
  else {
    _printf(aNotifyServerBo);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3581 start=0xf007b17c */

/* WARNING: Removing unreachable block (ram,0xf007b27c) */
/* WARNING: Removing unreachable block (ram,0xf007b244) */
/* WARNING: Removing unreachable block (ram,0xf007b2a4) */
/* WARNING: Removing unreachable block (ram,0xf007b22c) */
/* WARNING: Removing unreachable block (ram,0xf007b194) */

undefined8 sub_F007B17C(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  undefined4 unaff_l3;
  int iVar7;
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
  iVar7 = 0;
  if (*(int *)(param_1 + 0x14) == 0x41) {
    iVar3 = 0;
    if ((undefined4 **)dword_F0130F54 != &dword_F0130F54) {
      iVar3 = *(int *)(param_1 + 0x1c);
      puVar5 = dword_F0130F54;
      do {
        puVar6 = (undefined4 *)*puVar5;
        if (iVar3 == puVar5[3]) {
          puVar2 = (undefined4 *)puVar5[1];
          puVar4 = puVar6;
          puVar1 = puVar2;
          if ((undefined4 **)puVar6 != &dword_F0130F54) {
            puVar6[1] = puVar2;
            puVar1 = dword_F0130F58;
          }
loc_F007B268:
          dword_F0130F58 = puVar1;
          if ((undefined4 **)puVar2 != &dword_F0130F54) {
            *puVar2 = puVar4;
            puVar4 = dword_F0130F54;
          }
          dword_F0130F54 = puVar4;
          _kfree(puVar5,0x14);
          iVar7 = iVar7 + 1;
        }
        else if (iVar3 == puVar5[2]) {
          *(undefined4 *)(param_1 + 0x10) = puVar5[3];
          *(undefined4 *)(param_1 + 0xc) = 0;
          *(undefined *)(param_1 + 3) = 1;
          *(undefined *)(param_1 + 0x18) = 2;
          *(undefined *)(param_1 + 0x19) = 0x20;
          *(undefined4 *)(param_1 + 0x1c) = puVar5[4];
          iVar3 = param_1;
          _msg_send(param_1,1,0);
          if (iVar3 == 0) {
            puVar4 = (undefined4 *)*puVar5;
          }
          else {
            _printf(aPnNotifyMsgSen,iVar3);
            puVar4 = (undefined4 *)*puVar5;
          }
          puVar2 = (undefined4 *)puVar5[1];
          puVar1 = puVar2;
          if ((undefined4 **)puVar4 != &dword_F0130F54) {
            puVar4[1] = puVar2;
            puVar1 = dword_F0130F58;
          }
          goto loc_F007B268;
        }
        iVar3 = iVar7;
        if ((undefined4 **)puVar6 == &dword_F0130F54) break;
        iVar3 = *(int *)(param_1 + 0x1c);
        puVar5 = puVar6;
      } while( true );
    }
    if (iVar3 == 0) {
      _printf(aPnNotifyPortNo);
    }
  }
  else {
    _printf(aPnNotifyMsgIdD);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3582 start=0xf007b3f4 */

undefined8 sub_F007B3F4(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x2200018) {
      if ((code *)param_3[2] == (code *)0x0) {
        *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
        goto locret_F007B478;
      }
      uVar1 = *param_3;
      (*(code *)param_3[2])(uVar1,*(undefined4 *)(param_1 + 0x1c));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
locret_F007B478:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3583 start=0xf007b480 */

undefined8 sub_F007B480(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x6200018) {
      if ((code *)param_3[3] == (code *)0x0) {
        *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
        goto locret_F007B504;
      }
      uVar1 = *param_3;
      (*(code *)param_3[3])(uVar1,*(undefined4 *)(param_1 + 0x1c));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
locret_F007B504:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3584 start=0xf007b50c */

undefined8 sub_F007B50C(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x28) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if ((*(int *)(param_1 + 0x18) == 0x2200018) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) {
      if ((code *)param_3[4] == (code *)0x0) {
        *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
        goto locret_F007B5AC;
      }
      uVar1 = *param_3;
      (*(code *)param_3[4])(uVar1,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
locret_F007B5AC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3585 start=0xf007b5b4 */

undefined8 sub_F007B5B4(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x28) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if ((*(int *)(param_1 + 0x18) == 0x2200018) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) {
      if ((code *)param_3[5] == (code *)0x0) {
        *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
        goto locret_F007B654;
      }
      uVar1 = *param_3;
      (*(code *)param_3[5])(uVar1,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
locret_F007B654:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3586 start=0xf007b65c */

undefined8 sub_F007B65C(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x30) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x5200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) {
      if ((code *)param_3[6] == (code *)0x0) {
        *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
        goto locret_F007B718;
      }
      uVar1 = *param_3;
      (*(code *)param_3[6])
                (uVar1,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24),
                 *(undefined4 *)(param_1 + 0x2c));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
locret_F007B718:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3587 start=0xf007b720 */

undefined8 sub_F007B720(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x2200018) {
      if ((code *)param_3[7] == (code *)0x0) {
        uVar1 = 0xfffffed1;
      }
      else {
        (*(code *)param_3[7])(*param_3,*(undefined4 *)(param_1 + 0x1c));
        uVar1 = 0xfffffecf;
      }
    }
  }
  else {
    uVar1 = 0xfffffed0;
  }
  *(undefined4 *)(param_2 + 0x1c) = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3588 start=0xf007b78c */

undefined8 sub_F007B78C(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x28) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if ((*(int *)(param_1 + 0x18) == 0x2200018) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) {
      if ((code *)param_3[8] == (code *)0x0) {
        *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
        goto locret_F007B82C;
      }
      uVar1 = *param_3;
      (*(code *)param_3[8])(uVar1,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
locret_F007B82C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3589 start=0xf007b834 */

undefined8 sub_F007B834(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x18) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed1;
    if ((code *)param_3[9] != (code *)0x0) {
      (*(code *)param_3[9])(*param_3);
      uVar1 = 0xfffffecf;
    }
  }
  else {
    uVar1 = 0xfffffed0;
  }
  *(undefined4 *)(param_2 + 0x1c) = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3590 start=0xf007b880 */

undefined8 sub_F007B880(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x2200018) {
      if ((code *)param_3[10] == (code *)0x0) {
        uVar1 = 0xfffffed1;
      }
      else {
        (*(code *)param_3[10])(*param_3,*(undefined4 *)(param_1 + 0x1c));
        uVar1 = 0xfffffecf;
      }
    }
  }
  else {
    uVar1 = 0xfffffed0;
  }
  *(undefined4 *)(param_2 + 0x1c) = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3591 start=0xf007b8ec */

undefined8 sub_F007B8EC(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x6200018) {
      if ((code *)param_3[0xb] == (code *)0x0) {
        uVar1 = 0xfffffed1;
      }
      else {
        (*(code *)param_3[0xb])(*param_3,*(undefined4 *)(param_1 + 0x1c));
        uVar1 = 0xfffffecf;
      }
    }
  }
  else {
    uVar1 = 0xfffffed0;
  }
  *(undefined4 *)(param_2 + 0x1c) = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3592 start=0xf007b958 */

undefined8 sub_F007B958(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x30) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if (((*(int *)(param_1 + 0x18) == 0x5200018) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x2200018)) &&
       (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) {
      if ((code *)param_3[0xc] == (code *)0x0) {
        *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
        goto locret_F007BA14;
      }
      uVar1 = *param_3;
      (*(code *)param_3[0xc])
                (uVar1,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24),
                 *(undefined4 *)(param_1 + 0x2c));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
locret_F007BA14:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3593 start=0xf007ba1c */

undefined8 sub_F007BA1C(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x2200018) {
      if ((code *)param_3[0xd] == (code *)0x0) {
        *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
        goto locret_F007BAA0;
      }
      uVar1 = *param_3;
      (*(code *)param_3[0xd])(uVar1,*(undefined4 *)(param_1 + 0x1c));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
locret_F007BAA0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3594 start=0xf007baa8 */

undefined8 sub_F007BAA8(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x20) && (*(char *)(param_1 + 3) == '\x01')) {
    uVar1 = 0xfffffed0;
    if (*(int *)(param_1 + 0x18) == 0x2200018) {
      if ((code *)param_3[0xe] == (code *)0x0) {
        *(undefined4 *)(param_2 + 0x1c) = 0xfffffed1;
        goto locret_F007BB2C;
      }
      uVar1 = *param_3;
      (*(code *)param_3[0xe])(uVar1,*(undefined4 *)(param_1 + 0x1c));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
locret_F007BB2C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3595 start=0xf007bee8 */

/* WARNING: Removing unreachable block (ram,0xf007bf9c) */

undefined8 sub_F007BEE8(int param_1,int param_2)

{
  undefined4 uVar1;
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
  if ((*(int *)(param_1 + 4) == 0x40) && (*(char *)(param_1 + 3) == '\0')) {
    uVar1 = 0xfffffed0;
    if ((((*(int *)(param_1 + 0x18) == 0x6200018) &&
         (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x20) == 0x6200018)) &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x28) == 0x2200018)) &&
       ((uVar1 = 0xfffffed0, *(int *)(param_1 + 0x30) == 0x2200018 &&
        (uVar1 = 0xfffffed0, *(int *)(param_1 + 0x38) == 0x2200018)))) {
      uVar1 = *(undefined4 *)(param_1 + 0xc);
      _catch_exception_raise
                (uVar1,*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24),
                 *(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x34),
                 *(undefined4 *)(param_1 + 0x3c));
    }
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined *)(param_2 + 3) = 1;
      *(undefined4 *)(param_2 + 4) = 0x20;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3596 start=0xf007c05c */

/* WARNING: Removing unreachable block (ram,0xf007c098) */
/* WARNING: Removing unreachable block (ram,0xf007c08c) */

undefined8 sub_F007C05C(uint *param_1,uint *param_2)

{
  uint uVar1;
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
  if ((param_1[1] == 0x18) && ((*param_1 & 0x80000000) == 0)) {
    uVar1 = param_1[2];
    _convert_port_to_host_priv();
    _host_processors();
    param_2[7] = uVar1;
    if (uVar1 == 0) {
      param_2[1] = 0x30;
      *param_2 = *param_2 | 0x80000000;
      param_2[8] = dword_F011105C;
      param_2[9] = DAT_f0111060._0_4_;
      uVar1 = *(uint *)((int)register0x00000038 + -0xc);
      param_2[10] = DAT_f0111060._4_4_;
      param_2[10] = uVar1;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3597 start=0xf007c0f0 */

/* WARNING: Removing unreachable block (ram,0xf007c148) */
/* WARNING: Removing unreachable block (ram,0xf007c138) */

undefined8 sub_F007C0F0(int *param_1,int param_2)

{
  int iVar1;
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
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == dword_F0111068)) {
    iVar1 = param_1[2];
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0x400;
    _convert_port_to_host();
    _host_info();
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x20) = dword_F011106C;
      *(undefined4 *)(param_2 + 0x24) = DAT_f0111070._0_4_;
      iVar1 = *(int *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(param_2 + 0x28) = DAT_f0111070._4_4_;
      *(int *)(param_2 + 0x28) = iVar1;
      *(int *)(param_2 + 4) = iVar1 * 4 + 0x2c;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3598 start=0xf007c198 */

/* WARNING: Removing unreachable block (ram,0xf007c1fc) */
/* WARNING: Removing unreachable block (ram,0xf007c228) */
/* WARNING: Removing unreachable block (ram,0xf007c1e8) */

undefined8 sub_F007C198(uint *param_1,uint *param_2)

{
  uint uVar1;
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
  if (((param_1[1] == 0x20) && ((*param_1 & 0x80000000) == 0)) && (param_1[6] == dword_F0111078)) {
    uVar1 = param_1[2];
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0x400;
    _convert_port_to_processor();
    _processor_info();
    param_2[7] = uVar1;
    if (uVar1 == 0) {
      *param_2 = *param_2 | 0x80000000;
      uVar1 = *(uint *)((int)register0x00000038 + -0xc);
      param_2[8] = dword_F011107C;
      _convert_host_to_port();
      param_2[9] = uVar1;
      param_2[10] = dword_F0111080;
      param_2[0xb] = DAT_f0111084._0_4_;
      uVar1 = *(uint *)((int)register0x00000038 + -0x10);
      param_2[0xc] = DAT_f0111084._4_4_;
      param_2[0xc] = uVar1;
      param_2[1] = uVar1 * 4 + 0x34;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3599 start=0xf007c270 */

/* WARNING: Removing unreachable block (ram,0xf007c29c) */
/* WARNING: Removing unreachable block (ram,0xf007c294) */

undefined8 sub_F007C270(int *param_1,int param_2)

{
  int iVar1;
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
  iVar1 = -0x130;
  if ((param_1[1] == 0x18) && (iVar1 = -0x130, -1 < *param_1)) {
    iVar1 = param_1[2];
    _convert_port_to_processor();
    _processor_start();
  }
  *(int *)(param_2 + 0x1c) = iVar1;
  return CONCAT44(param_2,param_1);
}

