/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00191006 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00191006(void)

{
  short sVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_EBP;
  byte *unaff_ESI;
  short unaff_DI;
  
  *(short *)((int)unaff_EBX + 0x1a) = *(short *)((int)unaff_EBX + 0x1a) - unaff_DI;
  if (*(uint *)(unaff_EBP + 0x10) <= (uint)*(ushort *)(unaff_EBX + 6)) {
    sVar1 = (short)unaff_EBX[6] - *(short *)(unaff_EBP + 0x10);
    *(short *)(unaff_EBX + 6) = sVar1;
    if ((*(int *)(unaff_EBP + 0x18) != 0) && (iVar2 = _ptes_per_vm_page, sVar1 == 0)) {
      while (0 < iVar2) {
        *unaff_ESI = *unaff_ESI & 0xfe;
        unaff_ESI = unaff_ESI + 4;
        iVar2 = iVar2 + -1;
      }
      *(int *)(*unaff_EBX + 4) = unaff_EBX[1];
      *(int *)unaff_EBX[1] = *unaff_EBX;
      __pt_active_count = __pt_active_count + -1;
      *unaff_EBX = (int)&_pt_free_queue;
      unaff_EBX[1] = (int)DAT_001f7adc;
      *(int **)unaff_EBX[1] = unaff_EBX;
      __pt_free_count = __pt_free_count + 1;
      DAT_001f7adc = unaff_EBX;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_pmap_deallocate_mappings_001e25e5);
}

