/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168efc */

void _thread_swapin(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[0x13] & 0x300;
  if (uVar1 == 0x100) {
    param_1[0x13] = param_1[0x13] & 0xfffffcff | 0x200;
    do {
    } while (_swapper_lock_data != 0);
    LOCK();
    UNLOCK();
    *param_1 = &_swapin_queue;
    param_1[1] = DAT_001f6d94;
    *(undefined4 **)param_1[1] = param_1;
    DAT_001f6d94 = param_1;
    LOCK();
    _swapper_lock_data = 0;
    UNLOCK();
    _thread_wakeup_prim(&_swapin_queue,0,0);
  }
  else if (uVar1 != 0x200) {
                    /* WARNING: Subroutine does not return */
    _panic(s_thread_swapin_001dfcac);
  }
  return;
}

