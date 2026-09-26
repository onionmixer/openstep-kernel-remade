/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00158020 */

int _convert_port_to_pset(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if ((param_1[2] < 0) && ((short)param_1[2] == 6)) {
      iVar2 = param_1[5];
      _pset_reference(iVar2);
    }
    LOCK();
    *param_1 = 0;
    UNLOCK();
  }
  return iVar2;
}

