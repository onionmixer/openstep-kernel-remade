/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00165c94 */

int __regparm1 _task_reference(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    do {
      do {
      } while (*param_2 != 0);
      LOCK();
      iVar1 = *param_2;
      *param_2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    param_2[1] = param_2[1] + 1;
    LOCK();
    param_1 = *param_2;
    *param_2 = 0;
    UNLOCK();
  }
  return param_1;
}

