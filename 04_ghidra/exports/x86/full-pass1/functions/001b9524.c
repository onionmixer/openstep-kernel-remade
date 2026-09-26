/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b9524 */

void FUN_001b9524(int param_1,undefined4 param_2,undefined4 param_3)

{
  switch(param_3) {
  case 600:
    *(undefined4 *)(param_1 + 0x68) = 0;
    return;
  case 0x259:
    *(undefined4 *)(param_1 + 0x68) = 3;
    return;
  case 0x25a:
    *(undefined4 *)(param_1 + 0x68) = 1;
    return;
  case 0x25b:
    *(undefined4 *)(param_1 + 0x68) = 2;
    return;
  case 0x25c:
    *(undefined4 *)(param_1 + 0x68) = 4;
    return;
  default:
    _IOLog("Audio: supported encoding: %d\n",param_3);
    return;
  }
}

