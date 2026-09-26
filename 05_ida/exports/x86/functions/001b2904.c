/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2904. */
id __cdecl -[EventDriver attachDefaultEventSources](EventDriver *self, SEL a2)
{
  _DWORD *i; // ebx

  for ( i = defaultEventSources(); *i; ++i ) /*0x1b2913*/
    -[EventDriver attachEventSource:](self, sel_attachEventSource_, *i); /*0x1b2923*/
  return self; /*0x1b2938*/
}
