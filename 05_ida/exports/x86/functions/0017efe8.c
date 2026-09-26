/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17efe8. */
id __cdecl -[KernBusRangeResource _destroyRange:](KernBusRangeResource *self, SEL a2, id a3)
{
  void **p_ranges; // edi
  void **ranges; // ebx
  int rangeCount; // eax

  p_ranges = &self->_ranges; /*0x17eff1*/
  if ( !(unsigned __int8)objc_msgSend(a3, sel_isKindOf_, self->_kind) ) /*0x17f003*/
    return nullptr; /*0x17f00f*/
  ranges = (void **)self->_ranges; /*0x17f014*/
  if ( !ranges ) /*0x17f019*/
    return nullptr; /*0x17f062*/
  while ( a3 != ranges ) /*0x17f01f*/
  {
    p_ranges = ranges + 1; /*0x17f058*/
    ranges = (void **)ranges[1]; /*0x17f05b*/
    if ( !ranges ) /*0x17f060*/
      return nullptr; /*0x17f060*/
  }
  *p_ranges = ranges[1]; /*0x17f024*/
  rangeCount = self->_rangeCount; /*0x17f026*/
  self->_rangeCount = rangeCount - 1; /*0x17f02c*/
  if ( rangeCount == 1 ) /*0x17f032*/
    objc_msgSend(self->_owner, sel__resourceInactive); /*0x17f03f*/
  return objc_msgSend(ranges, sel_dealloc); /*0x17f067*/
}
