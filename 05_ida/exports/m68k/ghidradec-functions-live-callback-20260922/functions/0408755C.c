
byte _snd_stream_pause(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  char cVar6;
  bool bVar7;
  char cVar8;
  bool bVar9;
  byte bVar10;
  bool bVar11;
  bool bVar12;
  
  cVar3 = '\0';
  bVar10 = *(byte *)(param_1 + 0x24);
  *(byte *)(param_1 + 0x24) = bVar10 | 0x10;
  if ((bVar10 & 8) == 0) {
    uVar1 = *(uint *)(param_1 + 0x10);
    uVar2 = param_1 + 0xc;
    bVar11 = uVar1 < uVar2;
    bVar9 = SBORROW4(uVar1,uVar2);
    bVar5 = (int)(uVar1 - uVar2) < 0;
    bVar7 = uVar1 == uVar2;
    bVar12 = bVar11;
    if (!bVar7) {
      bVar10 = *(byte *)(uVar1 + 0x2d);
      while( true ) {
        bVar7 = false;
        bVar9 = false;
        bVar5 = (char)bVar10 < '\0';
        bVar12 = false;
        if ((bVar10 & 8) != 0) break;
        if ((*(byte *)(uVar1 + 0x2c) & 0x10) != 0) {
          _snd_reply_paused(*(undefined4 *)(uVar1 + 0x18),*(undefined4 *)(uVar1 + 0x2e));
        }
        uVar1 = *(uint *)(uVar1 + 0x36);
        bVar11 = uVar1 < uVar2;
        bVar9 = SBORROW4(uVar1,uVar2);
        bVar5 = (int)(uVar1 - uVar2) < 0;
        bVar7 = true;
        bVar12 = bVar11;
        if (uVar1 == uVar2) break;
        bVar10 = *(byte *)(uVar1 + 0x2d);
      }
    }
    bVar10 = bVar11 << 4 | bVar5 << 3 | bVar7 << 2 | bVar9 << 1 | bVar12;
  }
  else {
    cVar4 = param_1 < 0;
    cVar6 = param_1 == 0;
    cVar8 = '\0';
    bVar10 = 0;
    _snd_link_pause(param_1);
    bVar10 = cVar3 << 4 | cVar4 << 3 | cVar6 << 2 | cVar8 << 1 | bVar10;
  }
  return bVar10;
}

