/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134ccc. */
_BOOL4 __cdecl sub_134CCC(XDR *a1, __int32 *a2)
{
  return xdr_long(a1, a2) /*0x134d35*/
      && xdr_long(a1, a2 + 1)
      && xdr_long(a1, a2 + 2)
      && xdr_long(a1, a2 + 3)
      && xdr_long(a1, a2 + 4);
}
