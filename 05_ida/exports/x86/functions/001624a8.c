/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1624a8. */
int __cdecl sub_1624A8(__int16 a1)
{
  int v1; // eax
  __int16 v2; // dx
  unsigned __int8 *v3; // esi
  int v4; // edi
  int v5; // ebx
  unsigned int v7; // eax
  _WORD *v8; // ebx
  void *v9; // esi
  int result; // eax
  unsigned __int8 *v11; // [esp+Ch] [ebp-44h]
  int v12; // [esp+10h] [ebp-40h]
  _BYTE v13[8]; // [esp+18h] [ebp-38h] BYREF
  _BYTE v14[2]; // [esp+20h] [ebp-30h] BYREF
  _WORD v15[3]; // [esp+22h] [ebp-2Eh] BYREF
  char v16; // [esp+28h] [ebp-28h]
  __int16 v17; // [esp+2Ah] [ebp-26h]
  _DWORD v18[2]; // [esp+34h] [ebp-1Ch] BYREF
  char v19; // [esp+3Ch] [ebp-14h]
  char v20; // [esp+3Dh] [ebp-13h]
  __int16 v21; // [esp+3Eh] [ebp-12h]
  int v22; // [esp+40h] [ebp-10h]
  int v23; // [esp+44h] [ebp-Ch]
  __int16 v24; // [esp+48h] [ebp-8h]
  __int16 v25; // [esp+4Ah] [ebp-6h]
  __int16 v26; // [esp+4Ch] [ebp-4h]
  __int16 v27; // [esp+4Eh] [ebp-2h]

  if ( !dword_1E6448 ) /*0x1624c5*/
    kdp_panic(aKdpReply); /*0x1624cc*/
  dword_1E6440 -= 28; /*0x1624dc*/
  bcopy((const void *)(dword_1E6440 + 1990228), v18, 0x1Cu); /*0x1624ea*/
  v18[1] = 0; /*0x1624ef*/
  v18[0] = 0; /*0x1624f6*/
  v19 = 0; /*0x1624fd*/
  v20 = 17; /*0x162501*/
  v21 = __ROR2__(dword_1E6444 + 8, 8); /*0x162518*/
  v1 = v22; /*0x16251c*/
  v22 = v23; /*0x162522*/
  v23 = v1; /*0x162525*/
  v24 = __ROR2__(1139, 8); /*0x162531*/
  v25 = a1; /*0x162535*/
  v26 = v21; /*0x162539*/
  v27 = 0; /*0x16253d*/
  bcopy(v18, (void *)(dword_1E6440 + 1990228), 0x1Cu); /*0x162551*/
  bcopy((const void *)(dword_1E6440 + 1990228), v14, 0x14u); /*0x162567*/
  v15[0] = __ROR2__(dword_1E6444 + 28, 8); /*0x16257d*/
  v2 = ip_id++; /*0x16258b*/
  v15[1] = __ROR2__(v2, 8); /*0x16259d*/
  v14[0] = 69; /*0x1625a5*/
  v16 = udp_ttl; /*0x1625ae*/
  v17 = 0; /*0x1625b1*/
  v3 = v14; /*0x1625ba*/
  v12 = 0; /*0x1625bd*/
  v4 = 0; /*0x1625c4*/
  v5 = 4; /*0x1625c6*/
  v11 = (unsigned __int8 *)v15; /*0x1625d0*/
  do /*0x1625fc*/
  {
    v12 += v11[1] + *(v11 - 1); /*0x1625e1*/
    v4 += *v11 + *v3; /*0x1625ec*/
    v11 += 4; /*0x1625f1*/
    v3 += 4; /*0x1625f4*/
  }
  while ( v5-- ); /*0x1625fc*/
  v7 = ((unsigned int)(v12 + (v4 << 8)) >> 16) + (unsigned __int16)(v12 + ((_WORD)v4 << 8)); /*0x162610*/
  if ( v7 > 0xFFFF ) /*0x162617*/
    LOWORD(v7) = v7 + 1; /*0x162619*/
  v17 = __ROR2__(~(_WORD)v7, 8); /*0x16262a*/
  bcopy(v14, (void *)(dword_1E6440 + 1990228), 0x14u); /*0x16263c*/
  dword_1E6444 += 28; /*0x162641*/
  dword_1E6440 -= 14; /*0x162651*/
  v8 = (_WORD *)(dword_1E6440 + 1990228); /*0x162657*/
  v9 = (void *)(dword_1E6440 + 1990234); /*0x16265d*/
  bcopy((const void *)(dword_1E6440 + 1990234), v13, 6u); /*0x16266a*/
  bcopy(v8, v9, 6u); /*0x162676*/
  bcopy(v13, v8, 6u); /*0x162682*/
  v8[6] = __ROR2__(2048, 8); /*0x162693*/
  dword_1E6444 += 14; /*0x162697*/
  bcopy(&unk_1E5E54, &unk_1E644C, 0x5F8u); /*0x1626ad*/
  result = kdp_en_send_pkt(dword_1E6440 + 1990228, dword_1E6444); /*0x1626c4*/
  ++byte_1E5E50; /*0x1626c9*/
  return result; /*0x1626d2*/
}
