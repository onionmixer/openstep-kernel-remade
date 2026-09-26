/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ee54. */
id __cdecl -[KernBusRangeResource shareRange:](
        KernBusRangeResource *self,
        SEL a2,
        $85CD2974BE96D4886BB301820D1C36C2 a3)
{
  id result; // eax
  unsigned int end; // edx
  void **v6; // ebx
  unsigned int v7; // edx
  id v8; // eax
  int rangeCount; // edx
  id v10; // [esp+10h] [ebp-Ch]
  void **p_ranges; // [esp+14h] [ebp-8h]
  unsigned int v12; // [esp+18h] [ebp-4h]

  v12 = a3.var1 + a3.var0; /*0x17ee66*/
  p_ranges = &self->_ranges; /*0x17ee6f*/
  result = nullptr; /*0x17ee72*/
  if ( a3.var1 + a3.var0 && a3.var0 >= a3.var1 + a3.var0 ) /*0x17ee7f*/
    return nullptr; /*0x17ee8f*/
  if ( self->_base > a3.var0 ) /*0x17ee9a*/
    return nullptr; /*0x17ee9a*/
  end = self->_end; /*0x17ee9c*/
  if ( end ) /*0x17eea1*/
  {
    if ( v12 > end ) /*0x17eea6*/
      return nullptr; /*0x17eea8*/
  }
  while ( 1 ) /*0x17eec7*/
  {
    v6 = (void **)*p_ranges; /*0x17eec7*/
    if ( !*p_ranges ) /*0x17eec7*/
      break; /*0x17eec7*/
    v7 = (unsigned int)v6[3]; /*0x17eecd*/
    if ( v12 <= v7 ) /*0x17eed3*/
      break; /*0x17eed3*/
    if ( a3.var0 >= v7 && (unsigned int)v6[4] >= v12 ) /*0x17ef4b*/
      return objc_msgSend(v6, sel_share); /*0x17eebd*/
    if ( (unsigned int)v6[4] > a3.var0 ) /*0x17ef57*/
      return result; /*0x17ef57*/
    p_ranges = v6 + 1; /*0x17ef5c*/
  }
  v8 = objc_msgSend(self->_kind, sel_alloc); /*0x17eef6*/
  result = objc_msgSend(v8, sel_initForResource_range_shareable_); /*0x17eeff*/
  if ( result ) /*0x17ef09*/
  {
    *((_DWORD *)result + 1) = v6; /*0x17ef0b*/
    *p_ranges = result; /*0x17ef11*/
    rangeCount = self->_rangeCount; /*0x17ef16*/
    self->_rangeCount = rangeCount + 1; /*0x17ef1c*/
    if ( !rangeCount ) /*0x17ef21*/
    {
      v10 = result; /*0x17ef31*/
      objc_msgSend(self->_owner, sel__resourceActive); /*0x17ef34*/
      return v10; /*0x17ef39*/
    }
  }
  return result; /*0x17ef67*/
}
