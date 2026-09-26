/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b9ba8. */
id __cdecl -[InputStream dmaCompleteDescriptor:transfered:](
        InputStream *self,
        SEL a2,
        $2D87D4CA0FCCD4E0D80DDC4A8D8F85EA *a3,
        unsigned int a4)
{
  objc_super v5; // [esp+4h] [ebp-8h] BYREF

  v5.receiver = self; /*0x1b9bc1*/
  v5.super_class = (Class)stru_1FA4C4.ext; /*0x1b9bca*/
  -[AudioStream dmaCompleteDescriptor:transfered:](&v5, sel_dmaCompleteDescriptor_transfered_, a3, a4); /*0x1b9bd1*/
  if ( self->wantsRecordedData ) /*0x1b9bd9*/
    -[InputStream returnRecordedData](self, sel_returnRecordedData); /*0x1b9be7*/
  return self; /*0x1b9bee*/
}
