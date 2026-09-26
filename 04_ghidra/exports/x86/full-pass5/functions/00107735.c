/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107735 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00107735(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = **(int **)(unaff_ESI + 8);
  **(int **)(unaff_ESI + 8) = iVar1 + -1;
  if (iVar1 == 1) {
    if (*(int *)(*(int *)(unaff_ESI + 8) + 8) != 0) {
      iVar1 = _ttynty();
      *(undefined4 *)(iVar1 + 8) = 0;
    }
    _kfree(*(undefined4 *)(unaff_ESI + 8));
  }
  _kfree();
  return;
}

