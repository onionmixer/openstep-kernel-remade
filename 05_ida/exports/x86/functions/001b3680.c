/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3680. */
id EvOpen()
{
  id v0; // eax

  v0 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1b36a0*/
  return objc_msgSend(v0, sel_evOpen_token_); /*0x1b36b0*/
}
