/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1698b8. */
int __cdecl calloutEntryDispatchWithArgument(_DWORD *a1, int a2)
{
  int v2; // esi

  v2 = splsched(); /*0x1698c5*/
  do /*0x1698e1*/
  {
    while ( dword_1E7244 ) /*0x1698cf*/
      ; /*0x1698cd*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x1698e1*/
  if ( a1[7] ) /*0x1698e3*/
  {
    _InterlockedExchange(&dword_1E7244, 0); /*0x16992e*/
  }
  else
  {
    a1[3] = a2; /*0x1698ec*/
    a1[5] = 0; /*0x1698ef*/
    a1[6] = 0; /*0x1698f6*/
    *a1 = &dword_1E7250; /*0x1698fd*/
    a1[1] = dword_1E7254; /*0x169909*/
    *(_DWORD *)a1[1] = a1; /*0x16990f*/
    dword_1E7254 = (int)a1; /*0x169911*/
    ++dword_1E7260; /*0x169917*/
    a1[7] = 1; /*0x16991d*/
    sub_169C64(); /*0x169924*/
  }
  return splx(v2); /*0x16993d*/
}
