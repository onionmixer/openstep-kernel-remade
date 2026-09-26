/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18f644. */
int *__cdecl pmap_create(int a1)
{
  int *v2; // eax
  int *v3; // ebx

  if ( a1 ) /*0x18f64c*/
    return nullptr; /*0x18f64e*/
  v2 = (int *)zalloc(pmap_zone); /*0x18f65b*/
  v3 = v2; /*0x18f660*/
  if ( !v2 ) /*0x18f667*/
    panic(aPmapCreatePmap); /*0x18f66e*/
  bzero(v2, 0x1Cu); /*0x18f679*/
  sub_18F58C(v3); /*0x18f67f*/
  v3[2] = 1; /*0x18f684*/
  v3[3] = 0; /*0x18f68b*/
  return v3; /*0x18f694*/
}
