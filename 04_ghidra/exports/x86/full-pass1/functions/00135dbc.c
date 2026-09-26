/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135dbc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _clnt_sperrno(void)

{
  int iVar1;
  uint uVar2;
  int in_stack_00000004;
  
  uVar2 = 0;
  iVar1 = 0;
  do {
    if (*(int *)((int)&DAT_001dce88 + iVar1) == in_stack_00000004) {
      return *(char **)((int)&PTR_s_RPC__Success_001dce8c + iVar1);
    }
    iVar1 = iVar1 + 8;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x11);
  return s_RPC___unknown_error_code__001dd0bd;
}

