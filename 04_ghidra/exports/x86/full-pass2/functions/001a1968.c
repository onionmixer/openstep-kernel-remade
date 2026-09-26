/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a1968 */

void _PCbopFD(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  uint uVar1;
  
  *(undefined4 *)(param_2 + 0x1c) = *param_3;
  param_2[0x1e] = *(undefined2 *)(param_3 + 1);
  uVar1 = param_3[2];
  *(uint *)(param_2 + 0x20) = uVar1;
  *(uint *)(param_2 + 0x20) = uVar1 & 0x70fd7 | 0x20202;
  *(undefined4 *)(param_2 + 0x22) = param_3[3];
  param_2[0x24] = *(undefined2 *)(param_3 + 4);
  param_2[6] = 0;
  param_2[4] = 0;
  param_2[2] = 0;
  *param_2 = 0;
  _thread_exception_return();
  return;
}

