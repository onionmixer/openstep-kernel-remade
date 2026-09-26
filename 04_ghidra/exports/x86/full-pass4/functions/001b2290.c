/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2290 */

int FUN_001b2290(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(char *)(param_1 + 0x208) == '\x01') {
    _ns_untimeout(FUN_001b34a0,param_1);
  }
  _ns_abstimeout(FUN_001b34a0,param_1,param_3,param_4,4);
  *(undefined1 *)(param_1 + 0x208) = 1;
  return param_1;
}

