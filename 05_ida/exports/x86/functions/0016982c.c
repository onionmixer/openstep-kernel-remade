/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16982c. */
int __cdecl calloutEntryDispatch(_DWORD *a1)
{
  int v1; // esi

  v1 = splsched(); /*0x169839*/
  do /*0x169855*/
  {
    while ( dword_1E7244 ) /*0x169843*/
      ; /*0x169841*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169855*/
  if ( a1[7] ) /*0x169857*/
  {
    _InterlockedExchange(&dword_1E7244, 0); /*0x1698a2*/
  }
  else
  {
    a1[3] = a1[4]; /*0x169860*/
    a1[5] = 0; /*0x169863*/
    a1[6] = 0; /*0x16986a*/
    *a1 = &dword_1E7250; /*0x169871*/
    a1[1] = dword_1E7254; /*0x16987d*/
    *(_DWORD *)a1[1] = a1; /*0x169883*/
    dword_1E7254 = (int)a1; /*0x169885*/
    ++dword_1E7260; /*0x16988b*/
    a1[7] = 1; /*0x169891*/
    sub_169C64(); /*0x169898*/
  }
  return splx(v1); /*0x1698b1*/
}
