/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136114 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_rmtcall_args(void)

{
  boolean_t bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  XDR *in_stack_00000004;
  uint *in_stack_00000008;
  
  bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008);
  if (((bVar1 != 0) && (bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 1), bVar1 != 0))
     && (bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 2), bVar1 != 0)) {
    uVar2 = (*in_stack_00000004->x_ops->x_getpostn)(in_stack_00000004);
    bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 3);
    if (bVar1 != 0) {
      uVar3 = (*in_stack_00000004->x_ops->x_getpostn)(in_stack_00000004);
      iVar4 = (*(code *)in_stack_00000008[5])();
      if (iVar4 != 0) {
        uVar5 = (*in_stack_00000004->x_ops->x_getpostn)(in_stack_00000004);
        in_stack_00000008[3] = uVar5 - uVar3;
        (*in_stack_00000004->x_ops->x_setpostn)(in_stack_00000004,uVar2);
        bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 3);
        if (bVar1 != 0) {
          (*in_stack_00000004->x_ops->x_setpostn)(in_stack_00000004,uVar5);
          return 1;
        }
      }
    }
    return 0;
  }
  return 0;
}

