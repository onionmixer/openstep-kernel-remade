/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b36b4. */
id EvClose()
{
  id v0; // eax

  v0 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1b36d4*/
  return objc_msgSend(v0, sel_evClose_token_); /*0x1b36e4*/
}
