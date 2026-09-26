/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00117064 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00117064(void)

{
  int iVar1;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(undefined2 *)(unaff_ESI + 0xc) = 2;
  *(undefined4 *)(unaff_ESI + 8) = 3;
  *(undefined ***)(unaff_ESI + 0x14) = &_socketops;
  *(undefined4 *)(unaff_ESI + 0x18) = unaff_EBX;
  *(int *)(*(int *)(_active_u + 0x150) + *(int *)(DAT_001e875c + 0x60) * 4) = unaff_ESI;
  iVar1 = _m_get(1);
  _soaccept();
  if (*(int *)(unaff_EDI + 4) != 0) {
    if ((int)*(short *)(iVar1 + 8) < *(int *)(unaff_EBP + -4)) {
      *(int *)(unaff_EBP + -4) = (int)*(short *)(iVar1 + 8);
    }
    _copyout(iVar1 + *(int *)(iVar1 + 4),*(undefined4 *)(unaff_EDI + 4));
    _copyout(unaff_EBP + -4,*(undefined4 *)(unaff_EDI + 8),4);
  }
  _m_freem();
  _splx(*(undefined4 *)(unaff_EBP + -8));
  return;
}

