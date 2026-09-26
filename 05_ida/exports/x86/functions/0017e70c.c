/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e70c. */
int __cdecl KernLockAcquire(int a1)
{
  int result; // eax
  int v2; // esi
  int v3; // eax

  result = curipl(); /*0x17e717*/
  v2 = result; /*0x17e71c*/
  if ( a1 ) /*0x17e720*/
  {
    result = *(_DWORD *)(a1 + 8); /*0x17e722*/
    if ( v2 < result ) /*0x17e727*/
    {
      v3 = ipltospl(*(_DWORD *)(a1 + 8)); /*0x17e72a*/
      result = spln(v3); /*0x17e730*/
    }
    *(_DWORD *)(a1 + 12) = v2; /*0x17e735*/
  }
  return result; /*0x17e73b*/
}
