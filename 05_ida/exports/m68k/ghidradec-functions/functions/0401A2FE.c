
void _rmdir(void)

{
  undefined uVar1;
  
  uVar1 = _vn_remove(**(undefined4 **)(dword_40B57D4 + 0x24),0,1);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
