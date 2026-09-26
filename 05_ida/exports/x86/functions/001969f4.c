/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1969f4. */
int __cdecl -[kmDevice animationCtl:](kmDevice *self, SEL a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  int v6; // ecx
  int v7; // edx

  v3 = 0; /*0x1969ff*/
  v4 = 0; /*0x196a01*/
  if ( self->fbMode != 2 ) /*0x196a0a*/
    return 0; /*0x196a0c*/
  do /*0x196a2d*/
  {
    while ( dword_1E7774 ) /*0x196a1b*/
      ; /*0x196a19*/
  }
  while ( _InterlockedExchange(&dword_1E7774, 1) == 1 ); /*0x196a2d*/
  if ( (unsigned int)a3 <= 1 ) /*0x196a32*/
  {
    if ( dword_1E38E8 > 0 ) /*0x196a43*/
    {
      dword_1E38E8 = -dword_1E38E8; /*0x196a47*/
      (*((void (__cdecl **)($8EF4127CF77ECA3DDB612FCF233DC3A8 *, void *))self->fbp[0] + 4))(self->fbp[0], &unk_1E387C); /*0x196a5b*/
    }
  }
  else if ( a3 == 2 ) /*0x196a37*/
  {
    if ( dword_1E38E8 < 0 ) /*0x196a6b*/
    {
      dword_1E38E8 = -dword_1E38E8; /*0x196a6f*/
      v3 = 1; /*0x196a74*/
    }
  }
  else
  {
    v4 = 22; /*0x196a7c*/
  }
  _InterlockedExchange(&dword_1E7774, 0); /*0x196a83*/
  if ( v3 ) /*0x196a8b*/
  {
    do /*0x196aad*/
    {
      while ( dword_1E7774 ) /*0x196a9b*/
        ; /*0x196a99*/
    }
    while ( _InterlockedExchange(&dword_1E7774, 1) == 1 ); /*0x196aad*/
    if ( kmId ) /*0x196ab6*/
    {
      v6 = *((_DWORD *)kmId + 67); /*0x196ad4*/
      v7 = *((_DWORD *)kmId + 69); /*0x196ada*/
    }
    else
    {
      v6 = basicConsole; /*0x196ab8*/
      v7 = 1; /*0x196abe*/
      if ( MEMORY[0x1114C] ) /*0x196aca*/
        v7 = 2; /*0x196acc*/
    }
    if ( dword_1E38E8 > 0 ) /*0x196ae7*/
    {
      if ( v7 == 2 ) /*0x196aec*/
      {
        if ( v6 ) /*0x196afa*/
          (*(void (__cdecl **)(int, char *))(v6 + 12))(v6, &byte_1E384C[12 * dword_1E38E8]); /*0x196b0b*/
        if ( ++dword_1E38E8 > 3 ) /*0x196b1d*/
          dword_1E38E8 = 1; /*0x196b1f*/
        ns_timeout((int)sub_19585C, 0, 111111111); /*0x196b39*/
      }
      else
      {
        dword_1E38E8 = -dword_1E38E8; /*0x196af0*/
      }
    }
    _InterlockedExchange(&dword_1E7774, 0); /*0x196b40*/
  }
  return v4; /*0x196b4b*/
}
