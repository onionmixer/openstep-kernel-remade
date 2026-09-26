
void _km_flip_cursor(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  
  if (-1 < word_40B68D8) {
    _km_begin_access();
    iVar1 = dword_40B6980 + (uint)(((int)word_40B68D8 + (int)word_40B68DE) * 0x20) / _km_coni;
    iVar4 = (int)word_40B68DC;
    iVar2 = dword_40B6940 * 0xc;
    iVar6 = 0;
    do {
      if (word_40B68DA < 0) {
        iVar3 = (int)word_40B68DA;
      }
      else {
        iVar3 = word_40B68DA * 0xc;
      }
      puVar5 = (uint *)(dword_40B6940 * (iVar6 + iVar3) + iVar2 * iVar4 + iVar1);
      if (_km_coni == 0x10) {
        *(word *)puVar5 = ~*(word *)puVar5;
      }
      else {
        iVar3 = 0;
        do {
          *puVar5 = ~*puVar5;
          iVar3 = _km_coni + iVar3;
          puVar5 = puVar5 + 1;
        } while (iVar3 < 8);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0xc);
    _km_end_access();
    if ((byte_40B6953 & 2) != 0) {
      pushInvalidateCaches(1);
    }
  }
  return;
}

