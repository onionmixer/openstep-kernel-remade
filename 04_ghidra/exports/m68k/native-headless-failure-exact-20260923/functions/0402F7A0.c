
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

auth_stat __authenticate(void)

{
  auth_stat aVar1;
  int in_stack_00000004;
  int in_stack_00000008;
  
  *(undefined4 *)(in_stack_00000004 + 0xc) = *(undefined4 *)(in_stack_00000008 + 0x18);
  *(undefined4 *)(in_stack_00000004 + 0x10) = *(undefined4 *)(in_stack_00000008 + 0x1c);
  *(undefined4 *)(in_stack_00000004 + 0x14) = *(undefined4 *)(in_stack_00000008 + 0x20);
  *(undefined4 *)(*(int *)(in_stack_00000004 + 0x1c) + 0x1e) = __null_auth;
  *(undefined4 *)(*(int *)(in_stack_00000004 + 0x1c) + 0x26) = 0;
  if (*(uint *)(in_stack_00000004 + 0xc) < 3) {
    aVar1 = (**(code **)(&DAT_040af046 + *(uint *)(in_stack_00000004 + 0xc) * 4))();
  }
  else {
    aVar1 = AUTH_REJECTEDCRED;
  }
  return aVar1;
}

