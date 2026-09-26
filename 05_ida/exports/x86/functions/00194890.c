/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x194890. */
void sub_194890()
{
  int i; // ebx
  mach_header *v1; // esi
  const section *v2; // eax

  for ( i = 0; i < MEMORY[0x11154]; ++i ) /*0x1948a3*/
  {
    v1 = *(mach_header **)(8 * i + 0x11168); /*0x1948a8*/
    v2 = getsectbynamefromheader(v1, aData_0, sectname); /*0x1948ba*/
    if ( v2 ) /*0x1948c4*/
      bzero((void *)v2->addr, v2->size); /*0x1948ce*/
    objc_registerModule(v1, 0); /*0x1948d9*/
  }
}
