/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111b76 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int * __analysis_fragment_00111b76(void)

{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar1 = (int *)&DAT_001e56c4;
  piVar2 = DAT_001e56c4;
  if (DAT_001e56c4 != (int *)0x0) {
    do {
      if (*piVar2 == unaff_ESI) break;
      piVar1 = piVar2 + 1;
      piVar2 = (int *)piVar2[1];
    } while (piVar2 != (int *)0x0);
    if (piVar2 != (int *)0x0) {
      *piVar1 = piVar2[1];
      goto LAB_00111bd3;
    }
  }
  piVar2 = (int *)_kalloc();
  *piVar2 = unaff_ESI;
  piVar2[4] = 0x1c251a1c;
  *(undefined1 *)(piVar2 + 5) = 0x5c;
  *(undefined1 *)((int)piVar2 + 0x15) = 1;
  *(undefined1 *)((int)piVar2 + 0x16) = 0;
  piVar2[2] = 0;
  piVar2[3] = 0;
LAB_00111bd3:
  piVar2[1] = (int)DAT_001e56c4;
  DAT_001e56c4 = piVar2;
  _splx();
  return piVar2;
}

