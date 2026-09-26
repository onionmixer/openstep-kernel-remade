/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: matrox snapshot; requested VA: 0x1cebb0. */
id _objc_msgForward(id receiver, SEL sel, ...)
{
  if ( sel == sel_forward:: )
    __objc_error(receiver, "Does not recognize selector %s", sel_forward::); /*0x1cebee*/
  return objc_msgSend(receiver, sel_forward::, sel, &receiver); /*0x1cebd7*/
}
