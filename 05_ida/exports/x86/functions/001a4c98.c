/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4c98. */
int __cdecl +[IODevice getIntValues:forParameter:objectNumber:count:](
        id a1,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5,
        unsigned int *a6)
{
  int v6; // ebx
  id v8; // [esp+4h] [ebp-4h] BYREF

  objc_msgSend(dword_1E8674, sel_lock); /*0x1a4cb0*/
  v6 = sub_1A3D58(a5, (int *)&v8); /*0x1a4cbf*/
  objc_msgSend(dword_1E8674, sel_unlock); /*0x1a4ccf*/
  if ( !v6 ) /*0x1a4cd9*/
    return (int)objc_msgSend(v8, sel_getIntValues_forParameter_count_, a3, a4, a6); /*0x1a4cf7*/
  return v6; /*0x1a4cfb*/
}
