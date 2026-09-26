/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168b50 */

undefined4 __regparm1 _stack_finalize(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  if (_stack_check_usage != 0) {
    uVar1 = 0;
    do {
      if (*(int *)(param_2 + uVar1 * 4) != -0x21524111) break;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x3fd);
    uVar1 = uVar1 * -4 + 0xff4;
    do {
    } while (_stack_usage_lock != 0);
    LOCK();
    UNLOCK();
    if (_stack_max_usage < uVar1) {
      _stack_max_usage = uVar1;
    }
    LOCK();
    param_1 = 1;
    _stack_usage_lock = 0;
    UNLOCK();
  }
  return param_1;
}

