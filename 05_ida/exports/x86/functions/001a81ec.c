/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a81ec. */
void *__cdecl -[IODeviceDescription _fetchItemList:returnedNum:](
        IODeviceDescription *self,
        SEL a2,
        id a3,
        unsigned int *a4)
{
  _DWORD *v4; // edi
  signed int v5; // esi
  signed int v6; // ebx
  id v7; // eax

  v4 = nullptr; /*0x1a81f2*/
  v5 = (signed int)objc_msgSend(a3, sel_count); /*0x1a8204*/
  if ( v5 > 0 ) /*0x1a820b*/
  {
    v4 = (_DWORD *)IOMalloc(4 * v5); /*0x1a821a*/
    v6 = 0; /*0x1a821c*/
    do /*0x1a8252*/
    {
      v7 = objc_msgSend(a3, sel_objectAt_, v6); /*0x1a823b*/
      v4[v6++] = objc_msgSend(v7, sel_item); /*0x1a8249*/
    }
    while ( v6 < v5 ); /*0x1a8252*/
  }
  *a4 = v5; /*0x1a8257*/
  return v4; /*0x1a825e*/
}
