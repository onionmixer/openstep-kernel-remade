/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00184a74 */

void _IOSetDDMMask(int param_1,undefined4 param_2)

{
  if (4 < param_1) {
    _IOLog(s_xprSetBitmask__illegal_index___d_001e13a4,param_1);
    return;
  }
  *(undefined4 *)(&_IODDMMasks + param_1 * 4) = param_2;
  return;
}

