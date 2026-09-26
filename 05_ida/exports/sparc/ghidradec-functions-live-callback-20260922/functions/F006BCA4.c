
/* WARNING: Removing unreachable block (ram,0xf006bd50) */
/* WARNING: Removing unreachable block (ram,0xf006be48) */
/* WARNING: Removing unreachable block (ram,0xf006bdd0) */
/* WARNING: Removing unreachable block (ram,0xf006bd30) */
/* WARNING: Removing unreachable block (ram,0xf006bcf0) */
/* WARNING: Removing unreachable block (ram,0xf006bd1c) */
/* WARNING: Removing unreachable block (ram,0xf006bd3c) */
/* WARNING: Removing unreachable block (ram,0xf006bdd8) */
/* WARNING: Removing unreachable block (ram,0xf006be5c) */
/* WARNING: Removing unreachable block (ram,0xf006be64) */
/* WARNING: Removing unreachable block (ram,0xf006bcc8) */

undefined8 _receive_ip_datagram(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  byte *pbVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  uint uVar8;
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
  iVar4 = *param_1;
  pbVar6 = (byte *)(iVar4 + *(int *)(iVar4 + 4));
  if (5 < (*(byte *)(iVar4 + *(int *)(iVar4 + 4)) & 0xf)) {
    _ip_stripoptions(pbVar6,0);
  }
  if ((*(uint *)(iVar4 + 4) < 0x7d) && (0x17 < *(word *)(iVar4 + 8))) {
loc_F006BD0C:
    iVar2 = *(int *)(pbVar6 + 0xc);
    _find_listener(iVar2,*(undefined2 *)(pbVar6 + 0x14),*(undefined4 *)(pbVar6 + 0x10),
                   *(undefined2 *)(pbVar6 + 0x16),pbVar6[9]);
    uVar7 = 0;
    if (iVar2 == 0) goto locret_F006BE70;
    _spl0();
    iVar3 = _mach_net_kmsg_zone;
    _zget();
    if (iVar3 == 0) {
      _m_freem(iVar4);
    }
    else {
      *(undefined4 *)(iVar3 + 8) = 0xfffffffd;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      uVar5 = 0x7d4;
      *(word *)(pbVar6 + 2) = *(sword *)(pbVar6 + 2) + (*pbVar6 & 0xf) * 4;
      *(sword *)(pbVar6 + 6) = *(sword *)(pbVar6 + 6) >> 3;
      iVar1 = iVar3 + 0x2c;
      while (iVar4 != 0) {
        if ((int)uVar5 < 1) {
          *(uint *)(iVar3 + 0x10) = uVar5;
          goto loc_F006BDF0;
        }
        uVar8 = (int)*(sword *)(iVar4 + 8);
        if ((int)uVar5 < (int)*(sword *)(iVar4 + 8)) {
          uVar8 = uVar5;
        }
        uVar5 = uVar5 - uVar8;
        _bcopy(iVar4 + *(int *)(iVar4 + 4),iVar1);
        _m_free();
        iVar1 = iVar1 + uVar8;
      }
      *(uint *)(iVar3 + 0x10) = uVar5;
loc_F006BDF0:
      *(uint *)(iVar3 + 0x10) = (uVar5 & 0xfffffffc) - *(int *)(iVar3 + 0x10);
      *(undefined4 *)(iVar3 + 0x14) = dword_F012F684;
      *(undefined4 *)(iVar3 + 0x18) = DAT_f012f688._0_4_;
      *(undefined4 *)(iVar3 + 0x1c) = DAT_f012f688._4_4_;
      *(undefined4 *)(iVar3 + 0x20) = DAT_f012f688._8_4_;
      *(undefined4 *)(iVar3 + 0x24) = DAT_f012f688._12_4_;
      *(undefined4 *)(iVar3 + 0x28) = DAT_f012f688._16_4_;
      *(uint *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) - (uVar5 & 0xfffffffc);
      *(int *)(iVar3 + 0x1c) = iVar2;
      _ipc_object_reference();
      _ipc_mqueue_send(iVar3,0x10000,0,0);
    }
    _splnet();
  }
  else {
    _m_pullup(iVar4,0x18);
    *param_1 = iVar4;
    if (iVar4 != 0) {
      pbVar6 = (byte *)(iVar4 + *(int *)(iVar4 + 4));
      goto loc_F006BD0C;
    }
  }
  uVar7 = 1;
locret_F006BE70:
  return CONCAT44(param_2,uVar7);
}

