/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0fff */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001c0fff(void)

{
  int iVar1;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 uStack0000000c;
  undefined *puStack00000010;
  
  iVar1 = *(int *)(unaff_EBX + 4);
  *(int *)(unaff_EBX + 4) = iVar1 + -1;
  if (iVar1 == 1) {
    DAT_001e871c = *(int *)(unaff_EBX + 8);
    *(uint *)(unaff_EBP + -4) = (uint)(DAT_001e871c != 0);
    unaff_ESI = unaff_EBX;
  }
  LOCK();
  *DAT_001e8728 = 0;
  UNLOCK();
  if (*(int *)(unaff_EBP + -4) != 0) {
    puStack00000010 = &DAT_001e8724;
    uStack0000000c = 0x1c1041;
    _thread_wakeup();
  }
  if (unaff_ESI != 0) {
    puStack00000010 = (undefined *)0xc;
    _IOFree();
  }
  return;
}

