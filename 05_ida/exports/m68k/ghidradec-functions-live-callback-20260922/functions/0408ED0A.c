
uint _en_tx_dmaintr(int param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int *piVar11;
  char cVar12;
  char cVar13;
  bool bVar14;
  char cVar15;
  bool bVar16;
  bool bVar17;
  char cVar18;
  bool bVar19;
  byte bVar20;
  bool bVar21;
  
  iVar5 = param_1 * 0x52c;
  piVar11 = &_en_softc + param_1 * 0x14b;
  puVar3 = DAT_40c8f42 + iVar5;
  pbVar1 = *(byte **)(DAT_40c8f42 + iVar5 + 0x1f0);
  iVar8 = *piVar11;
  _untimeout(_en_jam,piVar11);
  _untimeout(_en_tx_guard,piVar11);
  if (((&byte_40C9139)[iVar5] & 2) == 0) {
    if (_dma_chip == 0x139) {
      uVar6 = (uint)(char)*pbVar1;
    }
    else {
      uVar6 = (uint)(byte)DAT_40c913a[iVar5 + 0x324];
    }
    uVar6 = _printf(aEnDSpuriousXmi,param_1,uVar6);
    return uVar6;
  }
  if (_dma_chip != 0x139) {
    pbVar1[4] = pbVar1[4] & 0x7f;
  }
  if (((&byte_40C9139)[iVar5] & 0x40) == 0) {
    if (_dma_chip == 0x139) {
      iVar9 = 0;
      if ((char)(*pbVar1 ^ 0x80) < '\0') {
        do {
          iVar9 = iVar9 + 1;
        } while ((word)((sword)-(iVar9 < 100000) & (word)(*pbVar1 ^ 0x80) >> 7) != 0);
      }
      if (iVar9 == 100000) {
        _printf(aEnDTransmitter,param_1);
      }
      bVar20 = *pbVar1;
      *pbVar1 = 0xff;
    }
    else {
      bVar20 = DAT_40c913a[iVar5 + 0x324];
      _dma_abort(puVar3);
    }
    bVar17 = false;
  }
  else {
    *(uint *)(DAT_40c8f42 + iVar5 + 500) = *(uint *)(DAT_40c8f42 + iVar5 + 500) & 0xffffffbf;
    bVar20 = 0;
    _dma_abort(puVar3);
    bVar17 = true;
  }
  puVar7 = (undefined4 *)_dma_dequeue(puVar3,0);
  uVar10 = dword_40AF7F0;
  if (puVar7 == (undefined4 *)0x0) {
loc_408F0CC:
    do {
      iVar8 = _dma_dequeue(puVar3,0);
    } while (iVar8 != 0);
    cVar12 = '\0';
    uVar6 = *(uint *)(DAT_40c8f42 + iVar5 + 500);
    uVar4 = uVar6 & 0xfffffffd;
    *(uint *)(DAT_40c8f42 + iVar5 + 500) = uVar4;
    cVar13 = (int)uVar4 < 0;
    cVar18 = '\0';
    bVar20 = 0;
    cVar15 = '\0';
    if ((uVar6 & 8) == 0) {
      cVar13 = param_1 < 0;
      cVar15 = param_1 == 0;
      cVar18 = '\0';
      bVar20 = 0;
      _enstart(param_1);
    }
    bVar20 = cVar12 << 4 | cVar13 << 3 | cVar15 << 2 | cVar18 << 1 | bVar20;
  }
  else {
    if (bVar17) {
      if ((_dma_chip == 0x139) || (iVar8 = sub_408DC16(pbVar1 + 2), iVar8 != 0)) {
        iVar8 = *(int *)(DAT_40c913a + iVar5);
        *(int *)(DAT_40c913a + iVar5) = *(int *)(DAT_40c913a + iVar5) + 1;
        if (3 < iVar8) goto loc_408F03C;
      }
      else {
        pbVar1[4] = pbVar1[4] | 4;
        _delay(500000);
      }
    }
    else {
      iVar9 = -(int)-(2 < (int)_time - *(int *)(DAT_40c913a + iVar5 + 8));
      if (iVar9 != 0) {
        *(code *)(DAT_40c913a + iVar5 + 8) = _time;
        *(undefined4 *)(DAT_40c913a + iVar5 + 0xc) = uVar10;
        iVar2 = *(int *)(DAT_40c913a + iVar5 + 0x10);
        if (iVar2 == 1) {
          if (_dma_chip == 0x139) {
            pbVar1[5] = 3;
          }
          else {
            sub_408DBD2(pbVar1 + 5,0xa1);
          }
          *(uint *)(DAT_40c8f42 + iVar5 + 500) = *(uint *)(DAT_40c8f42 + iVar5 + 500) | 0x20;
          uVar10 = 2;
        }
        else {
          if (iVar2 != 0) {
            if (iVar2 == 2) {
              if (((&byte_40C9139)[iVar5] & 0x20) != 0) {
                if ((*(word *)(iVar8 + 0xc) & 0x100) == 0) {
                  if (_dma_chip == 0x139) {
                    if ((*(word *)(iVar8 + 0xc) & 0x200) == 0) {
                      pbVar1[5] = 1;
                    }
                    else {
                      pbVar1[5] = 2;
                    }
                  }
                  else {
                    sub_408DBD2(pbVar1 + 5,0xa2);
                  }
                }
                *(uint *)(DAT_40c8f42 + iVar5 + 500) =
                     *(uint *)(DAT_40c8f42 + iVar5 + 500) & 0xffffffdf;
              }
              *(undefined4 *)(DAT_40c913a + iVar5 + 0x10) = 0;
            }
            goto loc_408EF80;
          }
          uVar10 = 1;
        }
        *(undefined4 *)(DAT_40c913a + iVar5 + 0x10) = uVar10;
        iVar9 = 0;
      }
loc_408EF80:
      bVar17 = false;
      if (((_bmap_chip != 0) && (*(int *)(_bmap_chip + 0x34) < 0)) ||
         ((_dma_chip != 0x139 && ((pbVar1[4] & 4) != 0)))) {
        bVar17 = true;
      }
      if ((bVar17) || (((bVar20 & 2) == 0 && (iVar9 == 0)))) {
        if ((_bmap_chip != 0) && ((*(int *)(_bmap_chip + 0x34) < 0 && (iVar9 != 0)))) {
loc_408F03C:
          iVar8 = _en_jam(piVar11);
          goto joined_r0x0408f002;
        }
        if (_dma_chip != 0x139) {
          if (((pbVar1[4] & 4) != 0) && ((pbVar1[6] & 0x40) != 0)) goto loc_408F03C;
          if ((_dma_chip != 0x139) && ((bVar20 & 0xc) != 0)) goto loc_408F106;
        }
        if ((*(uint *)(DAT_40c8f42 + iVar5 + 0x2c) & 0x4000) != 0) {
          _printf(aEnDDmaErrorOnT,param_1);
          *(uint *)(DAT_40c8f42 + iVar5 + 0x2c) = *(uint *)(DAT_40c8f42 + iVar5 + 0x2c) & 0xffffbfff
          ;
          goto loc_408F106;
        }
        iVar8 = _if_opackets(*piVar11);
        _if_opackets_set(*piVar11,iVar8 + 1);
loc_408F0A2:
        *(undefined4 *)(DAT_40c913a + iVar5) = 0;
        *(undefined4 *)(DAT_40c913a + iVar5 + 4) = 0;
        _if_busfree(puVar7);
        *puVar7 = *(undefined4 *)(DAT_40c913a + iVar5 + 0x314);
        *(undefined4 **)(DAT_40c913a + iVar5 + 0x314) = puVar7;
        goto loc_408F0CC;
      }
      iVar8 = _if_oerrors(*piVar11);
      _if_oerrors_set(*piVar11,iVar8 + 1);
      iVar8 = *(int *)(DAT_40c913a + iVar5);
      *(int *)(DAT_40c913a + iVar5) = *(int *)(DAT_40c913a + iVar5) + 1;
      if (((10 < iVar8) && (((&byte_40C9139)[iVar5] & 8) == 0)) || (iVar9 != 0)) {
        if (iVar9 != 0) {
          *(undefined4 *)(DAT_40c913a + iVar5 + 4) = 4;
        }
        iVar8 = _en_jam(piVar11);
joined_r0x0408f002:
        if (iVar8 == 2) goto loc_408F0A2;
      }
    }
loc_408F106:
    _timeout(_en_tx_guard,piVar11,_hz);
    puVar7[3] = 5;
    _dma_enqueue(puVar3,puVar7);
    bVar21 = _dma_chip < 0x139;
    bVar19 = SBORROW2(_dma_chip,0x139);
    bVar14 = (sword)(_dma_chip - 0x139) < 0;
    bVar16 = _dma_chip == 0x139;
    bVar17 = bVar16;
    if (!bVar16) {
      bVar20 = pbVar1[4] | 0x80;
      pbVar1[4] = bVar20;
      bVar14 = (char)bVar20 < '\0';
      bVar17 = bVar20 == 0;
    }
    bVar20 = bVar21 << 4 | bVar14 << 3 | bVar17 << 2 | (bVar16 && bVar19) << 1;
  }
  return (uint)bVar20;
}

