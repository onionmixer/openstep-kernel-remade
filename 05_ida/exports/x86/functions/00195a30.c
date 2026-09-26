/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x195a30. */
id kmDisableAnimation()
{
  id result; // eax

  result = kmId; /*0x195a33*/
  if ( kmId ) /*0x195a3a*/
    return objc_msgSend(kmId, sel_animationCtl_, 0); /*0x195a46*/
  return result; /*0x195a4d*/
}
