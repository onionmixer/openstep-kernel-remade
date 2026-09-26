/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8830 */

void FUN_001a8830(int param_1)

{
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 0x10c) != 0) {
    local_18 = 0x18;
    local_10 = *(undefined4 *)(param_1 + 0x10c);
    _msg_receive(local_1c,0,0);
  }
  return;
}

