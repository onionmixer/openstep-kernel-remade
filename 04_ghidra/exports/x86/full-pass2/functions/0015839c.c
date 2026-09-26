/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015839c */

int _ipc_kobject_set(int *param_1,int param_2,uint param_3)

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
  param_1[2] = param_1[2] & 0xffff0000U | param_3;
  param_1[5] = param_2;
  LOCK();
  iVar1 = *param_1;
  *param_1 = 0;
  UNLOCK();
  return iVar1;
}

