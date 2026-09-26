/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8c78. */
void __cdecl -[IODirectDevice unmapMemoryRange:from:](IODirectDevice *self, SEL a2, unsigned int a3, unsigned int a4)
{
  id *v4; // esi
  id v5; // ebx

  v4 = (id *)self->_private; /*0x1a8c87*/
  if ( a3 < -[IODeviceDescription numMemoryRanges](self->_deviceDescription, sel_numMemoryRanges) ) /*0x1a8ca5*/
  {
    v5 = objc_msgSend(*v4, sel_valueForKey_, a4); /*0x1a8cb7*/
    if ( v5 ) /*0x1a8cbe*/
    {
      objc_msgSend(*v4, sel_removeKey_, a4); /*0x1a8ccb*/
      objc_msgSend(v5, sel_free); /*0x1a8cd8*/
    }
  }
}
