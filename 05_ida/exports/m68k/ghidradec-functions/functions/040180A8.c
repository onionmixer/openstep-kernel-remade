
int _getnewbuf_count(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  puVar3 = &unk_40B5860;
  do {
    for (puVar1 = (undefined4 *)puVar3[3]; puVar3 != puVar1; puVar1 = (undefined4 *)puVar1[3]) {
      iVar2 = iVar2 + 1;
    }
    puVar3 = puVar3 + -0x11;
  } while (&_bfreelist < puVar3);
  return iVar2;
}
