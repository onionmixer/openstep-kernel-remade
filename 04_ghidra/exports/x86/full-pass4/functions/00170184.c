/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00170184 */

void FUN_00170184(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((param_1[1] == 0x20) && (*param_1 < 0)) && ((param_1[6] & 0x3fffffffU) == 0x10012011)) {
    uVar1 = _netipc_ignore(param_1[2],param_1[7]);
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

