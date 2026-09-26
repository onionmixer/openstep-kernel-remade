/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e538. */
void sub_17E538()
{
  const char **v0; // ebx
  Class Class; // eax

  v0 = (const char **)&indirectDevList; /*0x17e53c*/
  if ( indirectDevList ) /*0x17e548*/
  {
    do /*0x17e57f*/
    {
      Class = objc_getClass(*v0); /*0x17e54f*/
      if ( Class ) /*0x17e559*/
        -[objc_class name](Class, sel_name); /*0x17e574*/
      else
        IOLog(aRegisterindire); /*0x17e563*/
      ++v0; /*0x17e57c*/
    }
    while ( *v0 ); /*0x17e57f*/
  }
}
