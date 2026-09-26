/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b281c. */
id __cdecl -[EventDriver setUserAudioVolume:](EventDriver *self, SEL a2, int a3)
{
  -[EventDriver setAudioVolume:](self, sel_setAudioVolume_, a3); /*0x1b282f*/
  return -[EventDriver evSpecialKeyMsg:direction:flags:level:]( /*0x1b284e*/
           self,
           sel_evSpecialKeyMsg_direction_flags_level_,
           0,
           10,
           0,
           self->curVolume);
}
