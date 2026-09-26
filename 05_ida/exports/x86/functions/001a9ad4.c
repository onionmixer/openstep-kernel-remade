/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9ad4. */
int __cdecl IOAddToBdevswAt(int a1, int (*a2)(), int (*a3)(), int (*a4)(), int (*a5)(), int (*a6)(), char a7)
{
  int i; // ebx
  int (**v8)(); // edx
  int (**v9)(); // edx

  i = a1; /*0x1a9add*/
  if ( a1 == -1 ) /*0x1a9ae9*/
  {
    v8 = bdevsw; /*0x1a9aeb*/
    for ( i = 0; i < nblkdev; v8 += 6 ) /*0x1a9af9*/
    {
      if ( !memcmp(v8, &unk_1E512C, 0x18u) ) /*0x1a9b0b*/
        break; /*0x1a9b0d*/
      ++i; /*0x1a9b0f*/
    }
  }
  v9 = &bdevsw[6 * i]; /*0x1a9b1d*/
  if ( i < 0 || nblkdev <= i || memcmp(&bdevsw[6 * i], &unk_1E512C, 0x18u) ) /*0x1a9b3e*/
    return -1; /*0x1a9b42*/
  bdevsw[6 * i] = a2; /*0x1a9b4f*/
  v9[1] = a3; /*0x1a9b58*/
  v9[2] = a4; /*0x1a9b5e*/
  v9[3] = a5; /*0x1a9b64*/
  v9[4] = a6; /*0x1a9b6a*/
  v9[5] = nullptr; /*0x1a9b6d*/
  if ( a7 ) /*0x1a9b78*/
    v9[5] = (int (*)())1024; /*0x1a9b7a*/
  return i; /*0x1a9b86*/
}
