/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137b04. */
int __cdecl xdr_u_short(XDR *a1, unsigned __int16 *a2)
{
  int v3; // [esp+8h] [ebp-4h] BYREF

  switch ( a1->x_op )
  {
    case XDR_DECODE:
      if ( !a1->x_ops->x_getlong(a1, &v3) )
      {
        printf("xdr_u_short: decode FAILED\n");
        return 0; /*0x137b5b*/
      }
      *a2 = v3; /*0x137b64*/
      break;
    case XDR_ENCODE:
      v3 = *a2; /*0x137b27*/
      return ((int (__stdcall *)(XDR *))a1->x_ops->x_putlong)(a1); /*0x137b37*/
    case XDR_FREE:
      break;
    default:
      printf("xdr_u_short: bad op FAILED\n");
      return 0; /*0x137b20*/
  }
  return 1; /*0x137b7f*/
}
