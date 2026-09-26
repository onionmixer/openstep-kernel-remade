
void sub_408A41A(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _mon_global;
  iVar2 = _curipl();
  if (iVar2 < 3) {
    *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) & 0xf7;
    byte_40B228B = 1;
    _delay(100000);
  }
  return;
}

