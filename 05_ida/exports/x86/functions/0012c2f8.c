/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c2f8. */
int __cdecl nfs_attrcache(int a1, int a2)
{
  int result; // eax

  if ( (*(_BYTE *)(a1 + 4) & 0x40) == 0 ) /*0x12c303*/
  {
    result = *(_DWORD *)(*(_DWORD *)(a1 + 36) + 296); /*0x12c308*/
    if ( (*(_BYTE *)(result + 20) & 0x10) == 0 ) /*0x12c312*/
    {
      nattr_to_vattr(a1, a2, *(_DWORD *)(a1 + 48) + 128); /*0x12c322*/
      return sub_12C380(a1); /*0x12c328*/
    }
  }
  return result; /*0x12c32d*/
}
