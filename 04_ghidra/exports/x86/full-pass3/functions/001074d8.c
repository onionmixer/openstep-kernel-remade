/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001074d8 */

undefined4 * _pgfind(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(&_pgrphash)[param_1 & 0x3f];
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (puVar1[3] == param_1) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}

