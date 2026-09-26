/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e7f4. */
void __cdecl -[KernLock acquire](KernLock *self, SEL a2)
{
  int v2; // ebx
  int v3; // eax

  v2 = curipl(); /*0x17e801*/
  if ( v2 < self->_lockLevel ) /*0x17e808*/
  {
    v3 = ipltospl(self->_lockLevel); /*0x17e80b*/
    spln(v3); /*0x17e811*/
  }
  self->_savedLevel = v2; /*0x17e816*/
}
