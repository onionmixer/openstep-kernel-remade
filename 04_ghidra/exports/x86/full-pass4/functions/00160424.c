/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160424 */

undefined4 FUN_00160424(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  LOCK();
  iVar1 = *__kernDebuggerLock;
  *__kernDebuggerLock = 1;
  UNLOCK();
  if (iVar1 == 1) {
    _safe_prf(s_Couldn_t_acquire_debugger_lock__001df1d9);
    _safe_prf(s_exit_from_monitor_and_try_again__001df1fa);
    uVar2 = 1;
  }
  else {
    uVar2 = _miniMonGdb(param_1);
    LOCK();
    *__kernDebuggerLock = 0;
    UNLOCK();
  }
  return uVar2;
}

