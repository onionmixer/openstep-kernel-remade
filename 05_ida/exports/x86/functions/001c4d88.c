/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c4d88. */
char __cdecl +[IOFrameBufferDisplay probe:](id a1, SEL a2, id a3)
{
  id v3; // eax
  id v4; // eax
  void *v5; // ebx

  v3 = objc_msgSend(a1, sel_alloc); /*0x1c4da2*/
  v4 = objc_msgSend(v3, sel_initFromDeviceDescription_); /*0x1c4dab*/
  v5 = v4; /*0x1c4db0*/
  if ( !v4 ) /*0x1c4db7*/
    return 0; /*0x1c4de0*/
  objc_msgSend(v4, sel_setDeviceKind_, "Linear Framebuffer"); /*0x1c4dc6*/
  objc_msgSend(v5, sel_registerDevice); /*0x1c4dd3*/
  return 1; /*0x1c4de2*/
}
