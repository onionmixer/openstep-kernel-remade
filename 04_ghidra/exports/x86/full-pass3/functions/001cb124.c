/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cb124 */

void FUN_001cb124(code *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = param_3;
  if (param_2 == 1) {
    (*param_1)(param_4,param_3);
  }
  else {
    while (param_2 = param_2 + -1, param_2 != -1) {
      (*param_1)(param_4,*puVar1);
      puVar1 = puVar1 + 1;
    }
    _free(param_3);
  }
  return;
}

