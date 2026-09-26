
void _creat(void)

{
  undefined uVar1;
  
  uVar1 = _copen(**(undefined4 **)(dword_40B57D4 + 0x24),0x602,
                 (*(undefined4 **)(dword_40B57D4 + 0x24))[1]);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
