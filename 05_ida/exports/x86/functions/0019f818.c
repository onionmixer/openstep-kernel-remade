/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f818. */
id __cdecl +[EventSrcPCKeyboard probe](id a1, SEL a2)
{
  id result; // eax
  NXLock *v3; // edx
  id v4; // eax

  result = dword_1E488C; /*0x19f81b*/
  if ( !dword_1E488C ) /*0x19f822*/
  {
    dword_1E488C = objc_msgSend(a1, sel_alloc); /*0x19f838*/
    v3 = +[Object new](aNxlock, sel_new); /*0x19f850*/
    v4 = dword_1E488C; /*0x19f852*/
    *((_DWORD *)dword_1E488C + 73) = v3; /*0x19f857*/
    objc_msgSend(v4, sel_setName_, aEventsrcpckeyb_0); /*0x19f86a*/
    objc_msgSend(dword_1E488C, sel_setDeviceKind_, aEventsrcpckeyb_1); /*0x19f882*/
    if ( !objc_msgSend(dword_1E488C, sel_init) ) /*0x19f898*/
      objc_msgSend(dword_1E488C, sel_free); /*0x19f8b2*/
    return dword_1E488C; /*0x19f8b7*/
  }
  return result; /*0x19f8be*/
}
