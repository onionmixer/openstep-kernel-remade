/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107224 */

void _munmapfd(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_1 + *(int *)(_active_u + 0x154));
  *pbVar1 = *pbVar1 & 0xfd;
  return;
}

