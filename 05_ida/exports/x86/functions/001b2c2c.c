/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2c2c. */
id __cdecl -[EventDriver relativePointerEvent:deltaX:deltaY:](EventDriver *self, SEL a2, int a3, int a4, int a5)
{
  int v6[2]; // [esp+Ch] [ebp-8h] BYREF

  IOGetTimestamp(v6); /*0x1b2c42*/
  return -[EventDriver relativePointerEvent:deltaX:deltaY:atTime:]( /*0x1b2c65*/
           self,
           sel_relativePointerEvent_deltaX_deltaY_atTime_,
           a3,
           a4,
           a5,
           v6[0],
           v6[1]);
}
