
byte _if_down_all(void)

{
  int iVar1;
  char cVar2;
  
  cVar2 = '\0';
  for (iVar1 = _ifnet; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x5a)) {
    _if_down(iVar1);
  }
  return cVar2 << 4 | 4;
}
