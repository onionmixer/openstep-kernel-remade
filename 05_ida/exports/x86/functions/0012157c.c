/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12157c. */
void __cdecl raw_input(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int *v4; // eax
  int v5; // ebx
  _DWORD *v6; // eax
  int v7; // esi

  v4 = m_get(0, 2); /*0x12158c*/
  v5 = (int)v4; /*0x121591*/
  if ( v4 ) /*0x121598*/
  {
    *v4 = a1; /*0x1215ab*/
    *((_WORD *)v4 + 4) = 36; /*0x1215ad*/
    v6 = (int *)((char *)v4 + v4[1]); /*0x1215b5*/
    v6[1] = *a4; /*0x1215ba*/
    v6[2] = a4[1]; /*0x1215c0*/
    v6[3] = a4[2]; /*0x1215c6*/
    v6[4] = a4[3]; /*0x1215cc*/
    v6[5] = *a3; /*0x1215d1*/
    v6[6] = a3[1]; /*0x1215d7*/
    v6[7] = a3[2]; /*0x1215dd*/
    v6[8] = a3[3]; /*0x1215e3*/
    *v6 = *a2; /*0x1215eb*/
    v7 = splimp(); /*0x1215f2*/
    if ( dword_1E8A78 < dword_1E8A7C ) /*0x1215ff*/
    {
      *(_DWORD *)(v5 + 124) = 0; /*0x12160c*/
      if ( dword_1E8A74 ) /*0x12161a*/
        *(_DWORD *)(dword_1E8A74 + 124) = v5; /*0x121624*/
      else
        rawintrq = v5; /*0x12161c*/
      dword_1E8A74 = v5; /*0x121627*/
      ++dword_1E8A78; /*0x12162d*/
    }
    else
    {
      m_freem(v5); /*0x121602*/
    }
    splx(v7); /*0x121634*/
    LOBYTE(netisr) = netisr | 1; /*0x121639*/
    wakeup((int)&soft_net_wakeup); /*0x121645*/
  }
  else
  {
    m_freem(a1); /*0x12159e*/
  }
}
