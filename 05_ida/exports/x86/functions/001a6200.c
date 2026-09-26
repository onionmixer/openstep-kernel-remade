/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6200. */
char __cdecl -[IOLogicalDisk isAnyOtherOpen](IOLogicalDisk *self, SEL a2)
{
  IOLogicalDisk *i; // eax
  IOLogicalDisk *v4; // ebx

  for ( i = (IOLogicalDisk *)objc_msgSend(self->_physicalDisk, sel_nextLogicalDisk); /*0x1a6216*/
        ;
        i = -[IODisk nextLogicalDisk](v4, sel_nextLogicalDisk) )
  {
    v4 = i; /*0x1a6245*/
    if ( !i ) /*0x1a624c*/
      break; /*0x1a624c*/
    if ( i != self && -[IOLogicalDisk isInstanceOpen](i, sel_isInstanceOpen) ) /*0x1a6224*/
      return 1; /*0x1a6235*/
  }
  return 0; /*0x1a6253*/
}
