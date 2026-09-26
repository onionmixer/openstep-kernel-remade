/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a5c1 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0015a5c1(void)

{
  int iVar1;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if ((unaff_ESI == 0) ||
     (iVar1 = _ipc_object_copyout_compat(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x88)),
     iVar1 != 0)) {
    *unaff_EDI = 0;
  }
  return;
}

