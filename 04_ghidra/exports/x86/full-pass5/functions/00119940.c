/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119940 */

void _vfs_unlock(int param_1)

{
  uint uVar1;
  
  if ((*(byte *)(param_1 + 0xc) & 2) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vfs_unlock_001db549);
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffffd;
  if ((uVar1 & 4) != 0) {
    *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffff9;
    _wakeup(param_1);
  }
  return;
}

