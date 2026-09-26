/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00197514 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _kminit(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  DAT_001e777c = 1;
  _basicConsole = _FBAllocateVBEConsole();
  if (_basicConsole == 0) {
    _basicConsole = _BasicAllocateConsole();
  }
  bVar1 = _DAT_0001114c == 0;
  if (bVar1) {
    _basicConsoleMode = 1;
    uVar2 = 1;
  }
  else {
    _basicConsoleMode = 2;
    uVar2 = 2;
  }
  (**(code **)(_basicConsole + 4))(_basicConsole,uVar2,bVar1,bVar1,_mach_title);
  return;
}

