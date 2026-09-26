/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010df01 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0010df01(void)

{
  int unaff_EBX;
  
  *(uint *)(unaff_EBX + 0x40) = *(uint *)(unaff_EBX + 0x40) & 0xfffffffe;
  (*(code *)(&PTR__ttstart_001db008)[*(char *)(unaff_EBX + 0x47) * 0xc])();
  _splx();
  return;
}

