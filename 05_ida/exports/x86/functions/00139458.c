/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x139458. */
int __cdecl sub_139458(unsigned int a1)
{
  __int16 v1; // ax
  __int16 v2; // ax
  int v4; // [esp+4h] [ebp-4h] BYREF

  if ( dword_1DE6B8 > fifo_alloc ) /*0x13946e*/
  {
    fifo_alloc += dword_1DE6B4; /*0x1394c7*/
    kmem_alloc_wired(kernel_map, &v4, dword_1DE6B4); /*0x1394d9*/
    ++*(_WORD *)(a1 + 138); /*0x1394de*/
    return v4; /*0x1394e5*/
  }
  else
  {
    v1 = *(_WORD *)(a1 + 64); /*0x139470*/
    *(_WORD *)(a1 + 64) = v1 & 0xFFFE; /*0x139479*/
    if ( (v1 & 0x10) != 0 ) /*0x13947f*/
    {
      LOBYTE(v1) = v1 & 0xEE; /*0x139481*/
      *(_WORD *)(a1 + 64) = v1; /*0x139483*/
      wakeup(a1); /*0x139488*/
    }
    sleep((unsigned int)&fifo_alloc); /*0x139497*/
    while ( 1 ) /*0x1394ad*/
    {
      v2 = *(_WORD *)(a1 + 64); /*0x1394ad*/
      if ( (v2 & 1) == 0 ) /*0x1394b3*/
        break; /*0x1394b3*/
      LOBYTE(v2) = v2 | 0x10; /*0x13949c*/
      *(_WORD *)(a1 + 64) = v2; /*0x13949e*/
      sleep(a1); /*0x1394a5*/
    }
    *(_BYTE *)(a1 + 64) |= 1u; /*0x1394b5*/
    return 0; /*0x1394b9*/
  }
}
