
undefined4 _intr_spurious(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = dword_40B4F4E + 1;
  iVar2 = dword_40B4F4E % 0x100;
  dword_40B4F4E = iVar1;
  if (iVar2 == 1) {
    _printf(aIplDSpuriousIn,5);
  }
  return 1;
}
