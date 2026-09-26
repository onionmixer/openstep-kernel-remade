/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c334. */
int __cdecl nfs_attrcache_va(int a1, _DWORD *a2)
{
  int result; // eax

  if ( (*(_BYTE *)(a1 + 4) & 0x40) == 0 ) /*0x12c344*/
  {
    result = *(_DWORD *)(*(_DWORD *)(a1 + 36) + 296); /*0x12c349*/
    if ( (*(_BYTE *)(result + 20) & 0x10) == 0 ) /*0x12c353*/
    {
      qmemcpy((void *)(*(_DWORD *)(a1 + 48) + 128), a2, 0x40u); /*0x12c366*/
      *(_DWORD *)(a1 + 40) = *a2; /*0x12c36a*/
      return sub_12C380(a1); /*0x12c36e*/
    }
  }
  return result; /*0x12c376*/
}
