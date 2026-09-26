/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8f10. */
unsigned int __cdecl -[AudioStream mixRegion:descriptor:buffer:maxCount:virgin:rate:format:channelCount:](
        AudioStream *self,
        SEL a2,
        $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a3,
        $2D87D4CA0FCCD4E0D80DDC4A8D8F85EA *a4,
        unsigned int a5,
        unsigned int a6,
        char a7,
        unsigned int a8,
        int a9,
        unsigned int a10)
{
  IOLog((int)"Audio: subclass does not implement mixRegion\n");
  return 0; /*0x1b8f21*/
}
