/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140ca7 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00140ca7(void)

{
  int unaff_EBX;
  
  if ((*(ushort *)(unaff_EBX + 0x44) & 0x46) != 0) {
    *(ushort *)(unaff_EBX + 0x44) = *(ushort *)(unaff_EBX + 0x44) | 8;
    _microtime();
    if ((*(byte *)(unaff_EBX + 0x44) & 4) != 0) {
      *(undefined4 *)(unaff_EBX + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(unaff_EBX + 0x44) & 2) != 0) {
      *(undefined4 *)(unaff_EBX + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(unaff_EBX + 0x44) & 0x40) != 0) {
      *(undefined4 *)(unaff_EBX + 0x4c) = 0;
      *(undefined4 *)(unaff_EBX + 0x84) = _iuniqtime;
    }
    *(byte *)(unaff_EBX + 0x44) = *(byte *)(unaff_EBX + 0x44) & 0xb9;
  }
  _vn_rele();
  return;
}

