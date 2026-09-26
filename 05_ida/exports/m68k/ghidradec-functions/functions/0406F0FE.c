
void _kminit(void)

{
  int iVar1;
  undefined uStack_24;
  uint uStack_23;
  
  _km_select_console();
  _kminit2();
  word_40B68E0 = 0x32;
  word_40B68E4 = 0xf;
  iVar1 = dword_40B6944 + -400;
  if (iVar1 < 0) {
    iVar1 = dword_40B6944 + -0x181;
  }
  word_40B68DE = (undefined2)(iVar1 >> 4);
  _km_color = dword_40B6954;
  dword_40C3A10 = dword_40B6958;
  dword_40C3A14 = dword_40B695C;
  dword_40C3A18 = dword_40B6960;
  _evinit();
  _nvram_check(&uStack_24);
  _curBright = (uStack_23 & 0xfffffff) >> 0x16;
  unk_40B6904 = unk_40B6904 | 1;
  word_40B6906 = 0;
  word_40B6938 = 0;
  dword_40B68E8 = 0;
  dword_40B68EC = 0;
  return;
}
