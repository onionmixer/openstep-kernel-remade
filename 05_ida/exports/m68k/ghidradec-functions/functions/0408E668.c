
undefined4 _enstart(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  byte bVar5;
  undefined2 extraout_D0u;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  
  uVar6 = param_1 * 0x52c;
  iVar1 = *(int *)(DAT_40c8f42 + uVar6 + 0x1f0);
  iVar9 = (&_en_softc)[param_1 * 0x14b];
  uVar7 = uVar6 & 0xffff0000;
  iVar2 = *(int *)(iVar9 + 0x1a);
  bVar11 = false;
  bVar13 = false;
  bVar10 = iVar2 == 0;
  iVar3 = 0;
  if (!bVar10) {
    uVar7 = *(uint *)(iVar2 + 0x7c);
    *(uint *)(iVar9 + 0x1a) = uVar7;
    if (uVar7 == 0) {
      *(undefined4 *)(iVar9 + 0x1e) = 0;
    }
    *(undefined4 *)(iVar2 + 0x7c) = 0;
    iVar3 = *(int *)(iVar9 + 0x22);
    bVar13 = iVar3 == 0;
    bVar11 = SBORROW4(iVar3,1);
    iVar3 = iVar3 + -1;
    *(int *)(iVar9 + 0x22) = iVar3;
    bVar10 = iVar3 == 0;
  }
  uVar8 = CONCAT22((sword)(uVar7 >> 0x10),
                   (word)(byte)(bVar13 << 4 | (iVar3 < 0) << 3 | bVar10 << 2 | bVar11 << 1 | bVar13)
                  );
  if (iVar2 != 0) {
    puVar4 = *(undefined4 **)(DAT_40c944e + uVar6);
    if (puVar4 == (undefined4 *)0x0) {
      _printf(aEntxNoDmaHeade);
      uVar8 = _nb_free(iVar2);
    }
    else {
      *(undefined4 *)(DAT_40c944e + uVar6) = *puVar4;
      iVar9 = _nb_size(iVar2);
      _if_busalloc(puVar4,iVar2);
      if (iVar9 - 0xeU < 0x2e) {
        iVar9 = 0x3c;
      }
      puVar4[2] = iVar9 + puVar4[1];
      if (_dma_chip == 0x139) {
        puVar4[2] = (iVar9 + puVar4[1] | 0x80000000U) + 0xf;
      }
      puVar4[3] = 5;
      _timeout(_en_tx_guard,&_en_softc + param_1 * 0x14b,_hz);
      *(uint *)(DAT_40c8f42 + uVar6 + 500) = *(uint *)(DAT_40c8f42 + uVar6 + 500) | 2;
      _dma_enqueue(DAT_40c8f42 + uVar6,puVar4);
      bVar14 = _dma_chip < 0x139;
      bVar12 = SBORROW2(_dma_chip,0x139);
      bVar11 = (sword)(_dma_chip - 0x139) < 0;
      bVar13 = _dma_chip == 0x139;
      bVar10 = bVar13;
      if (!bVar13) {
        bVar5 = *(byte *)(iVar1 + 4) | 0x80;
        *(byte *)(iVar1 + 4) = bVar5;
        bVar11 = (char)bVar5 < '\0';
        bVar10 = bVar5 == 0;
      }
      uVar8 = CONCAT22(extraout_D0u,
                       (word)(byte)(bVar14 << 4 | bVar11 << 3 | bVar10 << 2 |
                                   (bVar13 && bVar12) << 1));
    }
  }
  return uVar8;
}
