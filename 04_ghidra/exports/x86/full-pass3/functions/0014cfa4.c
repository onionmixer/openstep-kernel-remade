/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014cfa4 */

int * _ipc_port_copy_send(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (param_1[2] < 0) {
      param_1[1] = param_1[1] + 1;
      param_1[7] = param_1[7] + 1;
      piVar2 = param_1;
    }
    else {
      piVar2 = (int *)0xffffffff;
    }
    LOCK();
    *param_1 = 0;
    UNLOCK();
    return piVar2;
  }
  return param_1;
}

