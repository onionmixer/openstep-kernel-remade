/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11f450. */
int __cdecl looutput(int a1, int a2, _WORD *a3)
{
  int v4; // eax
  int v5; // eax

  if ( *a3 == 2 ) /*0x11f461*/
  {
    inet_queue(a1, a2); /*0x11f472*/
    v4 = if_opackets(a1); /*0x11f47b*/
    if_opackets_set(a1, v4 + 1); /*0x11f483*/
    v5 = if_ipackets(a1); /*0x11f489*/
    if_ipackets_set(a1, v5 + 1); /*0x11f491*/
    return 0; /*0x11f496*/
  }
  else
  {
    nb_free(a2); /*0x11f464*/
    return 47; /*0x11f469*/
  }
}
