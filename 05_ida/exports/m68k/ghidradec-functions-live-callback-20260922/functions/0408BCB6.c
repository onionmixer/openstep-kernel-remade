
byte sub_408BCB6(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  
  iVar2 = param_1 * 0x164;
  piVar5 = (int *)(DAT_40b52d0 + iVar2);
  pbVar1 = *(byte **)(DAT_40b52d0 + iVar2 + 0xc);
  *(undefined4 *)(DAT_40b541c + iVar2) = 0xffffffff;
  *(undefined4 *)(DAT_40b541c + iVar2 + 8) = dword_40B2406;
  if (*piVar5 == 0) {
    if ((int)_scc_buffer < 0x20) {
      _scc_buffer = 1 << (_scc_buffer & 0x3f);
    }
    if (_scc_buffer - 0x20 < 0x3ffe1) {
      dword_40B51A8 = _scc_buffer;
    }
    else {
      dword_40B51A8 = 0x1000;
    }
    uVar3 = dword_40B51A8;
    if ((int)dword_40B51A8 < 0) {
      uVar3 = dword_40B51A8 + 1;
    }
    dword_40B51AC = (int)uVar3 >> 1;
    uVar3 = dword_40B51A8;
    if ((int)dword_40B51A8 < 0) {
      uVar3 = dword_40B51A8 + 3;
    }
    dword_40B51B0 = (int)uVar3 >> 2;
    uVar3 = dword_40B51A8;
    if ((int)dword_40B51A8 < 0) {
      uVar3 = dword_40B51A8 + 7;
    }
    dword_40B51B4 = (int)uVar3 >> 3;
    iVar4 = _kalloc(dword_40B51A8 * 2);
    *piVar5 = iVar4;
  }
  (&DAT_40b5400)[param_1 * 0x59] = (&DAT_40b5400)[param_1 * 0x59] & 0xfffffffe;
  bVar10 = 0x40;
  if (param_1 == 0) {
    bVar10 = 0x80;
  }
  cVar6 = '\0';
  _delay(1);
  *pbVar1 = 9;
  _delay(1);
  *pbVar1 = bVar10 | 2;
  _delay(10);
  _delay(1);
  *pbVar1 = 1;
  _delay(1);
  *pbVar1 = 0x13;
  _delay(1);
  *pbVar1 = 9;
  _delay(1);
  *pbVar1 = 10;
  _delay(1);
  *pbVar1 = 10;
  _delay(1);
  *pbVar1 = 0;
  _delay(1);
  *pbVar1 = 0xb;
  _delay(1);
  *pbVar1 = 0x50;
  bVar10 = 0x80;
  if (((int)dword_40B51B8 < 0) || (cVar6 = 1 < dword_40B51B8, 1 < (int)dword_40B51B8)) {
    if (((&DAT_40b5400)[param_1 * 0x59] & 0x40) != 0) {
      bVar10 = 0xa0;
    }
    if (((&DAT_40b5400)[param_1 * 0x59] & 4) != 0) {
      bVar10 = bVar10 | 8;
    }
  }
  else if ((*(byte *)((int)&DAT_40b5400 + iVar2 + 3) & 4) != 0) {
    bVar10 = 0xa0;
  }
  _delay(1);
  *pbVar1 = 0xf;
  _delay(1);
  *pbVar1 = bVar10;
  _delay(1);
  *pbVar1 = 0x30;
  _delay(1);
  *pbVar1 = 0x28;
  _delay(1);
  *pbVar1 = 0x10;
  *(uint *)(DAT_40b541c + iVar2 + 4) = *(uint *)(DAT_40b541c + iVar2 + 4) & 7;
  *(int *)(DAT_40b52d0 + iVar2 + 8) = *piVar5;
  *(int *)(DAT_40b52d0 + iVar2 + 4) = *piVar5;
  cVar7 = param_1 < 0;
  cVar8 = param_1 == 0;
  cVar9 = '\0';
  bVar10 = 0;
  sub_408CD86(param_1);
  return cVar6 << 4 | cVar7 << 3 | cVar8 << 2 | cVar9 << 1 | bVar10;
}

