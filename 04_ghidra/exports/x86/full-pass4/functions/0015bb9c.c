/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015bb9c */

undefined4 _lock_set_recursive(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = param_1 + 2;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if ((*(byte *)((int)param_1 + 6) & 2) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_lock_set_recursive__don_t_have_w_001dede0);
  }
  *param_1 = _active_threads;
  LOCK();
  uVar3 = param_1[2];
  param_1[2] = 0;
  UNLOCK();
  return uVar3;
}

