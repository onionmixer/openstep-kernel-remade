/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137340 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

auth_stat __authenticate(void)

{
  auth_stat aVar1;
  int in_stack_00000004;
  int in_stack_00000008;
  
  *(undefined4 *)(in_stack_00000004 + 0xc) = *(undefined4 *)(in_stack_00000008 + 0x18);
  *(undefined4 *)(in_stack_00000004 + 0x10) = *(undefined4 *)(in_stack_00000008 + 0x1c);
  *(undefined4 *)(in_stack_00000004 + 0x14) = *(undefined4 *)(in_stack_00000008 + 0x20);
  *(undefined4 *)(*(int *)(in_stack_00000004 + 0x1c) + 0x20) = __null_auth;
  *(undefined4 *)(*(int *)(in_stack_00000004 + 0x1c) + 0x28) = 0;
  if (*(uint *)(in_stack_00000004 + 0xc) < 3) {
    aVar1 = (*(code *)(&PTR___svcauth_null_001dd1a8)[*(uint *)(in_stack_00000004 + 0xc)])();
  }
  else {
    aVar1 = AUTH_REJECTEDCRED;
  }
  return aVar1;
}

