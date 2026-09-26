/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00193a54 */

undefined4
_machine_exception(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  if (param_1 == 2) {
    *param_4 = 4;
    *param_5 = param_2;
  }
  else {
    if (param_1 != 3) {
      return 0;
    }
    *param_4 = 8;
    *param_5 = param_2;
  }
  return 1;
}

