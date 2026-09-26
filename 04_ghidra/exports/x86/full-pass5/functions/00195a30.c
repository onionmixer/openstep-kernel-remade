/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00195a30 */

void _kmDisableAnimation(void)

{
  if (_kmId != 0) {
    _objc_msgSend(_kmId,PTR_s_animationCtl__001f94a4,0);
  }
  return;
}

