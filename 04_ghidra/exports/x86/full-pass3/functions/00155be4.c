/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155be4 */

undefined4 _port_translate_compat(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined1 local_10 [4];
  uint local_c;
  int local_8;
  
  iVar2 = _ipc_right_lookup_write(param_1,param_2,&local_8);
  if ((iVar2 == 0) &&
     (iVar2 = _ipc_right_info(param_1,param_2,local_8,&local_c,local_10), iVar2 == 0)) {
    if ((local_c & 0x20000) != 0) {
      piVar1 = *(int **)(local_8 + 4);
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
      *param_3 = piVar1;
      return 0;
    }
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    if ((local_c & 0x170000) != 0) {
      return 7;
    }
  }
  return 4;
}

