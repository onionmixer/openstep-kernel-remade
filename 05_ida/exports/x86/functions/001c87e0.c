/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c87e0. */
int __cdecl IOMallocLow(int a1)
{
  int v1; // esi
  int *v3; // eax
  int v4; // edx
  int v5; // eax

  v1 = IOMalloc(8u); /*0x1c87ef*/
  if ( dma_buf_alloc(v1, a1) ) /*0x1c87f3*/
  {
    v3 = (int *)IOMalloc(0xCu); /*0x1c882a*/
    v4 = (int)v3; /*0x1c882f*/
    *v3 = v1; /*0x1c8831*/
    if ( (int *)dmaBufQueue == &dmaBufQueue ) /*0x1c883d*/
    {
      dmaBufQueue = (int)v3; /*0x1c880c*/
      dword_1F7494 = (int)v3; /*0x1c8812*/
      v3[1] = (int)&dmaBufQueue; /*0x1c8818*/
      v3[2] = (int)&dmaBufQueue; /*0x1c881f*/
    }
    else
    {
      v5 = dword_1F7494; /*0x1c883f*/
      *(_DWORD *)(v4 + 8) = dword_1F7494; /*0x1c8844*/
      *(_DWORD *)(v4 + 4) = &dmaBufQueue; /*0x1c8847*/
      dword_1F7494 = v4; /*0x1c884e*/
      *(_DWORD *)(v5 + 4) = v4; /*0x1c8854*/
    }
    return *(_DWORD *)v1; /*0x1c8857*/
  }
  else
  {
    IOFree(v1, 8); /*0x1c8802*/
    return 0; /*0x1c8807*/
  }
}
