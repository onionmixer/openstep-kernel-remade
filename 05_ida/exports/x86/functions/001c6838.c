/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c6838. */
unsigned int __cdecl -[IOSVGADisplay mapFrameBufferAtPhysicalAddress:length:](
        IOSVGADisplay *self,
        SEL a2,
        unsigned int a3,
        int a4)
{
  id v4; // ebx
  int v5; // eax
  const char *v6; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = nullptr; /*0x1c6847*/
  if ( a3 )
  {
    v5 = current_task_EXTERNAL(); /*0x1c6851*/
    if ( _KernBusMemoryCreateMapping(a3, a4, &v8, v5, 1, 1) )
    {
      v6 = -[IODevice stringFromReturn:](self, sel_stringFromReturn_, -701); /*0x1c6871*/
LABEL_7:
      IOLog((int)"IOSVGADisplay/mapFrameBuffer: Can't map memory (%s)\n", v6);
      return 0; /*0x1c68af*/
    }
  }
  else
  {
    v4 = -[IOSVGADisplay mapMemoryRange:to:findSpace:cache:](self, sel_mapMemoryRange_to_findSpace_cache_, 0, &v8, 1, 1); /*0x1c688b*/
  }
  if ( v4 ) /*0x1c6892*/
  {
    v6 = -[IODevice stringFromReturn:](self, sel_stringFromReturn_, v4); /*0x1c689d*/
    goto LABEL_7; /*0x1c689d*/
  }
  return v8; /*0x1c68ba*/
}
