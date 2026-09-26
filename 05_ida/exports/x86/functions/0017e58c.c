/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e58c. */
void sub_17E58C()
{
  const char **v0; // ebx
  Class Class; // eax

  v0 = (const char **)&pseudoDevList; /*0x17e590*/
  if ( pseudoDevList ) /*0x17e59c*/
  {
    do /*0x17e5e0*/
    {
      Class = objc_getClass(*v0); /*0x17e5a3*/
      if ( Class ) /*0x17e5ad*/
        +[IODevice addLoadedClass:description:](aIodevice_0, sel_addLoadedClass_description_, Class, 0); /*0x17e5d5*/
      else
        IOLog(aProbepseudodev); /*0x17e5b7*/
      ++v0; /*0x17e5dd*/
    }
    while ( *v0 ); /*0x17e5e0*/
  }
}
