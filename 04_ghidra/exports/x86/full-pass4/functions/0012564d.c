/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012564d */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0012564d(void)

{
  short sVar1;
  size_t sVar2;
  ushort uVar3;
  undefined1 *unaff_EBX;
  void *pvVar4;
  int unaff_EBP;
  int unaff_ESI;
  
  *(int *)(&DAT_001eab3c + *(int *)(unaff_EBP + 0xc) * 4) =
       *(int *)(&DAT_001eab3c + *(int *)(unaff_EBP + 0xc) * 4) + 1;
  *unaff_EBX = *(undefined1 *)(unaff_EBP + 0xc);
  if (*(int *)(unaff_EBP + 0xc) == 5) {
    *(undefined4 *)(unaff_EBX + 4) = **(undefined4 **)(unaff_EBP + 0x18);
  }
  else {
    *(undefined4 *)(unaff_EBX + 4) = 0;
  }
  if (*(int *)(unaff_EBP + 0xc) == 0xc) {
    unaff_EBX[4] = *(undefined1 *)(unaff_EBP + 0x10);
    *(undefined4 *)(unaff_EBP + 0x10) = 0;
  }
  unaff_EBX[1] = *(undefined1 *)(unaff_EBP + 0x10);
  _bcopy(*(void **)(unaff_EBP + 8),unaff_EBX + 8,*(size_t *)(unaff_EBP + -8));
  uVar3 = *(short *)(unaff_EBP + -4) + *(short *)(unaff_EBX + 10);
  *(ushort *)(unaff_EBX + 10) = uVar3 >> 8 | uVar3 * 0x100;
  sVar1 = *(short *)(unaff_ESI + 8);
  if ((0x70 < (uint)(*(int *)(unaff_EBP + -4) + (int)sVar1)) &&
     (*(undefined4 *)(unaff_EBP + -4) = 0x14, 0x70 < (int)sVar1 + 0x14U)) {
                    /* WARNING: Subroutine does not return */
    _panic(s_icmp_len_001dbceb);
  }
  sVar2 = *(size_t *)(unaff_EBP + -4);
  *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) - sVar2;
  *(short *)(unaff_ESI + 8) = *(short *)(unaff_ESI + 8) + *(short *)(unaff_EBP + -4);
  pvVar4 = (void *)(unaff_ESI + *(int *)(unaff_ESI + 4));
  _bcopy(*(void **)(unaff_EBP + 8),pvVar4,sVar2);
  *(undefined2 *)((int)pvVar4 + 2) = *(undefined2 *)(unaff_ESI + 8);
  *(undefined1 *)((int)pvVar4 + 9) = 1;
  _icmp_reflect(pvVar4,*(undefined4 *)(unaff_EBP + 0x14));
  _m_freem();
  return;
}

