/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137efc */

boolean_t _xdr_union(XDR *param_1,int *param_2,char *param_3,xdr_discrim *param_4,xdrproc_t param_5)

{
  xdr_op xVar1;
  xdrproc_t pxVar2;
  boolean_t bVar3;
  _func_7612 *p_Var4;
  
  xVar1 = param_1->x_op;
  if (xVar1 == XDR_ENCODE) {
    p_Var4 = param_1->x_ops->x_putlong;
LAB_00137f2c:
    bVar3 = (*p_Var4)(param_1,param_2);
  }
  else {
    if (xVar1 == XDR_DECODE) {
      p_Var4 = (_func_7612 *)param_1->x_ops->x_getlong;
      goto LAB_00137f2c;
    }
    if (xVar1 == XDR_FREE) goto LAB_00137f58;
    _printf(s_xdr_long__FAILED_001dd217);
    bVar3 = 0;
  }
  if (bVar3 == 0) {
    _printf(s_xdr_enum__dscmp_FAILED_001dd346);
    return 0;
  }
LAB_00137f58:
  pxVar2 = param_4->proc;
  while (pxVar2 != (xdrproc_t)0x0) {
    if (param_4->value == *param_2) {
      bVar3 = (*param_4->proc)(param_1,param_3,0xffffffff);
      return bVar3;
    }
    pxVar2 = param_4[1].proc;
    param_4 = param_4 + 1;
  }
  if (param_5 == (xdrproc_t)0x0) {
    return 0;
  }
  bVar3 = (*param_5)(param_1,param_3,0xffffffff);
  return bVar3;
}

