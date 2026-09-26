/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137bc4. */
int __cdecl xdr_bool(XDR *a1, int *a2)
{
  _BOOL4 v3; // [esp+8h] [ebp-4h] BYREF

  switch ( a1->x_op )
  {
    case XDR_DECODE:
      if ( !a1->x_ops->x_getlong(a1, (__int32 *)&v3) )
      {
        printf("xdr_bool: decode FAILED\n");
        return 0; /*0x137c23*/
      }
      *a2 = v3; /*0x137c34*/
      break;
    case XDR_ENCODE:
      v3 = *a2 != 0; /*0x137bef*/
      return ((int (__stdcall *)(XDR *))a1->x_ops->x_putlong)(a1); /*0x137bff*/
    case XDR_FREE:
      break;
    default:
      printf("xdr_bool: bad op FAILED\n");
      return 0; /*0x137be0*/
  }
  return 1; /*0x137c4f*/
}
