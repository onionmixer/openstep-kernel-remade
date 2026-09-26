/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011fbb4 */

undefined4 _SRIsEqual(undefined4 param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*param_2 == *param_3) && ((short)param_2[1] == (short)param_3[1])) {
    uVar1 = 1;
  }
  return uVar1;
}

