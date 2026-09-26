/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18409c. */
int __cdecl sdsize(__int16 a1)
{
  void *v1; // eax

  v1 = (void *)sub_1840EC(a1); /*0x1840a4*/
  if ( v1 ) /*0x1840ae*/
    return (int)objc_msgSend(v1, sel_blockSize); /*0x1840b8*/
  else
    return -1; /*0x1840c4*/
}
