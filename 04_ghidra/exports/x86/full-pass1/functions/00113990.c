/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113990 */

short * _pffindtype(int param_1,int param_2)

{
  int *piVar1;
  short *psVar2;
  
  piVar1 = _domains;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (short *)0x0;
    }
    if (*piVar1 == param_1) break;
    piVar1 = (int *)piVar1[7];
  }
  psVar2 = (short *)piVar1[5];
  while( true ) {
    if ((short *)piVar1[6] <= psVar2) {
      return (short *)0x0;
    }
    if ((*psVar2 != 0) && (*psVar2 == param_2)) break;
    psVar2 = psVar2 + 0x18;
  }
  return psVar2;
}

