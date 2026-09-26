/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a1e0 */

void _bdwrite(uint *param_1)

{
  if ((*param_1 & 0x200) == 0) {
    *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + 1;
  }
  *param_1 = *param_1 | 0x202;
  _brelse(param_1);
  return;
}

