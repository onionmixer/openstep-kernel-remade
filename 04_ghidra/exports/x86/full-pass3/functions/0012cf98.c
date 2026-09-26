/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012cf98 */

void _exportfree(byte *param_1)

{
  if ((*(int *)(param_1 + 8) == 1) && (*(int *)(param_1 + 0xc) != 0)) {
    _kfree(*(undefined4 *)(param_1 + 0x10),*(int *)(param_1 + 0xc) << 4);
  }
  if (((*param_1 & 2) != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    _kfree(*(undefined4 *)(param_1 + 0x1c),*(int *)(param_1 + 0x18) << 4);
  }
  _kfree(*(ushort **)(param_1 + 0x28),**(ushort **)(param_1 + 0x28) + 2);
  _kfree(param_1,0x30);
  return;
}

