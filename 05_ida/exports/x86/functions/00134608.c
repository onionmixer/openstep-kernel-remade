/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134608. */
int __cdecl xdr_putrddirres(XDR *a1, _DWORD *a2)
{
  int v3; // ebx
  unsigned int v4; // edx
  int v5; // eax
  int v6; // [esp+Ch] [ebp-1Ch]
  unsigned int v7; // [esp+10h] [ebp-18h]
  int v8; // [esp+14h] [ebp-14h] BYREF
  unsigned __int32 v9; // [esp+18h] [ebp-10h] BYREF
  unsigned int v10; // [esp+1Ch] [ebp-Ch] BYREF
  char *v11; // [esp+20h] [ebp-8h] BYREF
  int v12; // [esp+24h] [ebp-4h] BYREF

  v12 = 1; /*0x134614*/
  v8 = 0; /*0x13461b*/
  if ( a1->x_op == XDR_ENCODE && xdr_enum(a1, a2 + 1) ) /*0x134633*/
  {
    if ( a2[1] ) /*0x134646*/
      return 1; /*0x134651*/
    v7 = a1->x_ops->x_getpostn(a1); /*0x134671*/
    v9 = a2[2]; /*0x13467a*/
    v6 = a2[3]; /*0x134683*/
    v3 = a2[5]; /*0x134689*/
    if ( v6 <= 0 ) /*0x134691*/
    {
LABEL_16:
      if ( xdr_bool(a1, &v8) && xdr_bool(a1, a2 + 4) ) /*0x134763*/
        return 1; /*0x13476a*/
    }
    else
    {
      while ( *(_WORD *)(v3 + 4) ) /*0x134698*/
      {
        v4 = *(unsigned __int16 *)(v3 + 4); /*0x1346ac*/
        if ( (unsigned int)*(unsigned __int16 *)(v3 + 6) + 9 > v4 ) /*0x1346b4*/
          break; /*0x1346b4*/
        v9 += v4; /*0x1346ba*/
        if ( *(_DWORD *)v3 ) /*0x1346bd*/
        {
          v11 = (char *)(v3 + 8); /*0x1346c5*/
          v10 = *(unsigned __int16 *)(v3 + 6); /*0x1346cc*/
          if ( !xdr_bool(a1, &v12) /*0x134711*/
            || !xdr_u_long(a1, (unsigned __int32 *)v3)
            || !xdr_bytes(a1, &v11, &v10, 0xFFu)
            || !xdr_u_long(a1, &v9) )
          {
            return 0; /*0x13471b*/
          }
          if ( *a2 <= a1->x_ops->x_getpostn(a1) - v7 ) /*0x134731*/
          {
            a2[4] = 0; /*0x13465b*/
            goto LABEL_16; /*0x134662*/
          }
        }
        v5 = *(unsigned __int16 *)(v3 + 4); /*0x134737*/
        v6 -= v5; /*0x13473b*/
        v3 += v5; /*0x13473e*/
        if ( v6 <= 0 ) /*0x134744*/
          goto LABEL_16; /*0x134744*/
      }
    }
  }
  return 0; /*0x134775*/
}
