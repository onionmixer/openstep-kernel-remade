
undefined4 _fd_start(int param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined *puVar9;
  
  puVar3 = (uint *)_disksort_first(param_1 + 0xba);
  if (puVar3 != (uint *)0x0) {
    *(byte *)(param_1 + 0xc6) = *(byte *)(param_1 + 0xc6) | 0x10;
  }
  if ((uint *)(param_1 + 0x18) == puVar3) {
    _bcopy(*(undefined4 *)(param_1 + 0x5c),param_1 + 0x60,0x5a);
    *(undefined4 *)(param_1 + 0x140) = 0;
    goto loc_406D862;
  }
  iVar1 = *(int *)(param_1 + 0x14);
  uVar6 = *(word *)((int)puVar3 + 0x1e) & 7;
  if (1 < uVar6) {
    uVar4 = *(undefined4 *)(param_1 + 0x10);
    puVar9 = aFdDBadFloppyPa;
loc_406D752:
    _printf(puVar9,uVar4);
    if ((*(word *)((int)puVar3 + 0x1e) & 7) == 1) {
      *(undefined2 *)(puVar3 + 7) = 4;
    }
    else {
      *(undefined2 *)(puVar3 + 7) = 0x16;
    }
    *puVar3 = *puVar3 | 4;
    _fd_done(param_1);
    return 1;
  }
  if ((*puVar3 & 1) == 0) {
    *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) & 0xfffffffe;
  }
  else {
    *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) | 1;
  }
  if (uVar6 == 1) {
    *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) | 2;
    *(uint *)(param_1 + 0x13c) = puVar3[9];
    uVar6 = *(uint *)(param_1 + 0x186);
    uVar7 = *(uint *)(param_1 + 0x13c);
    uVar5 = *(uint *)(param_1 + 0x192);
    if (uVar5 < ((puVar3[5] - 1) + uVar6) / uVar6 + uVar7) {
loc_406D7F2:
      *(uint *)(param_1 + 0x140) = uVar6 * (uVar5 - uVar7);
    }
    else {
      *(uint *)(param_1 + 0x140) = puVar3[5];
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x179) & 2) == 0) {
      uVar4 = *(undefined4 *)(param_1 + 0x10);
      puVar9 = aFdDInvalidLabe;
      goto loc_406D752;
    }
    *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) & 0xfffffffd;
    piVar8 = (int *)(uVar6 * 0x2e + 0xbe + iVar1);
    iVar2 = (int)*(sword *)(iVar1 + 0x70) + *piVar8 + puVar3[9];
    *(int *)(param_1 + 0x13c) = iVar2;
    *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x196) * iVar2;
    uVar6 = *(uint *)(iVar1 + 0x5c);
    uVar7 = puVar3[9];
    uVar5 = piVar8[1];
    if ((int)uVar5 < (int)((int)((puVar3[5] - 1) + uVar6) / (int)uVar6 + uVar7)) goto loc_406D7F2;
    *(uint *)(param_1 + 0x140) = puVar3[5];
  }
  *(uint *)(param_1 + 0x144) = puVar3[8];
  if ((*puVar3 & 0x4000010) == 0x10) {
    *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(*(int *)(puVar3[0xb] + 0x66) + 8);
    *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(*(int *)(param_1 + 0xb4) + 0x20);
  }
  else {
    uVar4 = _pmap_kernel();
    *(undefined4 *)(param_1 + 0xb0) = uVar4;
  }
  sub_406DC10(param_1,(*(uint *)(param_1 + 0x15c) ^ 1) & 1);
  *(undefined4 *)(param_1 + 0x154) = _fd_inner_retry;
  *(undefined4 *)(param_1 + 0x158) = _fd_outer_retry;
loc_406D862:
  *(undefined4 *)(param_1 + 0x132) = 1;
  uVar4 = _fc_start(param_1);
  return uVar4;
}

