
void _settimeofday(void)

{
  undefined uVar1;
  undefined auStack_c [8];
  
  if (**(int **)(dword_40B57D4 + 0x24) != 0) {
    uVar1 = _copyinmsg(**(int **)(dword_40B57D4 + 0x24),auStack_c,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar1;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _setthetime(auStack_c);
    }
  }
  return;
}
