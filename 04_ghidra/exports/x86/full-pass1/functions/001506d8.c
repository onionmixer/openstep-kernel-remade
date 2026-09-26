/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001506d8 */

void _ipc_space_release(int *param_1)

{
  int iVar1;
  
  do {
    do {
    } while (*param_1 != 0);
    LOCK();
    iVar1 = *param_1;
    *param_1 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  iVar1 = param_1[1];
  param_1[1] = iVar1 + -1;
  LOCK();
  *param_1 = 0;
  UNLOCK();
  if (iVar1 == 1) {
    _zfree(_ipc_space_zone,param_1);
  }
  return;
}

