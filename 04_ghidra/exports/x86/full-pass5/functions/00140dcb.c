/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140dcb */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00140dcb(void)

{
  ushort uVar1;
  uint unaff_EBX;
  
  if (*(char *)(*(int *)(unaff_EBX + 0x50) + 0xd2) == '\0') {
    while ((*(ushort *)(unaff_EBX + 0x44) & 1) != 0) {
      *(ushort *)(unaff_EBX + 0x44) = *(ushort *)(unaff_EBX + 0x44) | 0x10;
      _sleep(unaff_EBX);
    }
    *(byte *)(unaff_EBX + 0x44) = *(byte *)(unaff_EBX + 0x44) | 1;
    if (*(short *)(unaff_EBX + 0x66) < 1) {
      *(int *)(unaff_EBX + 0xd0) = *(int *)(unaff_EBX + 0xd0) + 1;
      *(ushort *)(unaff_EBX + 0x44) = *(ushort *)(unaff_EBX + 0x44) | 0x200;
      _itrunc();
      *(undefined2 *)(unaff_EBX + 100) = 0;
      *(undefined4 *)(unaff_EBX + 0x8c) = 0;
      *(byte *)(unaff_EBX + 0x44) = *(byte *)(unaff_EBX + 0x44) | 0x42;
      _ifree();
    }
    if ((*(byte *)(unaff_EBX + 0x44) & 0x4e) != 0) {
      _iupdat();
    }
    uVar1 = *(ushort *)(unaff_EBX + 0x44);
    *(ushort *)(unaff_EBX + 0x44) = uVar1 & 0xfffe;
    if ((uVar1 & 0x10) != 0) {
      *(ushort *)(unaff_EBX + 0x44) = uVar1 & 0xffee;
      _wakeup();
    }
  }
  *(undefined2 *)(unaff_EBX + 0x44) = 0;
  if (_ifreeh == 0) {
    _ifreeh = unaff_EBX;
    *(uint **)(unaff_EBX + 0x60) = &_ifreeh;
  }
  else {
    *_ifreet = unaff_EBX;
    *(uint **)(unaff_EBX + 0x60) = _ifreet;
  }
  *(undefined4 *)(unaff_EBX + 0x5c) = 0;
  _ifreet = (uint *)(unaff_EBX + 0x5c);
  return;
}

