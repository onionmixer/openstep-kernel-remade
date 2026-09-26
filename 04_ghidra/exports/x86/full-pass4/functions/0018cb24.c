/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018cb24 */

undefined4 _grade_cpu_subtype(int param_1)

{
  if (DAT_001e8e08 == 4) {
    if (param_1 == 4) {
      return 3;
    }
    if (4 < param_1) {
LAB_0018cb78:
      if (param_1 != 0x84) {
        return 0;
      }
      return 2;
    }
  }
  else if (DAT_001e8e08 < 5) {
    if (DAT_001e8e08 != 3) {
      return 0;
    }
  }
  else if (DAT_001e8e08 == 5) {
    if (param_1 == 4) {
      return 3;
    }
    if (4 < param_1) {
      if (param_1 == 5) {
        return 4;
      }
      goto LAB_0018cb78;
    }
  }
  else {
    if (DAT_001e8e08 != 0x84) {
      return 0;
    }
    if (param_1 == 4) {
      return 2;
    }
    if (4 < param_1) {
      if (param_1 != 0x84) {
        return 0;
      }
      return 3;
    }
  }
  if (param_1 != 3) {
    return 0;
  }
  return 1;
}

