/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014d1a4 */

undefined4 * _ipc_port_alloc_special(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_zalloc(_ipc_object_zones);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 1;
    puVar1[2] = 0x80000000;
    puVar1[3] = param_1;
    puVar1[4] = 1;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 5;
    _ipc_mqueue_init(puVar1 + 0x10);
    puVar1[0x13] = 0;
  }
  return puVar1;
}

