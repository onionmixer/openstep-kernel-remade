/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b0e0c. */
int __cdecl -[EventDriver evFrameBufferDevicePort:unitName:unitClass:unitPort:](
        EventDriver *self,
        SEL a2,
        int a3,
        char *__s1,
        char *name,
        int *a6)
{
  int v7; // ebx
  Class Class; // eax
  id v9; // [esp+8h] [ebp-4h] BYREF

  *a6 = 0; /*0x1b0e1d*/
  if ( !self->evOpenCalled || self->eventPort != a3 ) /*0x1b0e32*/
    return -706; /*0x1b0e34*/
  v7 = IOGetObjectForDeviceName(__s1, (int)&v9); /*0x1b0e4d*/
  if ( v7 ) /*0x1b0e54*/
  {
    Class = objc_getClass(name); /*0x1b0e5a*/
    v9 = Class; /*0x1b0e5f*/
    if ( !Class ) /*0x1b0e67*/
      return v7; /*0x1b0e67*/
    if ( !(unsigned __int8)-[objc_class respondsTo:](Class, sel_respondsTo_, sel_probe) ) /*0x1b0e78*/
      return v7; /*0x1b0e78*/
    v9 = objc_msgSend(v9, sel_probe); /*0x1b0e94*/
    if ( !v9 ) /*0x1b0e9c*/
      return v7; /*0x1b0e9e*/
  }
  if ( !(unsigned __int8)objc_msgSend(v9, sel_respondsTo_, sel_devicePort) ) /*0x1b0eb6*/
    return -705; /*0x1b0ed8*/
  *a6 = (int)objc_msgSend(v9, sel_devicePort); /*0x1b0ed2*/
  return 0; /*0x1b0ee0*/
}
