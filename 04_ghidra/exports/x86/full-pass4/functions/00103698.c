/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00103698 */

int _hzto(int *param_1)

{
  int local_14;
  int local_c;
  int local_8;
  
  _getthetime(&local_c);
  local_c = *param_1 - local_c;
  if (local_c < 0x20c0b4) {
    local_14 = ((param_1[1] - local_8) / 1000 + local_c * 1000) / (_tick / 1000);
  }
  else {
    local_14 = 0x7fffffff;
    if (local_c <= (int)(0x7fffffff / (longlong)_hz)) {
      local_14 = local_c * _hz;
    }
  }
  return local_14;
}

