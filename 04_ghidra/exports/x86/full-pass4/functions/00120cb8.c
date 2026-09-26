/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00120cb8 */

undefined4 _if_init(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x30))(param_1);
    return uVar1;
  }
  return 6;
}

