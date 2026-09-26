
void _rqinit(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  puVar2 = &_qs;
  do {
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  return;
}

