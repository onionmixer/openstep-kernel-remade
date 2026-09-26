/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015081c */

undefined4 _ipc_space_create_special(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)_zalloc(_ipc_space_zone);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 6;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 1;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *param_1 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}

