/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013de14 */

void _brelse_and_swap(int param_1)

{
  if (param_1 != 0) {
    _byte_swap_dir_block_out(param_1);
    _brelse(param_1);
  }
  return;
}

