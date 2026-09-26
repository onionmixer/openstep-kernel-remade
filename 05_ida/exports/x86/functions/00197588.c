/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x197588. */
id __cdecl kmDrawGraphicPanel(int a1)
{
  id result; // eax

  result = kmId; /*0x19758b*/
  if ( kmId ) /*0x197592*/
    return objc_msgSend(kmId, sel_drawGraphicPanel_, a1); /*0x1975a0*/
  return result; /*0x1975a7*/
}
