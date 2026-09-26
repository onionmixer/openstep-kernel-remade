/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccf18. */
Class __cdecl objc_getOrigClass(const char *name)
{
  Class result; // eax

  result = nullptr; /*0x1ccf1f*/
  if ( dword_1E55B0 ) /*0x1ccf28*/
    result = (Class)NXMapGet((_DWORD *)dword_1E55B0, (int)name); /*0x1ccf32*/
  if ( !result ) /*0x1ccf3c*/
    return objc_getClass(name); /*0x1ccf3f*/
  return result; /*0x1ccf44*/
}
