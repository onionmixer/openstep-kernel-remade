/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161441 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00161441(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x134);
  iVar2 = *(int *)(unaff_ESI + 0x138);
  if (unaff_EBX + 0x11c == iVar1) {
    *(int *)(unaff_EBX + 0x120) = iVar2;
  }
  else {
    *(int *)(iVar1 + 0x138) = iVar2;
  }
  if (unaff_EBX + 0x11c == iVar2) {
    *(int *)(unaff_EBX + 0x11c) = iVar1;
  }
  else {
    *(int *)(iVar2 + 0x134) = iVar1;
  }
  *(undefined4 *)(unaff_ESI + 300) = 0;
  *(int *)(unaff_EBX + 0x124) = *(int *)(unaff_EBX + 0x124) + -1;
  _quantum_set();
  return;
}

