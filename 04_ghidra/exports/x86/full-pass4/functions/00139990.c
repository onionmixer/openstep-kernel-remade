/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139990 */

undefined4 * _other_specvp(undefined4 *param_1)

{
  short sVar1;
  undefined4 *puVar2;
  
  sVar1 = *(short *)(param_1[0xc] + 0x42);
  puVar2 = (undefined4 *)(&_stable)[(uint)*(byte *)(param_1[0xc] + 0x43) + (uint)(byte)sVar1 & 0xf];
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (((*(short *)((int)puVar2 + 0x42) == sVar1) && (puVar2 + 1 != param_1)) &&
       (puVar2[0xb] == param_1[10])) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return puVar2 + 1;
}

