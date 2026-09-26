/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccd18. */
int __cdecl sub_1CCD18(int a1, char *__s1)
{
  int i; // ebx
  int v5; // [esp+Ch] [ebp-4h]

  do /*0x1ccd6d*/
  {
    if ( *(_DWORD *)(a1 + 24) ) /*0x1ccd24*/
    {
      v5 = *(_DWORD *)(a1 + 24) + 4; /*0x1ccd30*/
      for ( i = 0; **(_DWORD **)(a1 + 24) > i; ++i ) /*0x1ccd33*/
      {
        if ( !strcmp(__s1, *(const char **)(v5 + 12 * i)) ) /*0x1ccd4d*/
          return 12 * i + v5; /*0x1ccd5e*/
      }
    }
    a1 = *(_DWORD *)(a1 + 4); /*0x1ccd68*/
  }
  while ( a1 ); /*0x1ccd6d*/
  return 0; /*0x1ccd74*/
}
