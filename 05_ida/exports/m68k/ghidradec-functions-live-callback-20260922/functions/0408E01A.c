
undefined4 _en_rx_grabbufs(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  word extraout_D0u;
  uint in_D0;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = in_D0 >> 0x10;
  while( true ) {
    puVar1 = *(undefined4 **)(param_1 + 0x51e);
    if (puVar1 == (undefined4 *)0x0) {
      return CONCAT22((sword)uVar2,4);
    }
    *(undefined4 *)(param_1 + 0x51e) = *puVar1;
    iVar3 = _if_busalloc(puVar1,0);
    if (iVar3 == 0) break;
    puVar1[2] = puVar1[1] + 0x63d & 0xfffffff0;
    puVar1[3] = 4;
    _dma_enqueue(param_1 + 0x106,puVar1);
    uVar2 = (uint)extraout_D0u;
  }
  *puVar1 = *(undefined4 *)(param_1 + 0x51e);
  *(undefined4 **)(param_1 + 0x51e) = puVar1;
  uVar4 = _timeout(_en_rx_grabbufs,param_1,_hz);
  return uVar4;
}

