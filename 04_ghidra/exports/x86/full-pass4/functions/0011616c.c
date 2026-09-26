/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011616c */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011616c(void)

{
  int unaff_EBX;
  int unaff_ESI;
  
  _soqinsque();
  _sowakeup();
  _wakeup(unaff_EBX + 0x54);
  *(ushort *)(unaff_ESI + 6) = *(ushort *)(unaff_ESI + 6) & 0xfff3 | 2;
  _wakeup();
  _sowakeup();
  _sowakeup();
  return;
}

