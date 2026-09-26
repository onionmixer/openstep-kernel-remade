/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac248. */
$E7EB92A5B27EBB39AD62798E52927D35 *__cdecl -[IOSCSIController searchReserveQ:lun:](
        IOSCSIController *self,
        SEL a2,
        unsigned __int64 a3,
        unsigned __int64 a4)
{
  $E7EB92A5B27EBB39AD62798E52927D35 *result; // eax

  result = ($E7EB92A5B27EBB39AD62798E52927D35 *)self->_reserveQ.next; /*0x1ac25d*/
  if ( &self->_reserveQ == ($BAB6C68F9D34F0972F921D3DB17D7446 *)result ) /*0x1ac26b*/
    return nullptr; /*0x1ac28a*/
  while ( LODWORD(result->var0) != (_DWORD)a3 /*0x1ac281*/
       || *(unsigned __int64 *)((char *)&result->var0 + 4) != __PAIR64__(a4, HIDWORD(a3))
       || HIDWORD(result->var1) != HIDWORD(a4) )
  {
    result = ($E7EB92A5B27EBB39AD62798E52927D35 *)result->var3.var0; /*0x1ac283*/
    if ( &self->_reserveQ == ($BAB6C68F9D34F0972F921D3DB17D7446 *)result ) /*0x1ac288*/
      return nullptr; /*0x1ac288*/
  }
  return result; /*0x1ac28f*/
}
