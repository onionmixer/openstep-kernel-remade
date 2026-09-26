/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a94e8. */
int __cdecl -[IOBufDevice ownerForUnit:isNamed:](IOBufDevice *self, SEL a2, unsigned int a3, char *__dst)
{
  strncpy(__dst, self->unitInfo[a3].ownerName, 4u); /*0x1a950b*/
  return 0; /*0x1a9514*/
}
