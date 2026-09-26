/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cecb4. */
_BOOL4 __cdecl sub_1CECB4(int a1, int a2, int a3)
{
  int v3; // ebx
  const char *v4; // ecx

  v3 = 0; /*0x1cecbe*/
  v4 = *(const char **)(a2 + 8); /*0x1cecc0*/
  if ( **(_BYTE **)(a3 + 8) == *v4 ) /*0x1cecca*/
    return strcmp(v4, *(const char **)(a3 + 8)) == 0; /*0x1cecd7*/
  return v3; /*0x1cecde*/
}
