/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1385f4. */
void __cdecl xdrmem_create(XDR *a1, char *a2, unsigned int a3, xdr_op a4)
{
  a1->x_op = a4; /*0x138604*/
  a1->x_ops = (const __rpc_xdr::xdr_ops *)&unk_1DD484; /*0x138606*/
  a1->x_base = a2; /*0x13860d*/
  a1->x_private = a2; /*0x138610*/
  a1->x_handy = a3; /*0x138613*/
}
