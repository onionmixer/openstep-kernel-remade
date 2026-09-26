/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00184aa0 */

undefined4 _IOGetDDMMask(int param_1)

{
  if (4 < param_1) {
    _IOLog(s_xprGetBitmask__illegal_index___d_001e13c7,param_1);
    return 0;
  }
  return *(undefined4 *)(&_IODDMMasks + param_1 * 4);
}

