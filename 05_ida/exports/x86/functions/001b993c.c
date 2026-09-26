/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b993c. */
unsigned int __cdecl -[InputStream mixRegion:descriptor:buffer:maxCount:virgin:rate:format:channelCount:](
        InputStream *self,
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
  unsigned int var2; // edx
  unsigned int result; // eax

  var2 = a3->var2; /*0x1b9946*/
  result = a3->var1 - var2; /*0x1b994c*/
  if ( result > a6 ) /*0x1b9950*/
    result = a6; /*0x1b9952*/
  a3->var2 = result + var2; /*0x1b9956*/
  return result; /*0x1b9959*/
}
