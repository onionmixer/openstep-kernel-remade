/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x186e3c. */
void __usercall mach_kernel_trap_(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5)
{
  unsigned int v5; // kr00_4
  _DWORD v6[12]; // [esp-18h] [ebp-38h] BYREF
  _DWORD v7[2]; // [esp+18h] [ebp-8h] BYREF

  v5 = __getcallerseflags(); /*0x186e3c*/
  v7[1] = v5; /*0x186e3c*/
  v7[0] = 0; /*0x186e3d*/
  v6[8] = v7; /*0x186e3f*/
  v6[6] = a3; /*0x186e3f*/
  v6[5] = a2; /*0x186e3f*/
  v6[4] = a1; /*0x186e3f*/
  v6[3] = (unsigned __int16)__DS__; /*0x186e40*/
  v6[2] = (unsigned __int16)__ES__; /*0x186e41*/
  v6[1] = (unsigned __int16)__FS__; /*0x186e42*/
  v6[0] = (unsigned __int16)__GS__; /*0x186e44*/
  if ( empty_stacks ) /*0x186e75*/
  {
    _disable(); /*0x186e77*/
    empty_stacks = 0; /*0x186e7e*/
    _enable(); /*0x186e88*/
  }
  mach_kernel_trap(v6); /*0x186e8a*/
  __asm { iret } /*0x186e9b*/
}
