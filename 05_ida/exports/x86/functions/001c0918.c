/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0918. */
_DWORD *initDmaLock()
{
  _DWORD *result; // eax

  dword_1E871C = 0; /*0x1c091b*/
  dword_1E8720 = 0; /*0x1c0925*/
  result = (_DWORD *)simple_lock_alloc(); /*0x1c092f*/
  dword_1E8728 = (int)result; /*0x1c0934*/
  *result = 0; /*0x1c0939*/
  return result; /*0x1c0941*/
}
