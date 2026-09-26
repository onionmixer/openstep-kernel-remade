/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6c24. */
$0FF10449EE71A6B4D80D3A2D7B5E2C1F *__cdecl -[IOSVGADisplay allocateConsoleInfo](IOSVGADisplay *self, SEL a2)
{
  $514E7C50D28E54AB164B6500F83867A3 *v2; // eax

  v2 = -[IODisplay displayInfo](self, sel_displayInfo); /*0x1c6c32*/
  return ($0FF10449EE71A6B4D80D3A2D7B5E2C1F *)SVGAAllocateConsole(v2); /*0x1c6c3f*/
}
