/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114f3f */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00114f3f(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  
  *(byte *)(unaff_EBX + 6) = *(byte *)(unaff_EBX + 6) & 0xfe;
  uVar1 = (**(code **)(*(int *)(unaff_EBX + 0xc) + 0x1c))();
  _splx();
  return uVar1;
}

