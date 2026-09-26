
void sub_4089FBA(void)

{
  bool bVar1;
  sword sVar2;
  uint uVar3;
  int *piVar4;
  sword sVar6;
  int iVar5;
  sword sVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  int iStack_c;
  
  piVar4 = dword_40B518C;
  uVar8 = dword_40B518C[9];
  if (*(sword *)(dword_40B518C + 9) < (sword)*(word *)(dword_40B518C + 0xd)) {
    uVar8 = uVar8 & 0xffff | (uint)*(word *)(dword_40B518C + 0xd) << 0x10;
  }
  if (*(sword *)((int)dword_40B518C + 0x36) < (sword)uVar8) {
    uVar8 = CONCAT22((sword)(uVar8 >> 0x10),*(sword *)((int)dword_40B518C + 0x36));
  }
  sVar7 = *(sword *)(dword_40B518C + 0xc) +
          (*(sword *)(dword_40B518C + 8) - *(sword *)(dword_40B518C + 0xc) & 0xfff0U);
  sVar2 = sVar7 + 0x20;
  dword_40B518C[3] = CONCAT22(sVar7,sVar2);
  piVar4[4] = uVar8;
  iStack_c = 0x46;
  if (_dma_chip == 0x139) {
    iStack_c = 0x48;
  }
  sVar6 = (sword)(uVar8 >> 0x10);
  iVar5 = iStack_c * ((int)sVar6 - (int)*(sword *)(piVar4 + 0xd)) * 4;
  if (_dma_chip == 0x139) {
    iVar5 = iVar5 + 0xb000000;
  }
  else {
    iVar5 = iVar5 + 0xc000000;
  }
  puVar14 = (uint *)(((int)sVar7 - (int)*(sword *)(piVar4 + 0xc) >> 4) * 4 + _slot_id + iVar5);
  iVar5 = (*(word *)(dword_40B518C + 8) & 0xf) * 2;
  uVar3 = (*(word *)(dword_40B518C + 8) & 0xf) * -2 + 0x20;
  puVar11 = (uint *)(dword_40B518C + 0x92);
  puVar13 = (uint *)(dword_40B518C +
                    *dword_40B518C * 0x10 + (sword)(sVar6 - *(sword *)(dword_40B518C + 9)) + 0x12);
  puVar12 = (uint *)(dword_40B518C +
                    *dword_40B518C * 0x10 + (sword)(sVar6 - *(sword *)(dword_40B518C + 9)) + 0x52);
  bVar1 = *(sword *)((int)dword_40B518C + 0x32) < sVar2;
  sVar2 = (sword)uVar8;
  if (sVar7 < *(sword *)(dword_40B518C + 0xc)) {
    if ((!bVar1) && (sVar7 = (sVar2 - sVar6) + -1, sVar7 != -1)) {
      puVar14 = puVar14 + 1;
      do {
        uVar8 = *puVar14;
        *puVar11 = uVar8;
        *puVar14 = *puVar13 << (uVar3 & 0x3f) | ~(*puVar12 << (uVar3 & 0x3f)) & uVar8;
        puVar14 = puVar14 + iStack_c;
        sVar7 = sVar7 + -1;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
        puVar13 = puVar13 + 1;
      } while (sVar7 != -1);
    }
  }
  else if (bVar1) {
    sVar2 = sVar2 - sVar6;
    while (sVar2 = sVar2 + -1, sVar2 != -1) {
      uVar8 = *puVar14;
      *puVar11 = uVar8;
      *puVar14 = *puVar13 >> iVar5 | ~(*puVar12 >> iVar5) & uVar8;
      puVar14 = puVar14 + iStack_c;
      puVar11 = puVar11 + 1;
      puVar13 = puVar13 + 1;
      puVar12 = puVar12 + 1;
    }
  }
  else {
    sVar7 = (sVar2 - sVar6) + -1;
    if (sVar7 != -1) {
      puVar9 = puVar14 + 1;
      do {
        uVar8 = *puVar14;
        puVar10 = puVar11 + 1;
        *puVar11 = uVar8;
        *puVar14 = *puVar13 >> iVar5 | ~(*puVar12 >> iVar5) & uVar8;
        uVar8 = *puVar9;
        puVar11 = puVar11 + 2;
        *puVar10 = uVar8;
        *puVar9 = *puVar13 << (uVar3 & 0x3f) | ~(*puVar12 << (uVar3 & 0x3f)) & uVar8;
        puVar9 = puVar9 + iStack_c;
        puVar14 = puVar14 + iStack_c;
        sVar7 = sVar7 + -1;
        puVar12 = puVar12 + 1;
        puVar13 = puVar13 + 1;
      } while (sVar7 != -1);
    }
  }
  return;
}
