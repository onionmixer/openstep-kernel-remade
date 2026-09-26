
void _lstat(void)

{
  undefined uVar1;
  
  uVar1 = _stat1(*(undefined4 *)(dword_40B57D4 + 0x24),0);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}

