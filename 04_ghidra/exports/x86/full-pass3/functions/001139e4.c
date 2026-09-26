/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001139e4 */

short * _pffindproto(int param_1,int param_2,int param_3)

{
  int *piVar1;
  short *psVar2;
  short *psVar3;
  
  psVar3 = (short *)0x0;
  piVar1 = _domains;
  if (param_1 != 0) {
    for (; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[7]) {
      if (*piVar1 == param_1) {
        psVar2 = (short *)piVar1[5];
        if ((short *)piVar1[6] <= psVar2) {
          return (short *)0x0;
        }
        do {
          if ((param_2 == psVar2[4]) && (*psVar2 == param_3)) {
            return psVar2;
          }
          if ((((param_3 == 3) && (*psVar2 == 3)) && (psVar2[4] == 0)) && (psVar3 == (short *)0x0))
          {
            psVar3 = psVar2;
          }
          psVar2 = psVar2 + 0x18;
        } while (psVar2 < (short *)piVar1[6]);
        return psVar3;
      }
    }
  }
  return (short *)0x0;
}

