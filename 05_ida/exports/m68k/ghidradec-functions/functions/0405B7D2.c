
void sub_405B7D2(int *param_1,byte *param_2)

{
  byte *pbVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  uint uStack_7f4;
  undefined *puStack_7f0;
  uint uStack_7ec;
  byte *pbStack_7e8;
  undefined auStack_7e4 [2016];
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == dword_40B0594)) &&
     (param_1[8] == dword_40B0598)) {
    pbVar1 = param_2 + 0x2c;
    uStack_7ec = 0x19;
    if ((uint)param_1[7] < 0x19) {
      uStack_7ec = param_1[7];
    }
    puVar2 = auStack_7e4;
    uStack_7f4 = 0x38;
    if ((uint)param_1[9] < 0x38) {
      uStack_7f4 = param_1[9];
    }
    puStack_7f0 = puVar2;
    pbStack_7e8 = pbVar1;
    uVar3 = _convert_port_to_host(param_1[2],&pbStack_7e8,&uStack_7ec,&puStack_7f0,&uStack_7f4);
    iVar4 = _host_zone_info(uVar3);
    *(int *)(param_2 + 0x1c) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 *)(param_2 + 0x20) = dword_40B059C;
      *(undefined4 *)(param_2 + 0x24) = dword_40B05A0;
      *(undefined4 *)(param_2 + 0x28) = dword_40B05A4;
      bVar5 = pbVar1 != pbStack_7e8;
      if (bVar5) {
        param_2[0x23] = param_2[0x23] & 0xf7 | 2;
        *(byte **)pbVar1 = pbStack_7e8;
      }
      *(uint *)(param_2 + 0x28) = uStack_7ec * 0x50;
      iVar4 = 4;
      if ((param_2[0x23] & 8) != 0) {
        iVar4 = uStack_7ec * 0x50;
      }
      *(undefined4 *)(param_2 + iVar4 + 0x2c) = dword_40B05A8;
      *(undefined4 *)(param_2 + iVar4 + 0x30) = dword_40B05AC;
      *(undefined4 *)(param_2 + iVar4 + 0x34) = dword_40B05B0;
      bVar6 = puVar2 == puStack_7f0;
      if (bVar6) {
        _bcopy(puStack_7f0,param_2 + iVar4 + 0x38,uStack_7f4 * 0x24);
      }
      else {
        param_2[iVar4 + 0x2f] = param_2[iVar4 + 0x2f] & 0xf7 | 2;
        *(undefined **)(param_2 + iVar4 + 0x38) = puStack_7f0;
      }
      *(uint *)(param_2 + iVar4 + 0x34) = uStack_7f4 * 9;
      if ((param_2[iVar4 + 0x2f] & 8) == 0) {
        iVar4 = iVar4 + 0x3c;
      }
      else {
        iVar4 = iVar4 + 0x38 + uStack_7f4 * 0x24;
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
