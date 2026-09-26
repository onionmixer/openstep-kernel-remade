/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104900 */

int _getf(uint param_1)

{
  int iVar1;
  
  if (param_1 < *(uint *)(_active_u + 0x15c)) {
    iVar1 = *(int *)(*(int *)(_active_u + 0x150) + param_1 * 4);
    if (iVar1 != 0) {
      if (iVar1 == -0x10000) {
        iVar1 = DAT_001e875c;
        *(undefined1 *)(DAT_001e875c + 0x68) = 9;
        return iVar1;
      }
      return iVar1;
    }
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = 9;
  return 0;
}

