/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155c78 */

undefined4 _convert_port_type(uint param_1)

{
  param_1 = param_1 & 0x1f0000;
  if (param_1 == 0x30000) {
    return 7;
  }
  if (param_1 < 0x30001) {
    if (param_1 == 0x10000) {
      return 1;
    }
    if (param_1 == 0x20000) {
      return 7;
    }
  }
  else {
    if (param_1 == 0x80000) {
      return 9;
    }
    if (param_1 < 0x80001) {
      if (param_1 == 0x40000) {
        return 1;
      }
    }
    else if (param_1 == 0x100000) {
      return 1;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_convert_port_type__strange_port_t_001deafd);
}

