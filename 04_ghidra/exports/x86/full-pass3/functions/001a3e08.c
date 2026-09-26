/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a3e08 */

int * FUN_001a3e08(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_001e866c;
  while( true ) {
    if ((int **)piVar1 == &DAT_001e866c) {
      return (int *)0x0;
    }
    if (*piVar1 == param_1) break;
    piVar1 = (int *)piVar1[2];
  }
  return piVar1;
}

