
void _vhangup(void)

{
  int iVar1;
  undefined auStack_94 [136];
  undefined4 uStack_c;
  int iStack_8;
  
  iStack_8 = 0x401af06;
  iVar1 = _suser();
  if ((iVar1 != 0) && (*(int *)(_active_u + 0x15e) != 0)) {
    iStack_8 = (int)*(sword *)(_active_u + 0x162);
    uStack_c = 0x401af22;
    _forceclose();
    uStack_c = 1;
    _bcopy(*(undefined4 *)(_active_u + 0x15e),auStack_94,0x86);
    _gsignal();
  }
  return;
}
