/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135d94 */

void FUN_00135d94(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffff7;
  if ((uVar1 & 0x10) != 0) {
    *param_1 = uVar1 & 0xffffffe7;
    _wakeup(param_1 + 0x1a);
  }
  return;
}

