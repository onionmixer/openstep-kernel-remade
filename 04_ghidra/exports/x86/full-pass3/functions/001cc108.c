/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cc108 */

void _NXFreeMapTable(void *param_1)

{
  _NXResetMapTable(param_1);
  _free(*(void **)((int)param_1 + 0xc));
  _free(param_1);
  return;
}

