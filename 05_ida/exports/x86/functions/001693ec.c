/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1693ec. */
void __cdecl calloutDispatchDelayed(int a1, int a2, int a3, int a4)
{
  int *v4; // edx
  int *v5; // edi
  int *i; // ecx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // kr08_8
  unsigned __int64 v9; // kr00_8
  unsigned __int64 v10; // [esp+Ch] [ebp-14h]
  int v11; // [esp+1Ch] [ebp-4h]

  if ( dword_1DFCBC ) /*0x1693fc*/
  {
    v11 = splsched(); /*0x169407*/
    do /*0x169426*/
    {
      while ( dword_1E7244 ) /*0x169414*/
        ; /*0x169412*/
    }
    while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169426*/
    if ( (int *)dword_1E7248 == &dword_1E7248 ) /*0x169432*/
      panic(aInternalentrya); /*0x169439*/
    v4 = (int *)dword_1E7248; /*0x169454*/
    *(_DWORD *)(*(_DWORD *)dword_1E7248 + 4) = &dword_1E7248; /*0x16945c*/
    dword_1E7248 = *v4; /*0x169465*/
    v5 = v4; /*0x16946b*/
    v4[2] = a1; /*0x169470*/
    v4[3] = a2; /*0x169476*/
    v4[4] = 0; /*0x169479*/
    v4[5] = a3; /*0x169486*/
    v4[6] = a4; /*0x169489*/
    for ( i = (int *)dword_1E7258; i != &dword_1E7258 && *(_QWORD *)(i + 5) <= *(_QWORD *)(v4 + 5); i = (int *)*i ) /*0x16948c*/
    {
      if ( v4[5] == i[5] && v4[6] == i[6] ) /*0x1694c6*/
        goto LABEL_14; /*0x1694c6*/
    }
    i = (int *)i[1]; /*0x1694b0*/
LABEL_14:
    *v4 = *i; /*0x1694cc*/
    v4[1] = (int)i; /*0x1694d0*/
    *(_DWORD *)(*i + 4) = v4; /*0x1694d5*/
    *i = (int)v4; /*0x1694d8*/
    v4[7] = 2; /*0x1694da*/
    if ( (int *)dword_1E7258 == v4 ) /*0x1694e7*/
    {
      v7 = clock_value(1); /*0x1694eb*/
      if ( *(_QWORD *)(v5 + 5) >= v7 ) /*0x169503*/
      {
        v9 = v7; /*0x169519*/
        v10 = *(_QWORD *)timer_attributes(0); /*0x169523*/
        v8 = *(_QWORD *)(v5 + 5) - v9; /*0x16953c*/
        if ( v10 < v8 ) /*0x16954d*/
          v8 = v10; /*0x169552*/
      }
      else
      {
        v8 = 0; /*0x16950f*/
      }
      set_timer(0, v8, HIDWORD(v8)); /*0x169559*/
    }
    _InterlockedExchange(&dword_1E7244, 0); /*0x169563*/
    splx(v11); /*0x16956d*/
  }
}
