/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169944. */
int __cdecl calloutEntryDispatchDelayed(int *a1, int a2, int a3)
{
  int *i; // ecx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // kr08_8
  unsigned __int64 v6; // kr00_8
  unsigned __int64 v8; // [esp+Ch] [ebp-14h]
  int v9; // [esp+1Ch] [ebp-4h]

  v9 = splsched(); /*0x169955*/
  do /*0x169972*/
  {
    while ( dword_1E7244 ) /*0x169960*/
      ; /*0x16995e*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169972*/
  if ( !a1[7] ) /*0x169974*/
  {
    a1[3] = a1[4]; /*0x169981*/
    a1[5] = a2; /*0x16998a*/
    a1[6] = a3; /*0x16998d*/
    for ( i = (int *)dword_1E7258; i != &dword_1E7258 && *(_QWORD *)(i + 5) <= *(_QWORD *)(a1 + 5); i = (int *)*i ) /*0x169990*/
    {
      if ( a1[5] == i[5] && a1[6] == i[6] ) /*0x1699ca*/
        goto LABEL_12; /*0x1699ca*/
    }
    i = (int *)i[1]; /*0x1699b4*/
LABEL_12:
    *a1 = *i; /*0x1699d0*/
    a1[1] = (int)i; /*0x1699d4*/
    *(_DWORD *)(*i + 4) = a1; /*0x1699d9*/
    *i = (int)a1; /*0x1699dc*/
    a1[7] = 2; /*0x1699de*/
    if ( (int *)dword_1E7258 == a1 ) /*0x1699eb*/
    {
      v4 = clock_value(1); /*0x1699ef*/
      if ( *(_QWORD *)(a1 + 5) >= v4 ) /*0x169a07*/
      {
        v6 = v4; /*0x169a1d*/
        v8 = *(_QWORD *)timer_attributes(0); /*0x169a27*/
        v5 = *(_QWORD *)(a1 + 5) - v6; /*0x169a40*/
        if ( v8 < v5 ) /*0x169a51*/
          v5 = v8; /*0x169a56*/
      }
      else
      {
        v5 = 0; /*0x169a13*/
      }
      set_timer(0, v5, HIDWORD(v5)); /*0x169a5d*/
    }
  }
  _InterlockedExchange(&dword_1E7244, 0); /*0x169a67*/
  return splx(v9); /*0x169a79*/
}
