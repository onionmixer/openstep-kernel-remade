/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0d78 */

undefined4 _ev_try_lock(uint *param_1)

{
  uint uVar1;
  
  LOCK();
  uVar1 = *param_1;
  *param_1 = *param_1 | 1;
  UNLOCK();
  if ((uVar1 & 1) == 0) {
    return 1;
  }
  return 0;
}

