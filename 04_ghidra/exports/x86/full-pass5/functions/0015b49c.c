/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b49c */

void _stack_statistics(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  _lock_read(&_stack_queue_lock);
  puVar1 = DAT_001e5b98;
  if (_stack_check_usage != 0) {
    for (; (undefined4 **)puVar1 != &DAT_001e5b98; puVar1 = (undefined4 *)*puVar1) {
      uVar2 = _stack_usage(puVar1 + 3);
      if (*param_2 < uVar2) {
        *param_2 = uVar2;
      }
    }
  }
  *param_1 = DAT_001ded68;
  _lock_done(&_stack_queue_lock);
  return;
}

