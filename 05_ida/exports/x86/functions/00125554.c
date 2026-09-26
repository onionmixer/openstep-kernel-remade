/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125554. */
void __cdecl icmp_error(void *a1, unsigned int a2, char a3, int a4, _DWORD *a5)
{
  char v5; // dl
  int *v6; // esi
  __int16 v7; // ax
  int v8; // eax
  char *v9; // ebx
  int v10; // edx
  char *v11; // ebx
  int v12; // eax
  size_t v13; // [esp+Ch] [ebp-8h]
  int v14; // [esp+10h] [ebp-4h]

  v14 = 4 * (*(_BYTE *)a1 & 0xF); /*0x125568*/
  if ( a2 != 5 ) /*0x12556f*/
    ++icmpstat; /*0x125571*/
  if ( (*((_WORD *)a1 + 3) & 0x9FFF) == 0 ) /*0x125580*/
  {
    if ( *((_BYTE *)a1 + 9) != 1 /*0x1255b7*/
      || a2 == 5
      || (v5 = *((_BYTE *)a1 + v14)) == 0
      || v5 == 8
      || (unsigned __int8)(v5 - 13) <= 1u
      || (unsigned __int8)(v5 - 15) <= 1u
      || (unsigned __int8)(v5 - 17) <= 1u )
    {
      if ( (_byteswap_ulong(*((_DWORD *)a1 + 4)) & 0xF0000000) != 0xE0000000 && !in_broadcast(*((_DWORD *)a1 + 4)) ) /*0x1255df*/
      {
        v6 = m_get(0, 2); /*0x1255f8*/
        if ( v6 ) /*0x1255ff*/
        {
          v7 = *((_WORD *)a1 + 1); /*0x125605*/
          if ( v7 > 8 ) /*0x12560d*/
            v13 = v14 + 8; /*0x12561e*/
          else
            v13 = v14 + v7; /*0x125613*/
          *((_WORD *)v6 + 4) = v13 + 8; /*0x125629*/
          v8 = 124 - (__int16)(v13 + 8); /*0x125635*/
          v6[1] = v8; /*0x125637*/
          v9 = (char *)v6 + v8; /*0x12563a*/
          if ( a2 > 0x12 ) /*0x125641*/
            panic(aIcmpError); /*0x125648*/
          ++dword_1EAB3C[a2]; /*0x125653*/
          *v9 = a2; /*0x12565d*/
          if ( a2 == 5 ) /*0x125663*/
            *((_DWORD *)v9 + 1) = *a5; /*0x12566a*/
          else
            *((_DWORD *)v9 + 1) = 0; /*0x125670*/
          if ( a2 == 12 ) /*0x12567b*/
          {
            v9[4] = a3; /*0x125680*/
            a3 = 0; /*0x125683*/
          }
          v9[1] = a3; /*0x12568d*/
          bcopy(a1, v9 + 8, v13); /*0x12569c*/
          *((_WORD *)v9 + 5) = __ROR2__(*((_WORD *)v9 + 5) + v14, 8); /*0x1256b0*/
          v10 = *((__int16 *)v6 + 4); /*0x1256b4*/
          if ( (unsigned int)(v10 + v14) > 0x70 ) /*0x1256c0*/
          {
            v14 = 20; /*0x1256c2*/
            if ( (unsigned int)(v10 + 20) > 0x70 ) /*0x1256cf*/
              panic(aIcmpLen); /*0x1256d6*/
          }
          v6[1] -= v14; /*0x1256e1*/
          *((_WORD *)v6 + 4) += v14; /*0x1256e8*/
          v11 = (char *)v6 + v6[1]; /*0x1256ee*/
          bcopy(a1, v11, v14); /*0x1256f7*/
          *((_WORD *)v11 + 1) = *((_WORD *)v6 + 4); /*0x125700*/
          v11[9] = 1; /*0x125704*/
          icmp_reflect(v11, a4); /*0x12570d*/
        }
      }
    }
    else
    {
      ++dword_1EAB38; /*0x1255b9*/
    }
  }
  v12 = (int)a1; /*0x125715*/
  LOBYTE(v12) = (unsigned __int8)a1 & 0x80; /*0x125718*/
  m_freem(v12); /*0x12571b*/
}
