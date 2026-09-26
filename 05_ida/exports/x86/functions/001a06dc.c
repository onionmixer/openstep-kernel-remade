/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a06dc. */
id __cdecl +[EventSrcPCPointer probe](id a1, SEL a2)
{
  id result; // eax

  result = dword_1E49BC; /*0x1a06df*/
  if ( !dword_1E49BC ) /*0x1a06e6*/
  {
    dword_1E49BC = objc_msgSend(a1, sel_alloc); /*0x1a06f8*/
    objc_msgSend(dword_1E49BC, sel_setName_, aEventsrcpcpoin_0); /*0x1a070a*/
    objc_msgSend(dword_1E49BC, sel_setDeviceKind_, aEventsrcpcpoin_1); /*0x1a0722*/
    if ( !objc_msgSend(dword_1E49BC, sel_init) ) /*0x1a0738*/
      objc_msgSend(dword_1E49BC, sel_free); /*0x1a0752*/
    return dword_1E49BC; /*0x1a0757*/
  }
  return result; /*0x1a075e*/
}
