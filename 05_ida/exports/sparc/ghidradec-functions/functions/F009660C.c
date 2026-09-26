
uint _vik_pac_pageflush(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_o5;
  
  iVar3 = 0;
  iVar4 = 0;
  do {
    while( true ) {
      uVar2 = iVar4 << 0x1a | iVar3 << 5 | 0x80000000U;
      iVar1 = segment(0xe);
      if (((in_o5 != param_1) || (in_o5 = 0x1000000, (*(uint *)(uVar2 + iVar1) & 0x1000000) == 0))
         || (in_o5 = 0x10000, (*(uint *)(uVar2 + iVar1) & 0x10000) == 0)) break;
      uVar2 = uVar2 ^ iVar4 << 0x1a;
      for (iVar4 = 0; in_o5 = 0x1000, iVar4 != 7; iVar4 = iVar4 + 1) {
      }
loc_F00966AC:
      iVar4 = 0;
      if (iVar3 == 0x7f) {
        return uVar2;
      }
      iVar3 = iVar3 + 1;
    }
    if (iVar4 == 3) goto loc_F00966AC;
    iVar4 = iVar4 + 1;
  } while( true );
}
