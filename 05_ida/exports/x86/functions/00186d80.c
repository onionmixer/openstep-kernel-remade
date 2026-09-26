/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x186d80. */
void __usercall int_0xFF(int a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int v3; // esi
  _DWORD v4[12]; // [esp-18h] [ebp-38h] BYREF
  _DWORD v5[2]; // [esp+18h] [ebp-8h] BYREF

  v5[1] = 0; /*0x186d14*/
  v5[0] = 255; /*0x186d16*/
  v4[8] = v5; /*0x186d80*/
  v4[6] = a3; /*0x186d80*/
  v4[5] = a2; /*0x186d80*/
  v4[4] = a1; /*0x186d80*/
  v4[3] = (unsigned __int16)__DS__; /*0x186d81*/
  v4[2] = (unsigned __int16)__ES__; /*0x186d82*/
  v4[1] = (unsigned __int16)__FS__; /*0x186d83*/
  v4[0] = (unsigned __int16)__GS__; /*0x186d85*/
  v3 = empty_stacks; /*0x186da4*/
  if ( empty_stacks ) /*0x186dae*/
    empty_stacks = 0; /*0x186db6*/
  catch_interrupt(v4); /*0x186dc1*/
  empty_stacks = v3; /*0x186dc8*/
  __asm { iret } /*0x186dd8*/
}
