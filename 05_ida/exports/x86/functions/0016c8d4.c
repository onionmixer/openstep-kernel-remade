/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16c8d4. */
int __cdecl kern_serv_port_gone(int *a1, int a2)
{
  int result; // eax
  int v3; // ecx
  int i; // edx

  result = *a1; /*0x16c8de*/
  if ( *a1 ) /*0x16c8de*/
  {
    if ( *(_DWORD *)(result + 1200) == a2 ) /*0x16c8ea*/
      *(_DWORD *)(result + 1200) = 0; /*0x16c8ec*/
    v3 = 0; /*0x16c8f6*/
    for ( i = 0; *(_DWORD *)(i + result + 396) != a2; i += 16 ) /*0x16c8f8*/
    {
      if ( ++v3 > 49 ) /*0x16c927*/
        return result; /*0x16c927*/
    }
    *(_DWORD *)(i + result + 396) = 0; /*0x16c905*/
    *(_DWORD *)(i + result + 400) = 0; /*0x16c910*/
  }
  return result; /*0x16c929*/
}
