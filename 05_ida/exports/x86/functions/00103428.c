/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x103428. */
int __cdecl compress(Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen)
{
  int v4; // ebx
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  v6 = 0; /*0x103434*/
  v4 = 0; /*0x10343b*/
  v7 = (_DWORD)dest << 6; /*0x103443*/
  if ( destLen ) /*0x103448*/
    v7 += (int)destLen / 15625; /*0x103456*/
  while ( v7 > 0x1FFF ) /*0x103470*/
  {
    ++v6; /*0x10345c*/
    v4 = v7 & 4; /*0x103462*/
    v7 >>= 3; /*0x103465*/
  }
  if ( v4 ) /*0x103474*/
  {
    if ( ++v7 > 0x1FFF ) /*0x103480*/
    {
      v7 >>= 3; /*0x103482*/
      ++v6; /*0x103486*/
    }
  }
  return v7 + (v6 << 13); /*0x103495*/
}
