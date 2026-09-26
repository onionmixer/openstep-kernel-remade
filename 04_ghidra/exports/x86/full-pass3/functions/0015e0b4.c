/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015e0b4 */

void _vm_info_init(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)_zalloc(_vm_info_zone);
  }
  *puVar1 = 0;
  *(undefined2 *)(puVar1 + 1) = 0;
  *(undefined2 *)((int)puVar1 + 6) = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  *(byte *)(puVar1 + 0xe) = *(byte *)(puVar1 + 0xe) & 0xec | 4;
  puVar1[5] = 0;
  _lock_init(puVar1 + 6,1);
  puVar1[9] = 0;
  *param_1 = puVar1;
  return;
}

