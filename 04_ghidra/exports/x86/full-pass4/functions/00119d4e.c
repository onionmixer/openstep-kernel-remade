/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00119d4e */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00119d4e(void)

{
  int unaff_EBX;
  
  (**(code **)(*(int *)(*(int *)(unaff_EBX + 0x40) + 0x1c) + 0x54))();
  *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + 1;
  _biowait();
  return;
}

