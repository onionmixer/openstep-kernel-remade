/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x167b2c. */
int __cdecl thread_release(int a1)
{
  int v1; // esi
  volatile __int32 *v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // edx

  v1 = splsched(); /*0x167b39*/
  v2 = (volatile __int32 *)(a1 + 32); /*0x167b3b*/
  do /*0x167b52*/
  {
    while ( *v2 ) /*0x167b40*/
      ; /*0x167b42*/
  }
  while ( _InterlockedExchange(v2, 1) == 1 ); /*0x167b52*/
  v3 = *(_DWORD *)(a1 + 64); /*0x167b54*/
  *(_DWORD *)(a1 + 64) = v3 - 1; /*0x167b5a*/
  if ( v3 == 1 ) /*0x167b60*/
  {
    v4 = *(_DWORD *)(a1 + 76); /*0x167b62*/
    v5 = v4; /*0x167b65*/
    LOBYTE(v5) = v4 & 0xED; /*0x167b67*/
    *(_DWORD *)(a1 + 76) = v5; /*0x167b6a*/
    if ( (v4 & 5) == 0 ) /*0x167b6f*/
    {
      LOBYTE(v5) = v4 & 0xE9 | 4; /*0x167b71*/
      *(_DWORD *)(a1 + 76) = v5; /*0x167b74*/
      thread_setrun((char **)a1, 1); /*0x167b7a*/
    }
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x167b84*/
  return splx(v1); /*0x167b90*/
}
