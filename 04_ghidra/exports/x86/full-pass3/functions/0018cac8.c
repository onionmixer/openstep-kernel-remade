/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018cac8 */

undefined4 _check_cpu_subtype(int param_1)

{
  if (DAT_001e8e08 == 4) {
LAB_0018cb00:
    if (param_1 == 4) {
      return 1;
    }
  }
  else {
    if (DAT_001e8e08 < 5) {
      if (DAT_001e8e08 != 3) {
        return 0;
      }
      goto LAB_0018cb18;
    }
    if (DAT_001e8e08 != 5) {
      if (DAT_001e8e08 != 0x84) {
        return 0;
      }
      goto LAB_0018cb00;
    }
    if (param_1 - 4U < 2) {
      return 1;
    }
  }
  if (param_1 == 0x84) {
    return 1;
  }
LAB_0018cb18:
  if (param_1 == 3) {
    return 1;
  }
  return 0;
}

