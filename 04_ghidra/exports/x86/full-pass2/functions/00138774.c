/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138774 */

boolean_t _xdr_reference(XDR *param_1,char **param_2,uint param_3,xdrproc_t param_4)

{
  char *pcVar1;
  boolean_t bVar2;
  
  pcVar1 = *param_2;
  if (pcVar1 == (char *)0x0) {
    if (param_1->x_op == XDR_DECODE) {
      pcVar1 = (char *)_kalloc(param_3);
      *param_2 = pcVar1;
      _bzero(pcVar1,param_3);
    }
    else if (param_1->x_op == XDR_FREE) {
      return 1;
    }
  }
  bVar2 = (*param_4)(param_1,pcVar1,0xffffffff);
  if (param_1->x_op == XDR_FREE) {
    _kfree(pcVar1,param_3);
    *param_2 = (char *)0x0;
  }
  return bVar2;
}

