/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00169c64 */

void FUN_00169c64(void)

{
  bool bVar1;
  
  bVar1 = DAT_001e7268 < DAT_001e7264 + DAT_001e7260;
  LOCK();
  DAT_001e7244 = 0;
  UNLOCK();
  _thread_wakeup_prim(&DAT_001e7260,1,0);
  if (bVar1) {
    _thread_wakeup_prim(&DAT_001e7268,1,0);
  }
  return;
}

