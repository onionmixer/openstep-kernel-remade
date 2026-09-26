/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135330 */

void _clntkudp_once(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 8);
  if (param_2 != 0) {
    *(byte *)puVar1 = (byte)*puVar1 | 0x20;
    return;
  }
  *puVar1 = *puVar1 & 0xffffffdf;
  return;
}

