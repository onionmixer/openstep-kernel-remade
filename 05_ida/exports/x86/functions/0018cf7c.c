/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cf7c. */
void md_prepare_for_shutdown(int a1, char a2, ...)
{
  const char *v2; // ebx

  if ( (a2 & 8) != 0 ) /*0x18cf84*/
  {
    v2 = (const char *)kmLocalizeString(aPleaseWaitUnti); /*0x18cf90*/
    printf(v2); /*0x18cf96*/
    if ( prettyShutdown ) /*0x18cfa6*/
      kmGraphicPanelString(v2); /*0x18cfa9*/
  }
}
