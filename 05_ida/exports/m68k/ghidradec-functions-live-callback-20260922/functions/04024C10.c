
void _tcp_canceltimers(int param_1)

{
  word wVar1;
  int iVar2;
  sword sVar3;
  
  iVar2 = 3;
  do {
    do {
      *(undefined2 *)(param_1 + 10 + iVar2 * 2) = 0;
      wVar1 = (word)((uint)iVar2 >> 0x10);
      sVar3 = (sword)iVar2 + -1;
      iVar2 = CONCAT22(wVar1,sVar3);
    } while (sVar3 != -1);
    iVar2 = (uint)wVar1 * 0x10000 + -1;
  } while (wVar1 != 0);
  return;
}

