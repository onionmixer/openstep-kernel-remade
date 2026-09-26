
void _udp_input(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  sword sVar10;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  
  if (((0x7c < *(uint *)(param_1 + 4)) || (*(word *)(param_1 + 8) < 0x1c)) &&
     (param_1 = _m_pullup(param_1,0x1c), param_1 == 0)) {
    _udpstat = _udpstat + 1;
    return;
  }
  pbVar13 = (byte *)(*(int *)(param_1 + 4) + param_1);
  if (5 < (*pbVar13 & 0xf)) {
    _ip_stripoptions(pbVar13,0);
  }
  uVar11 = (uint)*(word *)(pbVar13 + 0x18);
  uVar12 = (uint)*(sword *)(pbVar13 + 2);
  if (uVar11 != uVar12) {
    if ((int)uVar12 < (int)uVar11) {
      dword_40B6A5C = dword_40B6A5C + 1;
      goto loc_40257AA;
    }
    _m_adj(param_1,uVar11 - uVar12);
  }
  uVar3 = *(undefined4 *)pbVar13;
  uVar4 = *(undefined4 *)(pbVar13 + 4);
  uVar5 = *(undefined4 *)(pbVar13 + 8);
  uVar6 = *(undefined4 *)(pbVar13 + 0xc);
  uVar1 = *(undefined4 *)(pbVar13 + 0x10);
  if ((_udpcksum != 0) && (*(sword *)(pbVar13 + 0x1a) != 0)) {
    pbVar13[4] = 0;
    pbVar13[5] = 0;
    pbVar13[6] = 0;
    pbVar13[7] = 0;
    pbVar13[0] = 0;
    pbVar13[1] = 0;
    pbVar13[2] = 0;
    pbVar13[3] = 0;
    pbVar13[8] = 0;
    *(undefined2 *)(pbVar13 + 10) = *(undefined2 *)(pbVar13 + 0x18);
    sVar10 = _in_cksum(param_1,uVar11 + 0x14);
    *(sword *)(pbVar13 + 0x1a) = sVar10;
    if (sVar10 != 0) {
      dword_40B6A58 = dword_40B6A58 + 1;
      goto loc_40257AA;
    }
  }
  if (((*(uint *)(pbVar13 + 0x10) & 0xf0000000) == 0xe0000000) ||
     (iVar7 = _in_broadcast(*(uint *)(pbVar13 + 0x10)), iVar7 != 0)) {
    word_40AEBCA = *(undefined2 *)(pbVar13 + 0x14);
    dword_40AEBCC = *(undefined4 *)(pbVar13 + 0xc);
    *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x1c;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x1c;
    iVar7 = 0;
    for (puVar2 = _udb; (undefined4 **)puVar2 != &_udb; puVar2 = (undefined4 *)*puVar2) {
      if (((*(sword *)(pbVar13 + 0x16) == *(sword *)((int)puVar2 + 0x16)) &&
          ((*(int *)((int)puVar2 + 0x12) == 0 ||
           (*(int *)((int)puVar2 + 0x12) == *(int *)(pbVar13 + 0x10))))) &&
         ((puVar2[3] == 0 ||
          ((puVar2[3] == *(int *)(pbVar13 + 0xc) &&
           (*(sword *)(pbVar13 + 0x14) == *(sword *)(puVar2 + 4))))))) {
        if ((iVar7 != 0) && (iVar8 = _m_copy(param_1,0,1000000000), iVar8 != 0)) {
          iVar9 = _sbappendaddr(iVar7 + 0x22,&_udp_in,iVar8,0);
          if (iVar9 == 0) {
            _m_freem(iVar8);
          }
          else {
            _sowakeup(iVar7,iVar7 + 0x22);
          }
        }
        iVar7 = puVar2[6];
        if ((*(byte *)(iVar7 + 3) & 4) == 0) break;
      }
    }
    if (iVar7 != 0) {
      iVar8 = _sbappendaddr(iVar7 + 0x22,&_udp_in,param_1,0);
      if (iVar8 != 0) {
        _sowakeup(iVar7,iVar7 + 0x22);
        return;
      }
    }
  }
  else {
    iVar7 = _in_pcblookup(&_udb,*(undefined4 *)(pbVar13 + 0xc),*(undefined2 *)(pbVar13 + 0x14),
                          *(undefined4 *)(pbVar13 + 0x10),*(undefined2 *)(pbVar13 + 0x16),1);
    if (iVar7 == 0) {
      for (iVar7 = _in_ifaddr; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x40)) {
        if (((*(byte *)(*(int *)(iVar7 + 0x20) + 0xd) & 2) != 0) &&
           ((((uVar11 = *(uint *)(pbVar13 + 0x10) ^ *(uint *)(iVar7 + 0x28),
              ~*(uint *)(iVar7 + 0x2c) == uVar11 || (uVar11 == 0)) ||
             (uVar11 = *(uint *)(pbVar13 + 0x10) ^ *(uint *)(iVar7 + 0x30),
             ~*(uint *)(iVar7 + 0x34) == uVar11)) || (uVar11 == 0)))) goto loc_40257AA;
      }
      iVar7 = *(int *)(pbVar13 + 0x10);
      if (((iVar7 != -1) && (iVar7 != 0)) && (iVar7 = _in_broadcast(iVar7), iVar7 == 0)) {
        *(undefined4 *)pbVar13 = uVar3;
        *(undefined4 *)(pbVar13 + 4) = uVar4;
        *(undefined4 *)(pbVar13 + 8) = uVar5;
        *(undefined4 *)(pbVar13 + 0xc) = uVar6;
        *(undefined4 *)(pbVar13 + 0x10) = uVar1;
        _icmp_error(pbVar13,3,3,param_2,0);
        return;
      }
    }
    else {
      word_40AEBCA = *(undefined2 *)(pbVar13 + 0x14);
      dword_40AEBCC = *(undefined4 *)(pbVar13 + 0xc);
      *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + -0x1c;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x1c;
      iVar8 = _sbappendaddr(*(int *)(iVar7 + 0x18) + 0x22,&_udp_in,param_1,0);
      if (iVar8 != 0) {
        _sowakeup(*(int *)(iVar7 + 0x18),*(int *)(iVar7 + 0x18) + 0x22);
        return;
      }
    }
  }
loc_40257AA:
  _m_freem(param_1);
  return;
}

