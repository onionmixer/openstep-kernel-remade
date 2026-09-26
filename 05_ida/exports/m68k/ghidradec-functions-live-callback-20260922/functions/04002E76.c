
void _bhinit(void)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = _bufhash;
  iVar1 = 0;
  do {
    *(undefined **)(puVar2 + 8) = puVar2;
    *(undefined **)(puVar2 + 4) = puVar2;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0xc;
  } while (iVar1 < 0x10);
  return;
}

