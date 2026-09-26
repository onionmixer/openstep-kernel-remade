/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9ffc. */
id __cdecl -[Object doesNotRecognize:](Object *self, SEL a2, SEL sel)
{
  int v3; // edx
  const char *Name; // [esp-8h] [ebp-Ch]

  Name = sel_getName(sel); /*0x1ca00c*/
  v3 = 45; /*0x1ca00f*/
  if ( (self->isa->info & 2) != 0 ) /*0x1ca018*/
    v3 = 43; /*0x1ca01a*/
  return -[Object error:](self, sel_error_, "does not recognize selector %c%s", v3, Name); /*0x1ca032*/
}
