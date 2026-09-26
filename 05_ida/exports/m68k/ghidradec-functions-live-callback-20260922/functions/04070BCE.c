
void _km_clear_win(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  _km_begin_access();
  iVar3 = word_40B68DC * 0xc;
  if (iVar3 < ((int)word_40B68E4 + (int)word_40B68DC) * 0xc) {
    do {
      iVar4 = (int)word_40B68DE;
      puVar1 = (undefined4 *)
               ((uint)((word_40B68D8 + iVar4) * 0x20) / _km_coni +
               dword_40B6980 + dword_40B6940 * iVar3);
      for (iVar2 = (word_40B68D8 + iVar4) * 8; iVar2 < (word_40B68E0 + iVar4) * 8;
          iVar2 = _km_coni + iVar2) {
        *puVar1 = dword_40B68F4;
        iVar4 = (int)word_40B68DE;
        puVar1 = puVar1 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < ((int)word_40B68E4 + (int)word_40B68DC) * 0xc);
  }
  _km_end_access();
  return;
}

