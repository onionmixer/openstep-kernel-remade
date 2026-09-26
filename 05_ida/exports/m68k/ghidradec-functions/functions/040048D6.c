
void _execv(void)

{
  undefined uVar1;
  
  *(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 8) = 0;
  uVar1 = _execve();
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  return;
}
