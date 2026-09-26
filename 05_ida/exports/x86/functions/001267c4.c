/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1267c4. */
int __cdecl ip_freef(_DWORD *a1)
{
  int v1; // esi
  _DWORD *v2; // ebx
  int v3; // eax
  int v4; // eax

  v1 = a1[3]; /*0x1267cd*/
  if ( (_DWORD *)v1 != a1 ) /*0x1267d2*/
  {
    do /*0x1267ee*/
    {
      v2 = *(_DWORD **)(v1 + 12); /*0x1267d4*/
      ip_deq(v1); /*0x1267d8*/
      v3 = v1; /*0x1267dd*/
      LOBYTE(v3) = v1 & 0x80; /*0x1267df*/
      m_freem(v3); /*0x1267e2*/
      v1 = (int)v2; /*0x1267ea*/
    }
    while ( v2 != a1 ); /*0x1267ee*/
  }
  *(_DWORD *)(*a1 + 4) = a1[1]; /*0x1267f5*/
  *(_DWORD *)a1[1] = *a1; /*0x1267fd*/
  v4 = (int)a1; /*0x1267ff*/
  LOBYTE(v4) = (unsigned __int8)a1 & 0x80; /*0x126801*/
  return m_free(v4); /*0x12680c*/
}
