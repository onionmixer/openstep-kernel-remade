/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1841bc. */
int __cdecl sgclose(__int16 a1)
{
  void *v1; // eax

  v1 = (void *)sub_18447C(a1); /*0x1841c4*/
  if ( v1 ) /*0x1841ce*/
    return (int)objc_msgSend(v1, sel_release_, v1); /*0x1841e5*/
  else
    return 6; /*0x1841d0*/
}
