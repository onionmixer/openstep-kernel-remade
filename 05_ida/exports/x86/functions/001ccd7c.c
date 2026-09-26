/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccd7c. */
Ivar __cdecl class_getInstanceVariable(Class cls, const char *name)
{
  if ( cls && name ) /*0x1ccd8b*/
    return (Ivar)sub_1CCD18((int)cls, (char *)name); /*0x1ccd8f*/
  else
    return nullptr; /*0x1ccd98*/
}
