/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196bd4. */
void __cdecl -[kmDevice returnToVGAMode](kmDevice *self, SEL a2)
{
  if ( (unsigned __int8)objc_msgSend(dword_1E7768, sel_respondsTo_, sel_revertToVGAMode) ) /*0x196bec*/
  {
    objc_msgSend(dword_1E7768, sel_revertToVGAMode); /*0x196c06*/
    IODelay(101000); /*0x196c10*/
  }
}
