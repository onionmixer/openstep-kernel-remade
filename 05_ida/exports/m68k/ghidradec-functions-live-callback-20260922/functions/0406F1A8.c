
void _kminit2(void)

{
  word wVar1;
  int iVar2;
  sword sVar3;
  undefined2 *puVar4;
  
  dword_40B68F4 = dword_40B6954;
  dword_40B68F0 = dword_40B6960;
  word_40B68DA = 0;
  word_40B68D8 = 0;
  dword_40B68FA = &DAT_40b6900;
  iVar2 = 2;
  puVar4 = &unk_40B6902;
  do {
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + -1;
      wVar1 = (word)((uint)iVar2 >> 0x10);
      sVar3 = (sword)iVar2 + -1;
      iVar2 = CONCAT22(wVar1,sVar3);
    } while (sVar3 != -1);
    iVar2 = (uint)wVar1 * 0x10000 + -1;
  } while (wVar1 != 0);
  return;
}

