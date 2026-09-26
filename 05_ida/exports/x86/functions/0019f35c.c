/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f35c. */
id __cdecl -[EventSrcPCKeyboard initKeyboard](EventSrcPCKeyboard *self, SEL a2)
{
  int v2; // eax

  v2 = IOGetObjectForDeviceName(aPckeyboard0_0, (int)&self->kbdDevice); /*0x19f36f*/
  if ( !v2 ) /*0x19f379*/
    return self; /*0x19f398*/
  -[IODevice stringFromReturn:](self, sel_stringFromReturn_, v2); /*0x19f384*/
  IOLog(aInitkeyboardCa); /*0x19f38f*/
  return nullptr; /*0x19f39a*/
}
