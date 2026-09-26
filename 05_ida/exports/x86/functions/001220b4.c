/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1220b4. */
char arptimer()
{
  char *v0; // edi
  int v1; // esi
  _BYTE *v2; // ebx
  int v3; // eax
  char v4; // al

  timeout((int)arptimer); /*0x1220d0*/
  v0 = (char *)&arptab; /*0x1220d5*/
  v1 = 0; /*0x1220da*/
  v2 = &unk_1E9C8B; /*0x1220df*/
  do /*0x122127*/
  {
    LOBYTE(v3) = *v2; /*0x1220e4*/
    if ( *v2 && (v3 & 4) == 0 ) /*0x1220ec*/
    {
      v4 = *(v2 - 1); /*0x1220ee*/
      *(v2 - 1) = v4 + 1; /*0x1220f5*/
      v3 = (unsigned __int8)(v4 + 1); /*0x1220fa*/
      if ( (*v2 & 2) != 0 ) /*0x122102*/
      {
        if ( v3 <= 19 ) /*0x122107*/
          goto LABEL_9; /*0x122107*/
      }
      else if ( v3 <= 2 ) /*0x12210f*/
      {
        goto LABEL_9; /*0x12210f*/
      }
      LOBYTE(v3) = arptfree(v0); /*0x122112*/
    }
LABEL_9:
    ++v1; /*0x12211a*/
    v2 += 20; /*0x12211b*/
    v0 += 20; /*0x12211e*/
  }
  while ( v1 <= 170 ); /*0x122127*/
  return v3; /*0x12212c*/
}
