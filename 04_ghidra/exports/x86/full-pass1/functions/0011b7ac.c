/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b7ac */

void _dnlc_purge_vp(int param_1)

{
  undefined *puVar1;
  bool bVar2;
  
  do {
    bVar2 = false;
    for (puVar1 = DAT_001e9be8; puVar1 != &_nc_lru; puVar1 = *(undefined **)(puVar1 + 8)) {
      if ((*(int *)(puVar1 + 0x14) == param_1) || (*(int *)(puVar1 + 0x10) == param_1)) {
        FUN_0011b830(puVar1);
        bVar2 = true;
        break;
      }
    }
    if (!bVar2) {
      return;
    }
  } while( true );
}

