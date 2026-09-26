/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137300 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _svc_run(void)

{
  undefined4 uVar1;
  int *in_stack_00000004;
  
  do {
    uVar1 = _splnet();
    while (*(short *)(*in_stack_00000004 + 0x24) == 0) {
      _sbwait(*in_stack_00000004 + 0x24);
    }
    _splx(uVar1);
    _svc_getreq();
    __Rpccnt = __Rpccnt + 1;
  } while( true );
}

