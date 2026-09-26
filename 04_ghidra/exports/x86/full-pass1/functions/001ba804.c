/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ba804 */

undefined4
FUN_001ba804(undefined4 param_1,undefined4 param_2,undefined1 *param_3,size_t param_4,int param_5)

{
  if (param_5 == 3) {
    while (param_4 = param_4 - 1, param_4 != 0xffffffff) {
      *param_3 = 0x80;
      param_3 = param_3 + 1;
    }
  }
  else if (param_5 == 1) {
    while (param_4 = param_4 - 1, param_4 != 0xffffffff) {
      *param_3 = 0x7f;
      param_3 = param_3 + 1;
    }
  }
  else {
    _bzero(param_3,param_4);
  }
  return param_1;
}

