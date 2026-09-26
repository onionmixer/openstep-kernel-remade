/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f1b4. */
$85CD2974BE96D4886BB301820D1C36C2 __cdecl -[KernBusRange range](KernBusRange *self, SEL a2)
{
  $85CD2974BE96D4886BB301820D1C36C2 result; // rax

  result.var0 = self->_base; /*0x17f1c6*/
  result.var1 = self->_end - result.var0; /*0x17f1c8*/
  return result; /*0x17f1cd*/
}
