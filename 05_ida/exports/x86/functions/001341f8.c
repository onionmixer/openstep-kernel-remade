/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1341f8. */
_BOOL4 __cdecl sub_1341F8(XDR *a1, int *a2)
{
  int32_t *v2; // edx
  _DWORD *v3; // edx
  unsigned int *v5; // eax

  if ( a1->x_op ) /*0x134203*/
  {
    v5 = (unsigned int *)a1->x_ops->x_inline(a1, 68); /*0x1342dd*/
    if ( v5 ) /*0x1342e6*/
    {
      *a2 = _byteswap_ulong(*v5); /*0x1342f3*/
      a2[1] = _byteswap_ulong(v5[1]); /*0x1342fc*/
      a2[2] = _byteswap_ulong(v5[2]); /*0x134306*/
      a2[3] = _byteswap_ulong(v5[3]); /*0x134310*/
      a2[4] = _byteswap_ulong(v5[4]); /*0x13431a*/
      a2[5] = _byteswap_ulong(v5[5]); /*0x134324*/
      a2[6] = _byteswap_ulong(v5[6]); /*0x13432e*/
      a2[7] = _byteswap_ulong(v5[7]); /*0x134338*/
      a2[8] = _byteswap_ulong(v5[8]); /*0x134342*/
      a2[9] = _byteswap_ulong(v5[9]); /*0x13434c*/
      a2[10] = _byteswap_ulong(v5[10]); /*0x134356*/
      a2[11] = _byteswap_ulong(v5[11]); /*0x134360*/
      a2[12] = _byteswap_ulong(v5[12]); /*0x13436a*/
      a2[13] = _byteswap_ulong(v5[13]); /*0x134374*/
      a2[14] = _byteswap_ulong(v5[14]); /*0x13437e*/
      a2[15] = _byteswap_ulong(v5[15]); /*0x134388*/
      a2[16] = _byteswap_ulong(v5[16]); /*0x13438f*/
      return 1; /*0x134397*/
    }
  }
  else
  {
    v2 = a1->x_ops->x_inline(a1, 68); /*0x134217*/
    if ( v2 ) /*0x13421e*/
    {
      *v2 = _byteswap_ulong(*a2); /*0x134228*/
      v3 = v2 + 1; /*0x13422a*/
      *v3++ = _byteswap_ulong(a2[1]); /*0x134232*/
      *v3++ = _byteswap_ulong(a2[2]); /*0x13423c*/
      *v3++ = _byteswap_ulong(a2[3]); /*0x134246*/
      *v3++ = _byteswap_ulong(a2[4]); /*0x134250*/
      *v3++ = _byteswap_ulong(a2[5]); /*0x13425a*/
      *v3++ = _byteswap_ulong(a2[6]); /*0x134264*/
      *v3++ = _byteswap_ulong(a2[7]); /*0x13426e*/
      *v3++ = _byteswap_ulong(a2[8]); /*0x134278*/
      *v3++ = _byteswap_ulong(a2[9]); /*0x134282*/
      *v3++ = _byteswap_ulong(a2[10]); /*0x13428c*/
      *v3++ = _byteswap_ulong(a2[11]); /*0x134296*/
      *v3++ = _byteswap_ulong(a2[12]); /*0x1342a0*/
      *v3++ = _byteswap_ulong(a2[13]); /*0x1342aa*/
      *v3++ = _byteswap_ulong(a2[14]); /*0x1342b4*/
      *v3 = _byteswap_ulong(a2[15]); /*0x1342be*/
      v3[1] = _byteswap_ulong(a2[16]); /*0x1342c8*/
      return 1; /*0x1342cf*/
    }
  }
  return xdr_enum(a1, a2) /*0x1344a9*/
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 1)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 2)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 3)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 4)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 5)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 6)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 7)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 8)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 9)
      && xdr_u_long(a1, (unsigned __int32 *)a2 + 10)
      && sub_134924(a1, a2 + 11)
      && sub_134924(a1, a2 + 13)
      && sub_134924(a1, a2 + 15);
}
