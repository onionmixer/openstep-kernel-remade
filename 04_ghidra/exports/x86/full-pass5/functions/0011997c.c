/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011997c */

int * _getvfs(int *param_1)

{
  int *piVar1;
  
  if (_rootvfs != (int *)0x0) {
    piVar1 = _rootvfs;
    do {
      if ((piVar1[5] == *param_1) && (piVar1[6] == param_1[1])) {
        return piVar1;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  return (int *)0x0;
}

