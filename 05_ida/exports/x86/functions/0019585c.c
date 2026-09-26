/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19585c. */
__int32 sub_19585C()
{
  int v0; // ecx
  int v1; // edx

  do /*0x195879*/
  {
    while ( dword_1E7774 ) /*0x195867*/
      ; /*0x195865*/
  }
  while ( _InterlockedExchange(&dword_1E7774, 1) == 1 ); /*0x195879*/
  if ( kmId ) /*0x195882*/
  {
    v0 = *((_DWORD *)kmId + 67); /*0x1958a0*/
    v1 = *((_DWORD *)kmId + 69); /*0x1958a6*/
  }
  else
  {
    v0 = basicConsole; /*0x195884*/
    v1 = 1; /*0x19588a*/
    if ( MEMORY[0x1114C] ) /*0x195896*/
      v1 = 2; /*0x195898*/
  }
  if ( dword_1E38E8 > 0 ) /*0x1958b3*/
  {
    if ( v1 == 2 ) /*0x1958b8*/
    {
      if ( v0 ) /*0x1958c6*/
        (*(void (__cdecl **)(int, char *))(v0 + 12))(v0, &byte_1E384C[12 * dword_1E38E8]); /*0x1958d7*/
      if ( ++dword_1E38E8 > 3 ) /*0x1958e9*/
        dword_1E38E8 = 1; /*0x1958eb*/
      ns_timeout((int)sub_19585C, 0, 111111111); /*0x195905*/
    }
    else
    {
      dword_1E38E8 = -dword_1E38E8; /*0x1958bc*/
    }
  }
  return _InterlockedExchange(&dword_1E7774, 0); /*0x195914*/
}
