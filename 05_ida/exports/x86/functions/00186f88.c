/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x186f88. */
// Alternative name is '_set_label'
int __cdecl setjmp(jmp_buf a1)
{
  int v1; // ebx
  int v2; // ebp
  int v3; // edi
  int v4; // esi
  int retaddr; // [esp+0h] [ebp+0h] BYREF

  a1[6] = curipl(); /*0x186f91*/
  *a1 = v3; /*0x186f94*/
  a1[1] = v4; /*0x186f97*/
  a1[2] = v1; /*0x186f9a*/
  a1[3] = v2; /*0x186f9d*/
  a1[4] = (int)&retaddr; /*0x186fa0*/
  a1[5] = retaddr; /*0x186fa7*/
  return 0; /*0x186fac*/
}
