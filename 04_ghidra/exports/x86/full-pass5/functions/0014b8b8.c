/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014b8b8 */

int _ipc_object_translate(int param_1,undefined4 param_2,char param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  uint *local_8;
  
  iVar2 = _ipc_right_lookup_write(param_1,param_2,&local_8);
  if (iVar2 == 0) {
    if ((*local_8 & 1 << (param_3 + 0x10U & 0x1f)) == 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      iVar2 = 0x11;
    }
    else {
      piVar1 = (int *)local_8[1];
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      *param_4 = piVar1;
      iVar2 = 0;
    }
  }
  return iVar2;
}

