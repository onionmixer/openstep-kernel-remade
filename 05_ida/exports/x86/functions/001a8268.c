/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a8268. */
void *__cdecl -[IODeviceDescription _fetchRangeList:returnedNum:](
        IODeviceDescription *self,
        SEL a2,
        id a3,
        unsigned int *a4)
{
  _DWORD *v4; // edi
  int v5; // eax
  signed int v6; // esi
  signed int v7; // ebx
  id v8; // eax
  int v9; // edx

  v4 = nullptr; /*0x1a826e*/
  v5 = (int)objc_msgSend(a3, sel_count); /*0x1a827b*/
  v6 = v5; /*0x1a8280*/
  if ( v5 > 0 ) /*0x1a8287*/
  {
    v4 = (_DWORD *)IOMalloc(8 * v5); /*0x1a8296*/
    v7 = 0; /*0x1a8298*/
    do /*0x1a82d2*/
    {
      v8 = objc_msgSend(a3, sel_objectAt_, v7); /*0x1a82b7*/
      v4[2 * v7] = objc_msgSend(v8, sel_range); /*0x1a82c5*/
      v4[2 * v7++ + 1] = v9; /*0x1a82c8*/
    }
    while ( v7 < v6 ); /*0x1a82d2*/
  }
  *a4 = v6; /*0x1a82d7*/
  return v4; /*0x1a82de*/
}
