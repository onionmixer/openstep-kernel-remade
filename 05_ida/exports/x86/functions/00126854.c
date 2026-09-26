/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x126854. */
int ip_slowtimo()
{
  int v0; // eax
  int v1; // edx
  _DWORD *v3; // edi
  int v4; // esi
  _DWORD *v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+Ch] [ebp-8h]
  int v10; // [esp+10h] [ebp-4h]

  v0 = splnet(); /*0x12685d*/
  v10 = v0; /*0x126862*/
  v1 = ipq; /*0x126865*/
  if ( !ipq ) /*0x12686d*/
    return splx(v0); /*0x126870*/
  while ( (int *)v1 != &ipq ) /*0x1268de*/
  {
    --*(_BYTE *)(v1 + 8); /*0x126874*/
    v1 = *(_DWORD *)v1; /*0x126877*/
    if ( !*(_BYTE *)(*(_DWORD *)(v1 + 4) + 8) ) /*0x12687c*/
    {
      ++dword_1EAAD0; /*0x126882*/
      v3 = *(_DWORD **)(v1 + 4); /*0x126888*/
      v4 = v3[3]; /*0x12688b*/
      if ( (_DWORD *)v4 != v3 ) /*0x126890*/
      {
        do /*0x1268b4*/
        {
          v5 = *(_DWORD **)(v4 + 12); /*0x126894*/
          v8 = v1; /*0x126898*/
          ip_deq(v4); /*0x12689b*/
          v6 = v4; /*0x1268a0*/
          LOBYTE(v6) = v4 & 0x80; /*0x1268a2*/
          m_freem(v6); /*0x1268a5*/
          v4 = (int)v5; /*0x1268ad*/
          v1 = v8; /*0x1268af*/
        }
        while ( v5 != v3 ); /*0x1268b4*/
      }
      *(_DWORD *)(*v3 + 4) = v3[1]; /*0x1268bb*/
      *(_DWORD *)v3[1] = *v3; /*0x1268c3*/
      v7 = (int)v3; /*0x1268c5*/
      LOBYTE(v7) = (unsigned __int8)v3 & 0x80; /*0x1268c7*/
      v9 = v1; /*0x1268ca*/
      m_free(v7); /*0x1268cd*/
      v1 = v9; /*0x1268d5*/
    }
  }
  return splx(v10); /*0x1268ec*/
}
