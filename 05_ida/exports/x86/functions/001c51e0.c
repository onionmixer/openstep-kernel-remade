/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c51e0. */
unsigned int __cdecl -[IOFrameBufferDisplay mapFrameBufferAtPhysicalAddress:length:](
        IOFrameBufferDisplay *self,
        SEL a2,
        unsigned int a3,
        int a4)
{
  id v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  int v10; // [esp-4h] [ebp-14h]
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v4 = nullptr; /*0x1c51ef*/
  v5 = *((_DWORD *)-[IODisplay displayInfo](self, sel_displayInfo) + 24) & 0xC; /*0x1c5201*/
  if ( v5 == 4 ) /*0x1c520a*/
    v6 = 2; /*0x1c521c*/
  else
    v6 = v5 != 8; /*0x1c520c*/
  if ( a3 )
  {
    v10 = v6; /*0x1c522a*/
    v7 = current_task_EXTERNAL(); /*0x1c522d*/
    if ( _KernBusMemoryCreateMapping(a3, a4, &v11, v7, 1, v10) )
    {
      v8 = -[IODevice stringFromReturn:](self, sel_stringFromReturn_, -701); /*0x1c524d*/
LABEL_10:
      IOLog((int)"IOFrameBufferDisplay/mapFrameBuffer: Can't map memory (%s)\n", v8);
      return 0; /*0x1c528a*/
    }
  }
  else
  {
    v4 = -[IOFrameBufferDisplay mapMemoryRange:to:findSpace:cache:]( /*0x1c5266*/
           self,
           sel_mapMemoryRange_to_findSpace_cache_,
           0,
           &v11,
           1,
           v6);
  }
  if ( v4 ) /*0x1c526d*/
  {
    v8 = -[IODevice stringFromReturn:](self, sel_stringFromReturn_, v4); /*0x1c5278*/
    goto LABEL_10; /*0x1c5278*/
  }
  return v11; /*0x1c5292*/
}
