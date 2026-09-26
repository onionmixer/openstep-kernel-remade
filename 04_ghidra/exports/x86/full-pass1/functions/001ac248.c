/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ac248 */

int * FUN_001ac248(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x128);
  while( true ) {
    if ((int *)(param_1 + 0x128) == piVar1) {
      return (int *)0x0;
    }
    if ((((*piVar1 == param_3) && (piVar1[1] == param_4)) && (piVar1[2] == param_5)) &&
       (piVar1[3] == param_6)) break;
    piVar1 = (int *)piVar1[5];
  }
  return piVar1;
}

