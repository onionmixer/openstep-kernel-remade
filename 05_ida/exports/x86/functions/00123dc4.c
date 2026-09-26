/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123dc4. */
char *__cdecl inet_ntoa(in_addr a1)
{
  int *v1; // ebx
  _BYTE *v2; // ecx
  int i; // esi
  int v5; // [esp+10h] [ebp-4h] BYREF

  v5 = *(_DWORD *)a1.s_addr; /*0x123dd2*/
  v1 = &v5; /*0x123dd5*/
  v2 = &unk_1E58F4; /*0x123dd8*/
  for ( i = 0; i <= 3; ++i ) /*0x123ddd*/
  {
    if ( i ) /*0x123de2*/
      *v2++ = 46; /*0x123de4*/
    if ( *(_BYTE *)v1 > 0x63u ) /*0x123dec*/
    {
      *v2++ = *(_BYTE *)v1 / 0x64u + 48; /*0x123df9*/
      if ( !(*(_BYTE *)v1 % 0x64u / 0xA) ) /*0x123e19*/
        *v2++ = 48; /*0x123e1f*/
      *(_BYTE *)v1 %= 0x64u; /*0x123e39*/
    }
    if ( *(_BYTE *)v1 > 9u ) /*0x123e3f*/
    {
      *v2++ = *(_BYTE *)v1 / 0xAu + 48; /*0x123e4c*/
      *(_BYTE *)v1 %= 0xAu; /*0x123e65*/
    }
    *v2++ = *(_BYTE *)v1 + 48; /*0x123e6c*/
    v1 = (int *)((char *)v1 + 1); /*0x123e6f*/
  }
  *v2 = 0; /*0x123e7a*/
  return (char *)&unk_1E58F4; /*0x123e85*/
}
