/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139860 */

void FUN_00139860(undefined4 *param_1)

{
  *param_1 = (&_stable)
             [(uint)*(byte *)((int)param_1 + 0x43) + (uint)*(byte *)((int)param_1 + 0x42) & 0xf];
  (&_stable)[(uint)*(byte *)((int)param_1 + 0x43) + (uint)*(byte *)((int)param_1 + 0x42) & 0xf] =
       param_1;
  return;
}

