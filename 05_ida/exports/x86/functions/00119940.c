/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119940. */
int __cdecl vfs_unlock(int a1)
{
  int result; // eax
  int v2; // edx

  if ( (*(_BYTE *)(a1 + 12) & 2) == 0 ) /*0x11994b*/
    panic(aVfsUnlock); /*0x119952*/
  result = *(_DWORD *)(a1 + 12); /*0x11995a*/
  v2 = result; /*0x11995d*/
  LOBYTE(v2) = result & 0xFD; /*0x11995f*/
  *(_DWORD *)(a1 + 12) = v2; /*0x119962*/
  if ( (result & 4) != 0 ) /*0x119967*/
  {
    LOBYTE(result) = result & 0xF9; /*0x119969*/
    *(_DWORD *)(a1 + 12) = result; /*0x11996b*/
    return wakeup(a1); /*0x11996f*/
  }
  return result; /*0x119974*/
}
