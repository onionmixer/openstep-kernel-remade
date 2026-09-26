
void _binit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  puVar6 = &_bfreelist;
  do {
    puVar6[4] = puVar6;
    puVar6[3] = puVar6;
    puVar6[2] = puVar6;
    puVar6[1] = puVar6;
    *puVar6 = 0x40000;
    puVar6 = puVar6 + 0x11;
  } while (puVar6 < &_buf);
  iVar5 = _bufpages % _nbuf;
  iVar4 = _bufpages / _nbuf;
  iVar2 = 0;
  if (0 < _nbuf) {
    iVar3 = 0;
    iVar7 = 0;
    do {
      puVar6 = (undefined4 *)(iVar7 + _buf);
      *(undefined2 *)((int)puVar6 + 0x1e) = 0xffff;
      puVar6[5] = 0;
      puVar6[8] = iVar3 + _buffers;
      iVar1 = iVar4;
      if (iVar2 < iVar5) {
        iVar1 = iVar4 + 1;
      }
      puVar6[6] = _page_size * iVar1;
      puVar6[0xf] = 0;
      if (puVar6[6] == 0) {
        puVar6[1] = dword_40B58A8;
        puVar6[2] = &DAT_40b58a4;
        dword_40B58A8[2] = puVar6;
        dword_40B58A8 = puVar6;
      }
      else {
        puVar6[1] = dword_40B5864;
        puVar6[2] = &unk_40B5860;
        dword_40B5864[2] = puVar6;
        dword_40B5864 = puVar6;
      }
      puVar6[0x10] = 0;
      *puVar6 = 0x10008;
      _brelse(puVar6);
      iVar3 = iVar3 + 0x2000;
      iVar7 = iVar7 + 0x44;
      iVar2 = iVar2 + 1;
    } while (iVar2 < _nbuf);
  }
  return;
}
