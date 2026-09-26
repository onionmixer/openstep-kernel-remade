
byte _ip_slowtimo(void)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined4 *puVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  
  if (_ipq == (undefined4 *)0x0) {
    bVar2 = 4;
  }
  else {
    bVar6 = &_ipq < _ipq;
    bVar5 = SBORROW4(0x40b6884,(int)_ipq);
    puVar3 = (undefined4 *)((int)&_ipq - (int)_ipq);
    bVar4 = (undefined4 **)_ipq == &_ipq;
    puVar1 = _ipq;
    while (!bVar4) {
      *(char *)(puVar1 + 2) = *(char *)(puVar1 + 2) + -1;
      puVar1 = (undefined4 *)*puVar1;
      if (*(char *)(puVar1[1] + 8) == '\0') {
        unk_40B68C0 = unk_40B68C0 + 1;
        _ip_freef(puVar1[1]);
      }
      bVar6 = puVar1 < &_ipq;
      bVar5 = SBORROW4((int)puVar1,0x40b6884);
      puVar3 = puVar1 + -0x102da21;
      bVar4 = (undefined4 **)puVar1 == &_ipq;
    }
    bVar2 = bVar6 << 4 | ((int)puVar3 < 0) << 3 | bVar4 << 2 | bVar5 << 1 | bVar6;
  }
  return bVar2;
}
