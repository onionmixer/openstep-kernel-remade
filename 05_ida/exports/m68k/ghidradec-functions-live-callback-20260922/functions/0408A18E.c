
void sub_408A18E(void)

{
  bool bVar1;
  bool bVar2;
  sword sVar4;
  int iVar3;
  word wVar5;
  sword sVar6;
  uint unaff_D6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint unaff_A5;
  
  iVar7 = 0x46;
  if (_dma_chip == 0x139) {
    iVar7 = 0x48;
  }
  sVar6 = (sword)((uint)*(undefined4 *)(dword_40B518C + 0x10) >> 0x10);
  iVar3 = iVar7 * ((int)sVar6 - (int)*(sword *)(dword_40B518C + 0x34)) * 4;
  sVar4 = (sword)((uint)*(undefined4 *)(dword_40B518C + 0xc) >> 0x10);
  if (_dma_chip == 0x139) {
    iVar3 = iVar3 + 0xb000000;
  }
  else {
    iVar3 = iVar3 + 0xc000000;
  }
  puVar10 = (uint *)(((int)sVar4 - (int)*(sword *)(dword_40B518C + 0x30) >> 4) * 4 +
                    _slot_id + iVar3);
  puVar9 = (uint *)(dword_40B518C + 0x248);
  bVar1 = sVar4 < *(sword *)(dword_40B518C + 0x30);
  if (!bVar1) {
    unaff_D6 = *(uint *)(unk_40B2340 + ((int)*(sword *)(dword_40B518C + 0x28) - (int)sVar4) * 4);
  }
  sVar4 = (sword)*(undefined4 *)(dword_40B518C + 0xc);
  bVar2 = *(sword *)(dword_40B518C + 0x32) < sVar4;
  if (!bVar2) {
    unaff_A5 = ~*(uint *)(unk_40B2340 +
                         (0x10 - ((int)sVar4 - (int)*(sword *)(dword_40B518C + 0x2a))) * 4);
  }
  sVar4 = (sword)*(undefined4 *)(dword_40B518C + 0x10);
  if (bVar1) {
    if ((!bVar2) && (iVar3 = ((int)sVar4 - (int)sVar6) + -1, iVar3 != -1)) {
      do {
        do {
          puVar8 = puVar9 + 1;
          puVar10[1] = unaff_A5 & *puVar9 | ~unaff_A5 & puVar10[1];
          puVar10 = puVar10 + iVar7;
          wVar5 = (word)((uint)iVar3 >> 0x10);
          sVar6 = (sword)iVar3 + -1;
          iVar3 = CONCAT22(wVar5,sVar6);
          puVar9 = puVar8;
        } while (sVar6 != -1);
        iVar3 = (uint)wVar5 * 0x10000 + -1;
      } while (wVar5 != 0);
    }
  }
  else if (bVar2) {
    iVar3 = ((int)sVar4 - (int)sVar6) + -1;
    if (iVar3 != -1) {
      do {
        do {
          puVar8 = puVar9 + 1;
          *puVar10 = unaff_D6 & *puVar9 | ~unaff_D6 & *puVar10;
          puVar10 = puVar10 + iVar7;
          wVar5 = (word)((uint)iVar3 >> 0x10);
          sVar6 = (sword)iVar3 + -1;
          iVar3 = CONCAT22(wVar5,sVar6);
          puVar9 = puVar8;
        } while (sVar6 != -1);
        iVar3 = (uint)wVar5 * 0x10000 + -1;
      } while (wVar5 != 0);
    }
  }
  else {
    iVar3 = ((int)sVar4 - (int)sVar6) + -1;
    if (iVar3 != -1) {
      do {
        do {
          puVar8 = puVar9 + 1;
          *puVar10 = unaff_D6 & *puVar9 | ~unaff_D6 & *puVar10;
          puVar9 = puVar9 + 2;
          puVar10[1] = unaff_A5 & *puVar8 | ~unaff_A5 & puVar10[1];
          puVar10 = puVar10 + iVar7;
          wVar5 = (word)((uint)iVar3 >> 0x10);
          sVar6 = (sword)iVar3 + -1;
          iVar3 = CONCAT22(wVar5,sVar6);
        } while (sVar6 != -1);
        iVar3 = (uint)wVar5 * 0x10000 + -1;
      } while (wVar5 != 0);
    }
  }
  return;
}

