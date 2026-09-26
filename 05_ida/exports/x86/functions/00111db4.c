/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111db4. */
int __cdecl ptsclose(unsigned __int8 a1)
{
  __int16 *v1; // esi
  int v2; // ebx

  v1 = &word_1E56C8[8 * a1]; /*0x111dc0*/
  v2 = *((_DWORD *)v1 + 2); /*0x111dc6*/
  if ( (v1[2] & 1) != 0 ) /*0x111dcd*/
  {
    (*(&off_1DAFEC + 12 * *(char *)(v2 + 71)))((FILE *)v2); /*0x111de0*/
    ttyclose((FILE *)v2); /*0x111de3*/
    *((_DWORD *)v1 + 1) = 0; /*0x111de8*/
  }
  return ptcwakeup(v2, 3); /*0x111dfd*/
}
