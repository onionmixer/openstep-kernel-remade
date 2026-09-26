/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001394f0 */

void * _fifosp(int param_1)

{
  void *pvVar1;
  undefined1 local_44 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  pvVar1 = (void *)_kalloc(0x8c);
  _bzero(pvVar1,0x8c);
  *(undefined ***)((int)pvVar1 + 0x20) = &_fifo_vnodeops;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))(param_1,local_44,*(undefined4 *)(_active_u + 0x1c))
  ;
  *(undefined4 *)((int)pvVar1 + 0x4c) = local_24;
  *(undefined4 *)((int)pvVar1 + 0x50) = local_20;
  *(undefined4 *)((int)pvVar1 + 0x54) = local_1c;
  *(undefined4 *)((int)pvVar1 + 0x58) = local_18;
  *(undefined4 *)((int)pvVar1 + 0x5c) = local_14;
  *(undefined4 *)((int)pvVar1 + 0x60) = local_10;
  return pvVar1;
}

