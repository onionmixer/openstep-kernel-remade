/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a416c. */
id __cdecl -[IODevice registerDevice](IODevice *self, SEL a2)
{
  IODevice **v2; // ebx
  int v3; // eax

  if ( self->_location[0] )
    IOLog("Registering: %s at %s\n");
  else
    IOLog("Registering: %s\n");
  v2 = (IODevice **)IOMalloc(0x10u); /*0x1a41c8*/
  *v2 = self; /*0x1a41ca*/
  objc_msgSend(dword_1E8674, sel_lock); /*0x1a41da*/
  v2[1] = (IODevice *)dword_1E8668++; /*0x1a41e5*/
  if ( (int *)dword_1E866C == &dword_1E866C ) /*0x1a41fb*/
  {
    dword_1E866C = (int)v2; /*0x1a4194*/
    dword_1E8670 = (int)v2; /*0x1a419a*/
    v2[2] = (IODevice *)&dword_1E866C; /*0x1a41a0*/
    v2[3] = (IODevice *)&dword_1E866C; /*0x1a41a7*/
  }
  else
  {
    v3 = dword_1E8670; /*0x1a41fd*/
    v2[3] = (IODevice *)dword_1E8670; /*0x1a4202*/
    v2[2] = (IODevice *)&dword_1E866C; /*0x1a4205*/
    dword_1E8670 = (int)v2; /*0x1a420c*/
    *(_DWORD *)(v3 + 8) = v2; /*0x1a4212*/
  }
  objc_msgSend(dword_1E8674, sel_unlock); /*0x1a4223*/
  +[IODevice connectToIndirectDevices:](aIodevice_0, sel_connectToIndirectDevices_, self); /*0x1a4237*/
  return self; /*0x1a4241*/
}
