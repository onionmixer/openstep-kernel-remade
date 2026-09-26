/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a60ec. */
char __cdecl -[IOLogicalDisk isOpen](IOLogicalDisk *self, SEL a2)
{
  id v3; // eax

  if ( -[IOLogicalDisk isInstanceOpen](self, sel_isInstanceOpen) ) /*0x1a60fb*/
    return 1; /*0x1a6107*/
  if ( !-[IODisk nextLogicalDisk](self, sel_nextLogicalDisk) ) /*0x1a6118*/
    return 0; /*0x1a6148*/
  v3 = -[IODisk nextLogicalDisk](self, sel_nextLogicalDisk); /*0x1a6133*/
  return (unsigned __int8)objc_msgSend(v3, sel_isOpen); /*0x1a614a*/
}
