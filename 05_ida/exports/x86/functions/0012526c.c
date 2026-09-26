/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12526c. */
int __cdecl in_pcbdetach(_DWORD *a1)
{
  int v1; // eax

  v1 = a1[7]; /*0x125273*/
  *(_DWORD *)(v1 + 8) = 0; /*0x125276*/
  sofree(v1); /*0x12527e*/
  if ( a1[14] ) /*0x125286*/
    m_free(a1[14]); /*0x12528e*/
  if ( a1[9] ) /*0x125296*/
    rtfree(a1[9]); /*0x12529e*/
  ip_freemoptions(a1[15]); /*0x1252aa*/
  *(_DWORD *)(*a1 + 4) = a1[1]; /*0x1252b7*/
  *(_DWORD *)a1[1] = *a1; /*0x1252bf*/
  return kfree((int)a1, 0x40u); /*0x1252c9*/
}
