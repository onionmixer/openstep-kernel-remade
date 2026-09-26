
void sub_4032B16(int param_1)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  bVar2 = *(byte *)(iVar1 + 0x75);
  *(byte *)(iVar1 + 0x75) = bVar2 & 0xfe;
  if ((bVar2 & 2) != 0) {
    *(byte *)(iVar1 + 0x75) = bVar2 & 0xfc;
    _wakeup(iVar1 + 0x75);
  }
  return;
}
