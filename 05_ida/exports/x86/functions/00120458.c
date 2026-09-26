/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x120458. */
int __cdecl sub_120458(int a1, int a2)
{
  _BYTE *v2; // esi
  char *v3; // edi
  int v4; // ecx
  bool v5; // zf
  int result; // eax
  int v7; // edi
  int v8; // ebx
  int v9; // eax
  __int16 v10; // bx
  int v11; // eax
  int v12; // esi
  _BYTE *v13; // eax
  int v14; // ebx
  _DWORD *v15; // eax
  int v16; // eax
  char v17; // bl
  int v18; // eax
  const char *v19; // [esp+10h] [ebp-4h]

  v2 = (_BYTE *)if_type(a2); /*0x120470*/
  v3 = a416mbTokenRing_0; /*0x120472*/
  v4 = 18; /*0x120477*/
  result = 0; /*0x12047d*/
  v5 = 1; /*0x12047d*/
  do /*0x12047f*/
  {
    if ( !v4 ) /*0x12047f*/
      break; /*0x12047f*/
    v5 = *v2++ == (unsigned __int8)*v3++; /*0x12047f*/
    --v4; /*0x12047f*/
  }
  while ( v5 ); /*0x12047f*/
  if ( !v5 ) /*0x120481*/
    result = (unsigned __int8)*(v2 - 1) - (unsigned __int8)*(v3 - 1); /*0x12048b*/
  if ( !result ) /*0x120492*/
  {
    result = if_unit(a2); /*0x12049c*/
    v7 = result; /*0x1204a1*/
    if ( *(_DWORD *)a1 == result ) /*0x1204ab*/
    {
      v19 = (const char *)if_name(a2); /*0x1204ba*/
      v8 = if_mtu(a2) - 8; /*0x1204c6*/
      v9 = *(_DWORD *)(a1 + 8); /*0x1204cf*/
      if ( !v9 ) /*0x1204d4*/
        v9 = dword_1DB8A4; /*0x1204d6*/
      if ( v9 > v8 ) /*0x1204dd*/
        LOWORD(v9) = v8; /*0x1204df*/
      v10 = v9; /*0x1204e1*/
      v11 = kalloc(0x20u); /*0x1204e5*/
      LOBYTE(v11) = v11 & 0xFC; /*0x1204ea*/
      v12 = if_attach( /*0x12051a*/
              0,
              sub_11FDDC,
              sub_11FBDC,
              sub_12075C,
              sub_120648,
              v19,
              v7,
              "Internet Protocol",
              v10,
              2,
              4096,
              v11);
      *(_DWORD *)if_private(v12) = 0; /*0x120528*/
      if ( (*(_BYTE *)(a1 + 4) & 1) != 0 ) /*0x120535*/
      {
        v13 = (_BYTE *)if_private(v12); /*0x120538*/
        *v13 |= 1u; /*0x120540*/
        v14 = if_private(v12); /*0x120549*/
        *(_DWORD *)(v14 + 4) = NXCreateHashTable(SRTablePrototype, 0, nullptr); /*0x120573*/
      }
      else
      {
        v15 = (_DWORD *)if_private(v12); /*0x12057d*/
        *v15 &= ~1u; /*0x120585*/
      }
      v16 = *(_DWORD *)(a1 + 12); /*0x12058b*/
      if ( v16 <= 7 ) /*0x120591*/
      {
        v17 = *(_DWORD *)(a1 + 12); /*0x1205a4*/
        if ( (unsigned __int8)v16 > 6u ) /*0x1205a9*/
          v17 = 6; /*0x1205ab*/
        *(_BYTE *)(if_private(v12) + 24) = (32 * v17) | 0x10; /*0x1205bf*/
      }
      else
      {
        *(_BYTE *)(if_private(v12) + 24) = 16; /*0x12059c*/
      }
      *(_DWORD *)(if_private(v12) + 20) = a2; /*0x1205ce*/
      v18 = if_private(v12); /*0x1205d2*/
      if_control(a2, "getaddr", v18 + 8); /*0x1205e7*/
      printf("IP protocol enabled for interface %s%d\n", v19, v7); /*0x1205f6*/
      return printf("IEEE 802.2 Null Sap protocol enabled for interface %s%d\n", v19, v7); /*0x120605*/
    }
  }
  return result; /*0x12060d*/
}
