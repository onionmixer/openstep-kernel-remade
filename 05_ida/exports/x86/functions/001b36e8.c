/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b36e8. */
id EvSetSpecialKeyPort()
{
  id v0; // eax

  v0 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1b370c*/
  return objc_msgSend(v0, sel_setSpecialKeyPort_keyFlavor_keyPort_); /*0x1b371c*/
}
