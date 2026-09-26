
/* WARNING: Removing unreachable block (ram,0xf0044c68) */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

auth_stat __authenticate(void)

{
  auth_stat in_o0;
  int in_o1;
  
  *(undefined4 *)(in_o0 + 0xc) = *(undefined4 *)(in_o1 + 0x18);
  *(undefined4 *)(in_o0 + 0x10) = *(undefined4 *)(in_o1 + 0x1c);
  *(undefined4 *)(in_o0 + 0x14) = *(undefined4 *)(in_o1 + 0x20);
  *(undefined4 *)(*(int *)(in_o0 + 0x1c) + 0x20) = __null_auth;
  *(undefined4 *)(*(int *)(in_o0 + 0x1c) + 0x28) = 0;
  if (*(uint *)(in_o0 + 0xc) < 3) {
    (*(code *)(&PTR___svcauth_null_f010de18)[*(uint *)(in_o0 + 0xc)])(in_o0,in_o1);
  }
  else {
    in_o0 = AUTH_REJECTEDCRED;
  }
  return in_o0;
}

