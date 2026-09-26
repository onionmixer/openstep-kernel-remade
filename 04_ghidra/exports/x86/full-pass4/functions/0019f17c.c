/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f17c */

int FUN_0019f17c(int param_1)

{
  if (*(char *)(param_1 + 0x154) == '\x01') {
    _ns_untimeout(__analysis_fragment_0019f0a0,param_1);
    *(undefined1 *)(param_1 + 0x154) = 0;
  }
  if ((*(int *)(param_1 + 0x160) != 0) || (*(int *)(param_1 + 0x164) != 0)) {
    _ns_abstimeout(__analysis_fragment_0019f0a0,param_1,*(undefined4 *)(param_1 + 0x160),
                   *(undefined4 *)(param_1 + 0x164),4);
    *(undefined1 *)(param_1 + 0x154) = 1;
  }
  return param_1;
}

