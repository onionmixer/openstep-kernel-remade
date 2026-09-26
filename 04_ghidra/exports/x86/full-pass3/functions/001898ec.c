/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001898ec */

void * FUN_001898ec(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)_alloc_cnvmem(0x10000,0x10000);
  if (pvVar1 != (void *)0x0) {
    _bzero(pvVar1,0x10000);
  }
  return pvVar1;
}

