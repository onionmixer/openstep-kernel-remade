/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169a80. */
int __cdecl calloutEntryDispatchWithArgumentDelayed(int *a1, int a2, int a3, int a4)
{
  int *i; // ecx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // kr08_8
  unsigned __int64 v7; // kr00_8
  unsigned __int64 v9; // [esp+Ch] [ebp-14h]
  int v10; // [esp+1Ch] [ebp-4h]

  v10 = splsched(); /*0x169a91*/
  do /*0x169aae*/
  {
    while ( dword_1E7244 ) /*0x169a9c*/
      ; /*0x169a9a*/
  }
  while ( _InterlockedExchange(&dword_1E7244, 1) == 1 ); /*0x169aae*/
  if ( !a1[7] ) /*0x169ab0*/
  {
    a1[3] = a2; /*0x169abd*/
    a1[5] = a3; /*0x169ac6*/
    a1[6] = a4; /*0x169ac9*/
    for ( i = (int *)dword_1E7258; i != &dword_1E7258 && *(_QWORD *)(i + 5) <= *(_QWORD *)(a1 + 5); i = (int *)*i ) /*0x169acc*/
    {
      if ( a1[5] == i[5] && a1[6] == i[6] ) /*0x169b06*/
        goto LABEL_12; /*0x169b06*/
    }
    i = (int *)i[1]; /*0x169af0*/
LABEL_12:
    *a1 = *i; /*0x169b0c*/
    a1[1] = (int)i; /*0x169b10*/
    *(_DWORD *)(*i + 4) = a1; /*0x169b15*/
    *i = (int)a1; /*0x169b18*/
    a1[7] = 2; /*0x169b1a*/
    if ( (int *)dword_1E7258 == a1 ) /*0x169b27*/
    {
      v5 = clock_value(1); /*0x169b2b*/
      if ( *(_QWORD *)(a1 + 5) >= v5 ) /*0x169b43*/
      {
        v7 = v5; /*0x169b59*/
        v9 = *(_QWORD *)timer_attributes(0); /*0x169b63*/
        v6 = *(_QWORD *)(a1 + 5) - v7; /*0x169b7c*/
        if ( v9 < v6 ) /*0x169b8d*/
          v6 = v9; /*0x169b92*/
      }
      else
      {
        v6 = 0; /*0x169b4f*/
      }
      set_timer(0, v6, HIDWORD(v6)); /*0x169b99*/
    }
  }
  _InterlockedExchange(&dword_1E7244, 0); /*0x169ba3*/
  return splx(v10); /*0x169bb5*/
}
