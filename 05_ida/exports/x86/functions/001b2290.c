/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2290. */
id __cdecl -[EventDriver runPeriodicEvent:](EventDriver *self, SEL a2, unsigned __int64 a3)
{
  if ( self->periodicRunPending == 1 ) /*0x1b229e*/
    ns_untimeout((int)sub_1B34A0, (int)self); /*0x1b22a6*/
  ns_abstimeout((int)sub_1B34A0, (int)self, a3, SHIDWORD(a3)); /*0x1b22be*/
  self->periodicRunPending = 1; /*0x1b22c3*/
  return self; /*0x1b22cc*/
}
