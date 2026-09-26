/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8f30. */
char __cdecl -[AudioStream canConvertRegion:rate:format:channelCount:](
        AudioStream *self,
        SEL a2,
        $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a3,
        unsigned int a4,
        int a5,
        unsigned int a6)
{
  return a4 == self->samplingRate && self->dataFormat == a5 && self->channelCount == a6; /*0x1b8f5a*/
}
