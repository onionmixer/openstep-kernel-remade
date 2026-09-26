/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139894 */

void _sunsave(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)0x0;
  puVar2 = (undefined4 *)
           (&_stable)
           [(uint)*(byte *)((int)param_1 + 0x43) + (uint)*(byte *)((int)param_1 + 0x42) & 0xf];
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    if (puVar2 == param_1) break;
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  }
  if (puVar1 == (undefined4 *)0x0) {
    (&_stable)[(uint)*(byte *)((int)puVar2 + 0x43) + (uint)*(byte *)((int)puVar2 + 0x42) & 0xf] =
         *puVar2;
    return;
  }
  *puVar1 = *puVar2;
  return;
}

