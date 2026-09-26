/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138bfc. */
int __cdecl sub_138BFC(int a1, char a2, int a3)
{
  int v3; // ebx
  __int16 v4; // ax
  __int16 v5; // ax
  int v6; // edx
  __int16 v7; // ax
  __int16 v8; // ax
  int i; // eax

  v3 = *(_DWORD *)(a1 + 48); /*0x138c07*/
  if ( a3 <= 1 ) /*0x138c0e*/
  {
    if ( (a2 & 1) != 0 ) /*0x138c1a*/
    {
      v4 = *(_WORD *)(v3 + 130); /*0x138c1c*/
      *(_WORD *)(v3 + 130) = v4 - 1; /*0x138c27*/
      if ( v4 == 1 ) /*0x138c32*/
      {
        v5 = *(_WORD *)(v3 + 136); /*0x138c34*/
        if ( (v5 & 2) != 0 ) /*0x138c3d*/
        {
          LOBYTE(v5) = v5 & 0xFD; /*0x138c3f*/
          *(_WORD *)(v3 + 136) = v5; /*0x138c41*/
          wakeup(v3 + 128); /*0x138c4f*/
        }
        v6 = *(_DWORD *)(v3 + 120); /*0x138c57*/
        if ( v6 ) /*0x138c5c*/
        {
          selwakeup(v6, *(_BYTE *)(v3 + 136) & 0x10); /*0x138c69*/
          thread_deallocate(*(_DWORD *)(v3 + 120)); /*0x138c72*/
          *(_BYTE *)(v3 + 136) &= ~0x10u; /*0x138c77*/
          *(_DWORD *)(v3 + 120) = 0; /*0x138c7e*/
        }
      }
    }
    if ( *(_DWORD *)(v3 + 116) ) /*0x138c88*/
    {
      thread_deallocate(*(_DWORD *)(v3 + 116)); /*0x138c90*/
      *(_DWORD *)(v3 + 116) = 0; /*0x138c95*/
    }
    if ( *(_DWORD *)(v3 + 112) ) /*0x138c9f*/
    {
      thread_deallocate(*(_DWORD *)(v3 + 112)); /*0x138ca7*/
      *(_DWORD *)(v3 + 112) = 0; /*0x138cac*/
    }
    if ( (a2 & 2) != 0 ) /*0x138cbc*/
    {
      v7 = *(_WORD *)(v3 + 128); /*0x138cbe*/
      *(_WORD *)(v3 + 128) = v7 - 1; /*0x138cc9*/
      if ( v7 == 1 ) /*0x138cd4*/
      {
        v8 = *(_WORD *)(v3 + 136); /*0x138cd6*/
        if ( (v8 & 1) != 0 ) /*0x138cdf*/
        {
          LOBYTE(v8) = v8 & 0xFE; /*0x138ce1*/
          *(_WORD *)(v3 + 136) = v8; /*0x138ce3*/
          wakeup(v3 + 130); /*0x138cf1*/
        }
      }
    }
    if ( !*(_DWORD *)(v3 + 128) ) /*0x138cf9*/
    {
      for ( i = *(_DWORD *)(v3 + 104); i; i = sub_139560(i, v3) ) /*0x138d07*/
        ; /*0x138d0e*/
      if ( *(_DWORD *)(v3 + 124) ) /*0x138d1a*/
        smark(v3, 66); /*0x138d23*/
      *(_DWORD *)(v3 + 104) = 0; /*0x138d28*/
      *(_WORD *)(v3 + 134) = 0; /*0x138d2f*/
      *(_WORD *)(v3 + 132) = 0; /*0x138d38*/
      *(_DWORD *)(v3 + 124) = 0; /*0x138d41*/
    }
  }
  return 0; /*0x138d4d*/
}
