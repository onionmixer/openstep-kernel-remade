/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012b2c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _udp_input(int param_1,undefined4 param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  int local_20;
  undefined4 local_18 [5];
  
  local_20 = param_1;
  if (((0x7c < *(uint *)(param_1 + 4)) || (*(ushort *)(param_1 + 8) < 0x1c)) &&
     (local_20 = _m_pullup(param_1,0x1c), local_20 == 0)) {
    __udpstat = __udpstat + 1;
    return;
  }
  pbVar5 = (byte *)(local_20 + *(int *)(local_20 + 4));
  if (5 < (*pbVar5 & 0xf)) {
    _ip_stripoptions(pbVar5,0);
  }
  uVar7 = (uint)(ushort)(*(ushort *)(pbVar5 + 0x18) >> 8 | *(ushort *)(pbVar5 + 0x18) << 8);
  uVar2 = (uint)*(short *)(pbVar5 + 2);
  if (uVar2 != uVar7) {
    if ((int)uVar2 < (int)uVar7) {
      _DAT_001eab28 = _DAT_001eab28 + 1;
      goto LAB_0012b62c;
    }
    _m_adj(local_20,uVar7 - uVar2);
  }
  pbVar8 = pbVar5;
  puVar9 = local_18;
  for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = *(undefined4 *)pbVar8;
    pbVar8 = pbVar8 + 4;
    puVar9 = puVar9 + 1;
  }
  if ((_udpcksum != 0) && (*(short *)(pbVar5 + 0x1a) != 0)) {
    pbVar5[4] = 0;
    pbVar5[5] = 0;
    pbVar5[6] = 0;
    pbVar5[7] = 0;
    pbVar5[0] = 0;
    pbVar5[1] = 0;
    pbVar5[2] = 0;
    pbVar5[3] = 0;
    pbVar5[8] = 0;
    *(undefined2 *)(pbVar5 + 10) = *(undefined2 *)(pbVar5 + 0x18);
    sVar1 = _in_cksum(local_20,uVar7 + 0x14);
    *(short *)(pbVar5 + 0x1a) = sVar1;
    if (sVar1 != 0) {
      _DAT_001eab24 = _DAT_001eab24 + 1;
      goto LAB_0012b62c;
    }
  }
  if (((*(uint *)(pbVar5 + 0x10) & 0xf0) == 0xe0) ||
     (iVar6 = _in_broadcast(*(uint *)(pbVar5 + 0x10)), iVar6 != 0)) {
    _DAT_001dbef6 = *(undefined2 *)(pbVar5 + 0x14);
    _DAT_001dbef8 = *(undefined4 *)(pbVar5 + 0xc);
    *(short *)(local_20 + 8) = *(short *)(local_20 + 8) + -0x1c;
    *(int *)(local_20 + 4) = *(int *)(local_20 + 4) + 0x1c;
    iVar6 = 0;
    for (puVar9 = _udb; (undefined4 **)puVar9 != &_udb; puVar9 = (undefined4 *)*puVar9) {
      if (((*(short *)(puVar9 + 6) == *(short *)(pbVar5 + 0x16)) &&
          ((puVar9[5] == 0 || (*(int *)(pbVar5 + 0x10) == puVar9[5])))) &&
         ((puVar9[3] == 0 ||
          ((*(int *)(pbVar5 + 0xc) == puVar9[3] &&
           (*(short *)(puVar9 + 4) == *(short *)(pbVar5 + 0x14))))))) {
        if ((iVar6 != 0) && (iVar3 = _m_copy(local_20,0,1000000000), iVar3 != 0)) {
          iVar4 = _sbappendaddr(iVar6 + 0x24,&_udp_in,iVar3,0);
          if (iVar4 == 0) {
            _m_freem(iVar3);
          }
          else {
            _sowakeup(iVar6,iVar6 + 0x24);
          }
        }
        iVar6 = puVar9[7];
        if ((*(byte *)(iVar6 + 2) & 4) == 0) break;
      }
    }
    if (iVar6 != 0) {
      iVar3 = iVar6 + 0x24;
      iVar4 = _sbappendaddr(iVar3,&_udp_in,local_20,0);
      if (iVar4 != 0) goto LAB_0012b620;
    }
  }
  else {
    iVar6 = _in_pcblookup(&_udb,*(undefined4 *)(pbVar5 + 0xc),*(undefined2 *)(pbVar5 + 0x14),
                          *(undefined4 *)(pbVar5 + 0x10),*(undefined2 *)(pbVar5 + 0x16),1);
    if (iVar6 == 0) {
      uVar2 = *(uint *)(pbVar5 + 0x10);
      uVar2 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      for (iVar6 = _in_ifaddr; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x40)) {
        if (((*(byte *)(*(int *)(iVar6 + 0x20) + 0xc) & 2) != 0) &&
           ((((uVar7 = *(uint *)(iVar6 + 0x28) ^ uVar2, uVar7 == ~*(uint *)(iVar6 + 0x2c) ||
              (uVar7 == 0)) ||
             (uVar7 = *(uint *)(iVar6 + 0x30) ^ uVar2, uVar7 == ~*(uint *)(iVar6 + 0x34))) ||
            (uVar7 == 0)))) goto LAB_0012b62c;
      }
      iVar6 = *(int *)(pbVar5 + 0x10);
      if (((iVar6 != -1) && (iVar6 != 0)) && (iVar6 = _in_broadcast(iVar6), iVar6 == 0)) {
        puVar9 = local_18;
        pbVar8 = pbVar5;
        for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined4 *)pbVar8 = *puVar9;
          puVar9 = puVar9 + 1;
          pbVar8 = pbVar8 + 4;
        }
        _icmp_error(pbVar5,3,3,param_2,0);
        return;
      }
    }
    else {
      _DAT_001dbef6 = *(undefined2 *)(pbVar5 + 0x14);
      _DAT_001dbef8 = *(undefined4 *)(pbVar5 + 0xc);
      *(short *)(local_20 + 8) = *(short *)(local_20 + 8) + -0x1c;
      *(int *)(local_20 + 4) = *(int *)(local_20 + 4) + 0x1c;
      iVar3 = _sbappendaddr(*(int *)(iVar6 + 0x1c) + 0x24,&_udp_in,local_20,0);
      if (iVar3 != 0) {
        iVar6 = *(int *)(iVar6 + 0x1c);
        iVar3 = iVar6 + 0x24;
LAB_0012b620:
        _sowakeup(iVar6,iVar3);
        return;
      }
    }
  }
LAB_0012b62c:
  _m_freem(local_20);
  return;
}

