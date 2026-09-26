
void _enattach(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  sword sVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  
  iVar4 = *(sword *)(param_1 + 4) * 0x52c;
  puVar10 = &_en_softc + *(sword *)(param_1 + 4) * 0x14b;
  iVar2 = iVar4 + 0x40c903a;
  iVar8 = *(int *)(param_1 + 0x12);
  *(int *)(DAT_40c8f42 + iVar4 + 0x1f0) = iVar8;
  _bcopy(&_etheraddr,(int)&unk_40C8F38 + iVar4,6);
  _bytecopy(&_etheraddr,iVar8 + 8,6);
  uVar5 = _ether_sprintf((int)&unk_40C8F38 + iVar4);
  _printf(aEnDEthernetAdd,(int)*(sword *)(param_1 + 4),uVar5);
  *(undefined *)(iVar8 + 6) = 0x80;
  if (_dma_chip != 0x139) {
    *(undefined *)(iVar8 + 6) = 0;
  }
  _bzero(DAT_40c8f42 + iVar4,0xf8);
  sVar3 = _dma_chip;
  pcVar6 = (code *)0x0;
  if (_dma_chip == 0x139) {
    pcVar6 = _en_tx_dmaintr;
  }
  *(code **)(DAT_40c8f42 + iVar4 + 0x10) = pcVar6;
  *(int *)(DAT_40c8f42 + iVar4 + 0x14) = (int)*(sword *)(param_1 + 4);
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x18) = 1;
  *(int *)(DAT_40c8f42 + iVar4 + 0x1c) = _slot_id + 0x2000110;
  uVar5 = 0x14;
  if (sVar3 == 0x139) {
    uVar5 = 0x15;
  }
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x2c) = uVar5;
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x20) = 0;
  _dma_init(DAT_40c8f42 + iVar4,0x1c61);
  _install_scanned_intr(0xa33,_en_tx_devintr,(int)*(sword *)(param_1 + 4));
  *(undefined4 *)(DAT_40c944e + iVar4) = 0;
  *(undefined4 *)(DAT_40c944e + iVar4 + 4) = 0;
  iVar8 = 0;
  iVar9 = 0x41a;
  do {
    *(undefined4 *)((int)puVar10 + iVar9) = *(undefined4 *)(DAT_40c944e + iVar4);
    *(undefined4 **)(DAT_40c944e + iVar4) = (undefined4 *)((int)puVar10 + iVar9);
    iVar9 = iVar9 + 0x20;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 8);
  _bzero(iVar2,0xf8);
  *(code **)(DAT_40c8f42 + iVar4 + 0x108) = _en_rx_dmaintr;
  *(int *)(DAT_40c8f42 + iVar4 + 0x10c) = (int)*(sword *)(param_1 + 4);
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x110) = 1;
  *(int *)(DAT_40c8f42 + iVar4 + 0x114) = _slot_id + 0x2000150;
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x124) = 0x8d;
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x118) = 0x40000;
  _dma_init(iVar2,0x1b62);
  if (_dma_chip != 0x139) {
    _install_scanned_intr(0x934,_en_rx_devintr,(int)*(sword *)(param_1 + 4));
  }
  iVar8 = 0;
  iVar9 = 0x21a;
  do {
    puVar1 = (undefined4 *)((int)puVar10 + iVar9);
    iVar7 = _if_busalloc(puVar1,0);
    if (iVar7 == 0) {
      *puVar1 = *(undefined4 *)(DAT_40c944e + iVar4 + 4);
      *(undefined4 **)(DAT_40c944e + iVar4 + 4) = puVar1;
    }
    else {
      puVar1[2] = puVar1[1] + 0x63d & 0xfffffff0;
      puVar1[3] = 4;
      _dma_enqueue(iVar2,puVar1);
    }
    iVar9 = iVar9 + 0x20;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x10);
  *(undefined4 *)(DAT_40c944e + iVar4 + 0xc) = 0;
  uVar5 = _if_attach(_eninit,0,_enoutput,_engetbuf,_encontrol,&aEn,(int)*(sword *)(param_1 + 4),
                     a10mbEthernet,0x5dc,0,0,0);
  *puVar10 = uVar5;
  return;
}
