
void _arptimer(void)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  char *pcVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  _timeout(_arptimer,0,_hz * 0x3c);
  puVar6 = _arptab;
  iVar2 = 0;
  puVar5 = unk_40B6E63;
  pcVar4 = &unk_40B6E62;
  do {
    if ((*puVar5 != 0) && ((*puVar5 & 4) == 0)) {
      cVar1 = *pcVar4;
      *pcVar4 = cVar1 + '\x01';
      bVar3 = 2;
      if ((*puVar5 & 2) != 0) {
        bVar3 = 0x13;
      }
      if (bVar3 < (byte)(cVar1 + 1U)) {
        _arptfree(puVar6);
      }
    }
    iVar2 = iVar2 + 1;
    puVar5 = puVar5 + 0x14;
    pcVar4 = pcVar4 + 0x14;
    puVar6 = puVar6 + 0x14;
  } while (iVar2 < 0xab);
  return;
}
