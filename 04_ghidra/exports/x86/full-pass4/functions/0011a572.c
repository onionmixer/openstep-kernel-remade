/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a572 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

uint * __analysis_fragment_0011a572(void)

{
  uint *puVar1;
  int iVar2;
  
  do {
    puVar1 = (uint *)_getnewbuf();
    *puVar1 = *puVar1 | 0x10000;
    _bfree();
    *(uint *)(puVar1[2] + 4) = puVar1[1];
    *(uint *)(puVar1[1] + 8) = puVar1[2];
    FUN_0011b26c(puVar1);
    *(undefined2 *)(puVar1 + 7) = 0;
    puVar1[10] = 0;
    puVar1[1] = (uint)DAT_001e87ec;
    puVar1[2] = (uint)&DAT_001e87e8;
    DAT_001e87ec[2] = (uint)puVar1;
    DAT_001e87ec = puVar1;
    iVar2 = _brealloc(puVar1);
  } while (iVar2 == 0);
  return puVar1;
}

