/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012fdd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0012fdd0(int param_1)

{
  __rlock_awaken_count = __rlock_awaken_count + 1;
  if (param_1 != 0) {
    _wakeup(param_1);
  }
  return;
}

