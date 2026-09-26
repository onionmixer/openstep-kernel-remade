/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e744. */
int __cdecl KernLockRelease(int a1)
{
  int result; // eax
  int v2; // eax

  result = a1; /*0x17e747*/
  if ( a1 ) /*0x17e74c*/
  {
    v2 = ipltospl(*(_DWORD *)(a1 + 12)); /*0x17e752*/
    return spln(v2); /*0x17e758*/
  }
  return result; /*0x17e75f*/
}
