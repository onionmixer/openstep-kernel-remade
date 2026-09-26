/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a943c. */
int __cdecl -[IOBufDevice acquireUnit:for:callbackId:deviceTag:](
        IOBufDevice *self,
        SEL a2,
        unsigned int a3,
        char *__src,
        id a5,
        void *a6)
{
  $56D1BF522F95260DED69B470E8535AF1 *v6; // ebx

  v6 = &self->unitInfo[a3]; /*0x1a9451*/
  if ( v6->callbackId ) /*0x1a9458*/
    return -725; /*0x1a948c*/
  strncpy(self->unitInfo[a3].ownerName, __src, 0x51u); /*0x1a9467*/
  v6->callbackId = (deviceTag *)a5; /*0x1a946f*/
  self->unitInfo[a3].var0 = a6; /*0x1a9474*/
  -[IOBufDevice initializeUnit:](self, sel_initializeUnit_, a3); /*0x1a9480*/
  return 0; /*0x1a9494*/
}
