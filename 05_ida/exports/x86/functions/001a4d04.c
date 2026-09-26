/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4d04. */
int __cdecl +[IODevice getCharValues:forParameter:objectNumber:count:](
        id a1,
        SEL a2,
        char *a3,
        char *a4,
        unsigned int a5,
        unsigned int *a6)
{
  int v6; // ebx
  id v8; // [esp+4h] [ebp-4h] BYREF

  objc_msgSend(dword_1E8674, sel_lock); /*0x1a4d1c*/
  v6 = sub_1A3D58(a5, (int *)&v8); /*0x1a4d2b*/
  objc_msgSend(dword_1E8674, sel_unlock); /*0x1a4d3b*/
  if ( !v6 ) /*0x1a4d45*/
    return (int)objc_msgSend(v8, sel_getCharValues_forParameter_count_, a3, a4, a6); /*0x1a4d63*/
  return v6; /*0x1a4d67*/
}
