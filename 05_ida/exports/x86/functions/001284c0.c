/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1284c0. */
void __cdecl tcp_trace(__int16 a1, __int16 a2, const void *a3, const void *a4, __int16 a5)
{
  int v5; // esi
  int *v6; // ebx

  v5 = 41 * tcp_debx; /*0x1284e0*/
  v6 = &tcp_debug[41 * tcp_debx++]; /*0x1284e7*/
  if ( tcp_debx == 100 ) /*0x1284fa*/
    tcp_debx = 0; /*0x1284fc*/
  tcp_debug[v5] = iptime(); /*0x12850b*/
  *((_WORD *)v6 + 2) = a1; /*0x128511*/
  *((_WORD *)v6 + 3) = a2; /*0x128519*/
  v6[2] = (int)a3; /*0x128520*/
  if ( a3 ) /*0x128525*/
    qmemcpy(v6 + 14, a3, 0x6Cu); /*0x128533*/
  else
    bzero(v6 + 14, 0x6Cu); /*0x12853e*/
  if ( a4 ) /*0x12854a*/
    qmemcpy(v6 + 3, a4, 0x28u); /*0x128558*/
  else
    bzero(v6 + 3, 0x28u); /*0x128562*/
  *((_WORD *)v6 + 26) = a5; /*0x12856b*/
}
