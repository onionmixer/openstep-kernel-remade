/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b375c. */
id EvFrameBufferDevicePort()
{
  id v0; // eax

  v0 = +[EventDriver instance](aEventdriver_0, sel_instance); /*0x1b3784*/
  return objc_msgSend(v0, sel_evFrameBufferDevicePort_unitName_unitClass_unitPort_); /*0x1b3794*/
}
