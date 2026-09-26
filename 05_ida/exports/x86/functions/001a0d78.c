/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0d78. */
_BOOL4 __cdecl ev_try_lock(volatile signed __int32 *a1)
{
  return !_interlockedbittestandset(a1, 0); /*0x1a0d8a*/
}
