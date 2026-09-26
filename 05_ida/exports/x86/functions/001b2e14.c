/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2e14. */
id __cdecl -[EventDriver absolutePointerEvent:at:inProximity:withPressure:](
        EventDriver *self,
        SEL a2,
        int a3,
        $9B414A52084CF78D000E95AF47DF0AD5 *a4,
        char a5,
        int a6)
{
  int v7[2]; // [esp+Ch] [ebp-8h] BYREF

  IOGetTimestamp(v7); /*0x1b2e2a*/
  -[EventDriver absolutePointerEvent:at:inProximity:withPressure:withAngle:atTime:]( /*0x1b2e4e*/
    self,
    sel_absolutePointerEvent_at_inProximity_withPressure_withAngle_atTime_,
    a3,
    a4,
    a5,
    a6,
    90,
    v7[0],
    v7[1]);
  return self; /*0x1b2e58*/
}
