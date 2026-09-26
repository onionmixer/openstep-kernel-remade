/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011988b */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011988b(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  
  piVar1 = _rootvfs;
  do {
    piVar3 = piVar1;
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vfs_remove__vfs_not_found_001db52f);
    }
    piVar1 = (int *)*piVar3;
  } while (piVar1 != (int *)unaff_EDI);
  *piVar3 = *piVar1;
  iVar2 = piVar1[2];
  if (*(int *)(iVar2 + 0xc) == 0) {
    piVar1 = (int *)(iVar2 + 0x10);
    for (iVar2 = *(int *)(iVar2 + 0x10); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x120)) {
      iVar2 = *piVar1;
      if (iVar2 == unaff_EDI) goto LAB_001198da;
      piVar1 = (int *)(iVar2 + 0x120);
    }
    if (*piVar1 != unaff_EDI) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vfs_remove__can_t_find_vfs_in_en_001db509);
    }
LAB_001198da:
    *piVar1 = *(int *)(unaff_EDI + 0x120);
    _microtime();
  }
  else {
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  _vfs_unlock();
  return;
}

