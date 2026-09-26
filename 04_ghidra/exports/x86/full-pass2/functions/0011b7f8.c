/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b7f8 */

undefined4 _dnlc_purge1(void)

{
  undefined *puVar1;
  
  puVar1 = DAT_001e9be8;
  while( true ) {
    if (puVar1 == &_nc_lru) {
      return 0;
    }
    if (*(int *)(puVar1 + 0x14) != 0) break;
    puVar1 = *(undefined **)(puVar1 + 8);
  }
  FUN_0011b830(puVar1);
  return 1;
}

