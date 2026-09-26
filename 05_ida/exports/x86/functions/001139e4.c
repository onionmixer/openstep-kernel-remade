/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1139e4. */
__int16 *__cdecl pffindproto(int a1, int a2, int a3)
{
  __int16 *v3; // ebx
  _DWORD *v4; // eax
  __int16 *v6; // edx
  unsigned int v7; // eax
  __int16 v8; // cx

  v3 = nullptr; /*0x1139f3*/
  if ( !a1 ) /*0x1139f7*/
    return nullptr; /*0x1139f7*/
  v4 = (_DWORD *)domains; /*0x1139f9*/
  if ( !domains ) /*0x113a00*/
    return nullptr; /*0x113a0f*/
  while ( *v4 != a1 ) /*0x113a06*/
  {
    v4 = (_DWORD *)v4[7]; /*0x113a08*/
    if ( !v4 ) /*0x113a0d*/
      return nullptr; /*0x113a0d*/
  }
  v6 = (__int16 *)v4[5]; /*0x113a18*/
  v7 = v4[6]; /*0x113a1b*/
  if ( (unsigned int)v6 >= v7 ) /*0x113a20*/
    return v3; /*0x113a59*/
  while ( 1 ) /*0x113a28*/
  {
    v8 = v6[4]; /*0x113a28*/
    if ( a2 == v8 && *v6 == a3 ) /*0x113a39*/
      break; /*0x113a39*/
    if ( a3 == 3 && *v6 == 3 && !v8 && !v3 ) /*0x113a4d*/
      v3 = v6; /*0x113a4f*/
    v6 += 24; /*0x113a51*/
    if ( v7 <= (unsigned int)v6 ) /*0x113a57*/
      return v3; /*0x113a57*/
  }
  return v6; /*0x113a5e*/
}
