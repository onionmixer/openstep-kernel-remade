/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001399e8 */

undefined4 * _slookup(int param_1,short param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(&_stable)[(uint)param_2._1_1_ + (uint)(byte)param_2 & 0xf];
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if ((*(short *)((int)puVar1 + 0x42) == param_2) && (puVar1[0xb] == param_1)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  *(short *)((int)puVar1 + 10) = *(short *)((int)puVar1 + 10) + 1;
  return puVar1 + 1;
}

