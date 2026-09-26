/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b37bc. */
id __cdecl +[IOEventSource registerEventSource:](id a1, SEL a2, id a3)
{
  id v3; // eax

  v3 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1b37d8*/
  return objc_msgSend(v3, sel_registerEventSource_); /*0x1b37e8*/
}
