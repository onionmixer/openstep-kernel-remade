/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a310. */
void __usercall fp_configure(__int16 a1@<fpstat>)
{
  unsigned __int32 v1; // edx

  v1 = __readcr0(); /*0x18a316*/
  LOBYTE(v1) = v1 & 0xF3; /*0x18a319*/
  __writecr0(v1); /*0x18a31c*/
  __asm { fninit } /*0x18a325*/
  if ( a1 || (boothowto & 0x200000) != 0 ) /*0x18a33a*/
  {
    LOBYTE(v1) = v1 & 0xF9 | 4; /*0x18a33f*/
    __writecr0(v1); /*0x18a342*/
  }
  else
  {
    LOBYTE(v1) = v1 | 0x22; /*0x18a34c*/
    __writecr0(v1); /*0x18a34f*/
    cpu_config = cpu_config & 0xFC | 2; /*0x18a35c*/
  }
}
