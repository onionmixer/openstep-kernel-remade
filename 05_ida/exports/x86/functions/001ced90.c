/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ced90. */
Class __cdecl objc_getMetaClass(const char *name)
{
  Class Class; // eax

  Class = objc_getClass(name); /*0x1ced97*/
  if ( Class ) /*0x1ced9e*/
    return Class->isa; /*0x1ceda8*/
  else
    return nullptr; /*0x1ceda0*/
}
