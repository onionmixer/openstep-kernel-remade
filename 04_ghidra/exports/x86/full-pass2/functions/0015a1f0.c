/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a1f0 */

undefined4 _convert_port_to_space(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if ((param_1[2] < 0) && ((short)param_1[2] == 2)) {
      uVar2 = *(undefined4 *)(param_1[5] + 0x88);
      _ipc_space_reference(uVar2);
    }
    LOCK();
    *param_1 = 0;
    UNLOCK();
  }
  return uVar2;
}

