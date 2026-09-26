/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1626dc. */
int __cdecl sub_1626DC(__int16 a1)
{
  __int16 v1; // dx
  unsigned __int8 *v2; // esi
  int v3; // edi
  int v4; // ebx
  unsigned int v6; // eax
  _WORD *v7; // ebx
  unsigned __int8 *v9; // [esp+Ch] [ebp-3Ch]
  int v10; // [esp+10h] [ebp-38h]
  _BYTE v11[2]; // [esp+18h] [ebp-30h] BYREF
  _WORD v12[3]; // [esp+1Ah] [ebp-2Eh] BYREF
  char v13; // [esp+20h] [ebp-28h]
  __int16 v14; // [esp+22h] [ebp-26h]
  _DWORD v15[2]; // [esp+2Ch] [ebp-1Ch] BYREF
  char v16; // [esp+34h] [ebp-14h]
  char v17; // [esp+35h] [ebp-13h]
  __int16 v18; // [esp+36h] [ebp-12h]
  int v19; // [esp+38h] [ebp-10h]
  int v20; // [esp+3Ch] [ebp-Ch]
  __int16 v21; // [esp+40h] [ebp-8h]
  __int16 v22; // [esp+42h] [ebp-6h]
  __int16 v23; // [esp+44h] [ebp-4h]
  __int16 v24; // [esp+46h] [ebp-2h]

  if ( dword_1E6448 ) /*0x1626f9*/
    kdp_panic(aKdpSend); /*0x162700*/
  dword_1E6440 -= 28; /*0x162710*/
  bcopy((const void *)(dword_1E6440 + 1990228), v15, 0x1Cu); /*0x16271e*/
  v15[1] = 0; /*0x162723*/
  v15[0] = 0; /*0x16272a*/
  v16 = 0; /*0x162731*/
  v17 = 17; /*0x162735*/
  v18 = __ROR2__(dword_1E6444 + 8, 8); /*0x16274c*/
  v19 = adr; /*0x162756*/
  v20 = dword_1F66CC; /*0x16275f*/
  v21 = __ROR2__(1139, 8); /*0x16276b*/
  v22 = a1; /*0x16276f*/
  v23 = v18; /*0x162773*/
  v24 = 0; /*0x162777*/
  bcopy(v15, (void *)(dword_1E6440 + 1990228), 0x1Cu); /*0x16278b*/
  bcopy((const void *)(dword_1E6440 + 1990228), v11, 0x14u); /*0x1627a1*/
  v12[0] = __ROR2__(dword_1E6444 + 28, 8); /*0x1627b7*/
  v1 = ip_id++; /*0x1627c5*/
  v12[1] = __ROR2__(v1, 8); /*0x1627d7*/
  v11[0] = 69; /*0x1627df*/
  v13 = udp_ttl; /*0x1627e8*/
  v14 = 0; /*0x1627eb*/
  v2 = v11; /*0x1627f4*/
  v10 = 0; /*0x1627f7*/
  v3 = 0; /*0x1627fe*/
  v4 = 4; /*0x162800*/
  v9 = (unsigned __int8 *)v12; /*0x16280a*/
  do /*0x162838*/
  {
    v10 += v9[1] + *(v9 - 1); /*0x16281d*/
    v3 += *v9 + *v2; /*0x162828*/
    v9 += 4; /*0x16282d*/
    v2 += 4; /*0x162830*/
  }
  while ( v4-- ); /*0x162838*/
  v6 = ((unsigned int)(v10 + (v3 << 8)) >> 16) + (unsigned __int16)(v10 + ((_WORD)v3 << 8)); /*0x16284c*/
  if ( v6 > 0xFFFF ) /*0x162853*/
    LOWORD(v6) = v6 + 1; /*0x162855*/
  v14 = __ROR2__(~(_WORD)v6, 8); /*0x162866*/
  bcopy(v11, (void *)(dword_1E6440 + 1990228), 0x14u); /*0x162878*/
  dword_1E6444 += 28; /*0x16287d*/
  dword_1E6440 -= 14; /*0x16288d*/
  v7 = (_WORD *)(dword_1E6440 + 1990228); /*0x162893*/
  bcopy(&unk_1F66C4, (void *)(dword_1E6440 + 1990234), 6u); /*0x1628a7*/
  bcopy(&unk_1F66D0, v7, 6u); /*0x1628b7*/
  v7[6] = __ROR2__(2048, 8); /*0x1628c8*/
  dword_1E6444 += 14; /*0x1628d4*/
  return kdp_en_send_pkt(dword_1E6440 + 1990228, dword_1E6444); /*0x1628ed*/
}
