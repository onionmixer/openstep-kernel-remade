/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00110fa4 */

void _ttyrubo(int param_1,int param_2)

{
  undefined *puVar1;
  
  puVar1 = &DAT_001dafd9;
  if ((*(byte *)(param_1 + 0x3e) & 4) != 0) {
    puVar1 = &DAT_001dafd5;
  }
  while (param_2 = param_2 + -1, -1 < param_2) {
    _ttyoutstr(puVar1,param_1);
  }
  return;
}

