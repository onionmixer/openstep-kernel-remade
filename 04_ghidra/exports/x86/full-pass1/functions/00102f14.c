/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00102f14 */

void _binit(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  puVar3 = &_bfreelist;
  puVar5 = &DAT_001e8764;
  do {
    puVar5[3] = puVar3;
    puVar5[2] = puVar3;
    puVar5[1] = puVar3;
    *puVar5 = puVar3;
    *puVar3 = 0x40000;
    puVar5 = puVar5 + 0x11;
    puVar3 = puVar3 + 0x11;
  } while (puVar3 < &_buf);
  iVar1 = _bufpages / _nbuf;
  iVar4 = _bufpages % _nbuf;
  iVar6 = 0;
  if (0 < _nbuf) {
    iVar7 = 0;
    do {
      puVar3 = (undefined4 *)(_buf + iVar7);
      *(undefined2 *)((int)puVar3 + 0x1e) = 0xffff;
      puVar3[5] = 0;
      puVar3[8] = iVar6 * 0x2000 + _buffers;
      iVar2 = iVar1;
      if (iVar6 < iVar4) {
        iVar2 = iVar1 + 1;
      }
      puVar3[6] = iVar2 * _page_size;
      puVar3[0xf] = 0;
      if (puVar3[6] == 0) {
        puVar3[1] = DAT_001e8830;
        puVar3[2] = &DAT_001e882c;
        DAT_001e8830[2] = puVar3;
        DAT_001e8830 = puVar3;
      }
      else {
        puVar3[1] = DAT_001e87ec;
        puVar3[2] = &DAT_001e87e8;
        DAT_001e87ec[2] = puVar3;
        DAT_001e87ec = puVar3;
      }
      puVar3[0x10] = 0;
      *puVar3 = 0x10008;
      _brelse(puVar3);
      iVar7 = iVar7 + 0x44;
      iVar6 = iVar6 + 1;
    } while (iVar6 < _nbuf);
  }
  return;
}

