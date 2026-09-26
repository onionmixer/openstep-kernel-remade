/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157d9b */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00157d9b(void)

{
  int iVar1;
  undefined4 unaff_EBX;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x15c) = unaff_EBX;
  iVar1 = _ipc_port_alloc_special();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_pset_init_001debdd);
  }
  *(int *)(unaff_ESI + 0x160) = iVar1;
  return;
}

