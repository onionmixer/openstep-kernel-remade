/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001603b4 */

void _safe_prf(undefined4 param_1)

{
  char cVar1;
  char *local_8;
  
  local_8 = &DAT_001e5bc4;
  _prf(param_1,&stack0x00000008,8,&local_8);
  *local_8 = '\0';
  local_8 = &DAT_001e5bc4;
  cVar1 = DAT_001e5bc4;
  while (cVar1 != '\0') {
    cVar1 = *local_8;
    local_8 = local_8 + 1;
    _miniMonPutchar((int)cVar1);
    cVar1 = *local_8;
  }
  return;
}

