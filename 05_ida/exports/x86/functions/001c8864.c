/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c8864. */
int __cdecl IOFreeLow(int a1)
{
  int *v1; // ebx
  int *v2; // ecx
  int *v3; // edx
  int *v4; // eax
  int *v5; // eax

  v1 = (int *)dmaBufQueue; /*0x1c886c*/
  if ( (int *)dmaBufQueue == &dmaBufQueue )
    return IOLog("IOFreeLow: buf 0x%x not found\n");
  while ( *(_DWORD *)*v1 != a1 )
  {
    v1 = (int *)v1[1]; /*0x1c88cc*/
    if ( v1 == &dmaBufQueue )
      return IOLog("IOFreeLow: buf 0x%x not found\n");
  }
  v2 = (int *)v1[1]; /*0x1c8882*/
  v3 = (int *)v1[2]; /*0x1c8885*/
  v4 = &dmaBufQueue; /*0x1c8888*/
  if ( v2 != &dmaBufQueue ) /*0x1c8893*/
    v4 = v2 + 1; /*0x1c8895*/
  v4[1] = (int)v3; /*0x1c8898*/
  v5 = &dmaBufQueue; /*0x1c889b*/
  if ( v3 != &dmaBufQueue ) /*0x1c88a6*/
    v5 = v3 + 1; /*0x1c88a8*/
  *v5 = (int)v2; /*0x1c88ab*/
  dma_buf_free(*v1); /*0x1c88b0*/
  IOFree(*v1, 8); /*0x1c88ba*/
  return IOFree((int)v1, 12); /*0x1c88e5*/
}
