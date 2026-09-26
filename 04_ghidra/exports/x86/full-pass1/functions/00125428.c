/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125428 */

void _in_losing(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    if ((*(byte *)(iVar1 + 0x24) & 0x10) != 0) {
      _rtrequest(0x8030720b,iVar1);
    }
    _rtfree(iVar1);
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}

