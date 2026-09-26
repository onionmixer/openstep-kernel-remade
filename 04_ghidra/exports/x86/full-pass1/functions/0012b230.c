/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012b230 */

int _tcp_usrclosed(int param_1)

{
  switch(*(undefined2 *)(param_1 + 8)) {
  case 0:
  case 1:
  case 2:
    *(undefined2 *)(param_1 + 8) = 0;
    param_1 = _tcp_close(param_1);
    break;
  case 3:
  case 4:
    *(undefined2 *)(param_1 + 8) = 6;
    break;
  case 5:
    *(undefined2 *)(param_1 + 8) = 8;
  }
  if ((param_1 != 0) && (8 < *(short *)(param_1 + 8))) {
    _soisdisconnected(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1c));
  }
  return param_1;
}

