/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9b90. */
int __cdecl IOAddToBdevsw(int (*a1)(), int (*a2)(), int (*a3)(), int (*a4)(), int (*a5)(), char a6)
{
  int (**v6)(); // edx
  int i; // ebx
  int (**v8)(); // edx

  v6 = bdevsw; /*0x1a9b9f*/
  for ( i = 0; i < nblkdev; v6 += 6 ) /*0x1a9bad*/
  {
    if ( !memcmp(v6, &unk_1E512C, 0x18u) ) /*0x1a9bbf*/
      break; /*0x1a9bc1*/
    ++i; /*0x1a9bc3*/
  }
  v8 = &bdevsw[6 * i]; /*0x1a9bd1*/
  if ( i < 0 || nblkdev <= i || memcmp(&bdevsw[6 * i], &unk_1E512C, 0x18u) ) /*0x1a9bf2*/
    return -1; /*0x1a9bf6*/
  bdevsw[6 * i] = a1; /*0x1a9c03*/
  v8[1] = a2; /*0x1a9c0c*/
  v8[2] = a3; /*0x1a9c12*/
  v8[3] = a4; /*0x1a9c18*/
  v8[4] = a5; /*0x1a9c1e*/
  v8[5] = nullptr; /*0x1a9c21*/
  if ( a6 ) /*0x1a9c2c*/
    v8[5] = (int (*)())1024; /*0x1a9c2e*/
  return i; /*0x1a9c3a*/
}
