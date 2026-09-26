/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137b88. */
int __cdecl xdr_char(XDR *a1, char *a2)
{
  __int32 v3; // [esp+4h] [ebp-4h] BYREF

  v3 = *a2; /*0x137b98*/
  if ( !xdr_long(a1, &v3) ) /*0x137ba0*/
    return 0; /*0x137bb8*/
  *a2 = v3; /*0x137bac*/
  return 1; /*0x137bba*/
}
