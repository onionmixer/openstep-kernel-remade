/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad828. */
$BB0ECD142E749ABD0946980FC80D177E *__cdecl -[SCSIDisk allocSdBuf:](SCSIDisk *self, SEL a2, void *a3)
{
  $BB0ECD142E749ABD0946980FC80D177E *v3; // ebx
  NXConditionLock *v4; // eax

  v3 = ($BB0ECD142E749ABD0946980FC80D177E *)IOMalloc(0x44u); /*0x1ad837*/
  bzero(v3, 0x44u); /*0x1ad83c*/
  if ( a3 ) /*0x1ad846*/
  {
    v3->var6 = a3; /*0x1ad870*/
  }
  else
  {
    v4 = +[Object alloc](aNxconditionloc, sel_alloc); /*0x1ad856*/
    v3->var7 = v4; /*0x1ad85b*/
    -[NXConditionLock initWith:](v4, sel_initWith_, 0); /*0x1ad868*/
  }
  return v3; /*0x1ad878*/
}
