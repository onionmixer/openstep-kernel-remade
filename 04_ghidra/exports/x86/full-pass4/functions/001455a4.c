/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001455a4 */

undefined4 FUN_001455a4(int param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)_kalloc(0xc);
  _bzero(puVar1,0xc);
  *puVar1 = 10;
  *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x48);
  *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xd0);
  *param_2 = puVar1;
  return 0;
}

