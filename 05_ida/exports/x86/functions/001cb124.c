/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cb124. */
void __cdecl sub_1CB124(void (__stdcall *a1)(int), int a2, _DWORD *a3, int a4)
{
  int v4; // ebx
  _DWORD *i; // esi

  v4 = a2; /*0x1cb12d*/
  if ( a2 == 1 ) /*0x1cb133*/
  {
    a1(a4); /*0x1cb13d*/
  }
  else
  {
    for ( i = a3; --v4 != -1; ++i ) /*0x1cb144*/
      ((void (__cdecl *)(int, _DWORD))a1)(a4, *i); /*0x1cb153*/
    free(a3); /*0x1cb165*/
  }
}
