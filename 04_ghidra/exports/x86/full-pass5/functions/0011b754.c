/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b754 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _dnlc_purge(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  _DAT_001e9c1c = _DAT_001e9c1c + 1;
  while( true ) {
    puVar2 = &_nc_hash;
    while (puVar1 = (undefined4 *)*puVar2, puVar1 == puVar2) {
      puVar2 = puVar2 + 2;
      if ((undefined4 *)0x1e9bdf < puVar2) {
        return;
      }
    }
    if ((puVar1[5] == 0) || (puVar1[4] == 0)) break;
    FUN_0011b830(puVar1);
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_dnlc_purge__zero_vp_001db6fc);
}

