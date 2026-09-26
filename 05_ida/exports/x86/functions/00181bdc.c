/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181bdc. */
id __cdecl -[KernStringList free](KernStringList *self, SEL a2)
{
  unsigned int i; // ebx
  objc_super v4; // [esp+10h] [ebp-8h] BYREF

  for ( i = 0; self->count > i; ++i ) /*0x181bea*/
    IOFree((int)self->strings[i], strlen(self->strings[i]) + 1); /*0x181c09*/
  IOFree((int)self->strings, 4 * self->count); /*0x181c25*/
  v4.receiver = self; /*0x181c33*/
  v4.super_class = (Class)stru_1F9FC4.ext; /*0x181c3b*/
  return -[Object free](&v4, sel_free); /*0x181c4c*/
}
