/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010c974 */

void FUN_0010c974(char *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  while( true ) {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    if (cVar1 == '\0') break;
    FUN_0010cbac((int)cVar1,param_2,param_3);
  }
  return;
}

