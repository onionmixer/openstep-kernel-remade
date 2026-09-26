/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135254. */
_BOOL4 __cdecl xdr_authkern(XDR *a1)
{
  int v1; // eax
  __int16 *v2; // ecx
  unsigned int v3; // eax
  unsigned int v5; // [esp+8h] [ebp-58h] BYREF
  int v6; // [esp+Ch] [ebp-54h] BYREF
  int v7; // [esp+10h] [ebp-50h] BYREF
  char *v8; // [esp+14h] [ebp-4Ch] BYREF
  unsigned __int32 v9[2]; // [esp+18h] [ebp-48h] BYREF
  char *v10[16]; // [esp+20h] [ebp-40h] BYREF

  v1 = *(_DWORD *)(active_u + 28); /*0x135265*/
  v2 = (__int16 *)(v1 + 10); /*0x135268*/
  v7 = *(__int16 *)(v1 + 2); /*0x13526f*/
  v6 = *(__int16 *)(*(_DWORD *)(active_u + 28) + 4); /*0x135279*/
  v8 = hostname; /*0x13527c*/
  if ( a1->x_op ) /*0x135283*/
    return 0; /*0x135283*/
  v5 = 0; /*0x13528c*/
  do /*0x1352b1*/
  {
    if ( *v2 == -1 ) /*0x13529b*/
      break; /*0x13529b*/
    v3 = v5; /*0x13529d*/
    v10[v5] = (char *)*v2++; /*0x1352a3*/
    v5 = v3 + 1; /*0x1352ab*/
  }
  while ( (int)(v3 + 1) <= 15 ); /*0x1352b1*/
  getthetime(v9); /*0x1352b7*/
  return xdr_u_long(a1, v9) /*0x13531d*/
      && xdr_string(a1, &v8, 0xFFu)
      && xdr_int(a1, &v7)
      && xdr_int(a1, &v6)
      && xdr_array(a1, v10, &v5, 0x10u, 4u, (xdrproc_t)xdr_int);
}
