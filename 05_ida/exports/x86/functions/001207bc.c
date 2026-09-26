/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1207bc. */
int __cdecl nullsap_input(int a1, int a2, int a3, _BYTE *a4)
{
  _BYTE *v4; // esi
  char v5; // al
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax

  v4 = (_BYTE *)nb_map(a3); /*0x1207d1*/
  if ( nb_size(a3) > 2u && !*v4 && (a4[1] & 0xC0) == 0x40 ) /*0x1207f8*/
  {
    v5 = v4[2] & 0xEF; /*0x120801*/
    if ( v5 == -81 && (v4[1] & 1) == 0 ) /*0x12080f*/
    {
      v6 = if_ipackets(a1); /*0x120816*/
      if_ipackets_set(a1, v6 + 1); /*0x12081e*/
      bcopy(a4 + 8, a4 + 2, 6u); /*0x120830*/
      a4[2] &= ~0x80u; /*0x120835*/
      if ( (char)a4[8] < 0 ) /*0x120840*/
      {
        a4[15] = (~(a4[15] >> 7) << 7) | a4[15] & 0x7F; /*0x120859*/
        a4[14] &= 0x1Fu; /*0x12085c*/
      }
      sub_120950(v4); /*0x120861*/
      if ( v4[3] == 0x81 && nb_size(a3) > 5u ) /*0x12087e*/
      {
        v4[4] = 1; /*0x120880*/
        v4[5] = 0; /*0x120884*/
      }
      if ( !sub_120968(a2, a3, a4) ) /*0x120891*/
      {
LABEL_19:
        v9 = if_opackets(a1); /*0x12092c*/
        if_opackets_set(a1, v9 + 1); /*0x120935*/
        return 0; /*0x120935*/
      }
LABEL_18:
      v8 = if_oerrors(a1); /*0x12091c*/
      if_oerrors_set(a1, v8 + 1); /*0x120925*/
      return 0; /*0x12093c*/
    }
    if ( v5 == -29 && (v4[1] & 1) == 0 ) /*0x1208b0*/
    {
      v7 = if_ipackets(a1); /*0x1208b7*/
      if_ipackets_set(a1, v7 + 1); /*0x1208bf*/
      bcopy(a4 + 8, a4 + 2, 6u); /*0x1208d1*/
      a4[2] &= ~0x80u; /*0x1208d6*/
      if ( (char)a4[8] < 0 ) /*0x1208e1*/
      {
        a4[15] = (~(a4[15] >> 7) << 7) | a4[15] & 0x7F; /*0x1208fa*/
        a4[14] &= 0x1Fu; /*0x1208fd*/
      }
      sub_120950(v4); /*0x120902*/
      if ( !sub_120968(a2, a3, a4) ) /*0x12091a*/
        goto LABEL_19; /*0x12091a*/
      goto LABEL_18; /*0x12091a*/
    }
  }
  return 47; /*0x120948*/
}
