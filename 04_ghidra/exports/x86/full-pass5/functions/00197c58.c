/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00197c58 */

void _BasicAllocateConsole(void)

{
  int iVar1;
  undefined4 local_8c;
  undefined4 local_88;
  
  iVar1 = _FBAllocateVBEConsole();
  if (iVar1 == 0) {
    _bzero(&local_8c,0x88);
    local_8c = 0x280;
    local_88 = 0x1e0;
    _VGAAllocateConsole(&local_8c);
  }
  return;
}

