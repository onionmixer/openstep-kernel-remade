/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016935a */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0016935a(void)

{
  int *piVar1;
  int unaff_EBX;
  int unaff_ESI;
  
  if ((int **)DAT_001e7248 == &DAT_001e7248) {
    piVar1 = (int *)0x0;
  }
  else {
    *(int ***)(*DAT_001e7248 + 4) = &DAT_001e7248;
    piVar1 = DAT_001e7248;
    DAT_001e7248 = (int *)*DAT_001e7248;
  }
  piVar1[2] = unaff_EBX;
  piVar1[3] = unaff_ESI;
  piVar1[4] = 0;
  piVar1[5] = 0;
  piVar1[6] = 0;
  *piVar1 = (int)&DAT_001e7250;
  piVar1[1] = (int)DAT_001e7254;
  *(int **)piVar1[1] = piVar1;
  DAT_001e7260 = DAT_001e7260 + 1;
  DAT_001e7254 = piVar1;
  piVar1[7] = 1;
  FUN_00169c64();
  _splx();
  return;
}

