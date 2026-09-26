/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001385f4 */

void _xdrmem_create(XDR *param_1,char *param_2,uint param_3,xdr_op param_4)

{
  param_1->x_op = param_4;
  param_1->x_ops = (xdr_ops *)&PTR_FUN_001dd484;
  param_1->x_base = param_2;
  param_1->x_private = param_2;
  param_1->x_handy = param_3;
  return;
}

