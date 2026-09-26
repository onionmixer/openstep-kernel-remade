/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2bac. */
int __cdecl -[EventDriver relinquishOwnershipRequest:](EventDriver *self, SEL a2, id a3)
{
  int v3; // edx

  v3 = 0; /*0x1b2bb2*/
  if ( self->eventsOpen ) /*0x1b2bb4*/
    return -725; /*0x1b2bbd*/
  return v3; /*0x1b2bc6*/
}
