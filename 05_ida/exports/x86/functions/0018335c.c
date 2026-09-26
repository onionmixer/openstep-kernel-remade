/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18335c. */
buf *sd_init_idmap()
{
  buf_t *v0; // edi
  int (__cdecl **v1)(__int16, int); // edx
  int (**v2)(); // eax
  int (__cdecl **v3)(__int16, int); // ecx
  int (__cdecl **v4)(__int16, int); // eax
  int v5; // esi
  _WORD *v6; // ebx
  buf *result; // eax

  v0 = &dword_1E1268; /*0x183367*/
  v1 = (int (__cdecl **)(__int16, int))bdevsw; /*0x18336c*/
  v2 = &bdevsw[6 * nblkdev]; /*0x183379*/
  if ( bdevsw < v2 ) /*0x183382*/
  {
    while ( *v1 != sdopen ) /*0x18338a*/
    {
      v1 += 6; /*0x1833b8*/
      if ( v1 >= (int (__cdecl **)(__int16, int))v2 ) /*0x1833bd*/
        goto LABEL_5; /*0x1833bd*/
    }
    dword_1E7564 = (-1431655765 * ((char *)v1 - (char *)bdevsw)) >> 3; /*0x1833ae*/
  }
LABEL_5:
  v3 = &cdevsw; /*0x1833bf*/
  v4 = &cdevsw + 11 * nchrdev; /*0x1833cf*/
  if ( &cdevsw < v4 ) /*0x1833d8*/
  {
    while ( *v3 != sdopen ) /*0x1833e2*/
    {
      v3 += 11; /*0x183410*/
      if ( v3 >= v4 ) /*0x183415*/
        goto LABEL_9; /*0x183415*/
    }
    dword_1E7568 = (-1171354717 * ((char *)v3 - (char *)&cdevsw)) >> 2; /*0x183409*/
  }
LABEL_9:
  bzero(dword_1E7324, 0x240u); /*0x183417*/
  v5 = 0; /*0x183422*/
  v6 = &unk_1E7346; /*0x183427*/
  do /*0x18346f*/
  {
    *(v6 - 1) = (8 * v5) | ((_WORD)dword_1E7568 << 8); /*0x18343f*/
    *v6 = (8 * v5) | ((_WORD)dword_1E7564 << 8); /*0x183450*/
    v6 += 18; /*0x183453*/
    result = (buf *)IOMalloc(0x44u); /*0x183458*/
    *v0 = result; /*0x18345d*/
    *(_DWORD *)result = 0; /*0x18345f*/
    ++v0; /*0x183465*/
    ++v5; /*0x18346b*/
  }
  while ( v5 <= 15 ); /*0x18346f*/
  return result; /*0x183474*/
}
