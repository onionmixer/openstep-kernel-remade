/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ac84 */

void _getthetime(int *param_1)

{
  int iVar1;
  
  do {
    iVar1 = _mtime[1];
  } while (*_mtime != _mtime[2]);
  *param_1 = _mtime[2];
  param_1[1] = iVar1;
  return;
}

