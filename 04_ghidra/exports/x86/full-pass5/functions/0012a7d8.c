/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012a7d8 */

void _tcp_notify(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(*(int *)(param_1 + 0x1c) + 0x56);
  if ((*(short *)(*(int *)(param_1 + 0x1c) + 6) == 4) ||
     (((sVar1 != 0x41 && (sVar1 != 0x33)) && (sVar1 != 0x40)))) {
    *(short *)(*(int *)(param_1 + 0x20) + 0x6a) = sVar1;
    _wakeup(*(int *)(param_1 + 0x1c) + 0x54);
    _sowakeup(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) + 0x24);
    _sowakeup(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) + 0x3c);
  }
  else {
    *(undefined2 *)(*(int *)(param_1 + 0x1c) + 0x56) = 0;
  }
  return;
}

