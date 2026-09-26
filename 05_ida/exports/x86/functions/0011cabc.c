/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cabc. */
int __cdecl pn_append(int a1, const char *a2)
{
  size_t v2; // edx
  size_t v3; // edi
  int v4; // ecx

  v2 = strlen(a2) + 1; /*0x11cad2*/
  v3 = v2 - 1; /*0x11cad8*/
  v4 = *(_DWORD *)(a1 + 8); /*0x11cadb*/
  if ( v2 - 1 + v4 > 0x3FF ) /*0x11cae6*/
    return 63; /*0x11cafc*/
  bcopy(a2, (void *)(v4 + *(_DWORD *)(a1 + 4)), v2); /*0x11caf0*/
  *(_DWORD *)(a1 + 8) += v3; /*0x11caf5*/
  return 0; /*0x11cb04*/
}
