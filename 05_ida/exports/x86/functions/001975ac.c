/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1975ac. */
id __cdecl kmGraphicPanelString(int a1)
{
  id result; // eax

  result = kmId; /*0x1975af*/
  if ( kmId ) /*0x1975b6*/
    return objc_msgSend(kmId, sel_graphicPanelString_, a1); /*0x1975c4*/
  return result; /*0x1975cb*/
}
