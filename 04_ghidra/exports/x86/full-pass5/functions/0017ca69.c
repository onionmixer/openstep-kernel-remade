/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ca69 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0017ca69(void)

{
  byte *pbVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x20) < unaff_EBX) {
    *(int *)(unaff_EDI + 0x20) = unaff_EBX;
  }
  iVar2 = unaff_EBX;
  if (unaff_EBX < 0) {
    iVar2 = unaff_EBX + 7;
  }
  pbVar1 = (byte *)((iVar2 >> 3) + *(int *)(unaff_EDI + 0x10));
  *pbVar1 = *pbVar1 | (byte)(1 << ((char)unaff_EBX + (char)(iVar2 >> 3) * -8 & 0x1fU));
  *(int *)(unaff_EDI + 0x18) = *(int *)(unaff_EDI + 0x18) + -1;
  *(int *)(unaff_EDI + 0x24) = unaff_EBX;
  _lock_done();
  return;
}

