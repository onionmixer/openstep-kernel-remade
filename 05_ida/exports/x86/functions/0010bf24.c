/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10bf24. */
int __cdecl logselect(int a1, int a2)
{
  int v2; // esi

  v2 = splhigh(); /*0x10bf31*/
  if ( a2 == 1 ) /*0x10bf36*/
  {
    if ( *(_DWORD *)(pmsgbuf + 8) != *(_DWORD *)(pmsgbuf + 4) ) /*0x10bf44*/
    {
      splx(v2); /*0x10bf47*/
      return 1; /*0x10bf51*/
    }
    selthreadcache(&dword_1E97C4); /*0x10bf59*/
  }
  splx(v2); /*0x10bf62*/
  return 0; /*0x10bf6c*/
}
