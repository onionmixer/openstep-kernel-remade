/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e824. */
void __cdecl -[KernLock release](KernLock *self, SEL a2)
{
  int v2; // eax

  v2 = ipltospl(self->_savedLevel); /*0x17e82e*/
  spln(v2); /*0x17e834*/
}
