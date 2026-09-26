/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169208. */
void __cdecl calloutDispatch(int a1, int a2)
{
  int v2; // ebx
  int *v3; // eax

  if ( dword_1DFCBC ) /*0x169213*/
  {
    v2 = splsched(); /*0x16921e*/
    do /*0x169239*/
    {
      while ( dword_1E7244 ) /*0x169227*/
        ; /*0x169225*/
    }
    while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169239*/
    if ( (int *)dword_1E7248 == &dword_1E7248 ) /*0x169245*/
      panic(aInternalentrya); /*0x16924c*/
    v3 = (int *)dword_1E7248; /*0x169264*/
    *(_DWORD *)(*(_DWORD *)dword_1E7248 + 4) = &dword_1E7248; /*0x16926b*/
    dword_1E7248 = *v3; /*0x169274*/
    v3[2] = a1; /*0x16927f*/
    v3[3] = a2; /*0x169285*/
    v3[4] = 0; /*0x169288*/
    v3[5] = 0; /*0x16928f*/
    v3[6] = 0; /*0x169296*/
    *v3 = (int)&dword_1E7250; /*0x16929d*/
    v3[1] = dword_1E7254; /*0x1692a9*/
    *(_DWORD *)v3[1] = v3; /*0x1692af*/
    dword_1E7254 = (int)v3; /*0x1692b1*/
    ++dword_1E7260; /*0x1692b7*/
    v3[7] = 1; /*0x1692bd*/
    sub_169C64(); /*0x1692c4*/
    splx(v2); /*0x1692ca*/
  }
}
