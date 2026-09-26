/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0f5c. */
char __cdecl -[IODirectDevice getEISAId:forSlot:](IODirectDevice *self, SEL a2, unsigned int *a3, int a4)
{
  return eisa_id(a4, a3); /*0x1c0f71*/
}
