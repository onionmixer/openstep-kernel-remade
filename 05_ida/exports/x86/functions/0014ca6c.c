/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14ca6c. */
int __cdecl ipc_port_alloc_name(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int result; // eax
  _DWORD *v4; // ebx
  _DWORD *v5; // [esp+Ch] [ebp-4h] BYREF

  result = ipc_object_alloc_name(a1, 0, 0x20000, 0, a2, (int *)&v5); /*0x14ca8a*/
  if ( !result ) /*0x14ca94*/
  {
    v4 = v5; /*0x14ca96*/
    v5[3] = a1; /*0x14ca99*/
    v4[4] = a2; /*0x14ca9c*/
    v4[6] = 0; /*0x14ca9f*/
    v4[7] = 0; /*0x14caa6*/
    v4[8] = 0; /*0x14caad*/
    v4[9] = 0; /*0x14cab4*/
    v4[10] = 0; /*0x14cabb*/
    v4[11] = 0; /*0x14cac2*/
    v4[12] = 0; /*0x14cac9*/
    v4[13] = 0; /*0x14cad0*/
    v4[14] = 0; /*0x14cad7*/
    v4[15] = 5; /*0x14cade*/
    ipc_mqueue_init(v4 + 16); /*0x14cae9*/
    v4[19] = 0; /*0x14caee*/
    *a3 = v5; /*0x14cafb*/
    return 0; /*0x14cafd*/
  }
  return result; /*0x14cb02*/
}
