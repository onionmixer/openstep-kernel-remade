/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139944 */

undefined4 _isclosing(short param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(&_stable)[(uint)param_1._1_1_ + (uint)(byte)param_1 & 0xf];
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (((*(short *)((int)puVar1 + 0x42) == param_1) && (puVar1[0xb] == param_2)) &&
       ((*(byte *)(puVar1 + 0x10) & 8) != 0)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}

