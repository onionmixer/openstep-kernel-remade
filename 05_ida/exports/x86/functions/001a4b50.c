/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4b50. */
int __cdecl +[IODevice lookupByObjectNumber:deviceKind:deviceName:](
        id a1,
        SEL a2,
        unsigned int a3,
        char (*a4)[80],
        char (*a5)[80])
{
  int v5; // ebx
  const char *v6; // eax
  const char *v7; // eax
  id v9; // [esp+4h] [ebp-4h] BYREF

  objc_msgSend(dword_1E8674, sel_lock); /*0x1a4b68*/
  v5 = sub_1A3D58(a3, (int *)&v9); /*0x1a4b77*/
  objc_msgSend(dword_1E8674, sel_unlock); /*0x1a4b87*/
  if ( !v5 ) /*0x1a4b91*/
  {
    v6 = (const char *)objc_msgSend(v9, sel_deviceKind); /*0x1a4ba0*/
    strncpy((char *)a4, v6, 0x50u); /*0x1a4bad*/
    v7 = (const char *)objc_msgSend(v9, sel_name); /*0x1a4bbf*/
    strncpy((char *)a5, v7, 0x50u); /*0x1a4bcc*/
  }
  return v5; /*0x1a4bd3*/
}
