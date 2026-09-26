/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x190c24. */
unsigned int __cdecl pmap_extract(int a1, unsigned int a2)
{
  int v2; // ecx
  volatile __int32 *v3; // edx
  _BYTE *v4; // eax
  _DWORD *v5; // eax
  unsigned int v6; // ebx

  v2 = splvm(); /*0x190c34*/
  v3 = (volatile __int32 *)(a1 + 12); /*0x190c36*/
  do /*0x190c4e*/
  {
    while ( *v3 ) /*0x190c3c*/
      ; /*0x190c3e*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x190c4e*/
  v4 = (_BYTE *)(*(_DWORD *)a1 + 4 * (a2 >> 22)); /*0x190c58*/
  if ( (*v4 & 1) != 0 /*0x190c78*/
    && (v5 = (_DWORD *)((*(_DWORD *)v4 & 0xFFFFF000) + ((a2 >> 10) & 0xFFC))) != nullptr
    && (*(_BYTE *)v5 & 1) != 0 )
  {
    v6 = (a2 & 0xFFF) + (*v5 & 0xFFFFF000); /*0x190c8f*/
  }
  else
  {
    v6 = 0; /*0x190c7a*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 12), 0); /*0x190c94*/
  splx(v2); /*0x190c98*/
  return v6; /*0x190ca2*/
}
