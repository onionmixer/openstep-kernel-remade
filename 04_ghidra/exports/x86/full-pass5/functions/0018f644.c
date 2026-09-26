/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018f644 */

void * _pmap_create(int param_1)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    pvVar1 = (void *)_zalloc(_pmap_zone);
    if (pvVar1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_create_pmap_001e2528);
    }
    _bzero(pvVar1,0x1c);
    FUN_0018f58c(pvVar1);
    *(undefined4 *)((int)pvVar1 + 8) = 1;
    *(undefined4 *)((int)pvVar1 + 0xc) = 0;
  }
  else {
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}

