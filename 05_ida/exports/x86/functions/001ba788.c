/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ba788. */
char __cdecl -[OutputStream canConvertRegion:rate:format:channelCount:](
        OutputStream *self,
        SEL a2,
        $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a3,
        unsigned int a4,
        int a5,
        unsigned int a6)
{
  objc_super v7; // [esp+Ch] [ebp-8h] BYREF

  v7.receiver = self; /*0x1ba7ab*/
  v7.super_class = (Class)stru_1FA514.super_class; /*0x1ba7b4*/
  return -[AudioStream canConvertRegion:rate:format:channelCount:]( /*0x1ba7fc*/
           &v7,
           sel_canConvertRegion_rate_format_channelCount_,
           a3,
           a4,
           a5,
           a6)
      || a5 != 2
      && a5 != 4
      && (a4 == 22050 && self->super.samplingRate == 44100 || a4 == 44100 && self->super.samplingRate == 22050);
}
