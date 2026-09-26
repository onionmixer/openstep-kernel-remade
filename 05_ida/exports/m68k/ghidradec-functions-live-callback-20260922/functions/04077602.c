
uint _od_dma_intr(int param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  if ((*(uint *)(param_1 + 0x2c) & 0x4000) != 0) {
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x10010000;
  }
  uVar1 = *(uint *)(param_1 + 0x220);
  if ((uVar1 & 0x10000000) != 0) {
    cVar2 = (_od_spl & 0x10) != 0;
    *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) & 0xefffffff;
    cVar3 = param_1 < 0;
    cVar4 = param_1 == 0;
    cVar5 = '\0';
    bVar6 = 0;
    _odintr(param_1);
    uVar1 = (uint)(byte)(cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6);
  }
  return uVar1;
}

