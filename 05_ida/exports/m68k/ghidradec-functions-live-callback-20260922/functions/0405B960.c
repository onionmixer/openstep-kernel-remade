
void sub_405B960(int *param_1,byte *param_2)

{
  byte *pbVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  uint uStack_814;
  undefined *puStack_810;
  uint uStack_80c;
  byte *pbStack_808;
  undefined auStack_804 [2048];
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == dword_40B05B4)) &&
     (param_1[8] == dword_40B05B8)) {
    pbVar1 = param_2 + 0x2c;
    uStack_80c = 0xaa;
    if ((uint)param_1[7] < 0xaa) {
      uStack_80c = param_1[7];
    }
    puVar2 = auStack_804;
    uStack_814 = 0x100;
    if ((uint)param_1[9] < 0x100) {
      uStack_814 = param_1[9];
    }
    puStack_810 = puVar2;
    pbStack_808 = pbVar1;
    uVar3 = _convert_port_to_host(param_1[2],&pbStack_808,&uStack_80c,&puStack_810,&uStack_814);
    iVar4 = _host_zone_free_space_info(uVar3);
    *(int *)(param_2 + 0x1c) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 *)(param_2 + 0x20) = dword_40B05BC;
      *(undefined4 *)(param_2 + 0x24) = dword_40B05C0;
      *(undefined4 *)(param_2 + 0x28) = dword_40B05C4;
      bVar5 = pbVar1 != pbStack_808;
      if (bVar5) {
        param_2[0x23] = param_2[0x23] & 0xf7 | 2;
        *(byte **)pbVar1 = pbStack_808;
      }
      *(uint *)(param_2 + 0x28) = uStack_80c * 3;
      iVar4 = 4;
      if ((param_2[0x23] & 8) != 0) {
        iVar4 = uStack_80c * 0xc;
      }
      *(undefined4 *)(param_2 + iVar4 + 0x2c) = dword_40B05C8;
      *(undefined4 *)(param_2 + iVar4 + 0x30) = dword_40B05CC;
      *(undefined4 *)(param_2 + iVar4 + 0x34) = dword_40B05D0;
      bVar6 = puVar2 == puStack_810;
      if (bVar6) {
        _bcopy(puStack_810,param_2 + iVar4 + 0x38,uStack_814 << 3);
      }
      else {
        param_2[iVar4 + 0x2f] = param_2[iVar4 + 0x2f] & 0xf7 | 2;
        *(undefined **)(param_2 + iVar4 + 0x38) = puStack_810;
      }
      *(uint *)(param_2 + iVar4 + 0x34) = uStack_814 * 2;
      if ((param_2[iVar4 + 0x2f] & 8) == 0) {
        iVar4 = iVar4 + 0x3c;
      }
      else {
        iVar4 = iVar4 + 0x38 + uStack_814 * 8;
      }
      if (!bVar6 || bVar5) {
        *param_2 = *param_2 | 0x80;
      }
      *(int *)(param_2 + 4) = iVar4;
    }
  }
  else {
    param_2[0x1c] = 0xff;
    param_2[0x1d] = 0xff;
    param_2[0x1e] = 0xfe;
    param_2[0x1f] = 0xd0;
  }
  return;
}

