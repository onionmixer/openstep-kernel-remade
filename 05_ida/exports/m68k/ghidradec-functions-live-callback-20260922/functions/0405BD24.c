
void sub_405BD24(int *param_1,byte *param_2)

{
  byte *pbVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  uint uStack_7fc;
  undefined *puStack_7f8;
  uint uStack_7f4;
  byte *pbStack_7f0;
  undefined auStack_7ec [2024];
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == dword_40B0600)) &&
     (param_1[8] == dword_40B0604)) {
    uVar3 = _convert_port_to_space(param_1[2]);
    pbVar1 = param_2 + 0x48;
    uStack_7f4 = 0x38;
    if ((uint)param_1[7] < 0x38) {
      uStack_7f4 = param_1[7];
    }
    puVar2 = auStack_7ec;
    uStack_7fc = 0x2e;
    if ((uint)param_1[9] < 0x2e) {
      uStack_7fc = param_1[9];
    }
    puStack_7f8 = puVar2;
    pbStack_7f0 = pbVar1;
    uVar4 = _mach_port_space_info
                      (uVar3,param_2 + 0x24,&pbStack_7f0,&uStack_7f4,&puStack_7f8,&uStack_7fc);
    *(undefined4 *)(param_2 + 0x1c) = uVar4;
    _space_deallocate(uVar3);
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 0x20) = dword_40B0608;
      *(undefined4 *)(param_2 + 0x3c) = dword_40B060C;
      *(undefined4 *)(param_2 + 0x40) = dword_40B0610;
      *(undefined4 *)(param_2 + 0x44) = dword_40B0614;
      bVar6 = pbVar1 != pbStack_7f0;
      if (bVar6) {
        param_2[0x3f] = param_2[0x3f] & 0xf7 | 2;
        *(byte **)pbVar1 = pbStack_7f0;
      }
      *(uint *)(param_2 + 0x44) = uStack_7f4 * 9;
      iVar5 = 4;
      if ((param_2[0x3f] & 8) != 0) {
        iVar5 = uStack_7f4 * 0x24;
      }
      *(undefined4 *)(param_2 + iVar5 + 0x48) = dword_40B0618;
      *(undefined4 *)(param_2 + iVar5 + 0x4c) = dword_40B061C;
      *(undefined4 *)(param_2 + iVar5 + 0x50) = dword_40B0620;
      bVar7 = puVar2 == puStack_7f8;
      if (bVar7) {
        _bcopy(puStack_7f8,param_2 + iVar5 + 0x54,uStack_7fc * 0x2c);
      }
      else {
        param_2[iVar5 + 0x4b] = param_2[iVar5 + 0x4b] & 0xf7 | 2;
        *(undefined **)(param_2 + iVar5 + 0x54) = puStack_7f8;
      }
      *(uint *)(param_2 + iVar5 + 0x50) = uStack_7fc * 0xb;
      if ((param_2[iVar5 + 0x4b] & 8) == 0) {
        iVar5 = iVar5 + 0x58;
      }
      else {
        iVar5 = iVar5 + 0x54 + uStack_7fc * 0x2c;
      }
      if (!bVar7 || bVar6) {
        *param_2 = *param_2 | 0x80;
      }
      *(int *)(param_2 + 4) = iVar5;
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

