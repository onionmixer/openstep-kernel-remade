/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142fa0 */

int _scanc(int param_1,byte *param_2,int param_3,byte param_4)

{
  byte *pbVar1;
  
  pbVar1 = param_2 + param_1;
  while ((param_2 < pbVar1 && ((*(byte *)((uint)*param_2 + param_3) & param_4) == 0))) {
    param_2 = param_2 + 1;
  }
  return (int)pbVar1 - (int)param_2;
}

