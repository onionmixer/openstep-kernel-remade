/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1283b8. */
int __cdecl rip_ctloutput(int a1, int a2, int a3, int a4, int *a5)
{
  int v5; // esi
  int v6; // ebx
  int v8; // eax
  int *v9; // eax
  int v10; // edx

  v5 = 0; /*0x1283c7*/
  v6 = *(_DWORD *)(a2 + 8); /*0x1283c9*/
  if ( a3 ) /*0x1283d0*/
    goto LABEL_20; /*0x1283d0*/
  if ( !a1 ) /*0x1283da*/
  {
    if ( a4 == 1 ) /*0x12842b*/
    {
      v9 = m_get(1, 10); /*0x128440*/
      *a5 = (int)v9; /*0x128445*/
      v10 = *(_DWORD *)(v6 + 52); /*0x12844a*/
      if ( v10 ) /*0x12844f*/
      {
        v9[1] = *(_DWORD *)(v10 + 4); /*0x128454*/
        *(_WORD *)(*a5 + 8) = *(_WORD *)(*(_DWORD *)(v6 + 52) + 8); /*0x128460*/
        bcopy( /*0x128476*/
          (const void *)(*(_DWORD *)(*(_DWORD *)(v6 + 52) + 4) + *(_DWORD *)(v6 + 52)),
          (void *)(*(_DWORD *)(*a5 + 4) + *a5),
          *(__int16 *)(*a5 + 8));
      }
      else
      {
        *((_WORD *)v9 + 4) = 0; /*0x128480*/
      }
LABEL_21:
      if ( a1 == 1 ) /*0x1284a5*/
      {
        if ( *a5 ) /*0x1284a7*/
          m_free(*a5); /*0x1284ae*/
      }
      return v5; /*0x1284ae*/
    }
    if ( a4 >= 1 && a4 <= 7 && a4 >= 3 ) /*0x128437*/
    {
      v8 = ip_getmoptions(a4, *(_DWORD *)(v6 + 80), (int **)a5); /*0x12848e*/
LABEL_19:
      v5 = v8; /*0x128493*/
      goto LABEL_21; /*0x128498*/
    }
LABEL_20:
    v5 = 22; /*0x12849c*/
    goto LABEL_21; /*0x12849c*/
  }
  if ( a1 == 1 ) /*0x1283e0*/
  {
    if ( a4 == 1 ) /*0x1283e9*/
      return ip_pcbopts((int *)(v6 + 52), *a5); /*0x1283f7*/
    if ( a4 < 1 || a4 > 7 || a4 < 3 ) /*0x128409*/
      v8 = ip_mrouter_cmd(a4, a2, *a5); /*0x128421*/
    else
      v8 = ip_setmoptions(a4, (int *)(v6 + 80), *a5); /*0x128413*/
    goto LABEL_19; /*0x128418*/
  }
  return v5; /*0x1284b8*/
}
