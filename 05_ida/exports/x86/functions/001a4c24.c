/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4c24. */
int __cdecl +[IODevice lookupByDeviceName:objectNumber:deviceKind:](
        id a1,
        SEL a2,
        char *__s1,
        unsigned int *a4,
        char (*a5)[80])
{
  int v5; // ebx
  const char *v6; // eax
  id v8; // [esp+8h] [ebp-4h] BYREF

  objc_msgSend(dword_1E8674, sel_lock); /*0x1a4c40*/
  v5 = sub_1A3D9C(__s1, &v8, a4); /*0x1a4c50*/
  objc_msgSend(dword_1E8674, sel_unlock); /*0x1a4c60*/
  if ( !v5 ) /*0x1a4c6a*/
  {
    v6 = (const char *)objc_msgSend(v8, sel_deviceKind); /*0x1a4c79*/
    strncpy((char *)a5, v6, 0x50u); /*0x1a4c86*/
  }
  return v5; /*0x1a4c90*/
}
