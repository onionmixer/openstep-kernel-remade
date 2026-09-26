
void _sigpending(void)

{
  undefined uVar1;
  
  uVar1 = _copyoutmsg(*_active_u + 0x18,**(undefined4 **)(dword_40B57D4 + 0x24),4);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
