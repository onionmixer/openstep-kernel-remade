/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137528 */

undefined4 * _svckudp_create(undefined4 param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  puVar1 = (undefined4 *)_kalloc(0x34);
  uVar2 = _kalloc(0x2260);
  puVar1[0xb] = uVar2;
  pvVar3 = (void *)_kalloc(0x1cc);
  _bzero(pvVar3,0x1cc);
  puVar1[3] = 0;
  puVar1[0xc] = pvVar3;
  puVar1[9] = (int)pvVar3 + 0x3c;
  puVar1[2] = &_svckudp_op;
  *(undefined2 *)(puVar1 + 1) = param_2;
  *puVar1 = param_1;
  _xprt_register();
  return puVar1;
}

