/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001163f8 */

void _sbselqueue(int param_1)

{
  int iVar1;
  
  iVar1 = _selthreadcache(param_1 + 0x10);
  if (iVar1 != 0) {
    *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 0x10;
  }
  return;
}

