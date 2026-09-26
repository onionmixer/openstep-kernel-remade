
undefined4 _en_rx_dmaintr(int param_1)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  byte *pbVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  undefined2 extraout_D0u;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  char cVar16;
  bool bVar17;
  bool bVar18;
  int local_14;
  
  iVar8 = param_1 * 0x52c;
  piVar5 = (int *)(&_en_softc + iVar8);
  iVar1 = *piVar5;
  iVar2 = *(int *)(&DAT_040c9132 + iVar8);
  local_14 = 0;
  do {
    while( true ) {
      puVar9 = (undefined4 *)_dma_dequeue(iVar8 + 0x40c903a,0);
      if (puVar9 == (undefined4 *)0x0) {
        uVar7 = 0;
        cVar16 = '\0';
        bVar17 = local_14 < 0;
        bVar18 = local_14 == 0;
        if (!bVar18) {
          iVar10 = _if_ipackets(*piVar5);
          _if_ipackets_set(*piVar5,local_14 + iVar10);
          *(uint *)(&DAT_040c9136 + iVar8) = *(uint *)(&DAT_040c9136 + iVar8) & 0xffffffef;
          uVar6 = DAT_040af7f0;
          *(undefined4 *)(&DAT_040c9142 + iVar8) = _time;
          *(undefined4 *)(&DAT_040c9146 + iVar8) = uVar6;
          *(undefined4 *)(&DAT_040c914a + iVar8) = 0;
          bVar17 = false;
          bVar18 = ((&DAT_040c9139)[iVar8] & 0x20) == 0;
          uVar7 = extraout_D0u;
          if (!bVar18) {
            uVar3 = *(ushort *)(iVar1 + 0xc);
            if ((uVar3 & 0x100) == 0) {
              cVar16 = _dma_chip < 0x139;
              if (_dma_chip == 0x139) {
                if ((uVar3 & 0x200) == 0) {
                  *(undefined1 *)(iVar2 + 5) = 1;
                }
                else {
                  *(undefined1 *)(iVar2 + 5) = 2;
                }
              }
              else {
                FUN_0408dbd2(iVar2 + 5,0xa2);
              }
            }
            uVar7 = 0;
            uVar15 = *(uint *)(&DAT_040c9136 + iVar8) & 0xffffffdf;
            *(uint *)(&DAT_040c9136 + iVar8) = uVar15;
            bVar17 = (int)uVar15 < 0;
            bVar18 = uVar15 == 0;
          }
        }
        return CONCAT22(uVar7,(ushort)(byte)(cVar16 << 4 | bVar17 << 3 | bVar18 << 2));
      }
      if ((*(uint *)(&DAT_040c9066 + iVar8) & 0x4000) != 0) {
        _printf("en%d: DMA error on receive\n",param_1);
        *(uint *)(&DAT_040c9066 + iVar8) = *(uint *)(&DAT_040c9066 + iVar8) & 0xffffbfff;
      }
      pbVar14 = (byte *)puVar9[1];
      uVar15 = (puVar9[5] & 0x3fffffff) - (int)pbVar14;
      iVar10 = uVar15 - 0x12;
      if (uVar15 - 0x40 < 0x5b0) break;
      iVar10 = _if_ierrors(*piVar5);
      _if_ierrors_set(*piVar5,iVar10 + 1);
LAB_0408e444:
      puVar9[2] = puVar9[1] + 0x63d & 0xfffffff0;
      puVar9[3] = 4;
      _dma_enqueue(iVar8 + 0x40c903a,puVar9);
    }
    if ((_dma_chip == 0) && ((*(byte *)(iVar1 + 0xc) & 1) == 0)) {
      pbVar4 = pbVar14 + 1;
      iVar11 = _bcmp(pbVar4,&DAT_040c8f38 + iVar8,6);
      if ((iVar11 == 0) || (iVar11 = _bcmp(pbVar4,&_etherbcastaddr,6), iVar11 == 0)) {
        iVar10 = uVar15 - 0x13;
        pbVar14 = pbVar4;
      }
      else {
        bVar17 = false;
        if (((*(int *)(&DAT_040c945a + iVar8) != 0) &&
            (iVar11 = _bcmp(pbVar14,&DAT_040c8f38 + iVar8,6), iVar11 != 0)) &&
           (iVar11 = _bcmp(pbVar14,&_etherbcastaddr,6), iVar11 != 0)) {
          bVar17 = true;
        }
        if (bVar17) {
          if (((pbVar14[1] & 1) == (*pbVar14 & 1)) && ((pbVar14[7] & 1) == (pbVar14[6] & 1))) {
            uVar12 = 0xffffffff;
            uVar13 = 0;
            if (uVar15 != 0) {
              do {
                uVar12 = uVar12 >> 8 ^ *(uint *)(&_crctab + ((pbVar14[uVar13] ^ uVar12) & 0xff) * 4)
                ;
                uVar13 = uVar13 + 1;
              } while (uVar13 < uVar15);
            }
            if (uVar12 != 0xdebb20e3) {
LAB_0408e388:
              iVar10 = uVar15 - 0x13;
              pbVar14 = pbVar14 + 1;
            }
          }
          else if (((*pbVar14 & 1) < (pbVar14[1] & 1)) || ((pbVar14[7] & 1) < (pbVar14[6] & 1)))
          goto LAB_0408e388;
        }
      }
    }
    if (((*pbVar14 & 1) != 0) && (iVar11 = _en_accept_multicast(piVar5,pbVar14), iVar11 == 0))
    goto LAB_0408e444;
    if ((*(short *)(pbVar14 + 0x22) == 0x473) &&
       ((pbVar14[0x17] == 0x11 && (*(short *)(pbVar14 + 0xc) == 0x800)))) {
      _dbg_from_ether(pbVar14);
    }
    local_14 = local_14 + 1;
    iVar10 = _if_rbusget(puVar9,pbVar14,iVar10 + 0xe);
    if (iVar10 == 0) {
      _printf("enrx: no network buffers\n");
      goto LAB_0408e444;
    }
    _if_handle_input(*piVar5,iVar10,0);
    iVar10 = _if_busalloc(puVar9,0);
    if (iVar10 != 0) goto LAB_0408e444;
    *puVar9 = *(undefined4 *)(&DAT_040c9452 + iVar8);
    *(undefined4 **)(&DAT_040c9452 + iVar8) = puVar9;
    _timeout(0x408e01a);
  } while( true );
}

