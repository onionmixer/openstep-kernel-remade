
void _gettimeofday(void)

{
  int *piVar1;
  undefined uVar2;
  undefined auStack_c [8];
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  if (*piVar1 != 0) {
    _microtime(auStack_c);
    uVar2 = _copyoutmsg(auStack_c,*piVar1,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  return;
}

