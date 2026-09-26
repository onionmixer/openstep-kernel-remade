/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13477c. */
int __cdecl xdr_getrddirres(XDR *a1, int *a2)
{
  int v3; // esi
  int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // eax
  __int16 v7; // ax
  int v8; // eax
  unsigned __int32 v9; // [esp+10h] [ebp-8h] BYREF
  int v10; // [esp+14h] [ebp-4h] BYREF

  v9 = -1; /*0x134788*/
  if ( xdr_enum(a1, a2 + 1) ) /*0x134797*/
  {
    if ( a2[1] ) /*0x1347aa*/
      return 1; /*0x1347b5*/
    v3 = a2[3]; /*0x1347bf*/
    v4 = a2[5]; /*0x1347c2*/
    while ( xdr_bool(a1, &v10) ) /*0x1347d7*/
    {
      if ( !v10 ) /*0x1347e1*/
      {
        if ( !xdr_bool(a1, a2 + 4) ) /*0x134883*/
          return 0; /*0x134883*/
        a2[3] = v4 - a2[5]; /*0x13488b*/
        a2[2] = v9; /*0x134891*/
        return 1; /*0x134899*/
      }
      if ( v3 <= 5 ) /*0x1347ea*/
        return 0; /*0x1347ea*/
      if ( !xdr_u_long(a1, (unsigned __int32 *)v4) ) /*0x1347f2*/
        return 0; /*0x1347f2*/
      if ( !xdr_u_short(a1, (unsigned __int16 *)(v4 + 6)) ) /*0x134807*/
        return 0; /*0x134807*/
      v5 = *(unsigned __int16 *)(v4 + 6); /*0x134817*/
      v6 = v5 + 12; /*0x134820*/
      LOBYTE(v6) = (v5 + 12) & 0xFC; /*0x134823*/
      if ( v6 > v3 ) /*0x134827*/
        return 0; /*0x134827*/
      if ( !xdr_opaque(a1, (char *)(v4 + 8), v5) ) /*0x13482f*/
        return 0; /*0x13482f*/
      if ( !xdr_u_long(a1, &v9) ) /*0x134840*/
        return 0; /*0x134840*/
      v7 = *(_WORD *)(v4 + 6) + 12; /*0x134850*/
      LOBYTE(v7) = v7 & 0xFC; /*0x134854*/
      *(_WORD *)(v4 + 4) = v7; /*0x134856*/
      *(_BYTE *)(*(unsigned __int16 *)(v4 + 6) + v4 + 8) = 0; /*0x13485e*/
      v8 = *(unsigned __int16 *)(v4 + 4); /*0x134863*/
      v3 -= v8; /*0x134867*/
      if ( v3 < 0 ) /*0x134869*/
        return 0; /*0x134869*/
      v4 += v8; /*0x13486b*/
    }
  }
  return 0; /*0x1348a1*/
}
