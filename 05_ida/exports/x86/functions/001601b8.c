/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1601b8. */
_DWORD *miniMonInit()
{
  _DWORD *result; // eax

  result = (_DWORD *)simple_lock_alloc(); /*0x1601bb*/
  _kernDebuggerLock = (int)result; /*0x1601c0*/
  *result = 0; /*0x1601c5*/
  return result; /*0x1601cd*/
}
