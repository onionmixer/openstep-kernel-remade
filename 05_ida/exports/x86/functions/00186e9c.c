/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x186e9c. */
void __usercall unix_syscall_(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5)
{
  unsigned int v5; // kr00_4
  _DWORD v6[12]; // [esp-18h] [ebp-38h] BYREF
  _DWORD v7[2]; // [esp+18h] [ebp-8h] BYREF

  v5 = __getcallerseflags(); /*0x186e9c*/
  v7[1] = v5; /*0x186e9c*/
  v7[0] = 0; /*0x186e9d*/
  v6[8] = v7; /*0x186e9f*/
  v6[6] = a3; /*0x186e9f*/
  v6[5] = a2; /*0x186e9f*/
  v6[4] = a1; /*0x186e9f*/
  v6[3] = (unsigned __int16)__DS__; /*0x186ea0*/
  v6[2] = (unsigned __int16)__ES__; /*0x186ea1*/
  v6[1] = (unsigned __int16)__FS__; /*0x186ea2*/
  v6[0] = (unsigned __int16)__GS__; /*0x186ea4*/
  if ( empty_stacks ) /*0x186ed5*/
  {
    _disable(); /*0x186ed7*/
    empty_stacks = 0; /*0x186ede*/
    _enable(); /*0x186ee8*/
  }
  unix_syscall((int)v6); /*0x186eea*/
  __asm { iret } /*0x186efb*/
}
