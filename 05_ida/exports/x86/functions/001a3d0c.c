/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a3d0c. */
int __cdecl IOGetObjectForDeviceName(char *__s1, int a2)
{
  int v2; // ebx
  int v4; // [esp+8h] [ebp-4h] BYREF

  objc_msgSend(dword_1E8674, sel_lock); /*0x1a3d28*/
  v2 = sub_1A3D9C(__s1, a2, (int)&v4); /*0x1a3d38*/
  objc_msgSend(dword_1E8674, sel_unlock); /*0x1a3d48*/
  return v2; /*0x1a3d52*/
}
