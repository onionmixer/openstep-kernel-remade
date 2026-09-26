/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00106d44 */

void _utask_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x15c);
  if (iVar1 != 0) {
    _kfree(*(undefined4 *)(param_1 + 0x150),iVar1 * 4);
    _kfree(*(undefined4 *)(param_1 + 0x154),iVar1);
    *(undefined4 *)(param_1 + 0x15c) = 0;
  }
  _zfree(_u_task_zone,param_1);
  return;
}

