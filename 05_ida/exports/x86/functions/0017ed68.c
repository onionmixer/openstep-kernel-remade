/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ed68. */
id __cdecl -[KernBusRangeResource reserveRange:](
        KernBusRangeResource *self,
        SEL a2,
        $85CD2974BE96D4886BB301820D1C36C2 a3)
{
  id result; // eax
  unsigned int end; // edx
  char *v6; // ebx
  id v7; // eax
  int rangeCount; // edx
  id v9; // [esp+10h] [ebp-10h]
  void **p_ranges; // [esp+14h] [ebp-Ch]
  unsigned int v11; // [esp+18h] [ebp-8h]

  v11 = a3.var1 + a3.var0; /*0x17ed7d*/
  p_ranges = &self->_ranges; /*0x17ed83*/
  result = nullptr; /*0x17ed86*/
  if ( a3.var1 + a3.var0 && a3.var0 >= a3.var1 + a3.var0 ) /*0x17ed93*/
    return nullptr; /*0x17eda3*/
  if ( self->_base > a3.var0 ) /*0x17edab*/
    return nullptr; /*0x17edab*/
  end = self->_end; /*0x17edad*/
  if ( end ) /*0x17edb2*/
  {
    if ( v11 > end ) /*0x17edb7*/
      return nullptr; /*0x17edb9*/
  }
  while ( 1 ) /*0x17edc3*/
  {
    v6 = (char *)*p_ranges; /*0x17edc3*/
    if ( !*p_ranges || *((_DWORD *)v6 + 3) >= v11 ) /*0x17edcf*/
      break; /*0x17edcf*/
    if ( *((_DWORD *)v6 + 4) > a3.var0 ) /*0x17ee3a*/
      return result; /*0x17ee3a*/
    p_ranges = (void **)(v6 + 4); /*0x17ee3f*/
  }
  v7 = objc_msgSend(self->_kind, sel_alloc); /*0x17edef*/
  result = objc_msgSend(v7, sel_initForResource_range_shareable_); /*0x17edf8*/
  if ( result ) /*0x17ee05*/
  {
    *((_DWORD *)result + 1) = v6; /*0x17ee07*/
    *p_ranges = result; /*0x17ee0d*/
    rangeCount = self->_rangeCount; /*0x17ee0f*/
    self->_rangeCount = rangeCount + 1; /*0x17ee15*/
    if ( !rangeCount ) /*0x17ee1a*/
    {
      v9 = result; /*0x17ee27*/
      objc_msgSend(self->_owner, sel__resourceActive); /*0x17ee2a*/
      return v9; /*0x17ee2f*/
    }
  }
  return result; /*0x17ee4b*/
}
