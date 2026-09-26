/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c4eac. */
$0FF10449EE71A6B4D80D3A2D7B5E2C1F *__cdecl -[IOFrameBufferDisplay allocateConsoleInfo](
        IOFrameBufferDisplay *self,
        SEL a2)
{
  $514E7C50D28E54AB164B6500F83867A3 *v2; // eax

  v2 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c4eba*/
  return ($0FF10449EE71A6B4D80D3A2D7B5E2C1F *)FBAllocateConsole(v2); /*0x1c4ec7*/
}
