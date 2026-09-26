/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014bc64 */

int _ipc_object_copyin_from_kernel(int *param_1,int param_2)

{
  int iVar1;
  
  switch(param_2 + -5) {
  case 0:
  case 0xb:
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    param_1[6] = 0;
    param_1[4] = 0;
    param_1[3] = 0;
    break;
  case 1:
  case 0xe:
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (param_1[2] < 0) {
      param_1[7] = param_1[7] + 1;
    }
    param_1[1] = param_1[1] + 1;
    break;
  default:
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_object_copyin_from_kernel__s_001de8d5);
  case 0xc:
  case 0xd:
    return param_2 + -5;
  case 0xf:
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    param_1[1] = param_1[1] + 1;
    param_1[6] = param_1[6] + 1;
    param_1[7] = param_1[7] + 1;
    break;
  case 0x10:
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    param_1[1] = param_1[1] + 1;
    param_1[8] = param_1[8] + 1;
  }
  LOCK();
  iVar1 = *param_1;
  *param_1 = 0;
  UNLOCK();
  return iVar1;
}

