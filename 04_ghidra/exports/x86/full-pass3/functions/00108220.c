/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108220 */

void _leavegroup(short param_1)

{
  short *psVar1;
  
  psVar1 = (short *)(*(int *)(_active_u + 0x1c) + 10);
  while( true ) {
    if ((short *)(*(int *)(_active_u + 0x1c) + 0x2a) <= psVar1) {
      return;
    }
    if (*psVar1 == param_1) break;
    psVar1 = psVar1 + 1;
  }
  for (; psVar1 < (short *)(*(int *)(_active_u + 0x1c) + 0x28); psVar1 = psVar1 + 1) {
    *psVar1 = psVar1[1];
  }
  *psVar1 = -1;
  return;
}

