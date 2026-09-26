/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137a9c. */
int __cdecl xdr_short(XDR *a1, __int16 *a2)
{
  int v3; // [esp+8h] [ebp-4h] BYREF

  switch ( a1->x_op ) /*0x137aaf*/
  {
    case XDR_DECODE: /*0x137aaf*/
      if ( !((int (__stdcall *)(XDR *, int *))a1->x_ops->x_getlong)(a1, &v3) ) /*0x137ade*/
        return 0; /*0x137ae6*/
      *a2 = v3; /*0x137aec*/
      break;
    case XDR_ENCODE: /*0x137aaf*/
      v3 = *a2; /*0x137abf*/
      return ((int (__stdcall *)(XDR *, int *))a1->x_ops->x_putlong)(a1, &v3); /*0x137acf*/
    case XDR_FREE: /*0x137aaf*/
      break;
    default:
      return 0; /*0x137ab8*/
  }
  return 1; /*0x137afd*/
}
