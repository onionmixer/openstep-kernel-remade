/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0b28. */
char __cdecl -[PCPointer setEventTarget:](PCPointer *self, SEL a2, id a3)
{
  if ( (unsigned __int8)objc_msgSend(a3, sel_conformsTo_, &stru_1FDDA4) ) /*0x1a0b40*/
  {
    self->target = a3; /*0x1a0b64*/
    return 1; /*0x1a0b6a*/
  }
  else
  {
    object_getClassName(a3); /*0x1a0b4d*/
    IOLog(aPcpointerSetev); /*0x1a0b58*/
    return 0; /*0x1a0b5d*/
  }
}
