/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140d27 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00140d27(void)

{
  ushort uVar1;
  short sVar2;
  int unaff_EBX;
  
  uVar1 = *(ushort *)(unaff_EBX + 0x44);
  *(ushort *)(unaff_EBX + 0x44) = uVar1 & 0xfffe;
  if ((uVar1 & 0x10) != 0) {
    *(ushort *)(unaff_EBX + 0x44) = uVar1 & 0xffee;
    _wakeup();
  }
  sVar2 = *(short *)(unaff_EBX + 0x12);
  *(short *)(unaff_EBX + 0x12) = sVar2 + -1;
  if (sVar2 == 1) {
    *(undefined2 *)(unaff_EBX + 0x44) = 0;
    if (_ifreeh == 0) {
      _ifreeh = unaff_EBX;
      *(int **)(unaff_EBX + 0x60) = &_ifreeh;
    }
    else {
      *_ifreet = unaff_EBX;
      *(int **)(unaff_EBX + 0x60) = _ifreet;
    }
    *(undefined4 *)(unaff_EBX + 0x5c) = 0;
    _ifreet = (int *)(unaff_EBX + 0x5c);
  }
  return;
}

