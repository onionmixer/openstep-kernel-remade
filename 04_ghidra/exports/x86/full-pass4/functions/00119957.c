/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119957 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00119957(void)

{
  uint uVar1;
  int unaff_EBX;
  
  uVar1 = *(uint *)(unaff_EBX + 0xc);
  *(uint *)(unaff_EBX + 0xc) = uVar1 & 0xfffffffd;
  if ((uVar1 & 4) != 0) {
    *(uint *)(unaff_EBX + 0xc) = uVar1 & 0xfffffff9;
    _wakeup();
  }
  return;
}

