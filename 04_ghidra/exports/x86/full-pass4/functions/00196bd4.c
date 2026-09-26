/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196bd4 */

void FUN_00196bd4(void)

{
  char cVar1;
  
  cVar1 = _objc_msgSend(DAT_001e7768,PTR_s_respondsTo__001f9464,PTR_s_revertToVGAMode_001f94a8);
  if (cVar1 != '\0') {
    _objc_msgSend(DAT_001e7768,PTR_s_revertToVGAMode_001f94a8);
    _IODelay(0x18a88);
  }
  return;
}

