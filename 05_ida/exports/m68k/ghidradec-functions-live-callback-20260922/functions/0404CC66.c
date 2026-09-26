
undefined4 _receive_ip_datagram(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = *param_1;
  pbVar5 = (byte *)(*(int *)(iVar1 + 4) + iVar1);
  if (5 < (*pbVar5 & 0xf)) {
    _ip_stripoptions(pbVar5,0);
  }
  if ((0x7c < *(uint *)(iVar1 + 4)) || (*(word *)(iVar1 + 8) < 0x18)) {
    iVar1 = _m_pullup(iVar1,0x18);
    *param_1 = iVar1;
    if (iVar1 == 0) {
      return 1;
    }
    pbVar5 = (byte *)(*(int *)(iVar1 + 4) + iVar1);
  }
  iVar2 = _find_listener(*(undefined4 *)(pbVar5 + 0xc),*(undefined2 *)(pbVar5 + 0x14),
                         *(undefined4 *)(pbVar5 + 0x10),*(undefined2 *)(pbVar5 + 0x16),pbVar5[9]);
  if (iVar2 != 0) {
    iVar3 = _zget(_mach_net_kmsg_zone);
    if (iVar3 == 0) {
      _m_freem(iVar1);
    }
    else {
      *(undefined4 *)(iVar3 + 8) = 0xfffffffd;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      *(word *)(pbVar5 + 2) = (*pbVar5 & 0xf) * 4 + *(sword *)(pbVar5 + 2);
      *(sword *)(pbVar5 + 6) = *(sword *)(pbVar5 + 6) >> 3;
      iVar7 = iVar3 + 0x2c;
      for (uVar4 = 0x7d4; (iVar1 != 0 && (0 < (int)uVar4)); uVar4 = uVar4 - uVar6) {
        uVar6 = (int)*(sword *)(iVar1 + 8);
        if ((int)uVar4 < (int)*(sword *)(iVar1 + 8)) {
          uVar6 = uVar4;
        }
        _bcopy(*(int *)(iVar1 + 4) + iVar1,iVar7,uVar6);
        iVar7 = uVar6 + iVar7;
        iVar1 = _m_free(iVar1);
      }
      *(uint *)(iVar3 + 0x10) = uVar4;
      *(uint *)(iVar3 + 0x10) = (uVar4 & 0xfffffffc) - *(int *)(iVar3 + 0x10);
      *(undefined4 *)(iVar3 + 0x14) = dword_40B3722;
      *(undefined4 *)(iVar3 + 0x18) = dword_40B3726;
      *(undefined4 *)(iVar3 + 0x1c) = dword_40B372A;
      *(undefined4 *)(iVar3 + 0x20) = dword_40B372E;
      *(undefined4 *)(iVar3 + 0x24) = dword_40B3732;
      *(undefined4 *)(iVar3 + 0x28) = dword_40B3736;
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) - (uVar4 & 0xfffffffc);
      *(int *)(iVar3 + 0x1c) = iVar2;
      _ipc_object_reference(iVar2);
      _ipc_mqueue_send(iVar3,0x10000,0,0);
    }
    return 1;
  }
  return 0;
}

