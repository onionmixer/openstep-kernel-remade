/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c68e8. */
char __cdecl +[IOSVGADisplay probe:](id a1, SEL a2, id a3)
{
  id v3; // eax
  id v4; // eax
  void *v5; // ebx

  v3 = objc_msgSend(a1, sel_alloc); /*0x1c6902*/
  v4 = objc_msgSend(v3, sel_initFromDeviceDescription_); /*0x1c690b*/
  v5 = v4; /*0x1c6910*/
  if ( !v4 ) /*0x1c6917*/
    return 0; /*0x1c6940*/
  objc_msgSend(v4, sel_setDeviceKind_, "frame buffer"); /*0x1c6926*/
  objc_msgSend(v5, sel_registerDevice); /*0x1c6933*/
  return 1; /*0x1c6942*/
}
