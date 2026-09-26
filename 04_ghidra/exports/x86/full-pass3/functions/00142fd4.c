/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142fd4 */

int _skpc(char param_1,int param_2,char *param_3)

{
  char *pcVar1;
  
  pcVar1 = param_3 + param_2;
  for (; (param_3 < pcVar1 && (*param_3 == param_1)); param_3 = param_3 + 1) {
  }
  return (int)pcVar1 - (int)param_3;
}

