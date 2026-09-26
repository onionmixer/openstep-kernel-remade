/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118964. */
void __cdecl unp_drop(int *a1, __int16 a2)
{
  int v2; // edi
  int *v3; // ebx
  __int16 v4; // ax
  int *v5; // eax
  int *v6; // ebx

  v2 = *a1; /*0x11896d*/
  *(_WORD *)(*a1 + 86) = a2; /*0x118973*/
  v3 = (int *)a1[3]; /*0x118977*/
  if ( v3 ) /*0x11897c*/
  {
    a1[3] = 0; /*0x11897e*/
    v4 = *(_WORD *)*a1; /*0x118987*/
    if ( v4 == 1 ) /*0x11898e*/
    {
      soisdisconnected(*a1); /*0x1189d9*/
      v3[3] = 0; /*0x1189de*/
      soisdisconnected(*v3); /*0x1189e8*/
    }
    else if ( v4 == 2 ) /*0x118994*/
    {
      v5 = (int *)v3[4]; /*0x118996*/
      if ( v5 == a1 ) /*0x11899b*/
      {
        v3[4] = a1[5]; /*0x1189a0*/
      }
      else
      {
        do /*0x1189c0*/
        {
          v6 = v5; /*0x1189a8*/
          if ( !v5 ) /*0x1189ac*/
            panic(aUnpDisconnect); /*0x1189b3*/
          v5 = (int *)v5[5]; /*0x1189bb*/
        }
        while ( v5 != a1 ); /*0x1189c0*/
        v6[5] = a1[5]; /*0x1189c5*/
      }
      a1[5] = 0; /*0x1189c8*/
      *(_BYTE *)(*a1 + 6) &= ~2u; /*0x1189d1*/
    }
  }
  if ( *(_DWORD *)(v2 + 16) ) /*0x1189f0*/
  {
    *(_DWORD *)(v2 + 8) = 0; /*0x1189f6*/
    m_freem(a1[6]); /*0x118a01*/
    kfree((int)a1, 0x24u); /*0x118a09*/
    sofree(v2); /*0x118a0f*/
  }
}
