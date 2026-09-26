/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b788 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011b788(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  do {
    FUN_0011b830();
    puVar2 = &_nc_hash;
    while (puVar1 = (undefined4 *)*puVar2, puVar1 == puVar2) {
      puVar2 = puVar2 + 2;
      if ((undefined4 *)0x1e9bdf < puVar2) {
        return;
      }
    }
  } while ((puVar1[5] != 0) && (puVar1[4] != 0));
                    /* WARNING: Subroutine does not return */
  _panic(s_dnlc_purge__zero_vp_001db6fc);
}

