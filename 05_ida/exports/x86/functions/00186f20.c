/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x186f20. */
// positive sp value has been detected, the output may be wrong!
void __usercall _switch_tss(int a1@<ebx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, int a5, int a6, int a7)
{
  int v7; // [esp-4h] [ebp-4h]
  _DWORD *retaddr; // [esp+0h] [ebp+0h] BYREF

  if ( retaddr ) /*0x186f26*/
  {
    retaddr[17] = a3; /*0x186f28*/
    retaddr[16] = a4; /*0x186f2b*/
    retaddr[13] = a1; /*0x186f2e*/
    retaddr[15] = a2; /*0x186f31*/
    retaddr[8] = v7; /*0x186f35*/
    retaddr[14] = &retaddr; /*0x186f38*/
    __asm { jmp edx } /*0x186f55*/
  }
  __asm { jmp edx } /*0x186f72*/
}
