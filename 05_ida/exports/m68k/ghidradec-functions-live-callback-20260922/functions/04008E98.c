
void _killpg(void)

{
  uint uVar1;
  undefined uVar2;
  
  uVar1 = (*(undefined4 **)(dword_40B57D4 + 0x24))[1];
  if (uVar1 < 0x21) {
    uVar2 = _killpg1(uVar1,**(undefined4 **)(dword_40B57D4 + 0x24),0);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}

